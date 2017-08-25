const fs = require('fs');
const path = require('path');
const grammar = require('./grammar');
const tokens = require('./tokens');
const ast_nodes = require('./ast_nodes');

const get_auto_gen_comment = () => {
  const filename = path.basename(__filename);

  return `
    /**
     * DO NOT MODIFY - AUTO GENERATED BY "../scripts/${filename}"
     */
  `
}

const get_base_class_name = (symbol) => {
  if (is_non_terminal(symbol)) {
    return `${symbol}_t`;
  }

  return `token_t`;
}

const get_derived_class_name = (group_name, pattern) => {
  if (!is_non_terminal(group_name)) {
    throw new Error(`${group_name} is terminal`);
  }

  const pattern_part = pattern.map((symbol) => symbol.toLowerCase()).join('_');
  return `${group_name}_${pattern_part}_t`;
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

const get_symbol_header_file_path = () => {
  return path.resolve(__dirname, '..', 'symbols.h');
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
    .trim()
    .split(/\s+\n/g)
    .join('\n\n') + '\n';
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

const get_forward_declaration = (group_name, pattern) => {
  return `class ${get_base_class_name(group_name, pattern)};`;
}

const get_forward_declarations = (group_name) => {
  return get_node_deps(group_name).map((dep) => {
    if (group_name === dep) {
      return;
    }

    return get_forward_declaration(dep);
  }).join('\n');
}

const get_class_prop_names = (pattern) => {
  return pattern.map((symbol, idx) => {
    return `${symbol.toLowerCase()}_${idx}`;
  });
}

const get_class_prop_types = (pattern) => {
  return pattern.map((symbol) => {
    return `std::unique_ptr<${get_base_class_name(symbol)}>`;
  });
}

const get_constructor_params = (pattern) => {
  const types = get_class_prop_types(pattern);
  const names = get_class_prop_names(pattern);
  return types.map((type, idx) => {
    const name = names[idx];
    return `${type} &&${name}_`;
  }).join(',\n        ');
}

const get_factory_func = (group_name, pattern) => {
  const class_name = get_derived_class_name(group_name, pattern);
  const params = pattern.map((symbol, idx) => {
    if (is_non_terminal(symbol)) {
      return `
        std::unique_ptr<${get_base_class_name(symbol)}> &&${symbol}_${idx}_
      `.trim();
    } else {
      return `
        const token_t *${symbol}_${idx}_
      `.trim();
    }
  }).join(',\n        ');

  const initializers = pattern.map((symbol, idx) => {
    if (is_non_terminal(symbol)) {
      return `
        std::move(${symbol}_${idx}_)
      `.trim();
    } else {
      return `
        std::make_unique<token_t>(*${symbol}_${idx}_)
      `.trim();
    }
  }).join(',\n          ');

  return `
      static std::unique_ptr<${class_name}> make(
        ${params}
      ) {
        return std::make_unique<${class_name}>(
          ${initializers}
        );
      }
  `.trim();

}

const get_constructor_init_list = (pattern) => {
  const types = get_class_prop_types(pattern);
  const names = get_class_prop_names(pattern);
  return types.map((type, idx) => {
    const name = names[idx];
    return `${name}(std::move(${name}_))`;
  }).join(',\n         ');
}

const get_constructor = (group_name, pattern) => {
  const class_name = get_derived_class_name(group_name, pattern);
  const parameters = get_constructor_params(pattern);
  const init_list = get_constructor_init_list(pattern);

  return `
      ${class_name}(
        ${parameters}
      ): ${init_list} {}
  `.trim();
}

const get_derived_class_properties = (group_name, pattern) => {
  const types = get_class_prop_types(pattern);
  const names = get_class_prop_names(pattern);
  return types.map((type, idx) => {
    const name = names[idx];
    return `${type} ${name}`;
  }).join(';\n\n      ') + ';';
}

const get_derived_class_declaration = (group_name, pattern, idx) => {
  const class_name = get_derived_class_name(group_name, pattern);
  const base_name = get_base_class_name(group_name);
  const constructor = get_constructor(group_name, pattern);
  const properties = get_derived_class_properties(group_name, pattern);

  return `
    class ${class_name}: public ${base_name} {

    public:

      ${properties}

      ${constructor}

      virtual void accept(const visitor_t &visitor) const override {
        visitor(this);
      }

      ${get_factory_func(group_name, pattern)}

    };  // ${class_name}
  `;
}

const get_empty_visitor = (group_name) => {
  if (!grammar[group_name].length) {
    const name = get_base_class_name(group_name);
    return `virtual void accept(const visitor_t &) const override {}`
  }

  return '';
}

const get_pattern_comments = (group_name) => {
  return grammar[group_name].map((pattern, idx) => {
    return `
     * ${idx+1}. ${pattern.join(' ')}
    `.trim();
  }).join('\n ');
}

const get_pattern_comment = (group_name) => {
  return `
    /**
     * Patterns for ${group_name}
     *
     ${get_pattern_comments(group_name)}
     */
  `
}

const get_base_class_declaration = (group_name) => {
  const class_name = get_base_class_name(group_name);

  return `
    class ${class_name}: public ast_t {

    public:

      static constexpr int num_types = ${grammar[group_name].length};

      ${get_empty_visitor(group_name)}
      virtual ~${class_name}() = default;

    };  // ${class_name}
  `.trim();
}

const get_ast_node_header = (group_name) => {
  const include_statements = get_include_statements(group_name);
  const base_class = get_base_class_declaration(group_name);
  const derived_classes = grammar[group_name].map(
    (pattern, idx) => get_derived_class_declaration(group_name, pattern, idx)
  ).join('\n    ');

  return format_code(4, `
    #pragma once

    ${get_auto_gen_comment()}

    #include <vector>
    #include "../ast.h"
    ${include_statements}

    ${get_pattern_comment(group_name)}

    namespace gliss {

    namespace ast {

    ${get_forward_declarations(group_name)}

    ${base_class}

    ${derived_classes}

    }   // ast

    }   // gliss
  `);
}

const get_all_classes = () => {
  const classes = [];
  Object.keys(grammar).forEach((key) => {
    grammar[key].forEach((pattern) => {
      classes.push(get_derived_class_name(key, pattern));
    });
  });
  return classes;
}

const get_visitor_declarations = () => {
  return get_all_classes()
    .map((name) => `virtual void operator()(const ${name} *) const = 0;`)
    .join('\n      ');
}

const get_ast_nodes_h = () => {
  const forwards = get_all_classes().map((name) => `class ${name};`).join('\n');

  return format_code(4, `
    #pragma once

    namespace gliss {

    namespace ast {

    ${forwards}
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

const get_symbols_h = () => {
  const list = Object.keys(ast_nodes.symbol_enum_values).map((key) => {
    return `${key} = ${ast_nodes.symbol_enum_values[key]}`;
  });
  // adding some custom tokens for lexer
  list.unshift(`end = ${list.length}`);
  list.unshift(`varying = ${list.length}`);
  list.unshift(`attribute = ${list.length}`);
  list.unshift(`reserved_keyword = ${list.length}`);
  const enums = list.join(',\n  ');
  return format_code(4, `
    #pragma once

    namespace gliss {

    enum symbol_t {
      ${enums}
    };

    }   // gliss
  `);
}

Object.keys(grammar).forEach((group_name) => {
  const head_src = get_ast_node_header(group_name);
  const head_path = get_node_header_file_path(group_name);
  fs.writeFileSync(head_path, head_src);
});

const all_src = get_ast_nodes_h();
const all_path = get_all_header_file_path();
fs.writeFileSync(all_path, all_src);

const combined_header = get_combined_header_file_path();
const combined_src = get_combined_ast_nodes_h();
fs.writeFileSync(combined_header, combined_src);

const symbols_src = get_symbols_h();
const symbol_path = get_symbol_header_file_path();
fs.writeFileSync(symbol_path, symbols_src);
