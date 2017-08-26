#pragma once

namespace gliss {

namespace ast {

class variable_identifier_identifier_t;
class primary_expression_variable_identifier_t;
class primary_expression_intconstant_t;
class primary_expression_uintconstant_t;
class primary_expression_floatconstant_t;
class primary_expression_boolconstant_t;
class primary_expression_doubleconstant_t;
class primary_expression_left_paren_expression_right_paren_t;
class postfix_expression_primary_expression_t;
class postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t;
class postfix_expression_function_call_t;
class postfix_expression_postfix_expression_dot_field_selection_t;
class postfix_expression_postfix_expression_inc_op_t;
class postfix_expression_postfix_expression_dec_op_t;
class integer_expression_expression_t;
class function_call_function_call_or_method_t;
class function_call_or_method_function_call_generic_t;
class function_call_generic_function_call_header_with_parameters_right_paren_t;
class function_call_generic_function_call_header_no_parameters_right_paren_t;
class function_call_header_no_parameters_function_call_header_void_t;
class function_call_header_no_parameters_function_call_header_t;
class function_call_header_with_parameters_function_call_header_assignment_expression_t;
class function_call_header_with_parameters_function_call_header_with_parameters_comma_assignment_expression_t;
class function_call_header_function_identifier_left_paren_t;
class function_identifier_type_specifier_t;
class function_identifier_postfix_expression_t;
class unary_expression_postfix_expression_t;
class unary_expression_inc_op_unary_expression_t;
class unary_expression_dec_op_unary_expression_t;
class unary_expression_unary_operator_unary_expression_t;
class unary_operator_plus_t;
class unary_operator_dash_t;
class unary_operator_bang_t;
class unary_operator_tilde_t;
class multiplicative_expression_unary_expression_t;
class multiplicative_expression_multiplicative_expression_star_unary_expression_t;
class multiplicative_expression_multiplicative_expression_slash_unary_expression_t;
class multiplicative_expression_multiplicative_expression_percent_unary_expression_t;
class additive_expression_multiplicative_expression_t;
class additive_expression_additive_expression_plus_multiplicative_expression_t;
class additive_expression_additive_expression_dash_multiplicative_expression_t;
class shift_expression_additive_expression_t;
class shift_expression_shift_expression_left_op_additive_expression_t;
class shift_expression_shift_expression_right_op_additive_expression_t;
class relational_expression_shift_expression_t;
class relational_expression_relational_expression_left_angle_shift_expression_t;
class relational_expression_relational_expression_right_angle_shift_expression_t;
class relational_expression_relational_expression_le_op_shift_expression_t;
class relational_expression_relational_expression_ge_op_shift_expression_t;
class equality_expression_relational_expression_t;
class equality_expression_equality_expression_eq_op_relational_expression_t;
class equality_expression_equality_expression_ne_op_relational_expression_t;
class and_expression_equality_expression_t;
class and_expression_and_expression_ampersand_equality_expression_t;
class exclusive_or_expression_and_expression_t;
class exclusive_or_expression_exclusive_or_expression_caret_and_expression_t;
class inclusive_or_expression_exclusive_or_expression_t;
class inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t;
class logical_and_expression_inclusive_or_expression_t;
class logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t;
class logical_xor_expression_logical_and_expression_t;
class logical_xor_expression_logical_xor_expression_xor_op_logical_and_expression_t;
class logical_or_expression_logical_xor_expression_t;
class logical_or_expression_logical_or_expression_or_op_logical_xor_expression_t;
class conditional_expression_logical_or_expression_t;
class conditional_expression_logical_or_expression_question_expression_colon_assignment_expression_t;
class assignment_expression_conditional_expression_t;
class assignment_expression_unary_expression_assignment_operator_assignment_expression_t;
class assignment_operator_equal_t;
class assignment_operator_mul_assign_t;
class assignment_operator_div_assign_t;
class assignment_operator_mod_assign_t;
class assignment_operator_add_assign_t;
class assignment_operator_sub_assign_t;
class assignment_operator_left_assign_t;
class assignment_operator_right_assign_t;
class assignment_operator_and_assign_t;
class assignment_operator_xor_assign_t;
class assignment_operator_or_assign_t;
class expression_assignment_expression_t;
class expression_expression_comma_assignment_expression_t;
class constant_expression_conditional_expression_t;
class declaration_function_prototype_semicolon_t;
class declaration_init_declarator_list_semicolon_t;
class declaration_precision_precision_qualifier_type_specifier_semicolon_t;
class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t;
class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t;
class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t;
class declaration_type_qualifier_semicolon_t;
class declaration_type_qualifier_identifier_semicolon_t;
class declaration_type_qualifier_identifier_identifier_list_semicolon_t;
class identifier_list_comma_identifier_t;
class identifier_list_identifier_list_comma_identifier_t;
class function_prototype_function_declarator_right_paren_t;
class function_declarator_function_header_t;
class function_declarator_function_header_with_parameters_t;
class function_header_with_parameters_function_header_parameter_declaration_t;
class function_header_with_parameters_function_header_with_parameters_comma_parameter_declaration_t;
class function_header_fully_specified_type_identifier_left_paren_t;
class parameter_declarator_type_specifier_identifier_t;
class parameter_declarator_type_specifier_identifier_array_specifier_t;
class parameter_declaration_type_qualifier_parameter_declarator_t;
class parameter_declaration_parameter_declarator_t;
class parameter_declaration_type_qualifier_parameter_type_specifier_t;
class parameter_declaration_parameter_type_specifier_t;
class parameter_type_specifier_type_specifier_t;
class init_declarator_list_single_declaration_t;
class init_declarator_list_init_declarator_list_comma_identifier_t;
class init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t;
class init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t;
class init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t;
class single_declaration_fully_specified_type_t;
class single_declaration_fully_specified_type_identifier_t;
class single_declaration_fully_specified_type_identifier_array_specifier_t;
class single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t;
class single_declaration_fully_specified_type_identifier_equal_initializer_t;
class fully_specified_type_type_specifier_t;
class fully_specified_type_type_qualifier_type_specifier_t;
class invariant_qualifier_invariant_t;
class interpolation_qualifier_smooth_t;
class interpolation_qualifier_flat_t;
class interpolation_qualifier_noperspective_t;
class layout_qualifier_layout_left_paren_layout_qualifier_id_list_right_paren_t;
class layout_qualifier_id_list_layout_qualifier_id_t;
class layout_qualifier_id_list_layout_qualifier_id_list_comma_layout_qualifier_id_t;
class layout_qualifier_id_identifier_t;
class layout_qualifier_id_identifier_equal_constant_expression_t;
class layout_qualifier_id_shared_t;
class precise_qualifier_precise_t;
class type_qualifier_single_type_qualifier_t;
class type_qualifier_type_qualifier_single_type_qualifier_t;
class single_type_qualifier_storage_qualifier_t;
class single_type_qualifier_layout_qualifier_t;
class single_type_qualifier_precision_qualifier_t;
class single_type_qualifier_interpolation_qualifier_t;
class single_type_qualifier_invariant_qualifier_t;
class single_type_qualifier_precise_qualifier_t;
class storage_qualifier_const_t;
class storage_qualifier_inout_t;
class storage_qualifier_in_t;
class storage_qualifier_out_t;
class storage_qualifier_centroid_t;
class storage_qualifier_patch_t;
class storage_qualifier_sample_t;
class storage_qualifier_uniform_t;
class storage_qualifier_buffer_t;
class storage_qualifier_shared_t;
class storage_qualifier_coherent_t;
class storage_qualifier_volatile_t;
class storage_qualifier_restrict_t;
class storage_qualifier_readonly_t;
class storage_qualifier_writeonly_t;
class storage_qualifier_subroutine_t;
class storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t;
class type_name_list_type_name_t;
class type_name_list_type_name_list_comma_type_name_t;
class type_specifier_type_specifier_nonarray_t;
class type_specifier_type_specifier_nonarray_array_specifier_t;
class array_specifier_left_bracket_right_bracket_t;
class array_specifier_left_bracket_conditional_expression_right_bracket_t;
class array_specifier_array_specifier_left_bracket_right_bracket_t;
class array_specifier_array_specifier_left_bracket_conditional_expression_right_bracket_t;
class type_specifier_nonarray_void_t;
class type_specifier_nonarray_float_t;
class type_specifier_nonarray_double_t;
class type_specifier_nonarray_int_t;
class type_specifier_nonarray_uint_t;
class type_specifier_nonarray_bool_t;
class type_specifier_nonarray_vec2_t;
class type_specifier_nonarray_vec3_t;
class type_specifier_nonarray_vec4_t;
class type_specifier_nonarray_dvec2_t;
class type_specifier_nonarray_dvec3_t;
class type_specifier_nonarray_dvec4_t;
class type_specifier_nonarray_bvec2_t;
class type_specifier_nonarray_bvec3_t;
class type_specifier_nonarray_bvec4_t;
class type_specifier_nonarray_ivec2_t;
class type_specifier_nonarray_ivec3_t;
class type_specifier_nonarray_ivec4_t;
class type_specifier_nonarray_uvec2_t;
class type_specifier_nonarray_uvec3_t;
class type_specifier_nonarray_uvec4_t;
class type_specifier_nonarray_mat2_t;
class type_specifier_nonarray_mat3_t;
class type_specifier_nonarray_mat4_t;
class type_specifier_nonarray_mat2x2_t;
class type_specifier_nonarray_mat2x3_t;
class type_specifier_nonarray_mat2x4_t;
class type_specifier_nonarray_mat3x2_t;
class type_specifier_nonarray_mat3x3_t;
class type_specifier_nonarray_mat3x4_t;
class type_specifier_nonarray_mat4x2_t;
class type_specifier_nonarray_mat4x3_t;
class type_specifier_nonarray_mat4x4_t;
class type_specifier_nonarray_dmat2_t;
class type_specifier_nonarray_dmat3_t;
class type_specifier_nonarray_dmat4_t;
class type_specifier_nonarray_dmat2x2_t;
class type_specifier_nonarray_dmat2x3_t;
class type_specifier_nonarray_dmat2x4_t;
class type_specifier_nonarray_dmat3x2_t;
class type_specifier_nonarray_dmat3x3_t;
class type_specifier_nonarray_dmat3x4_t;
class type_specifier_nonarray_dmat4x2_t;
class type_specifier_nonarray_dmat4x3_t;
class type_specifier_nonarray_dmat4x4_t;
class type_specifier_nonarray_atomic_uint_t;
class type_specifier_nonarray_sampler1d_t;
class type_specifier_nonarray_sampler2d_t;
class type_specifier_nonarray_sampler3d_t;
class type_specifier_nonarray_samplercube_t;
class type_specifier_nonarray_sampler1dshadow_t;
class type_specifier_nonarray_sampler2dshadow_t;
class type_specifier_nonarray_samplercubeshadow_t;
class type_specifier_nonarray_sampler1darray_t;
class type_specifier_nonarray_sampler2darray_t;
class type_specifier_nonarray_sampler1darrayshadow_t;
class type_specifier_nonarray_sampler2darrayshadow_t;
class type_specifier_nonarray_samplercubearray_t;
class type_specifier_nonarray_samplercubearrayshadow_t;
class type_specifier_nonarray_isampler1d_t;
class type_specifier_nonarray_isampler2d_t;
class type_specifier_nonarray_isampler3d_t;
class type_specifier_nonarray_isamplercube_t;
class type_specifier_nonarray_isampler1darray_t;
class type_specifier_nonarray_isampler2darray_t;
class type_specifier_nonarray_isamplercubearray_t;
class type_specifier_nonarray_usampler1d_t;
class type_specifier_nonarray_usampler2d_t;
class type_specifier_nonarray_usampler3d_t;
class type_specifier_nonarray_usamplercube_t;
class type_specifier_nonarray_usampler1darray_t;
class type_specifier_nonarray_usampler2darray_t;
class type_specifier_nonarray_usamplercubearray_t;
class type_specifier_nonarray_sampler2drect_t;
class type_specifier_nonarray_sampler2drectshadow_t;
class type_specifier_nonarray_isampler2drect_t;
class type_specifier_nonarray_usampler2drect_t;
class type_specifier_nonarray_samplerbuffer_t;
class type_specifier_nonarray_isamplerbuffer_t;
class type_specifier_nonarray_usamplerbuffer_t;
class type_specifier_nonarray_sampler2dms_t;
class type_specifier_nonarray_isampler2dms_t;
class type_specifier_nonarray_usampler2dms_t;
class type_specifier_nonarray_sampler2dmsarray_t;
class type_specifier_nonarray_isampler2dmsarray_t;
class type_specifier_nonarray_usampler2dmsarray_t;
class type_specifier_nonarray_image1d_t;
class type_specifier_nonarray_iimage1d_t;
class type_specifier_nonarray_uimage1d_t;
class type_specifier_nonarray_image2d_t;
class type_specifier_nonarray_iimage2d_t;
class type_specifier_nonarray_uimage2d_t;
class type_specifier_nonarray_image3d_t;
class type_specifier_nonarray_iimage3d_t;
class type_specifier_nonarray_uimage3d_t;
class type_specifier_nonarray_image2drect_t;
class type_specifier_nonarray_iimage2drect_t;
class type_specifier_nonarray_uimage2drect_t;
class type_specifier_nonarray_imagecube_t;
class type_specifier_nonarray_iimagecube_t;
class type_specifier_nonarray_uimagecube_t;
class type_specifier_nonarray_imagebuffer_t;
class type_specifier_nonarray_iimagebuffer_t;
class type_specifier_nonarray_uimagebuffer_t;
class type_specifier_nonarray_image1darray_t;
class type_specifier_nonarray_iimage1darray_t;
class type_specifier_nonarray_uimage1darray_t;
class type_specifier_nonarray_image2darray_t;
class type_specifier_nonarray_iimage2darray_t;
class type_specifier_nonarray_uimage2darray_t;
class type_specifier_nonarray_imagecubearray_t;
class type_specifier_nonarray_iimagecubearray_t;
class type_specifier_nonarray_uimagecubearray_t;
class type_specifier_nonarray_image2dms_t;
class type_specifier_nonarray_iimage2dms_t;
class type_specifier_nonarray_uimage2dms_t;
class type_specifier_nonarray_image2dmsarray_t;
class type_specifier_nonarray_iimage2dmsarray_t;
class type_specifier_nonarray_uimage2dmsarray_t;
class type_specifier_nonarray_struct_specifier_t;
class type_specifier_nonarray_type_name_t;
class precision_qualifier_high_precision_t;
class precision_qualifier_medium_precision_t;
class precision_qualifier_low_precision_t;
class struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t;
class struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t;
class struct_declaration_list_struct_declaration_t;
class struct_declaration_list_struct_declaration_list_struct_declaration_t;
class struct_declaration_type_specifier_struct_declarator_list_semicolon_t;
class struct_declaration_type_qualifier_type_specifier_struct_declarator_list_semicolon_t;
class struct_declarator_list_struct_declarator_t;
class struct_declarator_list_struct_declarator_list_comma_struct_declarator_t;
class struct_declarator_identifier_t;
class struct_declarator_identifier_array_specifier_t;
class initializer_assignment_expression_t;
class initializer_left_brace_initializer_list_right_brace_t;
class initializer_left_brace_initializer_list_comma_right_brace_t;
class initializer_list_initializer_t;
class initializer_list_initializer_list_comma_initializer_t;
class declaration_statement_declaration_t;
class statement_compound_statement_t;
class statement_simple_statement_t;
class simple_statement_declaration_statement_t;
class simple_statement_expression_statement_t;
class simple_statement_selection_statement_t;
class simple_statement_switch_statement_t;
class simple_statement_case_label_t;
class simple_statement_iteration_statement_t;
class simple_statement_jump_statement_t;
class compound_statement_left_brace_right_brace_t;
class compound_statement_left_brace_statement_list_right_brace_t;
class statement_no_new_scope_compound_statement_no_new_scope_t;
class statement_no_new_scope_simple_statement_t;
class compound_statement_no_new_scope_left_brace_right_brace_t;
class compound_statement_no_new_scope_left_brace_statement_list_right_brace_t;
class statement_list_statement_t;
class statement_list_statement_list_statement_t;
class expression_statement_semicolon_t;
class expression_statement_expression_semicolon_t;
class selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t;
class selection_rest_statement_statement_else_statement_t;
class selection_rest_statement_statement_t;
class condition_expression_t;
class condition_fully_specified_type_identifier_equal_initializer_t;
class switch_statement_switch_left_paren_expression_right_paren_left_brace_switch_statement_list_right_brace_t;
class switch_statement_list_nothing_t;
class switch_statement_list_statement_list_t;
class case_label_case_expression_colon_t;
class case_label_default_colon_t;
class iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t;
class iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t;
class iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t;
class for_init_statement_expression_statement_t;
class for_init_statement_declaration_statement_t;
class conditionopt_condition_t;
class conditionopt_nothing_t;
class for_rest_statement_conditionopt_semicolon_t;
class for_rest_statement_conditionopt_semicolon_expression_t;
class jump_statement_continue_semicolon_t;
class jump_statement_break_semicolon_t;
class jump_statement_return_semicolon_t;
class jump_statement_return_expression_semicolon_t;
class jump_statement_discard_semicolon_t;
class translation_unit_external_declaration_t;
class translation_unit_translation_unit_external_declaration_t;
class external_declaration_function_definition_t;
class external_declaration_declaration_t;
class external_declaration_semicolon_t;
class function_definition_function_prototype_compound_statement_no_new_scope_t;
class ast_t;

struct empty_visitor_t {
  virtual ~empty_visitor_t() = default;
};  // empty_visitor_t

struct default_visitor_t: public empty_visitor_t {
  virtual ~default_visitor_t() = default;
  virtual void operator()(const variable_identifier_identifier_t *) const = 0;
  virtual void operator()(const primary_expression_variable_identifier_t *) const = 0;
  virtual void operator()(const primary_expression_intconstant_t *) const = 0;
  virtual void operator()(const primary_expression_uintconstant_t *) const = 0;
  virtual void operator()(const primary_expression_floatconstant_t *) const = 0;
  virtual void operator()(const primary_expression_boolconstant_t *) const = 0;
  virtual void operator()(const primary_expression_doubleconstant_t *) const = 0;
  virtual void operator()(const primary_expression_left_paren_expression_right_paren_t *) const = 0;
  virtual void operator()(const postfix_expression_primary_expression_t *) const = 0;
  virtual void operator()(const postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t *) const = 0;
  virtual void operator()(const postfix_expression_function_call_t *) const = 0;
  virtual void operator()(const postfix_expression_postfix_expression_dot_field_selection_t *) const = 0;
  virtual void operator()(const postfix_expression_postfix_expression_inc_op_t *) const = 0;
  virtual void operator()(const postfix_expression_postfix_expression_dec_op_t *) const = 0;
  virtual void operator()(const integer_expression_expression_t *) const = 0;
  virtual void operator()(const function_call_function_call_or_method_t *) const = 0;
  virtual void operator()(const function_call_or_method_function_call_generic_t *) const = 0;
  virtual void operator()(const function_call_generic_function_call_header_with_parameters_right_paren_t *) const = 0;
  virtual void operator()(const function_call_generic_function_call_header_no_parameters_right_paren_t *) const = 0;
  virtual void operator()(const function_call_header_no_parameters_function_call_header_void_t *) const = 0;
  virtual void operator()(const function_call_header_no_parameters_function_call_header_t *) const = 0;
  virtual void operator()(const function_call_header_with_parameters_function_call_header_assignment_expression_t *) const = 0;
  virtual void operator()(const function_call_header_with_parameters_function_call_header_with_parameters_comma_assignment_expression_t *) const = 0;
  virtual void operator()(const function_call_header_function_identifier_left_paren_t *) const = 0;
  virtual void operator()(const function_identifier_type_specifier_t *) const = 0;
  virtual void operator()(const function_identifier_postfix_expression_t *) const = 0;
  virtual void operator()(const unary_expression_postfix_expression_t *) const = 0;
  virtual void operator()(const unary_expression_inc_op_unary_expression_t *) const = 0;
  virtual void operator()(const unary_expression_dec_op_unary_expression_t *) const = 0;
  virtual void operator()(const unary_expression_unary_operator_unary_expression_t *) const = 0;
  virtual void operator()(const unary_operator_plus_t *) const = 0;
  virtual void operator()(const unary_operator_dash_t *) const = 0;
  virtual void operator()(const unary_operator_bang_t *) const = 0;
  virtual void operator()(const unary_operator_tilde_t *) const = 0;
  virtual void operator()(const multiplicative_expression_unary_expression_t *) const = 0;
  virtual void operator()(const multiplicative_expression_multiplicative_expression_star_unary_expression_t *) const = 0;
  virtual void operator()(const multiplicative_expression_multiplicative_expression_slash_unary_expression_t *) const = 0;
  virtual void operator()(const multiplicative_expression_multiplicative_expression_percent_unary_expression_t *) const = 0;
  virtual void operator()(const additive_expression_multiplicative_expression_t *) const = 0;
  virtual void operator()(const additive_expression_additive_expression_plus_multiplicative_expression_t *) const = 0;
  virtual void operator()(const additive_expression_additive_expression_dash_multiplicative_expression_t *) const = 0;
  virtual void operator()(const shift_expression_additive_expression_t *) const = 0;
  virtual void operator()(const shift_expression_shift_expression_left_op_additive_expression_t *) const = 0;
  virtual void operator()(const shift_expression_shift_expression_right_op_additive_expression_t *) const = 0;
  virtual void operator()(const relational_expression_shift_expression_t *) const = 0;
  virtual void operator()(const relational_expression_relational_expression_left_angle_shift_expression_t *) const = 0;
  virtual void operator()(const relational_expression_relational_expression_right_angle_shift_expression_t *) const = 0;
  virtual void operator()(const relational_expression_relational_expression_le_op_shift_expression_t *) const = 0;
  virtual void operator()(const relational_expression_relational_expression_ge_op_shift_expression_t *) const = 0;
  virtual void operator()(const equality_expression_relational_expression_t *) const = 0;
  virtual void operator()(const equality_expression_equality_expression_eq_op_relational_expression_t *) const = 0;
  virtual void operator()(const equality_expression_equality_expression_ne_op_relational_expression_t *) const = 0;
  virtual void operator()(const and_expression_equality_expression_t *) const = 0;
  virtual void operator()(const and_expression_and_expression_ampersand_equality_expression_t *) const = 0;
  virtual void operator()(const exclusive_or_expression_and_expression_t *) const = 0;
  virtual void operator()(const exclusive_or_expression_exclusive_or_expression_caret_and_expression_t *) const = 0;
  virtual void operator()(const inclusive_or_expression_exclusive_or_expression_t *) const = 0;
  virtual void operator()(const inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t *) const = 0;
  virtual void operator()(const logical_and_expression_inclusive_or_expression_t *) const = 0;
  virtual void operator()(const logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t *) const = 0;
  virtual void operator()(const logical_xor_expression_logical_and_expression_t *) const = 0;
  virtual void operator()(const logical_xor_expression_logical_xor_expression_xor_op_logical_and_expression_t *) const = 0;
  virtual void operator()(const logical_or_expression_logical_xor_expression_t *) const = 0;
  virtual void operator()(const logical_or_expression_logical_or_expression_or_op_logical_xor_expression_t *) const = 0;
  virtual void operator()(const conditional_expression_logical_or_expression_t *) const = 0;
  virtual void operator()(const conditional_expression_logical_or_expression_question_expression_colon_assignment_expression_t *) const = 0;
  virtual void operator()(const assignment_expression_conditional_expression_t *) const = 0;
  virtual void operator()(const assignment_expression_unary_expression_assignment_operator_assignment_expression_t *) const = 0;
  virtual void operator()(const assignment_operator_equal_t *) const = 0;
  virtual void operator()(const assignment_operator_mul_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_div_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_mod_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_add_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_sub_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_left_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_right_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_and_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_xor_assign_t *) const = 0;
  virtual void operator()(const assignment_operator_or_assign_t *) const = 0;
  virtual void operator()(const expression_assignment_expression_t *) const = 0;
  virtual void operator()(const expression_expression_comma_assignment_expression_t *) const = 0;
  virtual void operator()(const constant_expression_conditional_expression_t *) const = 0;
  virtual void operator()(const declaration_function_prototype_semicolon_t *) const = 0;
  virtual void operator()(const declaration_init_declarator_list_semicolon_t *) const = 0;
  virtual void operator()(const declaration_precision_precision_qualifier_type_specifier_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_identifier_semicolon_t *) const = 0;
  virtual void operator()(const declaration_type_qualifier_identifier_identifier_list_semicolon_t *) const = 0;
  virtual void operator()(const identifier_list_comma_identifier_t *) const = 0;
  virtual void operator()(const identifier_list_identifier_list_comma_identifier_t *) const = 0;
  virtual void operator()(const function_prototype_function_declarator_right_paren_t *) const = 0;
  virtual void operator()(const function_declarator_function_header_t *) const = 0;
  virtual void operator()(const function_declarator_function_header_with_parameters_t *) const = 0;
  virtual void operator()(const function_header_with_parameters_function_header_parameter_declaration_t *) const = 0;
  virtual void operator()(const function_header_with_parameters_function_header_with_parameters_comma_parameter_declaration_t *) const = 0;
  virtual void operator()(const function_header_fully_specified_type_identifier_left_paren_t *) const = 0;
  virtual void operator()(const parameter_declarator_type_specifier_identifier_t *) const = 0;
  virtual void operator()(const parameter_declarator_type_specifier_identifier_array_specifier_t *) const = 0;
  virtual void operator()(const parameter_declaration_type_qualifier_parameter_declarator_t *) const = 0;
  virtual void operator()(const parameter_declaration_parameter_declarator_t *) const = 0;
  virtual void operator()(const parameter_declaration_type_qualifier_parameter_type_specifier_t *) const = 0;
  virtual void operator()(const parameter_declaration_parameter_type_specifier_t *) const = 0;
  virtual void operator()(const parameter_type_specifier_type_specifier_t *) const = 0;
  virtual void operator()(const init_declarator_list_single_declaration_t *) const = 0;
  virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_t *) const = 0;
  virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t *) const = 0;
  virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t *) const = 0;
  virtual void operator()(const init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t *) const = 0;
  virtual void operator()(const single_declaration_fully_specified_type_t *) const = 0;
  virtual void operator()(const single_declaration_fully_specified_type_identifier_t *) const = 0;
  virtual void operator()(const single_declaration_fully_specified_type_identifier_array_specifier_t *) const = 0;
  virtual void operator()(const single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t *) const = 0;
  virtual void operator()(const single_declaration_fully_specified_type_identifier_equal_initializer_t *) const = 0;
  virtual void operator()(const fully_specified_type_type_specifier_t *) const = 0;
  virtual void operator()(const fully_specified_type_type_qualifier_type_specifier_t *) const = 0;
  virtual void operator()(const invariant_qualifier_invariant_t *) const = 0;
  virtual void operator()(const interpolation_qualifier_smooth_t *) const = 0;
  virtual void operator()(const interpolation_qualifier_flat_t *) const = 0;
  virtual void operator()(const interpolation_qualifier_noperspective_t *) const = 0;
  virtual void operator()(const layout_qualifier_layout_left_paren_layout_qualifier_id_list_right_paren_t *) const = 0;
  virtual void operator()(const layout_qualifier_id_list_layout_qualifier_id_t *) const = 0;
  virtual void operator()(const layout_qualifier_id_list_layout_qualifier_id_list_comma_layout_qualifier_id_t *) const = 0;
  virtual void operator()(const layout_qualifier_id_identifier_t *) const = 0;
  virtual void operator()(const layout_qualifier_id_identifier_equal_constant_expression_t *) const = 0;
  virtual void operator()(const layout_qualifier_id_shared_t *) const = 0;
  virtual void operator()(const precise_qualifier_precise_t *) const = 0;
  virtual void operator()(const type_qualifier_single_type_qualifier_t *) const = 0;
  virtual void operator()(const type_qualifier_type_qualifier_single_type_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_storage_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_layout_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_precision_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_interpolation_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_invariant_qualifier_t *) const = 0;
  virtual void operator()(const single_type_qualifier_precise_qualifier_t *) const = 0;
  virtual void operator()(const storage_qualifier_const_t *) const = 0;
  virtual void operator()(const storage_qualifier_inout_t *) const = 0;
  virtual void operator()(const storage_qualifier_in_t *) const = 0;
  virtual void operator()(const storage_qualifier_out_t *) const = 0;
  virtual void operator()(const storage_qualifier_centroid_t *) const = 0;
  virtual void operator()(const storage_qualifier_patch_t *) const = 0;
  virtual void operator()(const storage_qualifier_sample_t *) const = 0;
  virtual void operator()(const storage_qualifier_uniform_t *) const = 0;
  virtual void operator()(const storage_qualifier_buffer_t *) const = 0;
  virtual void operator()(const storage_qualifier_shared_t *) const = 0;
  virtual void operator()(const storage_qualifier_coherent_t *) const = 0;
  virtual void operator()(const storage_qualifier_volatile_t *) const = 0;
  virtual void operator()(const storage_qualifier_restrict_t *) const = 0;
  virtual void operator()(const storage_qualifier_readonly_t *) const = 0;
  virtual void operator()(const storage_qualifier_writeonly_t *) const = 0;
  virtual void operator()(const storage_qualifier_subroutine_t *) const = 0;
  virtual void operator()(const storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t *) const = 0;
  virtual void operator()(const type_name_list_type_name_t *) const = 0;
  virtual void operator()(const type_name_list_type_name_list_comma_type_name_t *) const = 0;
  virtual void operator()(const type_specifier_type_specifier_nonarray_t *) const = 0;
  virtual void operator()(const type_specifier_type_specifier_nonarray_array_specifier_t *) const = 0;
  virtual void operator()(const array_specifier_left_bracket_right_bracket_t *) const = 0;
  virtual void operator()(const array_specifier_left_bracket_conditional_expression_right_bracket_t *) const = 0;
  virtual void operator()(const array_specifier_array_specifier_left_bracket_right_bracket_t *) const = 0;
  virtual void operator()(const array_specifier_array_specifier_left_bracket_conditional_expression_right_bracket_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_void_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_float_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_double_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_int_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uint_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_bool_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_vec2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_vec3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_vec4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dvec2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dvec3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dvec4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_bvec2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_bvec3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_bvec4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_ivec2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_ivec3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_ivec4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uvec2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uvec3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uvec4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat2x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat2x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat2x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat3x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat3x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat3x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat4x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat4x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_mat4x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat2x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat2x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat2x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat3x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat3x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat3x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat4x2_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat4x3_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_dmat4x4_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_atomic_uint_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_samplercube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler1dshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2dshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_samplercubeshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler1darrayshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2darrayshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_samplercubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_samplercubearrayshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isamplercube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isamplercubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usamplercube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usamplercubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2drectshadow_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_samplerbuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isamplerbuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usamplerbuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_sampler2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_isampler2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_usampler2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage1d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage2d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage3d_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage2drect_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_imagecube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimagecube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimagecube_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_imagebuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimagebuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimagebuffer_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage1darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage2darray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_imagecubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimagecubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimagecubearray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage2dms_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_image2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_iimage2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_uimage2dmsarray_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_struct_specifier_t *) const = 0;
  virtual void operator()(const type_specifier_nonarray_type_name_t *) const = 0;
  virtual void operator()(const precision_qualifier_high_precision_t *) const = 0;
  virtual void operator()(const precision_qualifier_medium_precision_t *) const = 0;
  virtual void operator()(const precision_qualifier_low_precision_t *) const = 0;
  virtual void operator()(const struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t *) const = 0;
  virtual void operator()(const struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t *) const = 0;
  virtual void operator()(const struct_declaration_list_struct_declaration_t *) const = 0;
  virtual void operator()(const struct_declaration_list_struct_declaration_list_struct_declaration_t *) const = 0;
  virtual void operator()(const struct_declaration_type_specifier_struct_declarator_list_semicolon_t *) const = 0;
  virtual void operator()(const struct_declaration_type_qualifier_type_specifier_struct_declarator_list_semicolon_t *) const = 0;
  virtual void operator()(const struct_declarator_list_struct_declarator_t *) const = 0;
  virtual void operator()(const struct_declarator_list_struct_declarator_list_comma_struct_declarator_t *) const = 0;
  virtual void operator()(const struct_declarator_identifier_t *) const = 0;
  virtual void operator()(const struct_declarator_identifier_array_specifier_t *) const = 0;
  virtual void operator()(const initializer_assignment_expression_t *) const = 0;
  virtual void operator()(const initializer_left_brace_initializer_list_right_brace_t *) const = 0;
  virtual void operator()(const initializer_left_brace_initializer_list_comma_right_brace_t *) const = 0;
  virtual void operator()(const initializer_list_initializer_t *) const = 0;
  virtual void operator()(const initializer_list_initializer_list_comma_initializer_t *) const = 0;
  virtual void operator()(const declaration_statement_declaration_t *) const = 0;
  virtual void operator()(const statement_compound_statement_t *) const = 0;
  virtual void operator()(const statement_simple_statement_t *) const = 0;
  virtual void operator()(const simple_statement_declaration_statement_t *) const = 0;
  virtual void operator()(const simple_statement_expression_statement_t *) const = 0;
  virtual void operator()(const simple_statement_selection_statement_t *) const = 0;
  virtual void operator()(const simple_statement_switch_statement_t *) const = 0;
  virtual void operator()(const simple_statement_case_label_t *) const = 0;
  virtual void operator()(const simple_statement_iteration_statement_t *) const = 0;
  virtual void operator()(const simple_statement_jump_statement_t *) const = 0;
  virtual void operator()(const compound_statement_left_brace_right_brace_t *) const = 0;
  virtual void operator()(const compound_statement_left_brace_statement_list_right_brace_t *) const = 0;
  virtual void operator()(const statement_no_new_scope_compound_statement_no_new_scope_t *) const = 0;
  virtual void operator()(const statement_no_new_scope_simple_statement_t *) const = 0;
  virtual void operator()(const compound_statement_no_new_scope_left_brace_right_brace_t *) const = 0;
  virtual void operator()(const compound_statement_no_new_scope_left_brace_statement_list_right_brace_t *) const = 0;
  virtual void operator()(const statement_list_statement_t *) const = 0;
  virtual void operator()(const statement_list_statement_list_statement_t *) const = 0;
  virtual void operator()(const expression_statement_semicolon_t *) const = 0;
  virtual void operator()(const expression_statement_expression_semicolon_t *) const = 0;
  virtual void operator()(const selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t *) const = 0;
  virtual void operator()(const selection_rest_statement_statement_else_statement_t *) const = 0;
  virtual void operator()(const selection_rest_statement_statement_t *) const = 0;
  virtual void operator()(const condition_expression_t *) const = 0;
  virtual void operator()(const condition_fully_specified_type_identifier_equal_initializer_t *) const = 0;
  virtual void operator()(const switch_statement_switch_left_paren_expression_right_paren_left_brace_switch_statement_list_right_brace_t *) const = 0;
  virtual void operator()(const switch_statement_list_nothing_t *) const = 0;
  virtual void operator()(const switch_statement_list_statement_list_t *) const = 0;
  virtual void operator()(const case_label_case_expression_colon_t *) const = 0;
  virtual void operator()(const case_label_default_colon_t *) const = 0;
  virtual void operator()(const iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t *) const = 0;
  virtual void operator()(const iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t *) const = 0;
  virtual void operator()(const iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t *) const = 0;
  virtual void operator()(const for_init_statement_expression_statement_t *) const = 0;
  virtual void operator()(const for_init_statement_declaration_statement_t *) const = 0;
  virtual void operator()(const conditionopt_condition_t *) const = 0;
  virtual void operator()(const conditionopt_nothing_t *) const = 0;
  virtual void operator()(const for_rest_statement_conditionopt_semicolon_t *) const = 0;
  virtual void operator()(const for_rest_statement_conditionopt_semicolon_expression_t *) const = 0;
  virtual void operator()(const jump_statement_continue_semicolon_t *) const = 0;
  virtual void operator()(const jump_statement_break_semicolon_t *) const = 0;
  virtual void operator()(const jump_statement_return_semicolon_t *) const = 0;
  virtual void operator()(const jump_statement_return_expression_semicolon_t *) const = 0;
  virtual void operator()(const jump_statement_discard_semicolon_t *) const = 0;
  virtual void operator()(const translation_unit_external_declaration_t *) const = 0;
  virtual void operator()(const translation_unit_translation_unit_external_declaration_t *) const = 0;
  virtual void operator()(const external_declaration_function_definition_t *) const = 0;
  virtual void operator()(const external_declaration_declaration_t *) const = 0;
  virtual void operator()(const external_declaration_semicolon_t *) const = 0;
  virtual void operator()(const function_definition_function_prototype_compound_statement_no_new_scope_t *) const = 0;
};  // default_visitor_t

template <int N>
struct reductions_from_t;

template <int N>
struct ast_by_id;

  template <>
  struct ast_by_id<211> {
    using type_t = type_specifier_nonarray_bvec3_t;
  };
  template <>
  struct ast_by_id<212> {
    using type_t = variable_identifier_identifier_t;
  };
  template <>
  struct ast_by_id<213> {
    using type_t = primary_expression_intconstant_t;
  };
  template <>
  struct ast_by_id<214> {
    using type_t = primary_expression_uintconstant_t;
  };
  template <>
  struct ast_by_id<215> {
    using type_t = primary_expression_floatconstant_t;
  };
  template <>
  struct ast_by_id<216> {
    using type_t = primary_expression_boolconstant_t;
  };
  template <>
  struct ast_by_id<217> {
    using type_t = primary_expression_doubleconstant_t;
  };
  template <>
  struct ast_by_id<218> {
    using type_t = external_declaration_semicolon_t;
  };
  template <>
  struct ast_by_id<219> {
    using type_t = postfix_expression_primary_expression_t;
  };
  template <>
  struct ast_by_id<220> {
    using type_t = external_declaration_declaration_t;
  };
  template <>
  struct ast_by_id<221> {
    using type_t = postfix_expression_function_call_t;
  };
  template <>
  struct ast_by_id<222> {
    using type_t = external_declaration_function_definition_t;
  };
  template <>
  struct ast_by_id<223> {
    using type_t = translation_unit_external_declaration_t;
  };
  template <>
  struct ast_by_id<224> {
    using type_t = conditionopt_nothing_t;
  };
  template <>
  struct ast_by_id<225> {
    using type_t = integer_expression_expression_t;
  };
  template <>
  struct ast_by_id<226> {
    using type_t = function_call_function_call_or_method_t;
  };
  template <>
  struct ast_by_id<227> {
    using type_t = function_call_or_method_function_call_generic_t;
  };
  template <>
  struct ast_by_id<228> {
    using type_t = conditionopt_condition_t;
  };
  template <>
  struct ast_by_id<229> {
    using type_t = for_init_statement_declaration_statement_t;
  };
  template <>
  struct ast_by_id<230> {
    using type_t = for_init_statement_expression_statement_t;
  };
  template <>
  struct ast_by_id<231> {
    using type_t = function_call_header_no_parameters_function_call_header_t;
  };
  template <>
  struct ast_by_id<232> {
    using type_t = switch_statement_list_statement_list_t;
  };
  template <>
  struct ast_by_id<233> {
    using type_t = switch_statement_list_nothing_t;
  };
  template <>
  struct ast_by_id<234> {
    using type_t = condition_expression_t;
  };
  template <>
  struct ast_by_id<235> {
    using type_t = function_identifier_type_specifier_t;
  };
  template <>
  struct ast_by_id<236> {
    using type_t = function_identifier_postfix_expression_t;
  };
  template <>
  struct ast_by_id<237> {
    using type_t = unary_expression_postfix_expression_t;
  };
  template <>
  struct ast_by_id<238> {
    using type_t = selection_rest_statement_statement_t;
  };
  template <>
  struct ast_by_id<239> {
    using type_t = expression_statement_semicolon_t;
  };
  template <>
  struct ast_by_id<240> {
    using type_t = statement_list_statement_t;
  };
  template <>
  struct ast_by_id<241> {
    using type_t = unary_operator_plus_t;
  };
  template <>
  struct ast_by_id<242> {
    using type_t = unary_operator_dash_t;
  };
  template <>
  struct ast_by_id<243> {
    using type_t = unary_operator_bang_t;
  };
  template <>
  struct ast_by_id<244> {
    using type_t = unary_operator_tilde_t;
  };
  template <>
  struct ast_by_id<245> {
    using type_t = multiplicative_expression_unary_expression_t;
  };
  template <>
  struct ast_by_id<246> {
    using type_t = statement_no_new_scope_simple_statement_t;
  };
  template <>
  struct ast_by_id<247> {
    using type_t = statement_no_new_scope_compound_statement_no_new_scope_t;
  };
  template <>
  struct ast_by_id<248> {
    using type_t = simple_statement_jump_statement_t;
  };
  template <>
  struct ast_by_id<249> {
    using type_t = additive_expression_multiplicative_expression_t;
  };
  template <>
  struct ast_by_id<250> {
    using type_t = simple_statement_iteration_statement_t;
  };
  template <>
  struct ast_by_id<251> {
    using type_t = simple_statement_case_label_t;
  };
  template <>
  struct ast_by_id<252> {
    using type_t = shift_expression_additive_expression_t;
  };
  template <>
  struct ast_by_id<253> {
    using type_t = simple_statement_switch_statement_t;
  };
  template <>
  struct ast_by_id<254> {
    using type_t = simple_statement_selection_statement_t;
  };
  template <>
  struct ast_by_id<255> {
    using type_t = relational_expression_shift_expression_t;
  };
  template <>
  struct ast_by_id<256> {
    using type_t = simple_statement_expression_statement_t;
  };
  template <>
  struct ast_by_id<257> {
    using type_t = simple_statement_declaration_statement_t;
  };
  template <>
  struct ast_by_id<258> {
    using type_t = statement_simple_statement_t;
  };
  template <>
  struct ast_by_id<259> {
    using type_t = statement_compound_statement_t;
  };
  template <>
  struct ast_by_id<260> {
    using type_t = equality_expression_relational_expression_t;
  };
  template <>
  struct ast_by_id<261> {
    using type_t = declaration_statement_declaration_t;
  };
  template <>
  struct ast_by_id<262> {
    using type_t = initializer_list_initializer_t;
  };
  template <>
  struct ast_by_id<263> {
    using type_t = and_expression_equality_expression_t;
  };
  template <>
  struct ast_by_id<264> {
    using type_t = initializer_assignment_expression_t;
  };
  template <>
  struct ast_by_id<265> {
    using type_t = exclusive_or_expression_and_expression_t;
  };
  template <>
  struct ast_by_id<266> {
    using type_t = struct_declarator_identifier_t;
  };
  template <>
  struct ast_by_id<267> {
    using type_t = inclusive_or_expression_exclusive_or_expression_t;
  };
  template <>
  struct ast_by_id<268> {
    using type_t = struct_declarator_list_struct_declarator_t;
  };
  template <>
  struct ast_by_id<269> {
    using type_t = logical_and_expression_inclusive_or_expression_t;
  };
  template <>
  struct ast_by_id<270> {
    using type_t = struct_declaration_list_struct_declaration_t;
  };
  template <>
  struct ast_by_id<271> {
    using type_t = logical_xor_expression_logical_and_expression_t;
  };
  template <>
  struct ast_by_id<272> {
    using type_t = precision_qualifier_low_precision_t;
  };
  template <>
  struct ast_by_id<273> {
    using type_t = logical_or_expression_logical_xor_expression_t;
  };
  template <>
  struct ast_by_id<274> {
    using type_t = precision_qualifier_medium_precision_t;
  };
  template <>
  struct ast_by_id<275> {
    using type_t = conditional_expression_logical_or_expression_t;
  };
  template <>
  struct ast_by_id<276> {
    using type_t = precision_qualifier_high_precision_t;
  };
  template <>
  struct ast_by_id<277> {
    using type_t = assignment_expression_conditional_expression_t;
  };
  template <>
  struct ast_by_id<278> {
    using type_t = type_specifier_nonarray_type_name_t;
  };
  template <>
  struct ast_by_id<279> {
    using type_t = assignment_operator_equal_t;
  };
  template <>
  struct ast_by_id<280> {
    using type_t = assignment_operator_mul_assign_t;
  };
  template <>
  struct ast_by_id<281> {
    using type_t = assignment_operator_div_assign_t;
  };
  template <>
  struct ast_by_id<282> {
    using type_t = assignment_operator_mod_assign_t;
  };
  template <>
  struct ast_by_id<283> {
    using type_t = assignment_operator_add_assign_t;
  };
  template <>
  struct ast_by_id<284> {
    using type_t = assignment_operator_sub_assign_t;
  };
  template <>
  struct ast_by_id<285> {
    using type_t = assignment_operator_left_assign_t;
  };
  template <>
  struct ast_by_id<286> {
    using type_t = assignment_operator_right_assign_t;
  };
  template <>
  struct ast_by_id<287> {
    using type_t = assignment_operator_and_assign_t;
  };
  template <>
  struct ast_by_id<288> {
    using type_t = assignment_operator_xor_assign_t;
  };
  template <>
  struct ast_by_id<289> {
    using type_t = assignment_operator_or_assign_t;
  };
  template <>
  struct ast_by_id<290> {
    using type_t = expression_assignment_expression_t;
  };
  template <>
  struct ast_by_id<291> {
    using type_t = type_specifier_nonarray_struct_specifier_t;
  };
  template <>
  struct ast_by_id<292> {
    using type_t = constant_expression_conditional_expression_t;
  };
  template <>
  struct ast_by_id<293> {
    using type_t = type_specifier_nonarray_uimage2dmsarray_t;
  };
  template <>
  struct ast_by_id<294> {
    using type_t = type_specifier_nonarray_iimage2dmsarray_t;
  };
  template <>
  struct ast_by_id<295> {
    using type_t = type_specifier_nonarray_image2dmsarray_t;
  };
  template <>
  struct ast_by_id<296> {
    using type_t = type_specifier_nonarray_uimage2dms_t;
  };
  template <>
  struct ast_by_id<297> {
    using type_t = type_specifier_nonarray_iimage2dms_t;
  };
  template <>
  struct ast_by_id<298> {
    using type_t = type_specifier_nonarray_image2dms_t;
  };
  template <>
  struct ast_by_id<299> {
    using type_t = type_specifier_nonarray_uimagecubearray_t;
  };
  template <>
  struct ast_by_id<300> {
    using type_t = type_specifier_nonarray_iimagecubearray_t;
  };
  template <>
  struct ast_by_id<301> {
    using type_t = type_specifier_nonarray_imagecubearray_t;
  };
  template <>
  struct ast_by_id<302> {
    using type_t = type_specifier_nonarray_uimage2darray_t;
  };
  template <>
  struct ast_by_id<303> {
    using type_t = type_specifier_nonarray_iimage2darray_t;
  };
  template <>
  struct ast_by_id<304> {
    using type_t = type_specifier_nonarray_image2darray_t;
  };
  template <>
  struct ast_by_id<305> {
    using type_t = function_declarator_function_header_t;
  };
  template <>
  struct ast_by_id<306> {
    using type_t = function_declarator_function_header_with_parameters_t;
  };
  template <>
  struct ast_by_id<307> {
    using type_t = type_specifier_nonarray_uimage1darray_t;
  };
  template <>
  struct ast_by_id<308> {
    using type_t = type_specifier_nonarray_iimage1darray_t;
  };
  template <>
  struct ast_by_id<309> {
    using type_t = type_specifier_nonarray_image1darray_t;
  };
  template <>
  struct ast_by_id<310> {
    using type_t = type_specifier_nonarray_uimagebuffer_t;
  };
  template <>
  struct ast_by_id<311> {
    using type_t = type_specifier_nonarray_iimagebuffer_t;
  };
  template <>
  struct ast_by_id<312> {
    using type_t = type_specifier_nonarray_imagebuffer_t;
  };
  template <>
  struct ast_by_id<313> {
    using type_t = parameter_declaration_parameter_declarator_t;
  };
  template <>
  struct ast_by_id<314> {
    using type_t = type_specifier_nonarray_uimagecube_t;
  };
  template <>
  struct ast_by_id<315> {
    using type_t = parameter_declaration_parameter_type_specifier_t;
  };
  template <>
  struct ast_by_id<316> {
    using type_t = parameter_type_specifier_type_specifier_t;
  };
  template <>
  struct ast_by_id<317> {
    using type_t = init_declarator_list_single_declaration_t;
  };
  template <>
  struct ast_by_id<318> {
    using type_t = type_specifier_nonarray_iimagecube_t;
  };
  template <>
  struct ast_by_id<319> {
    using type_t = type_specifier_nonarray_imagecube_t;
  };
  template <>
  struct ast_by_id<320> {
    using type_t = type_specifier_nonarray_uimage2drect_t;
  };
  template <>
  struct ast_by_id<321> {
    using type_t = type_specifier_nonarray_iimage2drect_t;
  };
  template <>
  struct ast_by_id<322> {
    using type_t = single_declaration_fully_specified_type_t;
  };
  template <>
  struct ast_by_id<323> {
    using type_t = type_specifier_nonarray_image2drect_t;
  };
  template <>
  struct ast_by_id<324> {
    using type_t = type_specifier_nonarray_uimage3d_t;
  };
  template <>
  struct ast_by_id<325> {
    using type_t = type_specifier_nonarray_iimage3d_t;
  };
  template <>
  struct ast_by_id<326> {
    using type_t = type_specifier_nonarray_image3d_t;
  };
  template <>
  struct ast_by_id<327> {
    using type_t = fully_specified_type_type_specifier_t;
  };
  template <>
  struct ast_by_id<328> {
    using type_t = type_specifier_nonarray_uimage2d_t;
  };
  template <>
  struct ast_by_id<329> {
    using type_t = invariant_qualifier_invariant_t;
  };
  template <>
  struct ast_by_id<330> {
    using type_t = interpolation_qualifier_smooth_t;
  };
  template <>
  struct ast_by_id<331> {
    using type_t = interpolation_qualifier_flat_t;
  };
  template <>
  struct ast_by_id<332> {
    using type_t = interpolation_qualifier_noperspective_t;
  };
  template <>
  struct ast_by_id<333> {
    using type_t = type_specifier_nonarray_iimage2d_t;
  };
  template <>
  struct ast_by_id<334> {
    using type_t = layout_qualifier_id_list_layout_qualifier_id_t;
  };
  template <>
  struct ast_by_id<335> {
    using type_t = type_specifier_nonarray_image2d_t;
  };
  template <>
  struct ast_by_id<336> {
    using type_t = layout_qualifier_id_identifier_t;
  };
  template <>
  struct ast_by_id<337> {
    using type_t = type_specifier_nonarray_uimage1d_t;
  };
  template <>
  struct ast_by_id<338> {
    using type_t = layout_qualifier_id_shared_t;
  };
  template <>
  struct ast_by_id<339> {
    using type_t = precise_qualifier_precise_t;
  };
  template <>
  struct ast_by_id<340> {
    using type_t = type_qualifier_single_type_qualifier_t;
  };
  template <>
  struct ast_by_id<341> {
    using type_t = type_specifier_nonarray_iimage1d_t;
  };
  template <>
  struct ast_by_id<342> {
    using type_t = single_type_qualifier_storage_qualifier_t;
  };
  template <>
  struct ast_by_id<343> {
    using type_t = single_type_qualifier_layout_qualifier_t;
  };
  template <>
  struct ast_by_id<344> {
    using type_t = single_type_qualifier_precision_qualifier_t;
  };
  template <>
  struct ast_by_id<345> {
    using type_t = single_type_qualifier_interpolation_qualifier_t;
  };
  template <>
  struct ast_by_id<346> {
    using type_t = single_type_qualifier_invariant_qualifier_t;
  };
  template <>
  struct ast_by_id<347> {
    using type_t = single_type_qualifier_precise_qualifier_t;
  };
  template <>
  struct ast_by_id<348> {
    using type_t = storage_qualifier_const_t;
  };
  template <>
  struct ast_by_id<349> {
    using type_t = storage_qualifier_inout_t;
  };
  template <>
  struct ast_by_id<350> {
    using type_t = storage_qualifier_in_t;
  };
  template <>
  struct ast_by_id<351> {
    using type_t = storage_qualifier_out_t;
  };
  template <>
  struct ast_by_id<352> {
    using type_t = storage_qualifier_centroid_t;
  };
  template <>
  struct ast_by_id<353> {
    using type_t = storage_qualifier_patch_t;
  };
  template <>
  struct ast_by_id<354> {
    using type_t = storage_qualifier_sample_t;
  };
  template <>
  struct ast_by_id<355> {
    using type_t = storage_qualifier_uniform_t;
  };
  template <>
  struct ast_by_id<356> {
    using type_t = storage_qualifier_buffer_t;
  };
  template <>
  struct ast_by_id<357> {
    using type_t = storage_qualifier_shared_t;
  };
  template <>
  struct ast_by_id<358> {
    using type_t = storage_qualifier_coherent_t;
  };
  template <>
  struct ast_by_id<359> {
    using type_t = storage_qualifier_volatile_t;
  };
  template <>
  struct ast_by_id<360> {
    using type_t = storage_qualifier_restrict_t;
  };
  template <>
  struct ast_by_id<361> {
    using type_t = storage_qualifier_readonly_t;
  };
  template <>
  struct ast_by_id<362> {
    using type_t = storage_qualifier_writeonly_t;
  };
  template <>
  struct ast_by_id<363> {
    using type_t = storage_qualifier_subroutine_t;
  };
  template <>
  struct ast_by_id<364> {
    using type_t = type_specifier_nonarray_image1d_t;
  };
  template <>
  struct ast_by_id<365> {
    using type_t = type_name_list_type_name_t;
  };
  template <>
  struct ast_by_id<366> {
    using type_t = type_specifier_nonarray_usampler2dmsarray_t;
  };
  template <>
  struct ast_by_id<367> {
    using type_t = type_specifier_type_specifier_nonarray_t;
  };
  template <>
  struct ast_by_id<368> {
    using type_t = type_specifier_nonarray_isampler2dmsarray_t;
  };
  template <>
  struct ast_by_id<369> {
    using type_t = type_specifier_nonarray_sampler2dmsarray_t;
  };
  template <>
  struct ast_by_id<370> {
    using type_t = type_specifier_nonarray_usampler2dms_t;
  };
  template <>
  struct ast_by_id<371> {
    using type_t = type_specifier_nonarray_isampler2dms_t;
  };
  template <>
  struct ast_by_id<372> {
    using type_t = type_specifier_nonarray_sampler2dms_t;
  };
  template <>
  struct ast_by_id<373> {
    using type_t = type_specifier_nonarray_void_t;
  };
  template <>
  struct ast_by_id<374> {
    using type_t = type_specifier_nonarray_float_t;
  };
  template <>
  struct ast_by_id<375> {
    using type_t = type_specifier_nonarray_double_t;
  };
  template <>
  struct ast_by_id<376> {
    using type_t = type_specifier_nonarray_int_t;
  };
  template <>
  struct ast_by_id<377> {
    using type_t = type_specifier_nonarray_uint_t;
  };
  template <>
  struct ast_by_id<378> {
    using type_t = type_specifier_nonarray_bool_t;
  };
  template <>
  struct ast_by_id<379> {
    using type_t = type_specifier_nonarray_vec2_t;
  };
  template <>
  struct ast_by_id<380> {
    using type_t = type_specifier_nonarray_vec3_t;
  };
  template <>
  struct ast_by_id<381> {
    using type_t = type_specifier_nonarray_vec4_t;
  };
  template <>
  struct ast_by_id<382> {
    using type_t = type_specifier_nonarray_dvec2_t;
  };
  template <>
  struct ast_by_id<383> {
    using type_t = type_specifier_nonarray_dvec3_t;
  };
  template <>
  struct ast_by_id<384> {
    using type_t = type_specifier_nonarray_dvec4_t;
  };
  template <>
  struct ast_by_id<385> {
    using type_t = type_specifier_nonarray_bvec2_t;
  };
  template <>
  struct ast_by_id<386> {
    using type_t = primary_expression_variable_identifier_t;
  };
  template <>
  struct ast_by_id<387> {
    using type_t = type_specifier_nonarray_bvec4_t;
  };
  template <>
  struct ast_by_id<388> {
    using type_t = type_specifier_nonarray_ivec2_t;
  };
  template <>
  struct ast_by_id<389> {
    using type_t = type_specifier_nonarray_ivec3_t;
  };
  template <>
  struct ast_by_id<390> {
    using type_t = type_specifier_nonarray_ivec4_t;
  };
  template <>
  struct ast_by_id<391> {
    using type_t = type_specifier_nonarray_uvec2_t;
  };
  template <>
  struct ast_by_id<392> {
    using type_t = type_specifier_nonarray_uvec3_t;
  };
  template <>
  struct ast_by_id<393> {
    using type_t = type_specifier_nonarray_uvec4_t;
  };
  template <>
  struct ast_by_id<394> {
    using type_t = type_specifier_nonarray_mat2_t;
  };
  template <>
  struct ast_by_id<395> {
    using type_t = type_specifier_nonarray_mat3_t;
  };
  template <>
  struct ast_by_id<396> {
    using type_t = type_specifier_nonarray_mat4_t;
  };
  template <>
  struct ast_by_id<397> {
    using type_t = type_specifier_nonarray_mat2x2_t;
  };
  template <>
  struct ast_by_id<398> {
    using type_t = type_specifier_nonarray_mat2x3_t;
  };
  template <>
  struct ast_by_id<399> {
    using type_t = type_specifier_nonarray_mat2x4_t;
  };
  template <>
  struct ast_by_id<400> {
    using type_t = type_specifier_nonarray_mat3x2_t;
  };
  template <>
  struct ast_by_id<401> {
    using type_t = type_specifier_nonarray_mat3x3_t;
  };
  template <>
  struct ast_by_id<402> {
    using type_t = type_specifier_nonarray_mat3x4_t;
  };
  template <>
  struct ast_by_id<403> {
    using type_t = type_specifier_nonarray_mat4x2_t;
  };
  template <>
  struct ast_by_id<404> {
    using type_t = type_specifier_nonarray_mat4x3_t;
  };
  template <>
  struct ast_by_id<405> {
    using type_t = type_specifier_nonarray_mat4x4_t;
  };
  template <>
  struct ast_by_id<406> {
    using type_t = type_specifier_nonarray_dmat2_t;
  };
  template <>
  struct ast_by_id<407> {
    using type_t = type_specifier_nonarray_dmat3_t;
  };
  template <>
  struct ast_by_id<408> {
    using type_t = type_specifier_nonarray_dmat4_t;
  };
  template <>
  struct ast_by_id<409> {
    using type_t = type_specifier_nonarray_dmat2x2_t;
  };
  template <>
  struct ast_by_id<410> {
    using type_t = type_specifier_nonarray_dmat2x3_t;
  };
  template <>
  struct ast_by_id<411> {
    using type_t = type_specifier_nonarray_dmat2x4_t;
  };
  template <>
  struct ast_by_id<412> {
    using type_t = type_specifier_nonarray_dmat3x2_t;
  };
  template <>
  struct ast_by_id<413> {
    using type_t = type_specifier_nonarray_dmat3x3_t;
  };
  template <>
  struct ast_by_id<414> {
    using type_t = type_specifier_nonarray_dmat3x4_t;
  };
  template <>
  struct ast_by_id<415> {
    using type_t = type_specifier_nonarray_dmat4x2_t;
  };
  template <>
  struct ast_by_id<416> {
    using type_t = type_specifier_nonarray_dmat4x3_t;
  };
  template <>
  struct ast_by_id<417> {
    using type_t = type_specifier_nonarray_dmat4x4_t;
  };
  template <>
  struct ast_by_id<418> {
    using type_t = type_specifier_nonarray_atomic_uint_t;
  };
  template <>
  struct ast_by_id<419> {
    using type_t = type_specifier_nonarray_sampler1d_t;
  };
  template <>
  struct ast_by_id<420> {
    using type_t = type_specifier_nonarray_sampler2d_t;
  };
  template <>
  struct ast_by_id<421> {
    using type_t = type_specifier_nonarray_sampler3d_t;
  };
  template <>
  struct ast_by_id<422> {
    using type_t = type_specifier_nonarray_samplercube_t;
  };
  template <>
  struct ast_by_id<423> {
    using type_t = type_specifier_nonarray_sampler1dshadow_t;
  };
  template <>
  struct ast_by_id<424> {
    using type_t = type_specifier_nonarray_sampler2dshadow_t;
  };
  template <>
  struct ast_by_id<425> {
    using type_t = type_specifier_nonarray_samplercubeshadow_t;
  };
  template <>
  struct ast_by_id<426> {
    using type_t = type_specifier_nonarray_sampler1darray_t;
  };
  template <>
  struct ast_by_id<427> {
    using type_t = type_specifier_nonarray_sampler2darray_t;
  };
  template <>
  struct ast_by_id<428> {
    using type_t = type_specifier_nonarray_sampler1darrayshadow_t;
  };
  template <>
  struct ast_by_id<429> {
    using type_t = type_specifier_nonarray_sampler2darrayshadow_t;
  };
  template <>
  struct ast_by_id<430> {
    using type_t = type_specifier_nonarray_samplercubearray_t;
  };
  template <>
  struct ast_by_id<431> {
    using type_t = type_specifier_nonarray_samplercubearrayshadow_t;
  };
  template <>
  struct ast_by_id<432> {
    using type_t = type_specifier_nonarray_isampler1d_t;
  };
  template <>
  struct ast_by_id<433> {
    using type_t = type_specifier_nonarray_isampler2d_t;
  };
  template <>
  struct ast_by_id<434> {
    using type_t = type_specifier_nonarray_isampler3d_t;
  };
  template <>
  struct ast_by_id<435> {
    using type_t = type_specifier_nonarray_isamplercube_t;
  };
  template <>
  struct ast_by_id<436> {
    using type_t = type_specifier_nonarray_isampler1darray_t;
  };
  template <>
  struct ast_by_id<437> {
    using type_t = type_specifier_nonarray_isampler2darray_t;
  };
  template <>
  struct ast_by_id<438> {
    using type_t = type_specifier_nonarray_isamplercubearray_t;
  };
  template <>
  struct ast_by_id<439> {
    using type_t = type_specifier_nonarray_usampler1d_t;
  };
  template <>
  struct ast_by_id<440> {
    using type_t = type_specifier_nonarray_usampler2d_t;
  };
  template <>
  struct ast_by_id<441> {
    using type_t = type_specifier_nonarray_usampler3d_t;
  };
  template <>
  struct ast_by_id<442> {
    using type_t = type_specifier_nonarray_usamplercube_t;
  };
  template <>
  struct ast_by_id<443> {
    using type_t = type_specifier_nonarray_usampler1darray_t;
  };
  template <>
  struct ast_by_id<444> {
    using type_t = type_specifier_nonarray_usampler2darray_t;
  };
  template <>
  struct ast_by_id<445> {
    using type_t = type_specifier_nonarray_usamplercubearray_t;
  };
  template <>
  struct ast_by_id<446> {
    using type_t = type_specifier_nonarray_sampler2drect_t;
  };
  template <>
  struct ast_by_id<447> {
    using type_t = type_specifier_nonarray_sampler2drectshadow_t;
  };
  template <>
  struct ast_by_id<448> {
    using type_t = type_specifier_nonarray_isampler2drect_t;
  };
  template <>
  struct ast_by_id<449> {
    using type_t = type_specifier_nonarray_usampler2drect_t;
  };
  template <>
  struct ast_by_id<450> {
    using type_t = type_specifier_nonarray_samplerbuffer_t;
  };
  template <>
  struct ast_by_id<451> {
    using type_t = type_specifier_nonarray_isamplerbuffer_t;
  };
  template <>
  struct ast_by_id<452> {
    using type_t = type_specifier_nonarray_usamplerbuffer_t;
  };
  template <>
  struct ast_by_id<453> {
    using type_t = for_rest_statement_conditionopt_semicolon_t;
  };
  template <>
  struct ast_by_id<454> {
    using type_t = function_definition_function_prototype_compound_statement_no_new_scope_t;
  };
  template <>
  struct ast_by_id<455> {
    using type_t = type_specifier_type_specifier_nonarray_array_specifier_t;
  };
  template <>
  struct ast_by_id<456> {
    using type_t = type_qualifier_type_qualifier_single_type_qualifier_t;
  };
  template <>
  struct ast_by_id<457> {
    using type_t = fully_specified_type_type_qualifier_type_specifier_t;
  };
  template <>
  struct ast_by_id<458> {
    using type_t = translation_unit_translation_unit_external_declaration_t;
  };
  template <>
  struct ast_by_id<459> {
    using type_t = postfix_expression_postfix_expression_inc_op_t;
  };
  template <>
  struct ast_by_id<460> {
    using type_t = single_declaration_fully_specified_type_identifier_t;
  };
  template <>
  struct ast_by_id<461> {
    using type_t = jump_statement_discard_semicolon_t;
  };
  template <>
  struct ast_by_id<462> {
    using type_t = jump_statement_return_semicolon_t;
  };
  template <>
  struct ast_by_id<463> {
    using type_t = parameter_declaration_type_qualifier_parameter_type_specifier_t;
  };
  template <>
  struct ast_by_id<464> {
    using type_t = parameter_declaration_type_qualifier_parameter_declarator_t;
  };
  template <>
  struct ast_by_id<465> {
    using type_t = parameter_declarator_type_specifier_identifier_t;
  };
  template <>
  struct ast_by_id<466> {
    using type_t = function_header_with_parameters_function_header_parameter_declaration_t;
  };
  template <>
  struct ast_by_id<467> {
    using type_t = function_prototype_function_declarator_right_paren_t;
  };
  template <>
  struct ast_by_id<468> {
    using type_t = identifier_list_comma_identifier_t;
  };
  template <>
  struct ast_by_id<469> {
    using type_t = jump_statement_break_semicolon_t;
  };
  template <>
  struct ast_by_id<470> {
    using type_t = declaration_type_qualifier_semicolon_t;
  };
  template <>
  struct ast_by_id<471> {
    using type_t = jump_statement_continue_semicolon_t;
  };
  template <>
  struct ast_by_id<472> {
    using type_t = array_specifier_left_bracket_right_bracket_t;
  };
  template <>
  struct ast_by_id<473> {
    using type_t = postfix_expression_postfix_expression_dec_op_t;
  };
  template <>
  struct ast_by_id<474> {
    using type_t = declaration_init_declarator_list_semicolon_t;
  };
  template <>
  struct ast_by_id<475> {
    using type_t = declaration_function_prototype_semicolon_t;
  };
  template <>
  struct ast_by_id<476> {
    using type_t = function_call_generic_function_call_header_with_parameters_right_paren_t;
  };
  template <>
  struct ast_by_id<477> {
    using type_t = function_call_generic_function_call_header_no_parameters_right_paren_t;
  };
  template <>
  struct ast_by_id<478> {
    using type_t = function_call_header_no_parameters_function_call_header_void_t;
  };
  template <>
  struct ast_by_id<479> {
    using type_t = struct_declaration_list_struct_declaration_list_struct_declaration_t;
  };
  template <>
  struct ast_by_id<480> {
    using type_t = case_label_default_colon_t;
  };
  template <>
  struct ast_by_id<481> {
    using type_t = struct_declarator_identifier_array_specifier_t;
  };
  template <>
  struct ast_by_id<482> {
    using type_t = compound_statement_left_brace_right_brace_t;
  };
  template <>
  struct ast_by_id<483> {
    using type_t = compound_statement_no_new_scope_left_brace_right_brace_t;
  };
  template <>
  struct ast_by_id<484> {
    using type_t = unary_expression_unary_operator_unary_expression_t;
  };
  template <>
  struct ast_by_id<485> {
    using type_t = statement_list_statement_list_statement_t;
  };
  template <>
  struct ast_by_id<486> {
    using type_t = unary_expression_dec_op_unary_expression_t;
  };
  template <>
  struct ast_by_id<487> {
    using type_t = expression_statement_expression_semicolon_t;
  };
  template <>
  struct ast_by_id<488> {
    using type_t = function_call_header_with_parameters_function_call_header_assignment_expression_t;
  };
  template <>
  struct ast_by_id<489> {
    using type_t = unary_expression_inc_op_unary_expression_t;
  };
  template <>
  struct ast_by_id<490> {
    using type_t = function_call_header_function_identifier_left_paren_t;
  };
  template <>
  struct ast_by_id<491> {
    using type_t = parameter_declarator_type_specifier_identifier_array_specifier_t;
  };
  template <>
  struct ast_by_id<492> {
    using type_t = expression_expression_comma_assignment_expression_t;
  };
  template <>
  struct ast_by_id<493> {
    using type_t = assignment_expression_unary_expression_assignment_operator_assignment_expression_t;
  };
  template <>
  struct ast_by_id<494> {
    using type_t = type_name_list_type_name_list_comma_type_name_t;
  };
  template <>
  struct ast_by_id<495> {
    using type_t = logical_or_expression_logical_or_expression_or_op_logical_xor_expression_t;
  };
  template <>
  struct ast_by_id<496> {
    using type_t = logical_xor_expression_logical_xor_expression_xor_op_logical_and_expression_t;
  };
  template <>
  struct ast_by_id<497> {
    using type_t = function_header_fully_specified_type_identifier_left_paren_t;
  };
  template <>
  struct ast_by_id<498> {
    using type_t = function_header_with_parameters_function_header_with_parameters_comma_parameter_declaration_t;
  };
  template <>
  struct ast_by_id<499> {
    using type_t = logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t;
  };
  template <>
  struct ast_by_id<500> {
    using type_t = primary_expression_left_paren_expression_right_paren_t;
  };
  template <>
  struct ast_by_id<501> {
    using type_t = struct_declaration_type_specifier_struct_declarator_list_semicolon_t;
  };
  template <>
  struct ast_by_id<502> {
    using type_t = single_declaration_fully_specified_type_identifier_array_specifier_t;
  };
  template <>
  struct ast_by_id<503> {
    using type_t = inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t;
  };
  template <>
  struct ast_by_id<504> {
    using type_t = struct_declarator_list_struct_declarator_list_comma_struct_declarator_t;
  };
  template <>
  struct ast_by_id<505> {
    using type_t = exclusive_or_expression_exclusive_or_expression_caret_and_expression_t;
  };
  template <>
  struct ast_by_id<506> {
    using type_t = identifier_list_identifier_list_comma_identifier_t;
  };
  template <>
  struct ast_by_id<507> {
    using type_t = array_specifier_array_specifier_left_bracket_right_bracket_t;
  };
  template <>
  struct ast_by_id<508> {
    using type_t = initializer_left_brace_initializer_list_right_brace_t;
  };
  template <>
  struct ast_by_id<509> {
    using type_t = case_label_case_expression_colon_t;
  };
  template <>
  struct ast_by_id<510> {
    using type_t = equality_expression_equality_expression_ne_op_relational_expression_t;
  };
  template <>
  struct ast_by_id<511> {
    using type_t = initializer_list_initializer_list_comma_initializer_t;
  };
  template <>
  struct ast_by_id<512> {
    using type_t = equality_expression_equality_expression_eq_op_relational_expression_t;
  };
  template <>
  struct ast_by_id<513> {
    using type_t = relational_expression_relational_expression_ge_op_shift_expression_t;
  };
  template <>
  struct ast_by_id<514> {
    using type_t = relational_expression_relational_expression_le_op_shift_expression_t;
  };
  template <>
  struct ast_by_id<515> {
    using type_t = relational_expression_relational_expression_right_angle_shift_expression_t;
  };
  template <>
  struct ast_by_id<516> {
    using type_t = relational_expression_relational_expression_left_angle_shift_expression_t;
  };
  template <>
  struct ast_by_id<517> {
    using type_t = shift_expression_shift_expression_right_op_additive_expression_t;
  };
  template <>
  struct ast_by_id<518> {
    using type_t = shift_expression_shift_expression_left_op_additive_expression_t;
  };
  template <>
  struct ast_by_id<519> {
    using type_t = additive_expression_additive_expression_dash_multiplicative_expression_t;
  };
  template <>
  struct ast_by_id<520> {
    using type_t = additive_expression_additive_expression_plus_multiplicative_expression_t;
  };
  template <>
  struct ast_by_id<521> {
    using type_t = multiplicative_expression_multiplicative_expression_percent_unary_expression_t;
  };
  template <>
  struct ast_by_id<522> {
    using type_t = and_expression_and_expression_ampersand_equality_expression_t;
  };
  template <>
  struct ast_by_id<523> {
    using type_t = compound_statement_left_brace_statement_list_right_brace_t;
  };
  template <>
  struct ast_by_id<524> {
    using type_t = multiplicative_expression_multiplicative_expression_slash_unary_expression_t;
  };
  template <>
  struct ast_by_id<525> {
    using type_t = multiplicative_expression_multiplicative_expression_star_unary_expression_t;
  };
  template <>
  struct ast_by_id<526> {
    using type_t = layout_qualifier_id_identifier_equal_constant_expression_t;
  };
  template <>
  struct ast_by_id<527> {
    using type_t = compound_statement_no_new_scope_left_brace_statement_list_right_brace_t;
  };
  template <>
  struct ast_by_id<528> {
    using type_t = declaration_type_qualifier_identifier_semicolon_t;
  };
  template <>
  struct ast_by_id<529> {
    using type_t = jump_statement_return_expression_semicolon_t;
  };
  template <>
  struct ast_by_id<530> {
    using type_t = layout_qualifier_id_list_layout_qualifier_id_list_comma_layout_qualifier_id_t;
  };
  template <>
  struct ast_by_id<531> {
    using type_t = for_rest_statement_conditionopt_semicolon_expression_t;
  };
  template <>
  struct ast_by_id<532> {
    using type_t = init_declarator_list_init_declarator_list_comma_identifier_t;
  };
  template <>
  struct ast_by_id<533> {
    using type_t = selection_rest_statement_statement_else_statement_t;
  };
  template <>
  struct ast_by_id<534> {
    using type_t = postfix_expression_postfix_expression_dot_field_selection_t;
  };
  template <>
  struct ast_by_id<535> {
    using type_t = array_specifier_left_bracket_conditional_expression_right_bracket_t;
  };
  template <>
  struct ast_by_id<536> {
    using type_t = function_call_header_with_parameters_function_call_header_with_parameters_comma_assignment_expression_t;
  };
  template <>
  struct ast_by_id<537> {
    using type_t = declaration_precision_precision_qualifier_type_specifier_semicolon_t;
  };
  template <>
  struct ast_by_id<538> {
    using type_t = array_specifier_array_specifier_left_bracket_conditional_expression_right_bracket_t;
  };
  template <>
  struct ast_by_id<539> {
    using type_t = initializer_left_brace_initializer_list_comma_right_brace_t;
  };
  template <>
  struct ast_by_id<540> {
    using type_t = struct_declaration_type_qualifier_type_specifier_struct_declarator_list_semicolon_t;
  };
  template <>
  struct ast_by_id<541> {
    using type_t = init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t;
  };
  template <>
  struct ast_by_id<542> {
    using type_t = storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t;
  };
  template <>
  struct ast_by_id<543> {
    using type_t = struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t;
  };
  template <>
  struct ast_by_id<544> {
    using type_t = declaration_type_qualifier_identifier_identifier_list_semicolon_t;
  };
  template <>
  struct ast_by_id<545> {
    using type_t = layout_qualifier_layout_left_paren_layout_qualifier_id_list_right_paren_t;
  };
  template <>
  struct ast_by_id<546> {
    using type_t = postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t;
  };
  template <>
  struct ast_by_id<547> {
    using type_t = condition_fully_specified_type_identifier_equal_initializer_t;
  };
  template <>
  struct ast_by_id<548> {
    using type_t = single_declaration_fully_specified_type_identifier_equal_initializer_t;
  };
  template <>
  struct ast_by_id<549> {
    using type_t = selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t;
  };
  template <>
  struct ast_by_id<550> {
    using type_t = conditional_expression_logical_or_expression_question_expression_colon_assignment_expression_t;
  };
  template <>
  struct ast_by_id<551> {
    using type_t = struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t;
  };
  template <>
  struct ast_by_id<552> {
    using type_t = iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t;
  };
  template <>
  struct ast_by_id<553> {
    using type_t = init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t;
  };
  template <>
  struct ast_by_id<554> {
    using type_t = single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t;
  };
  template <>
  struct ast_by_id<555> {
    using type_t = iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t;
  };
  template <>
  struct ast_by_id<556> {
    using type_t = declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t;
  };
  template <>
  struct ast_by_id<557> {
    using type_t = init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t;
  };
  template <>
  struct ast_by_id<558> {
    using type_t = declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t;
  };
  template <>
  struct ast_by_id<559> {
    using type_t = iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t;
  };
  template <>
  struct ast_by_id<560> {
    using type_t = switch_statement_switch_left_paren_expression_right_paren_left_brace_switch_statement_list_right_brace_t;
  };
  template <>
  struct ast_by_id<561> {
    using type_t = declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t;
  };

  template <>
  struct reductions_from_t<1> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<1>::reductions = {
    {478, { 220, 1 }},
    {373, { 1 }}
  };
  template <>
  struct reductions_from_t<3> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<3>::reductions = {
    {506, { 241, 39, 3 }},
    {532, { 249, 39, 3 }},
    {460, { 251, 3 }},
    {465, { 262, 3 }},
    {468, { 39, 3 }},
    {212, { 3 }},
    {266, { 3 }},
    {336, { 3 }}
  };
  template <>
  struct reductions_from_t<4> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<4>::reductions = {
    {494, { 261, 39, 4 }},
    {278, { 4 }},
    {365, { 4 }}
  };
  template <>
  struct reductions_from_t<5> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<5>::reductions = {
    {215, { 5 }}
  };
  template <>
  struct reductions_from_t<6> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<6>::reductions = {
    {217, { 6 }}
  };
  template <>
  struct reductions_from_t<7> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<7>::reductions = {
    {213, { 7 }}
  };
  template <>
  struct reductions_from_t<8> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<8>::reductions = {
    {214, { 8 }}
  };
  template <>
  struct reductions_from_t<9> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<9>::reductions = {
    {216, { 9 }}
  };
  template <>
  struct reductions_from_t<10> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<10>::reductions = {
    {534, { 213, 38, 10 }}
  };
  template <>
  struct reductions_from_t<13> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<13>::reductions = {
    {459, { 213, 13 }}
  };
  template <>
  struct reductions_from_t<14> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<14>::reductions = {
    {473, { 213, 14 }}
  };
  template <>
  struct reductions_from_t<22> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<22>::reductions = {
    {280, { 22 }}
  };
  template <>
  struct reductions_from_t<23> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<23>::reductions = {
    {281, { 23 }}
  };
  template <>
  struct reductions_from_t<24> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<24>::reductions = {
    {283, { 24 }}
  };
  template <>
  struct reductions_from_t<25> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<25>::reductions = {
    {282, { 25 }}
  };
  template <>
  struct reductions_from_t<26> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<26>::reductions = {
    {285, { 26 }}
  };
  template <>
  struct reductions_from_t<27> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<27>::reductions = {
    {286, { 27 }}
  };
  template <>
  struct reductions_from_t<28> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<28>::reductions = {
    {287, { 28 }}
  };
  template <>
  struct reductions_from_t<29> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<29>::reductions = {
    {288, { 29 }}
  };
  template <>
  struct reductions_from_t<30> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<30>::reductions = {
    {289, { 30 }}
  };
  template <>
  struct reductions_from_t<31> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<31>::reductions = {
    {284, { 31 }}
  };
  template <>
  struct reductions_from_t<32> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<32>::reductions = {
    {497, { 251, 3, 32 }},
    {490, { 221, 32 }}
  };
  template <>
  struct reductions_from_t<33> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<33>::reductions = {
    {542, { 79, 32, 261, 33 }},
    {545, { 118, 32, 255, 33 }},
    {500, { 32, 238, 33 }},
    {467, { 243, 33 }},
    {476, { 219, 33 }},
    {477, { 218, 33 }}
  };
  template <>
  struct reductions_from_t<35> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<35>::reductions = {
    {538, { 263, 34, 235, 35 }},
    {546, { 213, 34, 214, 35 }},
    {507, { 263, 34, 35 }},
    {535, { 34, 235, 35 }},
    {472, { 34, 35 }}
  };
  template <>
  struct reductions_from_t<37> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<37>::reductions = {
    {560, { 76, 32, 238, 33, 36, 285, 37 }},
    {551, { -1, 3, 36, 267, 37 }},
    {539, { 36, 272, 39, 37 }},
    {543, { -1, 36, 267, 37 }},
    {508, { 36, 272, 37 }},
    {523, { 36, 279, 37 }},
    {527, { 36, 279, 37 }},
    {482, { 36, 37 }},
    {483, { 36, 37 }}
  };
  template <>
  struct reductions_from_t<40> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<40>::reductions = {
    {509, { 77, 238, 40 }},
    {480, { 78, 40 }}
  };
  template <>
  struct reductions_from_t<41> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<41>::reductions = {
    {279, { 41 }}
  };
  template <>
  struct reductions_from_t<42> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<42>::reductions = {
    {561, { 258, 3, 36, 267, 37, 3, 263, 42 }},
    {559, { 70, 274, 2, 32, 238, 33, 42 }},
    {558, { 258, 3, 36, 267, 37, 3, 42 }},
    {556, { 258, 3, 36, 267, 37, 42 }},
    {537, { 61, 265, 262, 42 }},
    {540, { 258, 262, 269, 42 }},
    {544, { 258, 3, 241, 42 }},
    {501, { 262, 269, 42 }},
    {528, { 258, 3, 42 }},
    {529, { 75, 238, 42 }},
    {487, { 238, 42 }},
    {453, { 289, 42 }},
    {461, { 74, 42 }},
    {462, { 75, 42 }},
    {469, { 68, 42 }},
    {470, { 258, 42 }},
    {471, { 69, 42 }},
    {474, { 249, 42 }},
    {475, { 242, 42 }},
    {239, { 42 }},
    {218, { 42 }}
  };
  template <>
  struct reductions_from_t<43> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<43>::reductions = {
    {243, { 43 }}
  };
  template <>
  struct reductions_from_t<44> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<44>::reductions = {
    {242, { 44 }}
  };
  template <>
  struct reductions_from_t<45> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<45>::reductions = {
    {244, { 45 }}
  };
  template <>
  struct reductions_from_t<46> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<46>::reductions = {
    {241, { 46 }}
  };
  template <>
  struct reductions_from_t<56> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<56>::reductions = {
    {329, { 56 }}
  };
  template <>
  struct reductions_from_t<57> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<57>::reductions = {
    {339, { 57 }}
  };
  template <>
  struct reductions_from_t<58> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<58>::reductions = {
    {276, { 58 }}
  };
  template <>
  struct reductions_from_t<59> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<59>::reductions = {
    {274, { 59 }}
  };
  template <>
  struct reductions_from_t<60> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<60>::reductions = {
    {272, { 60 }}
  };
  template <>
  struct reductions_from_t<62> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<62>::reductions = {
    {348, { 62 }}
  };
  template <>
  struct reductions_from_t<63> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<63>::reductions = {
    {378, { 63 }}
  };
  template <>
  struct reductions_from_t<64> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<64>::reductions = {
    {374, { 64 }}
  };
  template <>
  struct reductions_from_t<65> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<65>::reductions = {
    {375, { 65 }}
  };
  template <>
  struct reductions_from_t<66> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<66>::reductions = {
    {376, { 66 }}
  };
  template <>
  struct reductions_from_t<67> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<67>::reductions = {
    {377, { 67 }}
  };
  template <>
  struct reductions_from_t<79> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<79>::reductions = {
    {363, { 79 }}
  };
  template <>
  struct reductions_from_t<80> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<80>::reductions = {
    {385, { 80 }}
  };
  template <>
  struct reductions_from_t<81> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<81>::reductions = {
    {211, { 81 }}
  };
  template <>
  struct reductions_from_t<82> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<82>::reductions = {
    {387, { 82 }}
  };
  template <>
  struct reductions_from_t<83> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<83>::reductions = {
    {388, { 83 }}
  };
  template <>
  struct reductions_from_t<84> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<84>::reductions = {
    {389, { 84 }}
  };
  template <>
  struct reductions_from_t<85> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<85>::reductions = {
    {390, { 85 }}
  };
  template <>
  struct reductions_from_t<86> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<86>::reductions = {
    {391, { 86 }}
  };
  template <>
  struct reductions_from_t<87> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<87>::reductions = {
    {392, { 87 }}
  };
  template <>
  struct reductions_from_t<88> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<88>::reductions = {
    {393, { 88 }}
  };
  template <>
  struct reductions_from_t<89> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<89>::reductions = {
    {379, { 89 }}
  };
  template <>
  struct reductions_from_t<90> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<90>::reductions = {
    {380, { 90 }}
  };
  template <>
  struct reductions_from_t<91> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<91>::reductions = {
    {381, { 91 }}
  };
  template <>
  struct reductions_from_t<92> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<92>::reductions = {
    {394, { 92 }}
  };
  template <>
  struct reductions_from_t<93> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<93>::reductions = {
    {395, { 93 }}
  };
  template <>
  struct reductions_from_t<94> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<94>::reductions = {
    {396, { 94 }}
  };
  template <>
  struct reductions_from_t<95> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<95>::reductions = {
    {352, { 95 }}
  };
  template <>
  struct reductions_from_t<96> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<96>::reductions = {
    {350, { 96 }}
  };
  template <>
  struct reductions_from_t<97> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<97>::reductions = {
    {351, { 97 }}
  };
  template <>
  struct reductions_from_t<98> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<98>::reductions = {
    {349, { 98 }}
  };
  template <>
  struct reductions_from_t<99> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<99>::reductions = {
    {355, { 99 }}
  };
  template <>
  struct reductions_from_t<100> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<100>::reductions = {
    {353, { 100 }}
  };
  template <>
  struct reductions_from_t<101> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<101>::reductions = {
    {354, { 101 }}
  };
  template <>
  struct reductions_from_t<102> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<102>::reductions = {
    {356, { 102 }}
  };
  template <>
  struct reductions_from_t<103> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<103>::reductions = {
    {338, { 103 }},
    {357, { 103 }}
  };
  template <>
  struct reductions_from_t<104> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<104>::reductions = {
    {358, { 104 }}
  };
  template <>
  struct reductions_from_t<105> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<105>::reductions = {
    {359, { 105 }}
  };
  template <>
  struct reductions_from_t<106> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<106>::reductions = {
    {360, { 106 }}
  };
  template <>
  struct reductions_from_t<107> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<107>::reductions = {
    {361, { 107 }}
  };
  template <>
  struct reductions_from_t<108> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<108>::reductions = {
    {362, { 108 }}
  };
  template <>
  struct reductions_from_t<109> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<109>::reductions = {
    {382, { 109 }}
  };
  template <>
  struct reductions_from_t<110> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<110>::reductions = {
    {383, { 110 }}
  };
  template <>
  struct reductions_from_t<111> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<111>::reductions = {
    {384, { 111 }}
  };
  template <>
  struct reductions_from_t<112> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<112>::reductions = {
    {406, { 112 }}
  };
  template <>
  struct reductions_from_t<113> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<113>::reductions = {
    {407, { 113 }}
  };
  template <>
  struct reductions_from_t<114> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<114>::reductions = {
    {408, { 114 }}
  };
  template <>
  struct reductions_from_t<115> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<115>::reductions = {
    {332, { 115 }}
  };
  template <>
  struct reductions_from_t<116> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<116>::reductions = {
    {331, { 116 }}
  };
  template <>
  struct reductions_from_t<117> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<117>::reductions = {
    {330, { 117 }}
  };
  template <>
  struct reductions_from_t<119> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<119>::reductions = {
    {397, { 119 }}
  };
  template <>
  struct reductions_from_t<120> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<120>::reductions = {
    {398, { 120 }}
  };
  template <>
  struct reductions_from_t<121> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<121>::reductions = {
    {399, { 121 }}
  };
  template <>
  struct reductions_from_t<122> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<122>::reductions = {
    {400, { 122 }}
  };
  template <>
  struct reductions_from_t<123> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<123>::reductions = {
    {401, { 123 }}
  };
  template <>
  struct reductions_from_t<124> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<124>::reductions = {
    {402, { 124 }}
  };
  template <>
  struct reductions_from_t<125> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<125>::reductions = {
    {403, { 125 }}
  };
  template <>
  struct reductions_from_t<126> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<126>::reductions = {
    {404, { 126 }}
  };
  template <>
  struct reductions_from_t<127> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<127>::reductions = {
    {405, { 127 }}
  };
  template <>
  struct reductions_from_t<128> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<128>::reductions = {
    {409, { 128 }}
  };
  template <>
  struct reductions_from_t<129> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<129>::reductions = {
    {410, { 129 }}
  };
  template <>
  struct reductions_from_t<130> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<130>::reductions = {
    {411, { 130 }}
  };
  template <>
  struct reductions_from_t<131> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<131>::reductions = {
    {412, { 131 }}
  };
  template <>
  struct reductions_from_t<132> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<132>::reductions = {
    {413, { 132 }}
  };
  template <>
  struct reductions_from_t<133> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<133>::reductions = {
    {414, { 133 }}
  };
  template <>
  struct reductions_from_t<134> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<134>::reductions = {
    {415, { 134 }}
  };
  template <>
  struct reductions_from_t<135> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<135>::reductions = {
    {416, { 135 }}
  };
  template <>
  struct reductions_from_t<136> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<136>::reductions = {
    {417, { 136 }}
  };
  template <>
  struct reductions_from_t<137> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<137>::reductions = {
    {418, { 137 }}
  };
  template <>
  struct reductions_from_t<138> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<138>::reductions = {
    {419, { 138 }}
  };
  template <>
  struct reductions_from_t<139> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<139>::reductions = {
    {420, { 139 }}
  };
  template <>
  struct reductions_from_t<140> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<140>::reductions = {
    {421, { 140 }}
  };
  template <>
  struct reductions_from_t<141> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<141>::reductions = {
    {422, { 141 }}
  };
  template <>
  struct reductions_from_t<142> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<142>::reductions = {
    {423, { 142 }}
  };
  template <>
  struct reductions_from_t<143> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<143>::reductions = {
    {424, { 143 }}
  };
  template <>
  struct reductions_from_t<144> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<144>::reductions = {
    {425, { 144 }}
  };
  template <>
  struct reductions_from_t<145> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<145>::reductions = {
    {426, { 145 }}
  };
  template <>
  struct reductions_from_t<146> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<146>::reductions = {
    {427, { 146 }}
  };
  template <>
  struct reductions_from_t<147> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<147>::reductions = {
    {428, { 147 }}
  };
  template <>
  struct reductions_from_t<148> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<148>::reductions = {
    {429, { 148 }}
  };
  template <>
  struct reductions_from_t<149> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<149>::reductions = {
    {432, { 149 }}
  };
  template <>
  struct reductions_from_t<150> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<150>::reductions = {
    {433, { 150 }}
  };
  template <>
  struct reductions_from_t<151> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<151>::reductions = {
    {434, { 151 }}
  };
  template <>
  struct reductions_from_t<152> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<152>::reductions = {
    {435, { 152 }}
  };
  template <>
  struct reductions_from_t<153> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<153>::reductions = {
    {436, { 153 }}
  };
  template <>
  struct reductions_from_t<154> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<154>::reductions = {
    {437, { 154 }}
  };
  template <>
  struct reductions_from_t<155> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<155>::reductions = {
    {439, { 155 }}
  };
  template <>
  struct reductions_from_t<156> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<156>::reductions = {
    {440, { 156 }}
  };
  template <>
  struct reductions_from_t<157> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<157>::reductions = {
    {441, { 157 }}
  };
  template <>
  struct reductions_from_t<158> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<158>::reductions = {
    {442, { 158 }}
  };
  template <>
  struct reductions_from_t<159> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<159>::reductions = {
    {443, { 159 }}
  };
  template <>
  struct reductions_from_t<160> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<160>::reductions = {
    {444, { 160 }}
  };
  template <>
  struct reductions_from_t<161> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<161>::reductions = {
    {446, { 161 }}
  };
  template <>
  struct reductions_from_t<162> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<162>::reductions = {
    {447, { 162 }}
  };
  template <>
  struct reductions_from_t<163> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<163>::reductions = {
    {448, { 163 }}
  };
  template <>
  struct reductions_from_t<164> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<164>::reductions = {
    {449, { 164 }}
  };
  template <>
  struct reductions_from_t<165> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<165>::reductions = {
    {450, { 165 }}
  };
  template <>
  struct reductions_from_t<166> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<166>::reductions = {
    {451, { 166 }}
  };
  template <>
  struct reductions_from_t<167> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<167>::reductions = {
    {452, { 167 }}
  };
  template <>
  struct reductions_from_t<168> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<168>::reductions = {
    {430, { 168 }}
  };
  template <>
  struct reductions_from_t<169> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<169>::reductions = {
    {431, { 169 }}
  };
  template <>
  struct reductions_from_t<170> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<170>::reductions = {
    {438, { 170 }}
  };
  template <>
  struct reductions_from_t<171> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<171>::reductions = {
    {445, { 171 }}
  };
  template <>
  struct reductions_from_t<172> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<172>::reductions = {
    {372, { 172 }}
  };
  template <>
  struct reductions_from_t<173> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<173>::reductions = {
    {371, { 173 }}
  };
  template <>
  struct reductions_from_t<174> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<174>::reductions = {
    {370, { 174 }}
  };
  template <>
  struct reductions_from_t<175> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<175>::reductions = {
    {369, { 175 }}
  };
  template <>
  struct reductions_from_t<176> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<176>::reductions = {
    {368, { 176 }}
  };
  template <>
  struct reductions_from_t<177> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<177>::reductions = {
    {366, { 177 }}
  };
  template <>
  struct reductions_from_t<178> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<178>::reductions = {
    {364, { 178 }}
  };
  template <>
  struct reductions_from_t<179> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<179>::reductions = {
    {341, { 179 }}
  };
  template <>
  struct reductions_from_t<180> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<180>::reductions = {
    {337, { 180 }}
  };
  template <>
  struct reductions_from_t<181> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<181>::reductions = {
    {335, { 181 }}
  };
  template <>
  struct reductions_from_t<182> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<182>::reductions = {
    {333, { 182 }}
  };
  template <>
  struct reductions_from_t<183> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<183>::reductions = {
    {328, { 183 }}
  };
  template <>
  struct reductions_from_t<184> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<184>::reductions = {
    {326, { 184 }}
  };
  template <>
  struct reductions_from_t<185> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<185>::reductions = {
    {325, { 185 }}
  };
  template <>
  struct reductions_from_t<186> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<186>::reductions = {
    {324, { 186 }}
  };
  template <>
  struct reductions_from_t<187> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<187>::reductions = {
    {323, { 187 }}
  };
  template <>
  struct reductions_from_t<188> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<188>::reductions = {
    {321, { 188 }}
  };
  template <>
  struct reductions_from_t<189> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<189>::reductions = {
    {320, { 189 }}
  };
  template <>
  struct reductions_from_t<190> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<190>::reductions = {
    {319, { 190 }}
  };
  template <>
  struct reductions_from_t<191> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<191>::reductions = {
    {318, { 191 }}
  };
  template <>
  struct reductions_from_t<192> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<192>::reductions = {
    {314, { 192 }}
  };
  template <>
  struct reductions_from_t<193> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<193>::reductions = {
    {312, { 193 }}
  };
  template <>
  struct reductions_from_t<194> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<194>::reductions = {
    {311, { 194 }}
  };
  template <>
  struct reductions_from_t<195> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<195>::reductions = {
    {310, { 195 }}
  };
  template <>
  struct reductions_from_t<196> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<196>::reductions = {
    {309, { 196 }}
  };
  template <>
  struct reductions_from_t<197> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<197>::reductions = {
    {308, { 197 }}
  };
  template <>
  struct reductions_from_t<198> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<198>::reductions = {
    {307, { 198 }}
  };
  template <>
  struct reductions_from_t<199> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<199>::reductions = {
    {304, { 199 }}
  };
  template <>
  struct reductions_from_t<200> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<200>::reductions = {
    {303, { 200 }}
  };
  template <>
  struct reductions_from_t<201> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<201>::reductions = {
    {302, { 201 }}
  };
  template <>
  struct reductions_from_t<202> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<202>::reductions = {
    {301, { 202 }}
  };
  template <>
  struct reductions_from_t<203> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<203>::reductions = {
    {300, { 203 }}
  };
  template <>
  struct reductions_from_t<204> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<204>::reductions = {
    {299, { 204 }}
  };
  template <>
  struct reductions_from_t<205> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<205>::reductions = {
    {298, { 205 }}
  };
  template <>
  struct reductions_from_t<206> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<206>::reductions = {
    {297, { 206 }}
  };
  template <>
  struct reductions_from_t<207> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<207>::reductions = {
    {296, { 207 }}
  };
  template <>
  struct reductions_from_t<208> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<208>::reductions = {
    {295, { 208 }}
  };
  template <>
  struct reductions_from_t<209> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<209>::reductions = {
    {294, { 209 }}
  };
  template <>
  struct reductions_from_t<210> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<210>::reductions = {
    {293, { 210 }}
  };
  template <>
  struct reductions_from_t<211> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<211>::reductions = {
    {386, { 211 }}
  };
  template <>
  struct reductions_from_t<212> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<212>::reductions = {
    {219, { 212 }}
  };
  template <>
  struct reductions_from_t<213> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<213>::reductions = {
    {236, { 213 }},
    {237, { 213 }}
  };
  template <>
  struct reductions_from_t<215> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<215>::reductions = {
    {221, { 215 }}
  };
  template <>
  struct reductions_from_t<216> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<216>::reductions = {
    {226, { 216 }}
  };
  template <>
  struct reductions_from_t<217> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<217>::reductions = {
    {227, { 217 }}
  };
  template <>
  struct reductions_from_t<220> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<220>::reductions = {
    {231, { 220 }}
  };
  template <>
  struct reductions_from_t<222> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<222>::reductions = {
    {521, { 224, 49, 222 }},
    {524, { 224, 48, 222 }},
    {525, { 224, 47, 222 }},
    {484, { 223, 222 }},
    {486, { 14, 222 }},
    {489, { 13, 222 }},
    {245, { 222 }}
  };
  template <>
  struct reductions_from_t<224> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<224>::reductions = {
    {519, { 225, 44, 224 }},
    {520, { 225, 46, 224 }},
    {249, { 224 }}
  };
  template <>
  struct reductions_from_t<225> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<225>::reductions = {
    {517, { 226, 12, 225 }},
    {518, { 226, 11, 225 }},
    {252, { 225 }}
  };
  template <>
  struct reductions_from_t<226> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<226>::reductions = {
    {513, { 227, 16, 226 }},
    {514, { 227, 15, 226 }},
    {515, { 227, 51, 226 }},
    {516, { 227, 50, 226 }},
    {255, { 226 }}
  };
  template <>
  struct reductions_from_t<227> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<227>::reductions = {
    {510, { 228, 18, 227 }},
    {512, { 228, 17, 227 }},
    {260, { 227 }}
  };
  template <>
  struct reductions_from_t<228> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<228>::reductions = {
    {522, { 229, 54, 228 }},
    {263, { 228 }}
  };
  template <>
  struct reductions_from_t<229> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<229>::reductions = {
    {505, { 230, 53, 229 }},
    {265, { 229 }}
  };
  template <>
  struct reductions_from_t<230> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<230>::reductions = {
    {503, { 231, 52, 230 }},
    {267, { 230 }}
  };
  template <>
  struct reductions_from_t<231> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<231>::reductions = {
    {499, { 232, 19, 231 }},
    {269, { 231 }}
  };
  template <>
  struct reductions_from_t<232> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<232>::reductions = {
    {496, { 233, 21, 232 }},
    {271, { 232 }}
  };
  template <>
  struct reductions_from_t<233> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<233>::reductions = {
    {495, { 234, 20, 233 }},
    {273, { 233 }}
  };
  template <>
  struct reductions_from_t<234> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<234>::reductions = {
    {275, { 234 }}
  };
  template <>
  struct reductions_from_t<235> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<235>::reductions = {
    {277, { 235 }},
    {292, { 235 }}
  };
  template <>
  struct reductions_from_t<236> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<236>::reductions = {
    {550, { 234, 55, 238, 40, 236 }},
    {492, { 238, 39, 236 }},
    {493, { 222, 237, 236 }},
    {536, { 219, 39, 236 }},
    {488, { 220, 236 }},
    {264, { 236 }},
    {290, { 236 }}
  };
  template <>
  struct reductions_from_t<238> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<238>::reductions = {
    {531, { 289, 42, 238 }},
    {225, { 238 }},
    {234, { 238 }}
  };
  template <>
  struct reductions_from_t<239> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<239>::reductions = {
    {526, { 3, 41, 239 }}
  };
  template <>
  struct reductions_from_t<240> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<240>::reductions = {
    {220, { 240 }},
    {261, { 240 }}
  };
  template <>
  struct reductions_from_t<244> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<244>::reductions = {
    {306, { 244 }}
  };
  template <>
  struct reductions_from_t<245> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<245>::reductions = {
    {305, { 245 }}
  };
  template <>
  struct reductions_from_t<246> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<246>::reductions = {
    {464, { 258, 246 }},
    {313, { 246 }}
  };
  template <>
  struct reductions_from_t<247> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<247>::reductions = {
    {498, { 244, 39, 247 }},
    {466, { 245, 247 }}
  };
  template <>
  struct reductions_from_t<248> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<248>::reductions = {
    {463, { 258, 248 }},
    {315, { 248 }}
  };
  template <>
  struct reductions_from_t<250> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<250>::reductions = {
    {317, { 250 }}
  };
  template <>
  struct reductions_from_t<251> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<251>::reductions = {
    {322, { 251 }}
  };
  template <>
  struct reductions_from_t<252> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<252>::reductions = {
    {346, { 252 }}
  };
  template <>
  struct reductions_from_t<253> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<253>::reductions = {
    {345, { 253 }}
  };
  template <>
  struct reductions_from_t<254> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<254>::reductions = {
    {343, { 254 }}
  };
  template <>
  struct reductions_from_t<256> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<256>::reductions = {
    {530, { 255, 39, 256 }},
    {334, { 256 }}
  };
  template <>
  struct reductions_from_t<257> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<257>::reductions = {
    {347, { 257 }}
  };
  template <>
  struct reductions_from_t<259> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<259>::reductions = {
    {456, { 258, 259 }},
    {340, { 259 }}
  };
  template <>
  struct reductions_from_t<260> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<260>::reductions = {
    {342, { 260 }}
  };
  template <>
  struct reductions_from_t<262> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<262>::reductions = {
    {457, { 258, 262 }},
    {235, { 262 }},
    {316, { 262 }},
    {327, { 262 }}
  };
  template <>
  struct reductions_from_t<263> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<263>::reductions = {
    {541, { 249, 39, 3, 263 }},
    {491, { 262, 3, 263 }},
    {502, { 251, 3, 263 }},
    {455, { 264, 263 }},
    {481, { 3, 263 }}
  };
  template <>
  struct reductions_from_t<264> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<264>::reductions = {
    {367, { 264 }}
  };
  template <>
  struct reductions_from_t<265> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<265>::reductions = {
    {344, { 265 }}
  };
  template <>
  struct reductions_from_t<266> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<266>::reductions = {
    {291, { 266 }}
  };
  template <>
  struct reductions_from_t<268> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<268>::reductions = {
    {479, { 267, 268 }},
    {270, { 268 }}
  };
  template <>
  struct reductions_from_t<270> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<270>::reductions = {
    {504, { 269, 39, 270 }},
    {268, { 270 }}
  };
  template <>
  struct reductions_from_t<271> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<271>::reductions = {
    {557, { 249, 39, 3, 263, 41, 271 }},
    {553, { 249, 39, 3, 41, 271 }},
    {554, { 251, 3, 263, 41, 271 }},
    {547, { 251, 3, 41, 271 }},
    {548, { 251, 3, 41, 271 }},
    {511, { 272, 39, 271 }},
    {262, { 271 }}
  };
  template <>
  struct reductions_from_t<273> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<273>::reductions = {
    {229, { 273 }},
    {257, { 273 }}
  };
  template <>
  struct reductions_from_t<274> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<274>::reductions = {
    {533, { 274, 71, 274 }},
    {485, { 279, 274 }},
    {238, { 274 }},
    {240, { 274 }}
  };
  template <>
  struct reductions_from_t<275> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<275>::reductions = {
    {246, { 275 }},
    {258, { 275 }}
  };
  template <>
  struct reductions_from_t<276> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<276>::reductions = {
    {259, { 276 }}
  };
  template <>
  struct reductions_from_t<277> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<277>::reductions = {
    {555, { 72, 32, 288, 290, 33, 277 }},
    {552, { 2, 32, 283, 33, 277 }}
  };
  template <>
  struct reductions_from_t<278> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<278>::reductions = {
    {454, { 242, 278 }},
    {247, { 278 }}
  };
  template <>
  struct reductions_from_t<279> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<279>::reductions = {
    {232, { 279 }}
  };
  template <>
  struct reductions_from_t<280> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<280>::reductions = {
    {230, { 280 }},
    {256, { 280 }}
  };
  template <>
  struct reductions_from_t<281> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<281>::reductions = {
    {254, { 281 }}
  };
  template <>
  struct reductions_from_t<282> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<282>::reductions = {
    {549, { 73, 32, 238, 33, 282 }}
  };
  template <>
  struct reductions_from_t<283> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<283>::reductions = {
    {228, { 283 }}
  };
  template <>
  struct reductions_from_t<284> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<284>::reductions = {
    {253, { 284 }}
  };
  template <>
  struct reductions_from_t<286> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<286>::reductions = {
    {251, { 286 }}
  };
  template <>
  struct reductions_from_t<287> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<287>::reductions = {
    {250, { 287 }}
  };
  template <>
  struct reductions_from_t<291> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<291>::reductions = {
    {248, { 291 }}
  };
  template <>
  struct reductions_from_t<293> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<293>::reductions = {
    {458, { 292, 293 }},
    {223, { 293 }}
  };
  template <>
  struct reductions_from_t<294> {
    static const std::map<int, std::vector<int>> reductions;
  };

  const std::map<int, std::vector<int>> reductions_from_t<294>::reductions = {
    {222, { 294 }}
  };

}   // ast

}   // gliss
