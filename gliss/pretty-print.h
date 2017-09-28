#pragma once

#include <ostream>
#include "glsl-lang.h"

namespace gliss {

std::ostream &operator<<(std::ostream &strm, const glsl::ast_t *ast) {
  struct pretty_print_t final: public glsl::default_visitor_t {

    pretty_print_t(std::ostream &strm_)
          : strm(strm_) {}

    void write(std::ostream &strm, const char *name, const glsl::ast_t *node) const {
      std::cout << name << "(" << std::endl;
      for (auto child: node->get_children()) {
        strm << child.get();
      }
      std::cout << ") // " << name << std::endl;
    }

    virtual void operator()(const glsl::__omega___branch_t *node) const override {
      write(strm, "__omega___branch_t", node);
    }
    virtual void operator()(const glsl::__omega___from_translation_unit_t *node) const override {
      write(strm, "__omega___from_translation_unit_t", node);
    }
    virtual void operator()(const glsl::external_declaration_branch_t *node) const override {
      write(strm, "external_declaration_branch_t", node);
    }
    virtual void operator()(const glsl::external_declaration_from_function_definition_t *node) const override {
      write(strm, "external_declaration_from_function_definition_t", node);
    }
    virtual void operator()(const glsl::external_declaration_from_declaration_t *node) const override {
      write(strm, "external_declaration_from_declaration_t", node);
    }
    virtual void operator()(const glsl::external_declaration_from_SEMICOLON_t *node) const override {
      write(strm, "external_declaration_from_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::for_rest_statement_branch_t *node) const override {
      write(strm, "for_rest_statement_branch_t", node);
    }
    virtual void operator()(const glsl::for_rest_statement_from_conditionopt_SEMICOLON_t *node) const override {
      write(strm, "for_rest_statement_from_conditionopt_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::for_rest_statement_from_conditionopt_SEMICOLON_expression_t *node) const override {
      write(strm, "for_rest_statement_from_conditionopt_SEMICOLON_expression_t", node);
    }
    virtual void operator()(const glsl::for_init_statement_branch_t *node) const override {
      write(strm, "for_init_statement_branch_t", node);
    }
    virtual void operator()(const glsl::for_init_statement_from_expression_statement_t *node) const override {
      write(strm, "for_init_statement_from_expression_statement_t", node);
    }
    virtual void operator()(const glsl::for_init_statement_from_declaration_statement_t *node) const override {
      write(strm, "for_init_statement_from_declaration_statement_t", node);
    }
    virtual void operator()(const glsl::nothing_branch_t *node) const override {
      write(strm, "nothing_branch_t", node);
    }
    virtual void operator()(const glsl::nothing_as_epsilon_t *node) const override {
      write(strm, "nothing_as_epsilon_t", node);
    }
    virtual void operator()(const glsl::selection_rest_statement_branch_t *node) const override {
      write(strm, "selection_rest_statement_branch_t", node);
    }
    virtual void operator()(const glsl::selection_rest_statement_from_statement_ELSE_statement_t *node) const override {
      write(strm, "selection_rest_statement_from_statement_ELSE_statement_t", node);
    }
    virtual void operator()(const glsl::selection_rest_statement_from_statement_t *node) const override {
      write(strm, "selection_rest_statement_from_statement_t", node);
    }
    virtual void operator()(const glsl::compound_statement_no_new_scope_branch_t *node) const override {
      write(strm, "compound_statement_no_new_scope_branch_t", node);
    }
    virtual void operator()(const glsl::compound_statement_no_new_scope_from_LEFT_BRACE_RIGHT_BRACE_t *node) const override {
      write(strm, "compound_statement_no_new_scope_from_LEFT_BRACE_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::compound_statement_no_new_scope_from_LEFT_BRACE_statement_list_RIGHT_BRACE_t *node) const override {
      write(strm, "compound_statement_no_new_scope_from_LEFT_BRACE_statement_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::selection_statement_branch_t *node) const override {
      write(strm, "selection_statement_branch_t", node);
    }
    virtual void operator()(const glsl::selection_statement_from_IF_LEFT_PAREN_expression_RIGHT_PAREN_selection_rest_statement_t *node) const override {
      write(strm, "selection_statement_from_IF_LEFT_PAREN_expression_RIGHT_PAREN_selection_rest_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_branch_t *node) const override {
      write(strm, "simple_statement_branch_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_declaration_statement_t *node) const override {
      write(strm, "simple_statement_from_declaration_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_expression_statement_t *node) const override {
      write(strm, "simple_statement_from_expression_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_selection_statement_t *node) const override {
      write(strm, "simple_statement_from_selection_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_switch_statement_t *node) const override {
      write(strm, "simple_statement_from_switch_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_case_label_t *node) const override {
      write(strm, "simple_statement_from_case_label_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_iteration_statement_t *node) const override {
      write(strm, "simple_statement_from_iteration_statement_t", node);
    }
    virtual void operator()(const glsl::simple_statement_from_jump_statement_t *node) const override {
      write(strm, "simple_statement_from_jump_statement_t", node);
    }
    virtual void operator()(const glsl::initializer_list_branch_t *node) const override {
      write(strm, "initializer_list_branch_t", node);
    }
    virtual void operator()(const glsl::initializer_list_from_initializer_t *node) const override {
      write(strm, "initializer_list_from_initializer_t", node);
    }
    virtual void operator()(const glsl::initializer_list_from_initializer_list_COMMA_initializer_t *node) const override {
      write(strm, "initializer_list_from_initializer_list_COMMA_initializer_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_branch_t *node) const override {
      write(strm, "struct_declaration_branch_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_from_type_specifier_struct_declarator_list_SEMICOLON_t *node) const override {
      write(strm, "struct_declaration_from_type_specifier_struct_declarator_list_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_from_type_qualifier_type_specifier_struct_declarator_list_SEMICOLON_t *node) const override {
      write(strm, "struct_declaration_from_type_qualifier_type_specifier_struct_declarator_list_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_list_branch_t *node) const override {
      write(strm, "struct_declarator_list_branch_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_list_from_struct_declarator_t *node) const override {
      write(strm, "struct_declarator_list_from_struct_declarator_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_list_from_struct_declarator_list_COMMA_struct_declarator_t *node) const override {
      write(strm, "struct_declarator_list_from_struct_declarator_list_COMMA_struct_declarator_t", node);
    }
    virtual void operator()(const glsl::struct_specifier_branch_t *node) const override {
      write(strm, "struct_specifier_branch_t", node);
    }
    virtual void operator()(const glsl::struct_specifier_from_STRUCT_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t *node) const override {
      write(strm, "struct_specifier_from_STRUCT_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::struct_specifier_from_STRUCT_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t *node) const override {
      write(strm, "struct_specifier_from_STRUCT_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::statement_branch_t *node) const override {
      write(strm, "statement_branch_t", node);
    }
    virtual void operator()(const glsl::statement_from_compound_statement_t *node) const override {
      write(strm, "statement_from_compound_statement_t", node);
    }
    virtual void operator()(const glsl::statement_from_simple_statement_t *node) const override {
      write(strm, "statement_from_simple_statement_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_branch_t *node) const override {
      write(strm, "type_specifier_nonarray_branch_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_VOID_t *node) const override {
      write(strm, "type_specifier_nonarray_from_VOID_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_FLOAT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_FLOAT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DOUBLE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DOUBLE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_INT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_INT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UINT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UINT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_BOOL_t *node) const override {
      write(strm, "type_specifier_nonarray_from_BOOL_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_VEC2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_VEC2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_VEC3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_VEC3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_VEC4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_VEC4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DVEC2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DVEC2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DVEC3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DVEC3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DVEC4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DVEC4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_BVEC2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_BVEC2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_BVEC3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_BVEC3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_BVEC4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_BVEC4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IVEC2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IVEC2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IVEC3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IVEC3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IVEC4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IVEC4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UVEC2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UVEC2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UVEC3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UVEC3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UVEC4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UVEC4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT2X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT2X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT2X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT2X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT2X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT2X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT3X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT3X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT3X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT3X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT3X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT3X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT4X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT4X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT4X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT4X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_MAT4X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_MAT4X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT2X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT2X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT2X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT2X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT2X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT2X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT3X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT3X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT3X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT3X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT3X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT3X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT4X2_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT4X2_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT4X3_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT4X3_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_DMAT4X4_t *node) const override {
      write(strm, "type_specifier_nonarray_from_DMAT4X4_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ATOMIC_UINT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ATOMIC_UINT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLERCUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLERCUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER1DSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER1DSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLERCUBESHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLERCUBESHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER1DARRAYSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER1DARRAYSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DARRAYSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DARRAYSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLERCUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLERCUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLERCUBEARRAYSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLERCUBEARRAYSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLERCUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLERCUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLERCUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLERCUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLERCUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLERCUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLERCUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLERCUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DRECTSHADOW_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DRECTSHADOW_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLERBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLERBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLERBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLERBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLERBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLERBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_SAMPLER2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_SAMPLER2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_ISAMPLER2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_ISAMPLER2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_USAMPLER2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_USAMPLER2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE1D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE1D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE2D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE2D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE3D_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE3D_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE2DRECT_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE2DRECT_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGECUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGECUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGECUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGECUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGECUBE_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGECUBE_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGEBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGEBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGEBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGEBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGEBUFFER_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGEBUFFER_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE1DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE1DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE2DARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE2DARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGECUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGECUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGECUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGECUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGECUBEARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGECUBEARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE2DMS_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE2DMS_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IMAGE2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IMAGE2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_IIMAGE2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_IIMAGE2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_UIMAGE2DMSARRAY_t *node) const override {
      write(strm, "type_specifier_nonarray_from_UIMAGE2DMSARRAY_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_struct_specifier_t *node) const override {
      write(strm, "type_specifier_nonarray_from_struct_specifier_t", node);
    }
    virtual void operator()(const glsl::type_specifier_nonarray_from_TYPE_NAME_t *node) const override {
      write(strm, "type_specifier_nonarray_from_TYPE_NAME_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_branch_t *node) const override {
      write(strm, "storage_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_CONST_t *node) const override {
      write(strm, "storage_qualifier_from_CONST_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_INOUT_t *node) const override {
      write(strm, "storage_qualifier_from_INOUT_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_IN_t *node) const override {
      write(strm, "storage_qualifier_from_IN_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_OUT_t *node) const override {
      write(strm, "storage_qualifier_from_OUT_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_CENTROID_t *node) const override {
      write(strm, "storage_qualifier_from_CENTROID_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_PATCH_t *node) const override {
      write(strm, "storage_qualifier_from_PATCH_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_SAMPLE_t *node) const override {
      write(strm, "storage_qualifier_from_SAMPLE_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_UNIFORM_t *node) const override {
      write(strm, "storage_qualifier_from_UNIFORM_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_BUFFER_t *node) const override {
      write(strm, "storage_qualifier_from_BUFFER_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_SHARED_t *node) const override {
      write(strm, "storage_qualifier_from_SHARED_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_COHERENT_t *node) const override {
      write(strm, "storage_qualifier_from_COHERENT_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_VOLATILE_t *node) const override {
      write(strm, "storage_qualifier_from_VOLATILE_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_RESTRICT_t *node) const override {
      write(strm, "storage_qualifier_from_RESTRICT_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_READONLY_t *node) const override {
      write(strm, "storage_qualifier_from_READONLY_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_WRITEONLY_t *node) const override {
      write(strm, "storage_qualifier_from_WRITEONLY_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_SUBROUTINE_t *node) const override {
      write(strm, "storage_qualifier_from_SUBROUTINE_t", node);
    }
    virtual void operator()(const glsl::storage_qualifier_from_SUBROUTINE_LEFT_PAREN_type_name_list_RIGHT_PAREN_t *node) const override {
      write(strm, "storage_qualifier_from_SUBROUTINE_LEFT_PAREN_type_name_list_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::statement_list_branch_t *node) const override {
      write(strm, "statement_list_branch_t", node);
    }
    virtual void operator()(const glsl::statement_list_from_statement_t *node) const override {
      write(strm, "statement_list_from_statement_t", node);
    }
    virtual void operator()(const glsl::statement_list_from_statement_list_statement_t *node) const override {
      write(strm, "statement_list_from_statement_list_statement_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_branch_t *node) const override {
      write(strm, "single_type_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_storage_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_storage_qualifier_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_layout_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_layout_qualifier_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_precision_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_precision_qualifier_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_interpolation_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_interpolation_qualifier_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_invariant_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_invariant_qualifier_t", node);
    }
    virtual void operator()(const glsl::single_type_qualifier_from_precise_qualifier_t *node) const override {
      write(strm, "single_type_qualifier_from_precise_qualifier_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_branch_t *node) const override {
      write(strm, "layout_qualifier_id_branch_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_from_IDENTIFIER_t *node) const override {
      write(strm, "layout_qualifier_id_from_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_from_IDENTIFIER_EQUAL_constant_expression_t *node) const override {
      write(strm, "layout_qualifier_id_from_IDENTIFIER_EQUAL_constant_expression_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_from_SHARED_t *node) const override {
      write(strm, "layout_qualifier_id_from_SHARED_t", node);
    }
    virtual void operator()(const glsl::interpolation_qualifier_branch_t *node) const override {
      write(strm, "interpolation_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::interpolation_qualifier_from_SMOOTH_t *node) const override {
      write(strm, "interpolation_qualifier_from_SMOOTH_t", node);
    }
    virtual void operator()(const glsl::interpolation_qualifier_from_FLAT_t *node) const override {
      write(strm, "interpolation_qualifier_from_FLAT_t", node);
    }
    virtual void operator()(const glsl::interpolation_qualifier_from_NOPERSPECTIVE_t *node) const override {
      write(strm, "interpolation_qualifier_from_NOPERSPECTIVE_t", node);
    }
    virtual void operator()(const glsl::initializer_branch_t *node) const override {
      write(strm, "initializer_branch_t", node);
    }
    virtual void operator()(const glsl::initializer_from_assignment_expression_t *node) const override {
      write(strm, "initializer_from_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::initializer_from_LEFT_BRACE_initializer_list_RIGHT_BRACE_t *node) const override {
      write(strm, "initializer_from_LEFT_BRACE_initializer_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::initializer_from_LEFT_BRACE_initializer_list_COMMA_RIGHT_BRACE_t *node) const override {
      write(strm, "initializer_from_LEFT_BRACE_initializer_list_COMMA_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::iteration_statement_branch_t *node) const override {
      write(strm, "iteration_statement_branch_t", node);
    }
    virtual void operator()(const glsl::iteration_statement_from_WHILE_LEFT_PAREN_condition_RIGHT_PAREN_statement_no_new_scope_t *node) const override {
      write(strm, "iteration_statement_from_WHILE_LEFT_PAREN_condition_RIGHT_PAREN_statement_no_new_scope_t", node);
    }
    virtual void operator()(const glsl::iteration_statement_from_DO_statement_WHILE_LEFT_PAREN_expression_RIGHT_PAREN_SEMICOLON_t *node) const override {
      write(strm, "iteration_statement_from_DO_statement_WHILE_LEFT_PAREN_expression_RIGHT_PAREN_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::iteration_statement_from_FOR_LEFT_PAREN_for_init_statement_for_rest_statement_RIGHT_PAREN_statement_no_new_scope_t *node) const override {
      write(strm, "iteration_statement_from_FOR_LEFT_PAREN_for_init_statement_for_rest_statement_RIGHT_PAREN_statement_no_new_scope_t", node);
    }
    virtual void operator()(const glsl::parameter_type_specifier_branch_t *node) const override {
      write(strm, "parameter_type_specifier_branch_t", node);
    }
    virtual void operator()(const glsl::parameter_type_specifier_from_type_specifier_t *node) const override {
      write(strm, "parameter_type_specifier_from_type_specifier_t", node);
    }
    virtual void operator()(const glsl::switch_statement_list_branch_t *node) const override {
      write(strm, "switch_statement_list_branch_t", node);
    }
    virtual void operator()(const glsl::switch_statement_list_from_nothing_t *node) const override {
      write(strm, "switch_statement_list_from_nothing_t", node);
    }
    virtual void operator()(const glsl::switch_statement_list_from_statement_list_t *node) const override {
      write(strm, "switch_statement_list_from_statement_list_t", node);
    }
    virtual void operator()(const glsl::function_header_with_parameters_branch_t *node) const override {
      write(strm, "function_header_with_parameters_branch_t", node);
    }
    virtual void operator()(const glsl::function_header_with_parameters_from_function_header_parameter_declaration_t *node) const override {
      write(strm, "function_header_with_parameters_from_function_header_parameter_declaration_t", node);
    }
    virtual void operator()(const glsl::function_header_with_parameters_from_function_header_with_parameters_COMMA_parameter_declaration_t *node) const override {
      write(strm, "function_header_with_parameters_from_function_header_with_parameters_COMMA_parameter_declaration_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_branch_t *node) const override {
      write(strm, "postfix_expression_branch_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_primary_expression_t *node) const override {
      write(strm, "postfix_expression_from_primary_expression_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_postfix_expression_LEFT_BRACKET_integer_expression_RIGHT_BRACKET_t *node) const override {
      write(strm, "postfix_expression_from_postfix_expression_LEFT_BRACKET_integer_expression_RIGHT_BRACKET_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_function_call_t *node) const override {
      write(strm, "postfix_expression_from_function_call_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_postfix_expression_DOT_FIELD_SELECTION_t *node) const override {
      write(strm, "postfix_expression_from_postfix_expression_DOT_FIELD_SELECTION_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_postfix_expression_INC_OP_t *node) const override {
      write(strm, "postfix_expression_from_postfix_expression_INC_OP_t", node);
    }
    virtual void operator()(const glsl::postfix_expression_from_postfix_expression_DEC_OP_t *node) const override {
      write(strm, "postfix_expression_from_postfix_expression_DEC_OP_t", node);
    }
    virtual void operator()(const glsl::function_declarator_branch_t *node) const override {
      write(strm, "function_declarator_branch_t", node);
    }
    virtual void operator()(const glsl::function_declarator_from_function_header_t *node) const override {
      write(strm, "function_declarator_from_function_header_t", node);
    }
    virtual void operator()(const glsl::function_declarator_from_function_header_with_parameters_t *node) const override {
      write(strm, "function_declarator_from_function_header_with_parameters_t", node);
    }
    virtual void operator()(const glsl::fully_specified_type_branch_t *node) const override {
      write(strm, "fully_specified_type_branch_t", node);
    }
    virtual void operator()(const glsl::fully_specified_type_from_type_specifier_t *node) const override {
      write(strm, "fully_specified_type_from_type_specifier_t", node);
    }
    virtual void operator()(const glsl::fully_specified_type_from_type_qualifier_type_specifier_t *node) const override {
      write(strm, "fully_specified_type_from_type_qualifier_type_specifier_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_branch_t *node) const override {
      write(strm, "struct_declarator_branch_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_from_IDENTIFIER_t *node) const override {
      write(strm, "struct_declarator_from_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::struct_declarator_from_IDENTIFIER_array_specifier_t *node) const override {
      write(strm, "struct_declarator_from_IDENTIFIER_array_specifier_t", node);
    }
    virtual void operator()(const glsl::function_header_branch_t *node) const override {
      write(strm, "function_header_branch_t", node);
    }
    virtual void operator()(const glsl::function_header_from_fully_specified_type_IDENTIFIER_LEFT_PAREN_t *node) const override {
      write(strm, "function_header_from_fully_specified_type_IDENTIFIER_LEFT_PAREN_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_list_branch_t *node) const override {
      write(strm, "struct_declaration_list_branch_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_list_from_struct_declaration_t *node) const override {
      write(strm, "struct_declaration_list_from_struct_declaration_t", node);
    }
    virtual void operator()(const glsl::struct_declaration_list_from_struct_declaration_list_struct_declaration_t *node) const override {
      write(strm, "struct_declaration_list_from_struct_declaration_list_struct_declaration_t", node);
    }
    virtual void operator()(const glsl::identifier_list_branch_t *node) const override {
      write(strm, "identifier_list_branch_t", node);
    }
    virtual void operator()(const glsl::identifier_list_from_COMMA_IDENTIFIER_t *node) const override {
      write(strm, "identifier_list_from_COMMA_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::identifier_list_from_identifier_list_COMMA_IDENTIFIER_t *node) const override {
      write(strm, "identifier_list_from_identifier_list_COMMA_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::function_call_generic_branch_t *node) const override {
      write(strm, "function_call_generic_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_generic_from_function_call_header_with_parameters_RIGHT_PAREN_t *node) const override {
      write(strm, "function_call_generic_from_function_call_header_with_parameters_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::function_call_generic_from_function_call_header_no_parameters_RIGHT_PAREN_t *node) const override {
      write(strm, "function_call_generic_from_function_call_header_no_parameters_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::type_qualifier_branch_t *node) const override {
      write(strm, "type_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::type_qualifier_from_single_type_qualifier_t *node) const override {
      write(strm, "type_qualifier_from_single_type_qualifier_t", node);
    }
    virtual void operator()(const glsl::type_qualifier_from_type_qualifier_single_type_qualifier_t *node) const override {
      write(strm, "type_qualifier_from_type_qualifier_single_type_qualifier_t", node);
    }
    virtual void operator()(const glsl::declaration_statement_branch_t *node) const override {
      write(strm, "declaration_statement_branch_t", node);
    }
    virtual void operator()(const glsl::declaration_statement_from_declaration_t *node) const override {
      write(strm, "declaration_statement_from_declaration_t", node);
    }
    virtual void operator()(const glsl::precision_qualifier_branch_t *node) const override {
      write(strm, "precision_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::precision_qualifier_from_HIGH_PRECISION_t *node) const override {
      write(strm, "precision_qualifier_from_HIGH_PRECISION_t", node);
    }
    virtual void operator()(const glsl::precision_qualifier_from_MEDIUM_PRECISION_t *node) const override {
      write(strm, "precision_qualifier_from_MEDIUM_PRECISION_t", node);
    }
    virtual void operator()(const glsl::precision_qualifier_from_LOW_PRECISION_t *node) const override {
      write(strm, "precision_qualifier_from_LOW_PRECISION_t", node);
    }
    virtual void operator()(const glsl::translation_unit_branch_t *node) const override {
      write(strm, "translation_unit_branch_t", node);
    }
    virtual void operator()(const glsl::translation_unit_from_external_declaration_t *node) const override {
      write(strm, "translation_unit_from_external_declaration_t", node);
    }
    virtual void operator()(const glsl::translation_unit_from_translation_unit_external_declaration_t *node) const override {
      write(strm, "translation_unit_from_translation_unit_external_declaration_t", node);
    }
    virtual void operator()(const glsl::constant_expression_branch_t *node) const override {
      write(strm, "constant_expression_branch_t", node);
    }
    virtual void operator()(const glsl::constant_expression_from_conditional_expression_t *node) const override {
      write(strm, "constant_expression_from_conditional_expression_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_branch_t *node) const override {
      write(strm, "assignment_operator_branch_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_EQUAL_t *node) const override {
      write(strm, "assignment_operator_from_EQUAL_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_MUL_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_MUL_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_DIV_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_DIV_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_MOD_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_MOD_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_ADD_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_ADD_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_SUB_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_SUB_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_LEFT_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_LEFT_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_RIGHT_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_RIGHT_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_AND_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_AND_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_XOR_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_XOR_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::assignment_operator_from_OR_ASSIGN_t *node) const override {
      write(strm, "assignment_operator_from_OR_ASSIGN_t", node);
    }
    virtual void operator()(const glsl::condition_branch_t *node) const override {
      write(strm, "condition_branch_t", node);
    }
    virtual void operator()(const glsl::condition_from_expression_t *node) const override {
      write(strm, "condition_from_expression_t", node);
    }
    virtual void operator()(const glsl::condition_from_fully_specified_type_IDENTIFIER_EQUAL_initializer_t *node) const override {
      write(strm, "condition_from_fully_specified_type_IDENTIFIER_EQUAL_initializer_t", node);
    }
    virtual void operator()(const glsl::case_label_branch_t *node) const override {
      write(strm, "case_label_branch_t", node);
    }
    virtual void operator()(const glsl::case_label_from_CASE_expression_COLON_t *node) const override {
      write(strm, "case_label_from_CASE_expression_COLON_t", node);
    }
    virtual void operator()(const glsl::case_label_from_DEFAULT_COLON_t *node) const override {
      write(strm, "case_label_from_DEFAULT_COLON_t", node);
    }
    virtual void operator()(const glsl::logical_or_expression_branch_t *node) const override {
      write(strm, "logical_or_expression_branch_t", node);
    }
    virtual void operator()(const glsl::logical_or_expression_from_logical_xor_expression_t *node) const override {
      write(strm, "logical_or_expression_from_logical_xor_expression_t", node);
    }
    virtual void operator()(const glsl::logical_or_expression_from_logical_or_expression_OR_OP_logical_xor_expression_t *node) const override {
      write(strm, "logical_or_expression_from_logical_or_expression_OR_OP_logical_xor_expression_t", node);
    }
    virtual void operator()(const glsl::logical_xor_expression_branch_t *node) const override {
      write(strm, "logical_xor_expression_branch_t", node);
    }
    virtual void operator()(const glsl::logical_xor_expression_from_logical_and_expression_t *node) const override {
      write(strm, "logical_xor_expression_from_logical_and_expression_t", node);
    }
    virtual void operator()(const glsl::logical_xor_expression_from_logical_xor_expression_XOR_OP_logical_and_expression_t *node) const override {
      write(strm, "logical_xor_expression_from_logical_xor_expression_XOR_OP_logical_and_expression_t", node);
    }
    virtual void operator()(const glsl::single_declaration_branch_t *node) const override {
      write(strm, "single_declaration_branch_t", node);
    }
    virtual void operator()(const glsl::single_declaration_from_fully_specified_type_t *node) const override {
      write(strm, "single_declaration_from_fully_specified_type_t", node);
    }
    virtual void operator()(const glsl::single_declaration_from_fully_specified_type_IDENTIFIER_t *node) const override {
      write(strm, "single_declaration_from_fully_specified_type_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::single_declaration_from_fully_specified_type_IDENTIFIER_array_specifier_t *node) const override {
      write(strm, "single_declaration_from_fully_specified_type_IDENTIFIER_array_specifier_t", node);
    }
    virtual void operator()(const glsl::single_declaration_from_fully_specified_type_IDENTIFIER_array_specifier_EQUAL_initializer_t *node) const override {
      write(strm, "single_declaration_from_fully_specified_type_IDENTIFIER_array_specifier_EQUAL_initializer_t", node);
    }
    virtual void operator()(const glsl::single_declaration_from_fully_specified_type_IDENTIFIER_EQUAL_initializer_t *node) const override {
      write(strm, "single_declaration_from_fully_specified_type_IDENTIFIER_EQUAL_initializer_t", node);
    }
    virtual void operator()(const glsl::assignment_expression_branch_t *node) const override {
      write(strm, "assignment_expression_branch_t", node);
    }
    virtual void operator()(const glsl::assignment_expression_from_conditional_expression_t *node) const override {
      write(strm, "assignment_expression_from_conditional_expression_t", node);
    }
    virtual void operator()(const glsl::assignment_expression_from_unary_expression_assignment_operator_assignment_expression_t *node) const override {
      write(strm, "assignment_expression_from_unary_expression_assignment_operator_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::parameter_declaration_branch_t *node) const override {
      write(strm, "parameter_declaration_branch_t", node);
    }
    virtual void operator()(const glsl::parameter_declaration_from_type_qualifier_parameter_declarator_t *node) const override {
      write(strm, "parameter_declaration_from_type_qualifier_parameter_declarator_t", node);
    }
    virtual void operator()(const glsl::parameter_declaration_from_parameter_declarator_t *node) const override {
      write(strm, "parameter_declaration_from_parameter_declarator_t", node);
    }
    virtual void operator()(const glsl::parameter_declaration_from_type_qualifier_parameter_type_specifier_t *node) const override {
      write(strm, "parameter_declaration_from_type_qualifier_parameter_type_specifier_t", node);
    }
    virtual void operator()(const glsl::parameter_declaration_from_parameter_type_specifier_t *node) const override {
      write(strm, "parameter_declaration_from_parameter_type_specifier_t", node);
    }
    virtual void operator()(const glsl::relational_expression_branch_t *node) const override {
      write(strm, "relational_expression_branch_t", node);
    }
    virtual void operator()(const glsl::relational_expression_from_shift_expression_t *node) const override {
      write(strm, "relational_expression_from_shift_expression_t", node);
    }
    virtual void operator()(const glsl::relational_expression_from_relational_expression_LEFT_ANGLE_shift_expression_t *node) const override {
      write(strm, "relational_expression_from_relational_expression_LEFT_ANGLE_shift_expression_t", node);
    }
    virtual void operator()(const glsl::relational_expression_from_relational_expression_RIGHT_ANGLE_shift_expression_t *node) const override {
      write(strm, "relational_expression_from_relational_expression_RIGHT_ANGLE_shift_expression_t", node);
    }
    virtual void operator()(const glsl::relational_expression_from_relational_expression_LE_OP_shift_expression_t *node) const override {
      write(strm, "relational_expression_from_relational_expression_LE_OP_shift_expression_t", node);
    }
    virtual void operator()(const glsl::relational_expression_from_relational_expression_GE_OP_shift_expression_t *node) const override {
      write(strm, "relational_expression_from_relational_expression_GE_OP_shift_expression_t", node);
    }
    virtual void operator()(const glsl::inclusive_or_expression_branch_t *node) const override {
      write(strm, "inclusive_or_expression_branch_t", node);
    }
    virtual void operator()(const glsl::inclusive_or_expression_from_exclusive_or_expression_t *node) const override {
      write(strm, "inclusive_or_expression_from_exclusive_or_expression_t", node);
    }
    virtual void operator()(const glsl::inclusive_or_expression_from_inclusive_or_expression_VERTICAL_BAR_exclusive_or_expression_t *node) const override {
      write(strm, "inclusive_or_expression_from_inclusive_or_expression_VERTICAL_BAR_exclusive_or_expression_t", node);
    }
    virtual void operator()(const glsl::jump_statement_branch_t *node) const override {
      write(strm, "jump_statement_branch_t", node);
    }
    virtual void operator()(const glsl::jump_statement_from_CONTINUE_SEMICOLON_t *node) const override {
      write(strm, "jump_statement_from_CONTINUE_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::jump_statement_from_BREAK_SEMICOLON_t *node) const override {
      write(strm, "jump_statement_from_BREAK_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::jump_statement_from_RETURN_SEMICOLON_t *node) const override {
      write(strm, "jump_statement_from_RETURN_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::jump_statement_from_RETURN_expression_SEMICOLON_t *node) const override {
      write(strm, "jump_statement_from_RETURN_expression_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::jump_statement_from_DISCARD_SEMICOLON_t *node) const override {
      write(strm, "jump_statement_from_DISCARD_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::exclusive_or_expression_branch_t *node) const override {
      write(strm, "exclusive_or_expression_branch_t", node);
    }
    virtual void operator()(const glsl::exclusive_or_expression_from_and_expression_t *node) const override {
      write(strm, "exclusive_or_expression_from_and_expression_t", node);
    }
    virtual void operator()(const glsl::exclusive_or_expression_from_exclusive_or_expression_CARET_and_expression_t *node) const override {
      write(strm, "exclusive_or_expression_from_exclusive_or_expression_CARET_and_expression_t", node);
    }
    virtual void operator()(const glsl::equality_expression_branch_t *node) const override {
      write(strm, "equality_expression_branch_t", node);
    }
    virtual void operator()(const glsl::equality_expression_from_relational_expression_t *node) const override {
      write(strm, "equality_expression_from_relational_expression_t", node);
    }
    virtual void operator()(const glsl::equality_expression_from_equality_expression_EQ_OP_relational_expression_t *node) const override {
      write(strm, "equality_expression_from_equality_expression_EQ_OP_relational_expression_t", node);
    }
    virtual void operator()(const glsl::equality_expression_from_equality_expression_NE_OP_relational_expression_t *node) const override {
      write(strm, "equality_expression_from_equality_expression_NE_OP_relational_expression_t", node);
    }
    virtual void operator()(const glsl::precise_qualifier_branch_t *node) const override {
      write(strm, "precise_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::precise_qualifier_from_PRECISE_t *node) const override {
      write(strm, "precise_qualifier_from_PRECISE_t", node);
    }
    virtual void operator()(const glsl::declaration_branch_t *node) const override {
      write(strm, "declaration_branch_t", node);
    }
    virtual void operator()(const glsl::declaration_from_function_prototype_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_function_prototype_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_init_declarator_list_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_init_declarator_list_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_PRECISION_precision_qualifier_type_specifier_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_PRECISION_precision_qualifier_type_specifier_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_IDENTIFIER_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_IDENTIFIER_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_IDENTIFIER_array_specifier_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_IDENTIFIER_array_specifier_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_IDENTIFIER_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_IDENTIFIER_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::declaration_from_type_qualifier_IDENTIFIER_identifier_list_SEMICOLON_t *node) const override {
      write(strm, "declaration_from_type_qualifier_IDENTIFIER_identifier_list_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::type_specifier_branch_t *node) const override {
      write(strm, "type_specifier_branch_t", node);
    }
    virtual void operator()(const glsl::type_specifier_from_type_specifier_nonarray_t *node) const override {
      write(strm, "type_specifier_from_type_specifier_nonarray_t", node);
    }
    virtual void operator()(const glsl::type_specifier_from_type_specifier_nonarray_array_specifier_t *node) const override {
      write(strm, "type_specifier_from_type_specifier_nonarray_array_specifier_t", node);
    }
    virtual void operator()(const glsl::statement_no_new_scope_branch_t *node) const override {
      write(strm, "statement_no_new_scope_branch_t", node);
    }
    virtual void operator()(const glsl::statement_no_new_scope_from_compound_statement_no_new_scope_t *node) const override {
      write(strm, "statement_no_new_scope_from_compound_statement_no_new_scope_t", node);
    }
    virtual void operator()(const glsl::statement_no_new_scope_from_simple_statement_t *node) const override {
      write(strm, "statement_no_new_scope_from_simple_statement_t", node);
    }
    virtual void operator()(const glsl::and_expression_branch_t *node) const override {
      write(strm, "and_expression_branch_t", node);
    }
    virtual void operator()(const glsl::and_expression_from_equality_expression_t *node) const override {
      write(strm, "and_expression_from_equality_expression_t", node);
    }
    virtual void operator()(const glsl::and_expression_from_and_expression_AMPERSAND_equality_expression_t *node) const override {
      write(strm, "and_expression_from_and_expression_AMPERSAND_equality_expression_t", node);
    }
    virtual void operator()(const glsl::expression_statement_branch_t *node) const override {
      write(strm, "expression_statement_branch_t", node);
    }
    virtual void operator()(const glsl::expression_statement_from_SEMICOLON_t *node) const override {
      write(strm, "expression_statement_from_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::expression_statement_from_expression_SEMICOLON_t *node) const override {
      write(strm, "expression_statement_from_expression_SEMICOLON_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_branch_t *node) const override {
      write(strm, "init_declarator_list_branch_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_from_single_declaration_t *node) const override {
      write(strm, "init_declarator_list_from_single_declaration_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_t *node) const override {
      write(strm, "init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_t *node) const override {
      write(strm, "init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_EQUAL_initializer_t *node) const override {
      write(strm, "init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_EQUAL_initializer_t", node);
    }
    virtual void operator()(const glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_EQUAL_initializer_t *node) const override {
      write(strm, "init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_EQUAL_initializer_t", node);
    }
    virtual void operator()(const glsl::shift_expression_branch_t *node) const override {
      write(strm, "shift_expression_branch_t", node);
    }
    virtual void operator()(const glsl::shift_expression_from_additive_expression_t *node) const override {
      write(strm, "shift_expression_from_additive_expression_t", node);
    }
    virtual void operator()(const glsl::shift_expression_from_shift_expression_LEFT_OP_additive_expression_t *node) const override {
      write(strm, "shift_expression_from_shift_expression_LEFT_OP_additive_expression_t", node);
    }
    virtual void operator()(const glsl::shift_expression_from_shift_expression_RIGHT_OP_additive_expression_t *node) const override {
      write(strm, "shift_expression_from_shift_expression_RIGHT_OP_additive_expression_t", node);
    }
    virtual void operator()(const glsl::unary_expression_branch_t *node) const override {
      write(strm, "unary_expression_branch_t", node);
    }
    virtual void operator()(const glsl::unary_expression_from_postfix_expression_t *node) const override {
      write(strm, "unary_expression_from_postfix_expression_t", node);
    }
    virtual void operator()(const glsl::unary_expression_from_INC_OP_unary_expression_t *node) const override {
      write(strm, "unary_expression_from_INC_OP_unary_expression_t", node);
    }
    virtual void operator()(const glsl::unary_expression_from_DEC_OP_unary_expression_t *node) const override {
      write(strm, "unary_expression_from_DEC_OP_unary_expression_t", node);
    }
    virtual void operator()(const glsl::unary_expression_from_unary_operator_unary_expression_t *node) const override {
      write(strm, "unary_expression_from_unary_operator_unary_expression_t", node);
    }
    virtual void operator()(const glsl::additive_expression_branch_t *node) const override {
      write(strm, "additive_expression_branch_t", node);
    }
    virtual void operator()(const glsl::additive_expression_from_multiplicative_expression_t *node) const override {
      write(strm, "additive_expression_from_multiplicative_expression_t", node);
    }
    virtual void operator()(const glsl::additive_expression_from_additive_expression_PLUS_multiplicative_expression_t *node) const override {
      write(strm, "additive_expression_from_additive_expression_PLUS_multiplicative_expression_t", node);
    }
    virtual void operator()(const glsl::additive_expression_from_additive_expression_DASH_multiplicative_expression_t *node) const override {
      write(strm, "additive_expression_from_additive_expression_DASH_multiplicative_expression_t", node);
    }
    virtual void operator()(const glsl::logical_and_expression_branch_t *node) const override {
      write(strm, "logical_and_expression_branch_t", node);
    }
    virtual void operator()(const glsl::logical_and_expression_from_inclusive_or_expression_t *node) const override {
      write(strm, "logical_and_expression_from_inclusive_or_expression_t", node);
    }
    virtual void operator()(const glsl::logical_and_expression_from_logical_and_expression_AND_OP_inclusive_or_expression_t *node) const override {
      write(strm, "logical_and_expression_from_logical_and_expression_AND_OP_inclusive_or_expression_t", node);
    }
    virtual void operator()(const glsl::function_definition_branch_t *node) const override {
      write(strm, "function_definition_branch_t", node);
    }
    virtual void operator()(const glsl::function_definition_from_function_prototype_compound_statement_no_new_scope_t *node) const override {
      write(strm, "function_definition_from_function_prototype_compound_statement_no_new_scope_t", node);
    }
    virtual void operator()(const glsl::type_name_list_branch_t *node) const override {
      write(strm, "type_name_list_branch_t", node);
    }
    virtual void operator()(const glsl::type_name_list_from_TYPE_NAME_t *node) const override {
      write(strm, "type_name_list_from_TYPE_NAME_t", node);
    }
    virtual void operator()(const glsl::type_name_list_from_type_name_list_COMMA_TYPE_NAME_t *node) const override {
      write(strm, "type_name_list_from_type_name_list_COMMA_TYPE_NAME_t", node);
    }
    virtual void operator()(const glsl::multiplicative_expression_branch_t *node) const override {
      write(strm, "multiplicative_expression_branch_t", node);
    }
    virtual void operator()(const glsl::multiplicative_expression_from_unary_expression_t *node) const override {
      write(strm, "multiplicative_expression_from_unary_expression_t", node);
    }
    virtual void operator()(const glsl::multiplicative_expression_from_multiplicative_expression_STAR_unary_expression_t *node) const override {
      write(strm, "multiplicative_expression_from_multiplicative_expression_STAR_unary_expression_t", node);
    }
    virtual void operator()(const glsl::multiplicative_expression_from_multiplicative_expression_SLASH_unary_expression_t *node) const override {
      write(strm, "multiplicative_expression_from_multiplicative_expression_SLASH_unary_expression_t", node);
    }
    virtual void operator()(const glsl::multiplicative_expression_from_multiplicative_expression_PERCENT_unary_expression_t *node) const override {
      write(strm, "multiplicative_expression_from_multiplicative_expression_PERCENT_unary_expression_t", node);
    }
    virtual void operator()(const glsl::unary_operator_branch_t *node) const override {
      write(strm, "unary_operator_branch_t", node);
    }
    virtual void operator()(const glsl::unary_operator_from_PLUS_t *node) const override {
      write(strm, "unary_operator_from_PLUS_t", node);
    }
    virtual void operator()(const glsl::unary_operator_from_DASH_t *node) const override {
      write(strm, "unary_operator_from_DASH_t", node);
    }
    virtual void operator()(const glsl::unary_operator_from_BANG_t *node) const override {
      write(strm, "unary_operator_from_BANG_t", node);
    }
    virtual void operator()(const glsl::unary_operator_from_TILDE_t *node) const override {
      write(strm, "unary_operator_from_TILDE_t", node);
    }
    virtual void operator()(const glsl::function_call_header_branch_t *node) const override {
      write(strm, "function_call_header_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_header_from_function_identifier_LEFT_PAREN_t *node) const override {
      write(strm, "function_call_header_from_function_identifier_LEFT_PAREN_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_list_branch_t *node) const override {
      write(strm, "layout_qualifier_id_list_branch_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_list_from_layout_qualifier_id_t *node) const override {
      write(strm, "layout_qualifier_id_list_from_layout_qualifier_id_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_id_list_from_layout_qualifier_id_list_COMMA_layout_qualifier_id_t *node) const override {
      write(strm, "layout_qualifier_id_list_from_layout_qualifier_id_list_COMMA_layout_qualifier_id_t", node);
    }
    virtual void operator()(const glsl::function_identifier_branch_t *node) const override {
      write(strm, "function_identifier_branch_t", node);
    }
    virtual void operator()(const glsl::function_identifier_from_type_specifier_t *node) const override {
      write(strm, "function_identifier_from_type_specifier_t", node);
    }
    virtual void operator()(const glsl::function_identifier_from_postfix_expression_t *node) const override {
      write(strm, "function_identifier_from_postfix_expression_t", node);
    }
    virtual void operator()(const glsl::function_prototype_branch_t *node) const override {
      write(strm, "function_prototype_branch_t", node);
    }
    virtual void operator()(const glsl::function_prototype_from_function_declarator_RIGHT_PAREN_t *node) const override {
      write(strm, "function_prototype_from_function_declarator_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::function_call_header_no_parameters_branch_t *node) const override {
      write(strm, "function_call_header_no_parameters_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_header_no_parameters_from_function_call_header_VOID_t *node) const override {
      write(strm, "function_call_header_no_parameters_from_function_call_header_VOID_t", node);
    }
    virtual void operator()(const glsl::function_call_header_no_parameters_from_function_call_header_t *node) const override {
      write(strm, "function_call_header_no_parameters_from_function_call_header_t", node);
    }
    virtual void operator()(const glsl::invariant_qualifier_branch_t *node) const override {
      write(strm, "invariant_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::invariant_qualifier_from_INVARIANT_t *node) const override {
      write(strm, "invariant_qualifier_from_INVARIANT_t", node);
    }
    virtual void operator()(const glsl::function_call_header_with_parameters_branch_t *node) const override {
      write(strm, "function_call_header_with_parameters_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_header_with_parameters_from_function_call_header_assignment_expression_t *node) const override {
      write(strm, "function_call_header_with_parameters_from_function_call_header_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::function_call_header_with_parameters_from_function_call_header_with_parameters_COMMA_assignment_expression_t *node) const override {
      write(strm, "function_call_header_with_parameters_from_function_call_header_with_parameters_COMMA_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::switch_statement_branch_t *node) const override {
      write(strm, "switch_statement_branch_t", node);
    }
    virtual void operator()(const glsl::switch_statement_from_SWITCH_LEFT_PAREN_expression_RIGHT_PAREN_LEFT_BRACE_switch_statement_list_RIGHT_BRACE_t *node) const override {
      write(strm, "switch_statement_from_SWITCH_LEFT_PAREN_expression_RIGHT_PAREN_LEFT_BRACE_switch_statement_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::parameter_declarator_branch_t *node) const override {
      write(strm, "parameter_declarator_branch_t", node);
    }
    virtual void operator()(const glsl::parameter_declarator_from_type_specifier_IDENTIFIER_t *node) const override {
      write(strm, "parameter_declarator_from_type_specifier_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::parameter_declarator_from_type_specifier_IDENTIFIER_array_specifier_t *node) const override {
      write(strm, "parameter_declarator_from_type_specifier_IDENTIFIER_array_specifier_t", node);
    }
    virtual void operator()(const glsl::array_specifier_branch_t *node) const override {
      write(strm, "array_specifier_branch_t", node);
    }
    virtual void operator()(const glsl::array_specifier_from_LEFT_BRACKET_RIGHT_BRACKET_t *node) const override {
      write(strm, "array_specifier_from_LEFT_BRACKET_RIGHT_BRACKET_t", node);
    }
    virtual void operator()(const glsl::array_specifier_from_LEFT_BRACKET_conditional_expression_RIGHT_BRACKET_t *node) const override {
      write(strm, "array_specifier_from_LEFT_BRACKET_conditional_expression_RIGHT_BRACKET_t", node);
    }
    virtual void operator()(const glsl::array_specifier_from_array_specifier_LEFT_BRACKET_RIGHT_BRACKET_t *node) const override {
      write(strm, "array_specifier_from_array_specifier_LEFT_BRACKET_RIGHT_BRACKET_t", node);
    }
    virtual void operator()(const glsl::array_specifier_from_array_specifier_LEFT_BRACKET_conditional_expression_RIGHT_BRACKET_t *node) const override {
      write(strm, "array_specifier_from_array_specifier_LEFT_BRACKET_conditional_expression_RIGHT_BRACKET_t", node);
    }
    virtual void operator()(const glsl::primary_expression_branch_t *node) const override {
      write(strm, "primary_expression_branch_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_variable_identifier_t *node) const override {
      write(strm, "primary_expression_from_variable_identifier_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_INTCONSTANT_t *node) const override {
      write(strm, "primary_expression_from_INTCONSTANT_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_UINTCONSTANT_t *node) const override {
      write(strm, "primary_expression_from_UINTCONSTANT_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_FLOATCONSTANT_t *node) const override {
      write(strm, "primary_expression_from_FLOATCONSTANT_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_BOOLCONSTANT_t *node) const override {
      write(strm, "primary_expression_from_BOOLCONSTANT_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_DOUBLECONSTANT_t *node) const override {
      write(strm, "primary_expression_from_DOUBLECONSTANT_t", node);
    }
    virtual void operator()(const glsl::primary_expression_from_LEFT_PAREN_expression_RIGHT_PAREN_t *node) const override {
      write(strm, "primary_expression_from_LEFT_PAREN_expression_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::function_call_branch_t *node) const override {
      write(strm, "function_call_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_from_function_call_or_method_t *node) const override {
      write(strm, "function_call_from_function_call_or_method_t", node);
    }
    virtual void operator()(const glsl::conditional_expression_branch_t *node) const override {
      write(strm, "conditional_expression_branch_t", node);
    }
    virtual void operator()(const glsl::conditional_expression_from_logical_or_expression_t *node) const override {
      write(strm, "conditional_expression_from_logical_or_expression_t", node);
    }
    virtual void operator()(const glsl::conditional_expression_from_logical_or_expression_QUESTION_expression_COLON_assignment_expression_t *node) const override {
      write(strm, "conditional_expression_from_logical_or_expression_QUESTION_expression_COLON_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::variable_identifier_branch_t *node) const override {
      write(strm, "variable_identifier_branch_t", node);
    }
    virtual void operator()(const glsl::variable_identifier_from_IDENTIFIER_t *node) const override {
      write(strm, "variable_identifier_from_IDENTIFIER_t", node);
    }
    virtual void operator()(const glsl::conditionopt_branch_t *node) const override {
      write(strm, "conditionopt_branch_t", node);
    }
    virtual void operator()(const glsl::conditionopt_from_condition_t *node) const override {
      write(strm, "conditionopt_from_condition_t", node);
    }
    virtual void operator()(const glsl::conditionopt_from_nothing_t *node) const override {
      write(strm, "conditionopt_from_nothing_t", node);
    }
    virtual void operator()(const glsl::integer_expression_branch_t *node) const override {
      write(strm, "integer_expression_branch_t", node);
    }
    virtual void operator()(const glsl::integer_expression_from_expression_t *node) const override {
      write(strm, "integer_expression_from_expression_t", node);
    }
    virtual void operator()(const glsl::expression_branch_t *node) const override {
      write(strm, "expression_branch_t", node);
    }
    virtual void operator()(const glsl::expression_from_assignment_expression_t *node) const override {
      write(strm, "expression_from_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::expression_from_expression_COMMA_assignment_expression_t *node) const override {
      write(strm, "expression_from_expression_COMMA_assignment_expression_t", node);
    }
    virtual void operator()(const glsl::compound_statement_branch_t *node) const override {
      write(strm, "compound_statement_branch_t", node);
    }
    virtual void operator()(const glsl::compound_statement_from_LEFT_BRACE_RIGHT_BRACE_t *node) const override {
      write(strm, "compound_statement_from_LEFT_BRACE_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::compound_statement_from_LEFT_BRACE_statement_list_RIGHT_BRACE_t *node) const override {
      write(strm, "compound_statement_from_LEFT_BRACE_statement_list_RIGHT_BRACE_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_branch_t *node) const override {
      write(strm, "layout_qualifier_branch_t", node);
    }
    virtual void operator()(const glsl::layout_qualifier_from_LAYOUT_LEFT_PAREN_layout_qualifier_id_list_RIGHT_PAREN_t *node) const override {
      write(strm, "layout_qualifier_from_LAYOUT_LEFT_PAREN_layout_qualifier_id_list_RIGHT_PAREN_t", node);
    }
    virtual void operator()(const glsl::function_call_or_method_branch_t *node) const override {
      write(strm, "function_call_or_method_branch_t", node);
    }
    virtual void operator()(const glsl::function_call_or_method_from_function_call_generic_t *node) const override {
      write(strm, "function_call_or_method_from_function_call_generic_t", node);
    }
    virtual void operator()(const glsl::ast_token_t *node) const override {
      strm << "ast_token_t(" << node->get_token() << ")" << std::endl;
    }

  private:

    std::ostream &strm;

  };  // pretty_print_t

  ast->accept(pretty_print_t { strm });
  return strm;
}   // std::ostream &operator<<

}   // gliss
