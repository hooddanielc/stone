#pragma once

namespace gliss {

 /* The base of all kinds of expressions. */
class ast_node_t {

public:

  virtual ~ast_node_t() {}

};  // ast_node_t

class translation_unit_t: public ast_node_t {
};  // translation_unit_t

class external_declaration_t: public ast_node_t {
};  // external_declaration_t

class translation_unit_external_declaration_t: public ast_node_t {
};  // translation_unit_t

class external_declaration_function_definition_t: public ast_node_t {
};  // external_declaration_function_definition_t

class external_declaration_declaration_t: public ast_node_t {
};  // external_declaration_declaration_t

class external_declaration_semicolon_t: public ast_node_t {
};  // external_declaration_semicolon_t

}   // gliss