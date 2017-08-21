const fs = require('fs');
const path = require('path');
const grammar = require('./grammar');
const tokens = require('./tokens');

const get_auto_gen_comment = () => {
  const filename = path.basename(__filename);

  return `
    /**
     * DO NOT MODIFY - AUTO GENERATED BY "../scripts/${filename}"
     */
  `
}

const get_class_name = (symbol) => {
  if (is_non_terminal(symbol)) {
    return `${symbol}_t`;
  }

  return `token_t`;
}

const get_node_header_file_name = (group_name) => {
  return `${group_name.split('_').join('-')}.h`;
}

const get_node_header_file_path = (group_name) => {
  const file_name = get_node_header_file_name(group_name);
  return path.resolve(__dirname, '..', 'ast-nodes', file_name);
}

const get_node_cc_file_name = (group_name) => {
  return `${group_name.split('_').join('-')}.cc`;
}

const get_node_cc_file_path = (group_name) => {
  const file_name = get_node_cc_file_name(group_name);
  return path.resolve(__dirname, '..', 'ast-nodes', file_name);
}

const get_all_header_file_path = () => {
  return path.resolve(__dirname, '..', 'ast-nodes.h');
}

const get_combined_header_file_path = () => {
  return path.resolve(__dirname, '..', 'ast-nodes', 'all.h');
}

const is_non_terminal = (group_name) => {
  return group_name !== (group_name + '').toUpperCase();
}

const get_node_deps = (group_name) => {
  const deps = [];

  grammar[group_name].forEach((symbols) => {
    symbols.forEach((name) => {
      if (is_non_terminal(name) && deps.indexOf(name) === -1) {
        deps.push(name);
      }
    });
  });

  return deps;
}

const format_code = (spaces, code) => {
  return code.split('\n' + new Array(spaces + 1)
    .join(' '))
    .join('\n')
    .trim() + '\n';
}

const has_terminals = (group_name) => {
  let has_terminals = false;

  grammar[group_name].forEach((symbols) => {
    symbols.forEach((name) => {
      if (!is_non_terminal(name)) {
        has_terminals = true;
      }
    });
  });

  return has_terminals;
}

const get_include_statement = (group_name) => {
  const file_name = get_node_header_file_name(group_name);
  return `#include "${file_name}"`;
}

const get_include_statements = (group_name) => {
  return get_node_deps(group_name).map((dep) => {
    if (group_name === dep) {
      return;
    }

    return get_include_statement(dep);
  }).join('\n');
}

const get_forward_declaration = (group_name) => {
  return `class ${get_class_name(group_name)};`;
}

const get_forward_declarations = (group_name) => {
  return get_node_deps(group_name).map((dep) => {
    if (group_name === dep) {
      return;
    }

    return get_forward_declaration(dep);
  }).join('\n');
}

const get_constructor_params = (group_name, pattern) => {
  let token_count = 0;
  let non_terminal_count = 0;

  return pattern.map((symbol) => {
    if (is_non_terminal(symbol)) {
      const variable_type = get_class_name(symbol);
      const variable_name = `${symbol}_${non_terminal_count++}`;
      return `    const ${variable_type} &`;
    } else {
      const variable_name = `token_${token_count++}`;
      return `    const token_t &`;
    }
  }).join(',\n      ');
}

const get_constructor_declaration = (group_name, pattern) => {
  const class_name = get_class_name(group_name);
  const parameters = get_constructor_params(group_name, pattern);

  return format_code(2, `
    ${class_name}(
      ${parameters}
    );
  `).trim();
}

const get_constructors = (group_name) => {
  const constructors = grammar[group_name].map((pattern) => {
    return get_constructor_declaration(group_name, pattern);
  });

  const taboo = [];
  return constructors.filter((item) => {
    if (taboo.indexOf(item) === -1) {
      taboo.push(item);
      return true;
    }

    return false;
  }).join('\n\n  ');
}

const get_pattern_initializer_list = (pattern) => {
  return pattern.map((symbol, idx) => {
    const space = idx > 0 ? '        ' : '  ';
    const class_name = get_class_name(symbol);

    if (is_non_terminal(symbol)) {
      return `${space}pattern_item_t<${class_name}>::get()`;
    }

    const kind_cc = `token_t::uppercase_to_kind("${symbol}")`;
    return `${space}pattern_item_t<${class_name}>::get(${kind_cc})`;
  }).join(',\n');
}

const get_pattern_initializer_lists = (group_name) => {
  return grammar[group_name].map((pattern) => {
    return `{
      ${get_pattern_initializer_list(pattern)}
      }`;
  }).join(', ');
}

const get_pattern_initializer = (group_name) => {
  const class_name = get_class_name(group_name);
  const initializer_lists = get_pattern_initializer_lists(group_name);
  return `const std::vector<${class_name}::pattern_t> ${class_name}::patterns = {
      ${initializer_lists}
    };`;
}

const get_class_declaration = (group_name) => {
  const class_name = get_class_name(group_name);
  const include_statements = get_include_statements(group_name);
  const forward_declarations = get_forward_declarations(group_name);
  const constructors = get_constructors(group_name);
  const pattern_initializer = get_pattern_initializer(group_name);

  return format_code(4, `
    #pragma once

    ${get_auto_gen_comment()}

    #include <vector>
    #include "../ast.h"
    ${include_statements}

    namespace gliss {

    namespace ast {

    class ${class_name}: public ast_t {

    public:

      using unique_pattern_t = std::shared_ptr<any_pattern_item_t>;

      using pattern_t = std::vector<unique_pattern_t>;

      static const std::vector<pattern_t> patterns;

      ${constructors}

      virtual void accept(const visitor_t &visitor) const override {
        visitor(this);
      }

    };  // ${class_name}

    ${pattern_initializer}

    }   // ast

    }   // gliss
  `);
}


const get_visitor_declarations = () => {
  return Object.keys(grammar)
    .map((key) => get_class_name(key))
    .map((name) => `virtual void operator()(const ${name} *) const = 0;`)
    .join('\n      ');
}

const get_ast_nodes_h = () => {
  const classes = Object.keys(grammar)
    .map((key) => get_class_name(key))
    .map((name) => `class ${name};`)
    .join('\n');

  return format_code(4, `
    #pragma once

    namespace gliss {

    namespace ast {

    ${classes}
    class ast_t;

    struct empty_visitor_t {
      virtual ~empty_visitor_t() = default;
    };  // empty_visitor_t

    struct default_visitor_t: public empty_visitor_t {
      virtual ~default_visitor_t() = default;
      ${get_visitor_declarations()}
    };  // default_visitor_t

    }   // ast

    }   // gliss
  `);
}

const get_combined_ast_nodes_h = () => {
  const includes = Object.keys(grammar)
    .map((key) => get_include_statement(key))
    .join('\n');

  return format_code(4, `
    #pragma once

    ${includes}

  `);
}

Object.keys(grammar).forEach((group_name) => {
  const head_src = get_class_declaration(group_name);
  const head_path = get_node_header_file_path(group_name);
  fs.writeFileSync(head_path, head_src);
});

const all_src = get_ast_nodes_h();
const all_path = get_all_header_file_path();
fs.writeFileSync(all_path, all_src);

const combined_header = get_combined_header_file_path();
const combined_src = get_combined_ast_nodes_h();
fs.writeFileSync(combined_header, combined_src);
