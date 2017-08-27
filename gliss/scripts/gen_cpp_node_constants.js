const fs = require('fs');
const path = require('path');
const grammar = require('./grammar');
const tokens = require('./tokens');
const ast_nodes = require('./ast_nodes');

const get_group_id = (group_name) => {
  const symbols = ast_nodes.reduced_symbols.filter((sym) => {
    return sym.group_name === group_name;
  });

  return symbols[0] ? symbols[0].group_id : -1;
}

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

  return `ast_token_t`;
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

const get_ast_reducer_header_file_path = () => {
  return path.resolve(__dirname, '..', 'ast-reducer.h');
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
    return `${get_base_class_name(symbol)}`;
  });
}

const get_constructor_params = (pattern) => {
  const types = get_class_prop_types(pattern);
  const names = get_class_prop_names(pattern);
  return types.map((type, idx) => {
    const name = names[idx];
    return `std::shared_ptr<${type}> ${name}_`;
  }).join(',\n        ');
}

const get_factory_func = (group_name, pattern) => {
  const class_name = get_derived_class_name(group_name, pattern);
  const params = pattern.map((symbol, idx) => {
    if (is_non_terminal(symbol)) {
      return `
        std::shared_ptr<${get_base_class_name(symbol)}> ${symbol}_${idx}_
      `.trim();
    } else {
      return `
        std::shared_ptr<ast_token_t> ${symbol}_${idx}_
      `.trim();
    }
  }).join(',\n        ');

  const initializers = pattern.map((symbol, idx) => {
    if (is_non_terminal(symbol)) {
      return `
        ${symbol}_${idx}_
      `.trim();
    } else {
      return `
        ${symbol}_${idx}_
      `.trim();
    }
  }).join(',\n          ');

  return `
      static std::shared_ptr<${class_name}> make(
        ${params}
      ) {
        return std::make_shared<${class_name}>(
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
    return `${name}(${name}_)`;
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
    return `std::shared_ptr<${type}> ${name}`;
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

      virtual int get_id() const override {
        return ${get_group_id(group_name)};
      }

      ${get_factory_func(group_name, pattern)}

    };  // ${class_name}
  `;
}

const get_empty_visitor = (group_name) => {
  if (!grammar[group_name].length) {
    const name = get_base_class_name(group_name);
    return `
      virtual void accept(const visitor_t &) const override {}
      virtual int get_id() const override {return -1;}
    `;
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

      static constexpr int rules = ${grammar[group_name].length};

      static constexpr int id = ${get_group_id(group_name)};

      ${get_empty_visitor(group_name)}
      virtual ~${class_name}() = default;

    };  // ${class_name}
  `.trim();
}

const get_rule_array = (rules) => {
  return `{ ${rules.join(', ')} }`;
}

const get_reduction = (reduction) => {
  return `
    {${reduction.id}, ${get_rule_array(reduction.rule)}}
  `.trim();
}

const get_possible_reductions_from_right = () => {
  const reductions = ast_nodes.symbol_to_reductions;
  return Object.keys(ast_nodes.symbol_to_reductions).map((id) => {
    const defs = reductions[id].map(get_reduction).join(',\n        ');
    return '  ' +  `
      template <>
      struct reductions_from_t<${id}> {
        static const std::map<int, std::vector<int>> reductions;
      };

      const std::map<int, std::vector<int>> reductions_from_t<${id}>::reductions = {
        ${defs}
      };
    `.trim();
  }).join('\n');
}

const get_ast_nodes_by_id = () => {
  return ast_nodes.reduced_symbols.map((ast) => {
    return '  ' + `
      template <>
      struct ast_by_id<${ast.rule_id}> {
        using type_t = ${ast.name}_t;
      };
    `.trim();
  }).join('\n');
}

const get_ast_nodes_by_group_id = () => {
  return Object.keys(grammar).map((group_name) => {
    return `
      template <>
      struct ast_by_group_id<${get_group_id(group_name)}> {
        using type_t = ${get_base_class_name(group_name)};
      };
    `.trim();
  }).join('\n');
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

const get_all_derived_classes = () => {
  const classes = [];
  Object.keys(grammar).forEach((key) => {
    grammar[key].forEach((pattern) => {
      classes.push(get_derived_class_name(key, pattern));
    });
  });
  classes.push('ast_token_t');
  return classes;
}

const get_all_classes = () => {
  const classes = get_all_derived_classes();
  Object.keys(grammar).forEach((key) => {
    classes.push(get_base_class_name(key));
  });
  return classes;
}


const get_visitor_declarations = () => {
  return get_all_derived_classes()
    .map((name) => `virtual void operator()(const ${name} *) const = 0;`)
    .join('\n      ');
}

const get_ast_reduction_factory = (reduction) => {
  const names = [];

  const dyn_casts = reduction.rule.map((group_id, idx) => {
    const symbol = ast_nodes.symbols_by_group[group_id];
    const class_name = `${symbol.group_name}_t`;
    const name = `${symbol.group_name}_${idx}`;
    names.push(name);

    if (symbol.terminal) {
      return `
        auto ${name} = std::static_pointer_cast<ast_token_t>(nodes[${idx}]); // group_id ${group_id}
      `.trim();
    } else {
      return `
        auto ${name} = std::static_pointer_cast<${class_name}>(nodes[${idx}]); // group_id ${group_id}
      `.trim();
    }
  }).join('\n            ');

  const init_list = names.join(', ');

  return `
            ${dyn_casts}
            return ast_by_id<${reduction.id}>::type_t::make(${init_list});
  `;
}

const get_ast_reduction_condition = (reduction) => {
  const target = reduction.id;
  const checks = reduction.rule.reverse().map((id, idx) => {
    return `delegate.check_stack_item(${idx}, ${id})`
  }).join(' && ');
  // reverse back to normal
  reduction.rule.reverse();

  return `
        if (${checks}) {
          delegate.reduce(${reduction.rule.length}, [](std::vector<std::shared_ptr<ast_t>> nodes) {
            ${get_ast_reduction_factory(reduction)}
          });
          break;
        }
  `.trim();
}

const get_ast_predicted_checks = () => {
  const reductions = ast_nodes.symbol_to_reductions;
  return Object.keys(reductions).map((id) => {
    const checks = reductions[id].map(get_ast_reduction_condition).join('\n        ');
    return `
      case ${id}: {
        ${checks}
        // if can't reduce, shift()
        delegate.shift();
        break;
      }
    `;
  }).join('\n');
}

const get_ast_reducer = () => {
  return `
    template <typename delegate_t>
    void try_reduce(delegate_t &delegate) {
      switch(delegate.back()) {
        ${get_ast_predicted_checks()}
        default: {
          delegate.shift();
          break;
        }
      }
    }
  `;
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

    template <int N>
    struct reductions_from_t;

    template <int N>
    struct ast_by_id;

    template <int N>
    struct ast_by_group_id {
      using type_t = ast_token_t;
    };

    ${get_ast_nodes_by_id()}

    ${get_ast_nodes_by_group_id()}

    ${get_possible_reductions_from_right()}

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

const get_ast_reducer_h = () => {
  return format_code(4, `
    #pragma once

    #include "ast-nodes.h"
    #include "ast-nodes/all.h"

    namespace gliss {

    namespace ast {
      ${get_ast_reducer()}
    }   // ast

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

const reducer_src = get_ast_reducer_h();
const reducer_path = get_ast_reducer_header_file_path();
fs.writeFileSync(reducer_path, reducer_src);