const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);
const tokens_text = fs.readFileSync(path.join(__dirname, 'tokens.json')).toString();
const tokens = JSON.parse(tokens_text);

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
    return get_include_statement(dep);
  }).join('\n');
}

const get_forward_declaration = (group_name) => {
  return `class ${get_class_name(group_name)};`;
}

const get_forward_declarations = (group_name) => {
  return get_node_deps(group_name).map((dep) => {
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

const get_constructor = (group_name, pattern) => {
  const class_name = get_class_name(group_name);
  const parameters = get_constructor_params(group_name, pattern);

  return format_code(2, `
    ${class_name}(
      ${parameters}
    ) {}
  `).trim();
}

const get_constructors = (group_name) => {
  const constructors = grammar[group_name].map((pattern) => {
    return get_constructor(group_name, pattern);
  })

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
    return `${space}pattern_item_t<${class_name}>::get()`;
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
  return `const std::vector<std::vector<any_pattern_item_t>> ${class_name}::patterns = {
      ${initializer_lists}
    };`;
}

const get_class_definition = (group_name) => {
  const class_name = get_class_name(group_name);
  const include_statements = get_include_statements(group_name);
  const forward_declarations = get_forward_declarations(group_name);
  const constructors = get_constructors(group_name);
  const pattern_initializer = get_pattern_initializer(group_name);

  return format_code(4, `
    #pragma once

    #include <vector>
    #include "ast-node.h"

    ${include_statements}

    ${forward_declarations}

    namespace gliss {

    class ${class_name}: public ast_node_t {

    public:

      static const std::vector<ast_node_t> nodes;

      static const std::vector<std::vector<any_pattern_item_t>> patterns;

      ${constructors}

    };  // ${class_name}

    ${pattern_initializer}

    }   // gliss
  `);
}

Object.keys(grammar).forEach((group_name) => {
  const src = get_class_definition(group_name);
  const header_path = get_node_header_file_path(group_name);
  fs.writeFileSync(header_path, src);
});
