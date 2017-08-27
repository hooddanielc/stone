#pragma once
#include <ostream>
#include "ast-nodes.h"
#include "ast-nodes/all.h"

namespace gliss {

namespace ast {

std::ostream &operator<<(std::ostream &strm, const ast_t *ast) {
  class pretty_printer_t final: public default_visitor_t {
  public:

    pretty_printer_t(std::ostream &strm_)
        : strm(strm_) {}

    virtual void operator()(const ast_token_t *tok) const override {
      strm << "ast_token_t(" << tok->token << ")";
    }

    virtual void operator()(const variable_identifier_identifier_t *tok) const override {
      strm << "variable_identifier_identifier_t(" << tok->identifier_0 << ")";
    }

    virtual void operator()(const primary_expression_variable_identifier_t *tok) const override {
      strm << "primary_expression_variable_identifier_t(" << tok->variable_identifier_0 << ")";
    }

    virtual void operator()(const primary_expression_intconstant_t *) const override {
      strm << "primary_expression_intconstant_t unknown";
    }

    virtual void operator()(const primary_expression_uintconstant_t *) const override {
      strm << "primary_expression_uintconstant_t unknown";
    }

    virtual void operator()(const primary_expression_floatconstant_t *) const override {
      strm << "primary_expression_floatconstant_t unknown";
    }

    virtual void operator()(const primary_expression_boolconstant_t *) const override {
      strm << "primary_expression_boolconstant_t unknown";
    }

    virtual void operator()(const primary_expression_doubleconstant_t *) const override {
      strm << "primary_expression_doubleconstant_t unknown";
    }

    virtual void operator()(const primary_expression_left_paren_expression_right_paren_t *) const override {
      strm << "primary_expression_left_paren_expression_right_paren_t unknown";
    }

    virtual void operator()(const postfix_expression_primary_expression_t *tok) const override {
      strm << "postfix_expression_primary_expression_t(" << tok->primary_expression_0 << ")";
    }

    virtual void operator()(const postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t *) const override {
      strm << "postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t unknown";
    }

    virtual void operator()(const postfix_expression_function_call_t *) const override {
      strm << "postfix_expression_function_call_t unknown";
    }

    virtual void operator()(const postfix_expression_postfix_expression_dot_field_selection_t *) const override {
      strm << "postfix_expression_postfix_expression_dot_field_selection_t unknown";
    }

    virtual void operator()(const postfix_expression_postfix_expression_inc_op_t *) const override {
      strm << "postfix_expression_postfix_expression_inc_op_t unknown";
    }

    virtual void operator()(const postfix_expression_postfix_expression_dec_op_t *) const override {
      strm << "postfix_expression_postfix_expression_dec_op_t unknown";
    }

    virtual void operator()(const integer_expression_expression_t *) const override {
      strm << "integer_expression_expression_t unknown";
    }

    virtual void operator()(const function_call_function_call_or_method_t *) const override {
      strm << "function_call_function_call_or_method_t unknown";
    }

    virtual void operator()(const function_call_or_method_function_call_generic_t *) const override {
      strm << "function_call_or_method_function_call_generic_t unknown";
    }

    virtual void operator()(const function_call_generic_function_call_header_with_parameters_right_paren_t *) const override {
      strm << "function_call_generic_function_call_header_with_parameters_right_paren_t unknown";
    }

    virtual void operator()(const function_call_generic_function_call_header_no_parameters_right_paren_t *) const override {
      strm << "function_call_generic_function_call_header_no_parameters_right_paren_t unknown";
    }

    virtual void operator()(const function_call_header_no_parameters_function_call_header_void_t *) const override {
      strm << "function_call_header_no_parameters_function_call_header_void_t unknown";
    }

    virtual void operator()(const function_call_header_no_parameters_function_call_header_t *) const override {
      strm << "function_call_header_no_parameters_function_call_header_t unknown";
    }

    virtual void operator()(const function_call_header_with_parameters_function_call_header_assignment_expression_t *) const override {
      strm << "function_call_header_with_parameters_function_call_header_assignment_expression_t unknown";
    }

    virtual void operator()(const function_call_header_with_parameters_function_call_header_with_parameters_comma_assignment_expression_t *) const override {
      strm << "function_call_header_with_parameters_function_call_header_with_parameters_comma_assignment_expression_t unknown";
    }

    virtual void operator()(const function_call_header_function_identifier_left_paren_t *) const override {
      strm << "function_call_header_function_identifier_left_paren_t unknown";
    }

    virtual void operator()(const function_identifier_type_specifier_t *) const override {
      strm << "function_identifier_type_specifier_t unknown";
    }

    virtual void operator()(const function_identifier_postfix_expression_t *tok) const override {
      strm << "function_identifier_postfix_expression_t("<< tok->postfix_expression_0 << ")";
    }

    virtual void operator()(const unary_expression_postfix_expression_t *) const override {
      strm << "unary_expression_postfix_expression_t unknown";
    }

    virtual void operator()(const unary_expression_inc_op_unary_expression_t *) const override {
      strm << "unary_expression_inc_op_unary_expression_t unknown";
    }

    virtual void operator()(const unary_expression_dec_op_unary_expression_t *) const override {
      strm << "unary_expression_dec_op_unary_expression_t unknown";
    }

    virtual void operator()(const unary_expression_unary_operator_unary_expression_t *) const override {
      strm << "unary_expression_unary_operator_unary_expression_t unknown";
    }

    virtual void operator()(const unary_operator_plus_t *) const override {
      strm << "unary_operator(+)";
    }

    virtual void operator()(const unary_operator_dash_t *) const override {
      strm << "unary_operator(-)";
    }

    virtual void operator()(const unary_operator_bang_t *) const override {
      strm << "unary_operator(!)";
    }

    virtual void operator()(const unary_operator_tilde_t *) const override {
      strm << "unary_operator(~)";
    }

    virtual void operator()(const multiplicative_expression_unary_expression_t *) const override {
      strm << "multiplicative_expression_unary_expression_t unknown";
    }

    virtual void operator()(const multiplicative_expression_multiplicative_expression_star_unary_expression_t *) const override {
      strm << "multiplicative_expression_multiplicative_expression_star_unary_expression_t unknown";
    }

    virtual void operator()(const multiplicative_expression_multiplicative_expression_slash_unary_expression_t *) const override {
      strm << "multiplicative_expression_multiplicative_expression_slash_unary_expression_t unknown";
    }

    virtual void operator()(const multiplicative_expression_multiplicative_expression_percent_unary_expression_t *) const override {
      strm << "multiplicative_expression_multiplicative_expression_percent_unary_expression_t unknown";
    }

    virtual void operator()(const additive_expression_multiplicative_expression_t *) const override {
      strm << "additive_expression_multiplicative_expression_t unknown";
    }

    virtual void operator()(const additive_expression_additive_expression_plus_multiplicative_expression_t *) const override {
      strm << "additive_expression_additive_expression_plus_multiplicative_expression_t unknown";
    }

    virtual void operator()(const additive_expression_additive_expression_dash_multiplicative_expression_t *) const override {
      strm << "additive_expression_additive_expression_dash_multiplicative_expression_t unknown";
    }

    virtual void operator()(const shift_expression_additive_expression_t *) const override {
      strm << "shift_expression_additive_expression_t unknown";
    }

    virtual void operator()(const shift_expression_shift_expression_left_op_additive_expression_t *) const override {
      strm << "shift_expression_shift_expression_left_op_additive_expression_t unknown";
    }

    virtual void operator()(const shift_expression_shift_expression_right_op_additive_expression_t *) const override {
      strm << "shift_expression_shift_expression_right_op_additive_expression_t unknown";
    }

    virtual void operator()(const relational_expression_shift_expression_t *) const override {
      strm << "relational_expression_shift_expression_t unknown";
    }

    virtual void operator()(const relational_expression_relational_expression_left_angle_shift_expression_t *) const override {
      strm << "relational_expression_relational_expression_left_angle_shift_expression_t unknown";
    }

    virtual void operator()(const relational_expression_relational_expression_right_angle_shift_expression_t *) const override {
      strm << "relational_expression_relational_expression_right_angle_shift_expression_t unknown";
    }

    virtual void operator()(const relational_expression_relational_expression_le_op_shift_expression_t *) const override {
      strm << "relational_expression_relational_expression_le_op_shift_expression_t unknown";
    }

    virtual void operator()(const relational_expression_relational_expression_ge_op_shift_expression_t *) const override {
      strm << "relational_expression_relational_expression_ge_op_shift_expression_t unknown";
    }

    virtual void operator()(const equality_expression_relational_expression_t *) const override {
      strm << "equality_expression_relational_expression_t unknown";
    }

    virtual void operator()(const equality_expression_equality_expression_eq_op_relational_expression_t *) const override {
      strm << "equality_expression_equality_expression_eq_op_relational_expression_t unknown";
    }

    virtual void operator()(const equality_expression_equality_expression_ne_op_relational_expression_t *) const override {
      strm << "equality_expression_equality_expression_ne_op_relational_expression_t unknown";
    }

    virtual void operator()(const and_expression_equality_expression_t *) const override {
      strm << "and_expression_equality_expression_t unknown";
    }

    virtual void operator()(const and_expression_and_expression_ampersand_equality_expression_t *) const override {
      strm << "and_expression_and_expression_ampersand_equality_expression_t unknown";
    }

    virtual void operator()(const exclusive_or_expression_and_expression_t *) const override {
      strm << "exclusive_or_expression_and_expression_t unknown";
    }

    virtual void operator()(const exclusive_or_expression_exclusive_or_expression_caret_and_expression_t *) const override {
      strm << "exclusive_or_expression_exclusive_or_expression_caret_and_expression_t unknown";
    }

    virtual void operator()(const inclusive_or_expression_exclusive_or_expression_t *) const override {
      strm << "inclusive_or_expression_exclusive_or_expression_t unknown";
    }

    virtual void operator()(const inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t *) const override {
      strm << "inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t unknown";
    }

    virtual void operator()(const logical_and_expression_inclusive_or_expression_t *) const override {
      strm << "logical_and_expression_inclusive_or_expression_t unknown";
    }

    virtual void operator()(const logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t *) const override {
      strm << "logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t unknown";
    }

    virtual void operator()(const logical_xor_expression_logical_and_expression_t *) const override {
      strm << "logical_xor_expression_logical_and_expression_t unknown";
    }

    virtual void operator()(const logical_xor_expression_logical_xor_expression_xor_op_logical_and_expression_t *) const override {
      strm << "logical_xor_expression_logical_xor_expression_xor_op_logical_and_expression_t unknown";
    }

    virtual void operator()(const logical_or_expression_logical_xor_expression_t *) const override {
      strm << "logical_or_expression_logical_xor_expression_t unknown";
    }

    virtual void operator()(const logical_or_expression_logical_or_expression_or_op_logical_xor_expression_t *) const override {
      strm << "logical_or_expression_logical_or_expression_or_op_logical_xor_expression_t unknown";
    }

    virtual void operator()(const conditional_expression_logical_or_expression_t *) const override {
      strm << "conditional_expression_logical_or_expression_t unknown";
    }

    virtual void operator()(const conditional_expression_logical_or_expression_question_expression_colon_assignment_expression_t *) const override {
      strm << "conditional_expression_logical_or_expression_question_expression_colon_assignment_expression_t unknown";
    }

    virtual void operator()(const assignment_expression_conditional_expression_t *) const override {
      strm << "assignment_expression_conditional_expression_t unknown";
    }

    virtual void operator()(const assignment_expression_unary_expression_assignment_operator_assignment_expression_t *) const override {
      strm << "assignment_expression_unary_expression_assignment_operator_assignment_expression_t unknown";
    }

    virtual void operator()(const assignment_operator_equal_t *) const override {
      strm << "assignment_operator_equal_t unknown";
    }

    virtual void operator()(const assignment_operator_mul_assign_t *) const override {
      strm << "assignment_operator_mul_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_div_assign_t *) const override {
      strm << "assignment_operator_div_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_mod_assign_t *) const override {
      strm << "assignment_operator_mod_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_add_assign_t *) const override {
      strm << "assignment_operator_add_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_sub_assign_t *) const override {
      strm << "assignment_operator_sub_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_left_assign_t *) const override {
      strm << "assignment_operator_left_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_right_assign_t *) const override {
      strm << "assignment_operator_right_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_and_assign_t *) const override {
      strm << "assignment_operator_and_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_xor_assign_t *) const override {
      strm << "assignment_operator_xor_assign_t unknown";
    }

    virtual void operator()(const assignment_operator_or_assign_t *) const override {
      strm << "assignment_operator_or_assign_t unknown";
    }

    virtual void operator()(const expression_assignment_expression_t *) const override {
      strm << "expression_assignment_expression_t unknown";
    }

    virtual void operator()(const expression_expression_comma_assignment_expression_t *) const override {
      strm << "expression_expression_comma_assignment_expression_t unknown";
    }

    virtual void operator()(const constant_expression_conditional_expression_t *) const override {
      strm << "constant_expression_conditional_expression_t unknown";
    }

    virtual void operator()(const declaration_function_prototype_semicolon_t *) const override {
      strm << "declaration_function_prototype_semicolon_t unknown";
    }

    virtual void operator()(const declaration_init_declarator_list_semicolon_t *) const override {
      strm << "declaration_init_declarator_list_semicolon_t unknown";
    }

    virtual void operator()(const declaration_precision_precision_qualifier_type_specifier_semicolon_t *) const override {
      strm << "declaration_precision_precision_qualifier_type_specifier_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t *) const override {
      strm << "declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t *) const override {
      strm << "declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t *) const override {
      strm << "declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_semicolon_t *) const override {
      strm << "declaration_type_qualifier_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_identifier_semicolon_t *) const override {
      strm << "declaration_type_qualifier_identifier_semicolon_t unknown";
    }

    virtual void operator()(const declaration_type_qualifier_identifier_identifier_list_semicolon_t *) const override {
      strm << "declaration_type_qualifier_identifier_identifier_list_semicolon_t unknown";
    }

    virtual void operator()(const identifier_list_comma_identifier_t *) const override {
      strm << "identifier_list_comma_identifier_t unknown";
    }

    virtual void operator()(const identifier_list_identifier_list_comma_identifier_t *) const override {
      strm << "identifier_list_identifier_list_comma_identifier_t unknown";
    }

    virtual void operator()(const function_prototype_function_declarator_right_paren_t *) const override {
      strm << "function_prototype_function_declarator_right_paren_t unknown";
    }

    virtual void operator()(const function_declarator_function_header_t *) const override {
      strm << "function_declarator_function_header_t unknown";
    }

    virtual void operator()(const function_declarator_function_header_with_parameters_t *) const override {
      strm << "function_declarator_function_header_with_parameters_t unknown";
    }

    virtual void operator()(const function_header_with_parameters_function_header_parameter_declaration_t *) const override {
      strm << "function_header_with_parameters_function_header_parameter_declaration_t unknown";
    }

    virtual void operator()(const function_header_with_parameters_function_header_with_parameters_comma_parameter_declaration_t *) const override {
      strm << "function_header_with_parameters_function_header_with_parameters_comma_parameter_declaration_t unknown";
    }

    virtual void operator()(const function_header_fully_specified_type_identifier_left_paren_t *) const override {
      strm << "function_header_fully_specified_type_identifier_left_paren_t unknown";
    }

    virtual void operator()(const parameter_declarator_type_specifier_identifier_t *) const override {
      strm << "parameter_declarator_type_specifier_identifier_t unknown";
    }

    virtual void operator()(const parameter_declarator_type_specifier_identifier_array_specifier_t *) const override {
      strm << "parameter_declarator_type_specifier_identifier_array_specifier_t unknown";
    }

    virtual void operator()(const parameter_declaration_type_qualifier_parameter_declarator_t *) const override {
      strm << "parameter_declaration_type_qualifier_parameter_declarator_t unknown";
    }

    virtual void operator()(const parameter_declaration_parameter_declarator_t *) const override {
      strm << "parameter_declaration_parameter_declarator_t unknown";
    }

    virtual void operator()(const parameter_declaration_type_qualifier_parameter_type_specifier_t *) const override {
      strm << "parameter_declaration_type_qualifier_parameter_type_specifier_t unknown";
    }

    virtual void operator()(const parameter_declaration_parameter_type_specifier_t *) const override {
      strm << "parameter_declaration_parameter_type_specifier_t unknown";
    }

    virtual void operator()(const parameter_type_specifier_type_specifier_t *) const override {
      strm << "parameter_type_specifier_type_specifier_t unknown";
    }

    virtual void operator()(const init_declarator_list_single_declaration_t *) const override {
      strm << "init_declarator_list_single_declaration_t unknown";
    }

    virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_t *) const override {
      strm << "init_declarator_list_init_declarator_list_comma_identifier_t unknown";
    }

    virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t *) const override {
      strm << "init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t unknown";
    }

    virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t *) const override {
      strm << "init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t unknown";
    }

    virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t *) const override {
      strm << "init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t unknown";
    }

    virtual void operator()(const single_declaration_fully_specified_type_t *) const override {
      strm << "single_declaration_fully_specified_type_t unknown";
    }

    virtual void operator()(const single_declaration_fully_specified_type_identifier_t *) const override {
      strm << "single_declaration_fully_specified_type_identifier_t unknown";
    }

    virtual void operator()(const single_declaration_fully_specified_type_identifier_array_specifier_t *) const override {
      strm << "single_declaration_fully_specified_type_identifier_array_specifier_t unknown";
    }

    virtual void operator()(const single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t *) const override {
      strm << "single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t unknown";
    }

    virtual void operator()(const single_declaration_fully_specified_type_identifier_equal_initializer_t *) const override {
      strm << "single_declaration_fully_specified_type_identifier_equal_initializer_t unknown";
    }

    virtual void operator()(const fully_specified_type_type_specifier_t *) const override {
      strm << "fully_specified_type_type_specifier_t unknown";
    }

    virtual void operator()(const fully_specified_type_type_qualifier_type_specifier_t *) const override {
      strm << "fully_specified_type_type_qualifier_type_specifier_t unknown";
    }

    virtual void operator()(const invariant_qualifier_invariant_t *) const override {
      strm << "invariant_qualifier_invariant_t unknown";
    }

    virtual void operator()(const interpolation_qualifier_smooth_t *) const override {
      strm << "interpolation_qualifier_smooth_t unknown";
    }

    virtual void operator()(const interpolation_qualifier_flat_t *) const override {
      strm << "interpolation_qualifier_flat_t unknown";
    }

    virtual void operator()(const interpolation_qualifier_noperspective_t *) const override {
      strm << "interpolation_qualifier_noperspective_t unknown";
    }

    virtual void operator()(const layout_qualifier_layout_left_paren_layout_qualifier_id_list_right_paren_t *) const override {
      strm << "layout_qualifier_layout_left_paren_layout_qualifier_id_list_right_paren_t unknown";
    }

    virtual void operator()(const layout_qualifier_id_list_layout_qualifier_id_t *) const override {
      strm << "layout_qualifier_id_list_layout_qualifier_id_t unknown";
    }

    virtual void operator()(const layout_qualifier_id_list_layout_qualifier_id_list_comma_layout_qualifier_id_t *) const override {
      strm << "layout_qualifier_id_list_layout_qualifier_id_list_comma_layout_qualifier_id_t unknown";
    }

    virtual void operator()(const layout_qualifier_id_identifier_t *) const override {
      strm << "layout_qualifier_id_identifier_t unknown";
    }

    virtual void operator()(const layout_qualifier_id_identifier_equal_constant_expression_t *) const override {
      strm << "layout_qualifier_id_identifier_equal_constant_expression_t unknown";
    }

    virtual void operator()(const layout_qualifier_id_shared_t *) const override {
      strm << "layout_qualifier_id_shared_t unknown";
    }

    virtual void operator()(const precise_qualifier_precise_t *) const override {
      strm << "precise_qualifier_precise_t unknown";
    }

    virtual void operator()(const type_qualifier_single_type_qualifier_t *) const override {
      strm << "type_qualifier_single_type_qualifier_t unknown";
    }

    virtual void operator()(const type_qualifier_type_qualifier_single_type_qualifier_t *) const override {
      strm << "type_qualifier_type_qualifier_single_type_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_storage_qualifier_t *) const override {
      strm << "single_type_qualifier_storage_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_layout_qualifier_t *) const override {
      strm << "single_type_qualifier_layout_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_precision_qualifier_t *) const override {
      strm << "single_type_qualifier_precision_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_interpolation_qualifier_t *) const override {
      strm << "single_type_qualifier_interpolation_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_invariant_qualifier_t *) const override {
      strm << "single_type_qualifier_invariant_qualifier_t unknown";
    }

    virtual void operator()(const single_type_qualifier_precise_qualifier_t *) const override {
      strm << "single_type_qualifier_precise_qualifier_t unknown";
    }

    virtual void operator()(const storage_qualifier_const_t *) const override {
      strm << "storage_qualifier_const_t unknown";
    }

    virtual void operator()(const storage_qualifier_inout_t *) const override {
      strm << "storage_qualifier_inout_t unknown";
    }

    virtual void operator()(const storage_qualifier_in_t *) const override {
      strm << "storage_qualifier_in_t unknown";
    }

    virtual void operator()(const storage_qualifier_out_t *) const override {
      strm << "storage_qualifier_out_t unknown";
    }

    virtual void operator()(const storage_qualifier_centroid_t *) const override {
      strm << "storage_qualifier_centroid_t unknown";
    }

    virtual void operator()(const storage_qualifier_patch_t *) const override {
      strm << "storage_qualifier_patch_t unknown";
    }

    virtual void operator()(const storage_qualifier_sample_t *) const override {
      strm << "storage_qualifier_sample_t unknown";
    }

    virtual void operator()(const storage_qualifier_uniform_t *) const override {
      strm << "storage_qualifier_uniform_t unknown";
    }

    virtual void operator()(const storage_qualifier_buffer_t *) const override {
      strm << "storage_qualifier_buffer_t unknown";
    }

    virtual void operator()(const storage_qualifier_shared_t *) const override {
      strm << "storage_qualifier_shared_t unknown";
    }

    virtual void operator()(const storage_qualifier_coherent_t *) const override {
      strm << "storage_qualifier_coherent_t unknown";
    }

    virtual void operator()(const storage_qualifier_volatile_t *) const override {
      strm << "storage_qualifier_volatile_t unknown";
    }

    virtual void operator()(const storage_qualifier_restrict_t *) const override {
      strm << "storage_qualifier_restrict_t unknown";
    }

    virtual void operator()(const storage_qualifier_readonly_t *) const override {
      strm << "storage_qualifier_readonly_t unknown";
    }

    virtual void operator()(const storage_qualifier_writeonly_t *) const override {
      strm << "storage_qualifier_writeonly_t unknown";
    }

    virtual void operator()(const storage_qualifier_subroutine_t *) const override {
      strm << "storage_qualifier_subroutine_t unknown";
    }

    virtual void operator()(const storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t *) const override {
      strm << "storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t unknown";
    }

    virtual void operator()(const type_name_list_type_name_t *) const override {
      strm << "type_name_list_type_name_t unknown";
    }

    virtual void operator()(const type_name_list_type_name_list_comma_type_name_t *) const override {
      strm << "type_name_list_type_name_list_comma_type_name_t unknown";
    }

    virtual void operator()(const type_specifier_type_specifier_nonarray_t *) const override {
      strm << "type_specifier_type_specifier_nonarray_t unknown";
    }

    virtual void operator()(const type_specifier_type_specifier_nonarray_array_specifier_t *) const override {
      strm << "type_specifier_type_specifier_nonarray_array_specifier_t unknown";
    }

    virtual void operator()(const array_specifier_left_bracket_right_bracket_t *) const override {
      strm << "array_specifier_left_bracket_right_bracket_t unknown";
    }

    virtual void operator()(const array_specifier_left_bracket_conditional_expression_right_bracket_t *) const override {
      strm << "array_specifier_left_bracket_conditional_expression_right_bracket_t unknown";
    }

    virtual void operator()(const array_specifier_array_specifier_left_bracket_right_bracket_t *) const override {
      strm << "array_specifier_array_specifier_left_bracket_right_bracket_t unknown";
    }

    virtual void operator()(const array_specifier_array_specifier_left_bracket_conditional_expression_right_bracket_t *) const override {
      strm << "array_specifier_array_specifier_left_bracket_conditional_expression_right_bracket_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_void_t *) const override {
      strm << "type_specifier_nonarray_void_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_float_t *) const override {
      strm << "type_specifier_nonarray_float_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_double_t *) const override {
      strm << "type_specifier_nonarray_double_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_int_t *) const override {
      strm << "type_specifier_nonarray_int_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uint_t *) const override {
      strm << "type_specifier_nonarray_uint_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_bool_t *) const override {
      strm << "type_specifier_nonarray_bool_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_vec2_t *) const override {
      strm << "type_specifier_nonarray_vec2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_vec3_t *) const override {
      strm << "type_specifier_nonarray_vec3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_vec4_t *) const override {
      strm << "type_specifier_nonarray_vec4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dvec2_t *) const override {
      strm << "type_specifier_nonarray_dvec2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dvec3_t *) const override {
      strm << "type_specifier_nonarray_dvec3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dvec4_t *) const override {
      strm << "type_specifier_nonarray_dvec4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_bvec2_t *) const override {
      strm << "type_specifier_nonarray_bvec2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_bvec3_t *) const override {
      strm << "type_specifier_nonarray_bvec3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_bvec4_t *) const override {
      strm << "type_specifier_nonarray_bvec4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_ivec2_t *) const override {
      strm << "type_specifier_nonarray_ivec2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_ivec3_t *) const override {
      strm << "type_specifier_nonarray_ivec3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_ivec4_t *) const override {
      strm << "type_specifier_nonarray_ivec4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uvec2_t *) const override {
      strm << "type_specifier_nonarray_uvec2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uvec3_t *) const override {
      strm << "type_specifier_nonarray_uvec3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uvec4_t *) const override {
      strm << "type_specifier_nonarray_uvec4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat2_t *) const override {
      strm << "type_specifier_nonarray_mat2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat3_t *) const override {
      strm << "type_specifier_nonarray_mat3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat4_t *) const override {
      strm << "type_specifier_nonarray_mat4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat2x2_t *) const override {
      strm << "type_specifier_nonarray_mat2x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat2x3_t *) const override {
      strm << "type_specifier_nonarray_mat2x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat2x4_t *) const override {
      strm << "type_specifier_nonarray_mat2x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat3x2_t *) const override {
      strm << "type_specifier_nonarray_mat3x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat3x3_t *) const override {
      strm << "type_specifier_nonarray_mat3x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat3x4_t *) const override {
      strm << "type_specifier_nonarray_mat3x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat4x2_t *) const override {
      strm << "type_specifier_nonarray_mat4x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat4x3_t *) const override {
      strm << "type_specifier_nonarray_mat4x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_mat4x4_t *) const override {
      strm << "type_specifier_nonarray_mat4x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat2_t *) const override {
      strm << "type_specifier_nonarray_dmat2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat3_t *) const override {
      strm << "type_specifier_nonarray_dmat3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat4_t *) const override {
      strm << "type_specifier_nonarray_dmat4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat2x2_t *) const override {
      strm << "type_specifier_nonarray_dmat2x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat2x3_t *) const override {
      strm << "type_specifier_nonarray_dmat2x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat2x4_t *) const override {
      strm << "type_specifier_nonarray_dmat2x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat3x2_t *) const override {
      strm << "type_specifier_nonarray_dmat3x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat3x3_t *) const override {
      strm << "type_specifier_nonarray_dmat3x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat3x4_t *) const override {
      strm << "type_specifier_nonarray_dmat3x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat4x2_t *) const override {
      strm << "type_specifier_nonarray_dmat4x2_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat4x3_t *) const override {
      strm << "type_specifier_nonarray_dmat4x3_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_dmat4x4_t *) const override {
      strm << "type_specifier_nonarray_dmat4x4_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_atomic_uint_t *) const override {
      strm << "type_specifier_nonarray_atomic_uint_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler1d_t *) const override {
      strm << "type_specifier_nonarray_sampler1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2d_t *) const override {
      strm << "type_specifier_nonarray_sampler2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler3d_t *) const override {
      strm << "type_specifier_nonarray_sampler3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_samplercube_t *) const override {
      strm << "type_specifier_nonarray_samplercube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler1dshadow_t *) const override {
      strm << "type_specifier_nonarray_sampler1dshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2dshadow_t *) const override {
      strm << "type_specifier_nonarray_sampler2dshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_samplercubeshadow_t *) const override {
      strm << "type_specifier_nonarray_samplercubeshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler1darray_t *) const override {
      strm << "type_specifier_nonarray_sampler1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2darray_t *) const override {
      strm << "type_specifier_nonarray_sampler2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler1darrayshadow_t *) const override {
      strm << "type_specifier_nonarray_sampler1darrayshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2darrayshadow_t *) const override {
      strm << "type_specifier_nonarray_sampler2darrayshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_samplercubearray_t *) const override {
      strm << "type_specifier_nonarray_samplercubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_samplercubearrayshadow_t *) const override {
      strm << "type_specifier_nonarray_samplercubearrayshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler1d_t *) const override {
      strm << "type_specifier_nonarray_isampler1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler2d_t *) const override {
      strm << "type_specifier_nonarray_isampler2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler3d_t *) const override {
      strm << "type_specifier_nonarray_isampler3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isamplercube_t *) const override {
      strm << "type_specifier_nonarray_isamplercube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler1darray_t *) const override {
      strm << "type_specifier_nonarray_isampler1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler2darray_t *) const override {
      strm << "type_specifier_nonarray_isampler2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isamplercubearray_t *) const override {
      strm << "type_specifier_nonarray_isamplercubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler1d_t *) const override {
      strm << "type_specifier_nonarray_usampler1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler2d_t *) const override {
      strm << "type_specifier_nonarray_usampler2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler3d_t *) const override {
      strm << "type_specifier_nonarray_usampler3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usamplercube_t *) const override {
      strm << "type_specifier_nonarray_usamplercube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler1darray_t *) const override {
      strm << "type_specifier_nonarray_usampler1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler2darray_t *) const override {
      strm << "type_specifier_nonarray_usampler2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usamplercubearray_t *) const override {
      strm << "type_specifier_nonarray_usamplercubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2drect_t *) const override {
      strm << "type_specifier_nonarray_sampler2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2drectshadow_t *) const override {
      strm << "type_specifier_nonarray_sampler2drectshadow_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler2drect_t *) const override {
      strm << "type_specifier_nonarray_isampler2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler2drect_t *) const override {
      strm << "type_specifier_nonarray_usampler2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_samplerbuffer_t *) const override {
      strm << "type_specifier_nonarray_samplerbuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isamplerbuffer_t *) const override {
      strm << "type_specifier_nonarray_isamplerbuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usamplerbuffer_t *) const override {
      strm << "type_specifier_nonarray_usamplerbuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2dms_t *) const override {
      strm << "type_specifier_nonarray_sampler2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler2dms_t *) const override {
      strm << "type_specifier_nonarray_isampler2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler2dms_t *) const override {
      strm << "type_specifier_nonarray_usampler2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_sampler2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_sampler2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_isampler2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_isampler2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_usampler2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_usampler2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image1d_t *) const override {
      strm << "type_specifier_nonarray_image1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage1d_t *) const override {
      strm << "type_specifier_nonarray_iimage1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage1d_t *) const override {
      strm << "type_specifier_nonarray_uimage1d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image2d_t *) const override {
      strm << "type_specifier_nonarray_image2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage2d_t *) const override {
      strm << "type_specifier_nonarray_iimage2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage2d_t *) const override {
      strm << "type_specifier_nonarray_uimage2d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image3d_t *) const override {
      strm << "type_specifier_nonarray_image3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage3d_t *) const override {
      strm << "type_specifier_nonarray_iimage3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage3d_t *) const override {
      strm << "type_specifier_nonarray_uimage3d_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image2drect_t *) const override {
      strm << "type_specifier_nonarray_image2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage2drect_t *) const override {
      strm << "type_specifier_nonarray_iimage2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage2drect_t *) const override {
      strm << "type_specifier_nonarray_uimage2drect_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_imagecube_t *) const override {
      strm << "type_specifier_nonarray_imagecube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimagecube_t *) const override {
      strm << "type_specifier_nonarray_iimagecube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimagecube_t *) const override {
      strm << "type_specifier_nonarray_uimagecube_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_imagebuffer_t *) const override {
      strm << "type_specifier_nonarray_imagebuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimagebuffer_t *) const override {
      strm << "type_specifier_nonarray_iimagebuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimagebuffer_t *) const override {
      strm << "type_specifier_nonarray_uimagebuffer_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image1darray_t *) const override {
      strm << "type_specifier_nonarray_image1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage1darray_t *) const override {
      strm << "type_specifier_nonarray_iimage1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage1darray_t *) const override {
      strm << "type_specifier_nonarray_uimage1darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image2darray_t *) const override {
      strm << "type_specifier_nonarray_image2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage2darray_t *) const override {
      strm << "type_specifier_nonarray_iimage2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage2darray_t *) const override {
      strm << "type_specifier_nonarray_uimage2darray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_imagecubearray_t *) const override {
      strm << "type_specifier_nonarray_imagecubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimagecubearray_t *) const override {
      strm << "type_specifier_nonarray_iimagecubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimagecubearray_t *) const override {
      strm << "type_specifier_nonarray_uimagecubearray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image2dms_t *) const override {
      strm << "type_specifier_nonarray_image2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage2dms_t *) const override {
      strm << "type_specifier_nonarray_iimage2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage2dms_t *) const override {
      strm << "type_specifier_nonarray_uimage2dms_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_image2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_image2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_iimage2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_iimage2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_uimage2dmsarray_t *) const override {
      strm << "type_specifier_nonarray_uimage2dmsarray_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_struct_specifier_t *) const override {
      strm << "type_specifier_nonarray_struct_specifier_t unknown";
    }

    virtual void operator()(const type_specifier_nonarray_type_name_t *) const override {
      strm << "type_specifier_nonarray_type_name_t unknown";
    }

    virtual void operator()(const precision_qualifier_high_precision_t *) const override {
      strm << "precision_qualifier_high_precision_t unknown";
    }

    virtual void operator()(const precision_qualifier_medium_precision_t *) const override {
      strm << "precision_qualifier_medium_precision_t unknown";
    }

    virtual void operator()(const precision_qualifier_low_precision_t *) const override {
      strm << "precision_qualifier_low_precision_t unknown";
    }

    virtual void operator()(const struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t *) const override {
      strm << "struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t unknown";
    }

    virtual void operator()(const struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t *) const override {
      strm << "struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t unknown";
    }

    virtual void operator()(const struct_declaration_list_struct_declaration_t *) const override {
      strm << "struct_declaration_list_struct_declaration_t unknown";
    }

    virtual void operator()(const struct_declaration_list_struct_declaration_list_struct_declaration_t *) const override {
      strm << "struct_declaration_list_struct_declaration_list_struct_declaration_t unknown";
    }

    virtual void operator()(const struct_declaration_type_specifier_struct_declarator_list_semicolon_t *) const override {
      strm << "struct_declaration_type_specifier_struct_declarator_list_semicolon_t unknown";
    }

    virtual void operator()(const struct_declaration_type_qualifier_type_specifier_struct_declarator_list_semicolon_t *) const override {
      strm << "struct_declaration_type_qualifier_type_specifier_struct_declarator_list_semicolon_t unknown";
    }

    virtual void operator()(const struct_declarator_list_struct_declarator_t *) const override {
      strm << "struct_declarator_list_struct_declarator_t unknown";
    }

    virtual void operator()(const struct_declarator_list_struct_declarator_list_comma_struct_declarator_t *) const override {
      strm << "struct_declarator_list_struct_declarator_list_comma_struct_declarator_t unknown";
    }

    virtual void operator()(const struct_declarator_identifier_t *) const override {
      strm << "struct_declarator_identifier_t unknown";
    }

    virtual void operator()(const struct_declarator_identifier_array_specifier_t *) const override {
      strm << "struct_declarator_identifier_array_specifier_t unknown";
    }

    virtual void operator()(const initializer_assignment_expression_t *) const override {
      strm << "initializer_assignment_expression_t unknown";
    }

    virtual void operator()(const initializer_left_brace_initializer_list_right_brace_t *) const override {
      strm << "initializer_left_brace_initializer_list_right_brace_t unknown";
    }

    virtual void operator()(const initializer_left_brace_initializer_list_comma_right_brace_t *) const override {
      strm << "initializer_left_brace_initializer_list_comma_right_brace_t unknown";
    }

    virtual void operator()(const initializer_list_initializer_t *) const override {
      strm << "initializer_list_initializer_t unknown";
    }

    virtual void operator()(const initializer_list_initializer_list_comma_initializer_t *) const override {
      strm << "initializer_list_initializer_list_comma_initializer_t unknown";
    }

    virtual void operator()(const declaration_statement_declaration_t *) const override {
      strm << "declaration_statement_declaration_t unknown";
    }

    virtual void operator()(const statement_compound_statement_t *) const override {
      strm << "statement_compound_statement_t unknown";
    }

    virtual void operator()(const statement_simple_statement_t *) const override {
      strm << "statement_simple_statement_t unknown";
    }

    virtual void operator()(const simple_statement_declaration_statement_t *) const override {
      strm << "simple_statement_declaration_statement_t unknown";
    }

    virtual void operator()(const simple_statement_expression_statement_t *) const override {
      strm << "simple_statement_expression_statement_t unknown";
    }

    virtual void operator()(const simple_statement_selection_statement_t *) const override {
      strm << "simple_statement_selection_statement_t unknown";
    }

    virtual void operator()(const simple_statement_switch_statement_t *) const override {
      strm << "simple_statement_switch_statement_t unknown";
    }

    virtual void operator()(const simple_statement_case_label_t *) const override {
      strm << "simple_statement_case_label_t unknown";
    }

    virtual void operator()(const simple_statement_iteration_statement_t *) const override {
      strm << "simple_statement_iteration_statement_t unknown";
    }

    virtual void operator()(const simple_statement_jump_statement_t *) const override {
      strm << "simple_statement_jump_statement_t unknown";
    }

    virtual void operator()(const compound_statement_left_brace_right_brace_t *) const override {
      strm << "compound_statement_left_brace_right_brace_t unknown";
    }

    virtual void operator()(const compound_statement_left_brace_statement_list_right_brace_t *) const override {
      strm << "compound_statement_left_brace_statement_list_right_brace_t unknown";
    }

    virtual void operator()(const statement_no_new_scope_compound_statement_no_new_scope_t *) const override {
      strm << "statement_no_new_scope_compound_statement_no_new_scope_t unknown";
    }

    virtual void operator()(const statement_no_new_scope_simple_statement_t *) const override {
      strm << "statement_no_new_scope_simple_statement_t unknown";
    }

    virtual void operator()(const compound_statement_no_new_scope_left_brace_right_brace_t *) const override {
      strm << "compound_statement_no_new_scope_left_brace_right_brace_t unknown";
    }

    virtual void operator()(const compound_statement_no_new_scope_left_brace_statement_list_right_brace_t *) const override {
      strm << "compound_statement_no_new_scope_left_brace_statement_list_right_brace_t unknown";
    }

    virtual void operator()(const statement_list_statement_t *) const override {
      strm << "statement_list_statement_t unknown";
    }

    virtual void operator()(const statement_list_statement_list_statement_t *) const override {
      strm << "statement_list_statement_list_statement_t unknown";
    }

    virtual void operator()(const expression_statement_semicolon_t *) const override {
      strm << "expression_statement_semicolon_t unknown";
    }

    virtual void operator()(const expression_statement_expression_semicolon_t *) const override {
      strm << "expression_statement_expression_semicolon_t unknown";
    }

    virtual void operator()(const selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t *) const override {
      strm << "selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t unknown";
    }

    virtual void operator()(const selection_rest_statement_statement_else_statement_t *) const override {
      strm << "selection_rest_statement_statement_else_statement_t unknown";
    }

    virtual void operator()(const selection_rest_statement_statement_t *) const override {
      strm << "selection_rest_statement_statement_t unknown";
    }

    virtual void operator()(const condition_expression_t *) const override {
      strm << "condition_expression_t unknown";
    }

    virtual void operator()(const condition_fully_specified_type_identifier_equal_initializer_t *) const override {
      strm << "condition_fully_specified_type_identifier_equal_initializer_t unknown";
    }

    virtual void operator()(const switch_statement_switch_left_paren_expression_right_paren_left_brace_switch_statement_list_right_brace_t *) const override {
      strm << "switch_statement_switch_left_paren_expression_right_paren_left_brace_switch_statement_list_right_brace_t unknown";
    }

    virtual void operator()(const switch_statement_list_nothing_t *) const override {
      strm << "switch_statement_list_nothing_t unknown";
    }

    virtual void operator()(const switch_statement_list_statement_list_t *) const override {
      strm << "switch_statement_list_statement_list_t unknown";
    }

    virtual void operator()(const case_label_case_expression_colon_t *) const override {
      strm << "case_label_case_expression_colon_t unknown";
    }

    virtual void operator()(const case_label_default_colon_t *) const override {
      strm << "case_label_default_colon_t unknown";
    }

    virtual void operator()(const iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t *) const override {
      strm << "iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t unknown";
    }

    virtual void operator()(const iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t *) const override {
      strm << "iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t unknown";
    }

    virtual void operator()(const iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t *) const override {
      strm << "iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t unknown";
    }

    virtual void operator()(const for_init_statement_expression_statement_t *) const override {
      strm << "for_init_statement_expression_statement_t unknown";
    }

    virtual void operator()(const for_init_statement_declaration_statement_t *) const override {
      strm << "for_init_statement_declaration_statement_t unknown";
    }

    virtual void operator()(const conditionopt_condition_t *) const override {
      strm << "conditionopt_condition_t unknown";
    }

    virtual void operator()(const conditionopt_nothing_t *) const override {
      strm << "conditionopt_nothing_t unknown";
    }

    virtual void operator()(const for_rest_statement_conditionopt_semicolon_t *) const override {
      strm << "for_rest_statement_conditionopt_semicolon_t unknown";
    }

    virtual void operator()(const for_rest_statement_conditionopt_semicolon_expression_t *) const override {
      strm << "for_rest_statement_conditionopt_semicolon_expression_t unknown";
    }

    virtual void operator()(const jump_statement_continue_semicolon_t *) const override {
      strm << "jump_statement_continue_semicolon_t unknown";
    }

    virtual void operator()(const jump_statement_break_semicolon_t *) const override {
      strm << "jump_statement_break_semicolon_t unknown";
    }

    virtual void operator()(const jump_statement_return_semicolon_t *) const override {
      strm << "jump_statement_return_semicolon_t unknown";
    }

    virtual void operator()(const jump_statement_return_expression_semicolon_t *) const override {
      strm << "jump_statement_return_expression_semicolon_t unknown";
    }

    virtual void operator()(const jump_statement_discard_semicolon_t *) const override {
      strm << "jump_statement_discard_semicolon_t unknown";
    }

    virtual void operator()(const translation_unit_external_declaration_t *) const override {
      strm << "translation_unit_external_declaration_t unknown";
    }

    virtual void operator()(const translation_unit_translation_unit_external_declaration_t *) const override {
      strm << "translation_unit_translation_unit_external_declaration_t unknown";
    }

    virtual void operator()(const external_declaration_function_definition_t *) const override {
      strm << "external_declaration_function_definition_t unknown";
    }

    virtual void operator()(const external_declaration_declaration_t *) const override {
      strm << "external_declaration_declaration_t unknown";
    }

    virtual void operator()(const external_declaration_semicolon_t *) const override {
      strm << "external_declaration_semicolon_t unknown";
    }

    virtual void operator()(const function_definition_function_prototype_compound_statement_no_new_scope_t *) const override {
      strm << "function_definition_function_prototype_compound_statement_no_new_scope_t unknown";
    }

  private:

    std::ostream &strm;

  };  // pretty_printer_t
  ast->accept(pretty_printer_t { strm });
  return strm;
}

}   // gliss

}   // ast
