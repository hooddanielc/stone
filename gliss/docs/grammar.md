# Grammar

### The following describes the grammar for the OpenGL Shading Language in terms of [these tokens](tokens.md).

The starting rule is [translation_unit](#translation_unit). An empty shader (one having no tokens to parse, after preprocessing) is valid, resulting in no compile-time errors, even though the grammar below does not have a rule to accept an empty token stream. Taken from [OpenGL 4.60 Specification Ch. 9](https://www.khronos.org/registry/OpenGL/specs/gl/GLSLangSpec.4.60.pdf) 

#### variable_identifier:
*  _IDENTIFIER_

#### primary_expression:
*  [variable_identifier](#variable_identifier)
*  _BOOLCONSTANT_
*  _DOUBLECONSTANT_
*  _FLOATCONSTANT_
*  _INTCONSTANT_
*  _LEFT_PAREN_ [expression](#expression) _RIGHT_PAREN_
*  _UINTCONSTANT_

#### postfix_expression:
*  [function_call](#function_call)
*  [postfix_expression](#postfix_expression) _DEC_OP_
*  [postfix_expression](#postfix_expression) _DOT_ _FIELD_SELECTION_
*  [postfix_expression](#postfix_expression) _INC_OP_
*  [postfix_expression](#postfix_expression) _LEFT_BRACKET_ [integer_expression](#integer_expression) _RIGHT_BRACKET_
*  [primary_expression](#primary_expression)

#### integer_expression:
*  [expression](#expression)

#### function_call:
*  [function_call_or_method](#function_call_or_method)

#### function_call_or_method:
*  [function_call_generic](#function_call_generic)

#### function_call_generic:
*  [function_call_header_no_parameters](#function_call_header_no_parameters) _RIGHT_PAREN_
*  [function_call_header_with_parameters](#function_call_header_with_parameters) _RIGHT_PAREN_

#### function_call_header_no_parameters:
*  [function_call_header](#function_call_header)
*  [function_call_header](#function_call_header) _VOID_

#### function_call_header_with_parameters:
*  [function_call_header](#function_call_header) [assignment_expression](#assignment_expression)
*  [function_call_header_with_parameters](#function_call_header_with_parameters) _COMMA_ [assignment_expression](#assignment_expression)

#### function_call_header:
*  [function_identifier](#function_identifier) _LEFT_PAREN_

#### function_identifier:
*  [postfix_expression](#postfix_expression)
*  [type_specifier](#type_specifier)

#### unary_expression:
*  [postfix_expression](#postfix_expression)
*  [unary_operator](#unary_operator) [unary_expression](#unary_expression)
*  _DEC_OP_ [unary_expression](#unary_expression)
*  _INC_OP_ [unary_expression](#unary_expression)

#### unary_operator:
*  _BANG_
*  _DASH_
*  _PLUS_
*  _TILDE_

#### multiplicative_expression:
*  [multiplicative_expression](#multiplicative_expression) _PERCENT_ [unary_expression](#unary_expression)
*  [multiplicative_expression](#multiplicative_expression) _SLASH_ [unary_expression](#unary_expression)
*  [multiplicative_expression](#multiplicative_expression) _STAR_ [unary_expression](#unary_expression)
*  [unary_expression](#unary_expression)

#### additive_expression:
*  [additive_expression](#additive_expression) _DASH_ [multiplicative_expression](#multiplicative_expression)
*  [additive_expression](#additive_expression) _PLUS_ [multiplicative_expression](#multiplicative_expression)
*  [multiplicative_expression](#multiplicative_expression)

#### shift_expression:
*  [additive_expression](#additive_expression)
*  [shift_expression](#shift_expression) _LEFT_OP_ [additive_expression](#additive_expression)
*  [shift_expression](#shift_expression) _RIGHT_OP_ [additive_expression](#additive_expression)

#### relational_expression:
*  [relational_expression](#relational_expression) _GE_OP_ [shift_expression](#shift_expression)
*  [relational_expression](#relational_expression) _LEFT_ANGLE_ [shift_expression](#shift_expression)
*  [relational_expression](#relational_expression) _LE_OP_ [shift_expression](#shift_expression)
*  [relational_expression](#relational_expression) _RIGHT_ANGLE_ [shift_expression](#shift_expression)
*  [shift_expression](#shift_expression)

#### equality_expression:
*  [equality_expression](#equality_expression) _EQ_OP_ [relational_expression](#relational_expression)
*  [equality_expression](#equality_expression) _NE_OP_ [relational_expression](#relational_expression)
*  [relational_expression](#relational_expression)

#### and_expression:
*  [and_expression](#and_expression) _AMPERSAND_ [equality_expression](#equality_expression)
*  [equality_expression](#equality_expression)

#### exclusive_or_expression:
*  [and_expression](#and_expression)
*  [exclusive_or_expression](#exclusive_or_expression) _CARET_ [and_expression](#and_expression)

#### inclusive_or_expression:
*  [exclusive_or_expression](#exclusive_or_expression)
*  [inclusive_or_expression](#inclusive_or_expression) _VERTICAL_BAR_ [exclusive_or_expression](#exclusive_or_expression)

#### logical_and_expression:
*  [inclusive_or_expression](#inclusive_or_expression)
*  [logical_and_expression](#logical_and_expression) _AND_OP_ [inclusive_or_expression](#inclusive_or_expression)

#### logical_xor_expression:
*  [logical_and_expression](#logical_and_expression)
*  [logical_xor_expression](#logical_xor_expression) _XOR_OP_ [logical_and_expression](#logical_and_expression)

#### logical_or_expression:
*  [logical_or_expression](#logical_or_expression) _OR_OP_ [logical_xor_expression](#logical_xor_expression)
*  [logical_xor_expression](#logical_xor_expression)

#### conditional_expression:
*  [logical_or_expression](#logical_or_expression)
*  [logical_or_expression](#logical_or_expression) _QUESTION_ [expression](#expression) _COLON_ [assignment_expression](#assignment_expression)

#### assignment_expression:
*  [conditional_expression](#conditional_expression)
*  [unary_expression](#unary_expression) [assignment_operator](#assignment_operator) [assignment_expression](#assignment_expression)

#### assignment_operator:
*  _ADD_ASSIGN_
*  _AND_ASSIGN_
*  _DIV_ASSIGN_
*  _EQUAL_
*  _LEFT_ASSIGN_
*  _MOD_ASSIGN_
*  _MUL_ASSIGN_
*  _OR_ASSIGN_
*  _RIGHT_ASSIGN_
*  _SUB_ASSIGN_
*  _XOR_ASSIGN_

#### expression:
*  [assignment_expression](#assignment_expression)
*  [expression](#expression) _COMMA_ [assignment_expression](#assignment_expression)

#### constant_expression:
*  [conditional_expression](#conditional_expression)

#### declaration:
*  [function_prototype](#function_prototype) _SEMICOLON_
*  [init_declarator_list](#init_declarator_list) _SEMICOLON_
*  [type_qualifier](#type_qualifier) _IDENTIFIER_ [identifier_list](#identifier_list) _SEMICOLON_
*  [type_qualifier](#type_qualifier) _IDENTIFIER_ _LEFT_BRACE_ [struct_declaration_list](#struct_declaration_list) _RIGHT_BRACE_ _IDENTIFIER_ [array_specifier](#array_specifier) _SEMICOLON_
*  [type_qualifier](#type_qualifier) _IDENTIFIER_ _LEFT_BRACE_ [struct_declaration_list](#struct_declaration_list) _RIGHT_BRACE_ _IDENTIFIER_ _SEMICOLON_
*  [type_qualifier](#type_qualifier) _IDENTIFIER_ _LEFT_BRACE_ [struct_declaration_list](#struct_declaration_list) _RIGHT_BRACE_ _SEMICOLON_
*  [type_qualifier](#type_qualifier) _IDENTIFIER_ _SEMICOLON_
*  [type_qualifier](#type_qualifier) _SEMICOLON_
*  _PRECISION_ [precision_qualifier](#precision_qualifier) [type_specifier](#type_specifier) _SEMICOLON_

#### identifier_list:
*  [identifier_list](#identifier_list) _COMMA_ _IDENTIFIER_
*  _COMMA_ _IDENTIFIER_

#### function_prototype:
*  [function_declarator](#function_declarator) _RIGHT_PAREN_

#### function_declarator:
*  [function_header](#function_header)
*  [function_header_with_parameters](#function_header_with_parameters)

#### function_header_with_parameters:
*  [function_header](#function_header) [parameter_declaration](#parameter_declaration)
*  [function_header_with_parameters](#function_header_with_parameters) _COMMA_ [parameter_declaration](#parameter_declaration)

#### function_header:
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_ _LEFT_PAREN_

#### parameter_declarator:
*  [type_specifier](#type_specifier) _IDENTIFIER_
*  [type_specifier](#type_specifier) _IDENTIFIER_ [array_specifier](#array_specifier)

#### parameter_declaration:
*  [parameter_declarator](#parameter_declarator)
*  [parameter_type_specifier](#parameter_type_specifier)
*  [type_qualifier](#type_qualifier) [parameter_declarator](#parameter_declarator)
*  [type_qualifier](#type_qualifier) [parameter_type_specifier](#parameter_type_specifier)

#### parameter_type_specifier:
*  [type_specifier](#type_specifier)

#### init_declarator_list:
*  [init_declarator_list](#init_declarator_list) _COMMA_ _IDENTIFIER_
*  [init_declarator_list](#init_declarator_list) _COMMA_ _IDENTIFIER_ [array_specifier](#array_specifier)
*  [init_declarator_list](#init_declarator_list) _COMMA_ _IDENTIFIER_ [array_specifier](#array_specifier) _EQUAL_ [initializer](#initializer)
*  [init_declarator_list](#init_declarator_list) _COMMA_ _IDENTIFIER_ _EQUAL_ [initializer](#initializer)
*  [single_declaration](#single_declaration)

#### single_declaration:
*  [fully_specified_type](#fully_specified_type)
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_ [array_specifier](#array_specifier)
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_ [array_specifier](#array_specifier) _EQUAL_ [initializer](#initializer)
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_ _EQUAL_ [initializer](#initializer)

#### fully_specified_type:
*  [type_qualifier](#type_qualifier) [type_specifier](#type_specifier)
*  [type_specifier](#type_specifier)

#### invariant_qualifier:
*  _INVARIANT_

#### interpolation_qualifier:
*  _FLAT_
*  _NOPERSPECTIVE_
*  _SMOOTH_

#### layout_qualifier:
*  _LAYOUT_ _LEFT_PAREN_ [layout_qualifier_id_list](#layout_qualifier_id_list) _RIGHT_PAREN_

#### layout_qualifier_id_list:
*  [layout_qualifier_id](#layout_qualifier_id)
*  [layout_qualifier_id_list](#layout_qualifier_id_list) _COMMA_ [layout_qualifier_id](#layout_qualifier_id)

#### layout_qualifier_id:
*  _IDENTIFIER_
*  _IDENTIFIER_ _EQUAL_ [constant_expression](#constant_expression)
*  _SHARED_

#### precise_qualifier:
*  _PRECISE_

#### type_qualifier:
*  [single_type_qualifier](#single_type_qualifier)
*  [type_qualifier](#type_qualifier) [single_type_qualifier](#single_type_qualifier)

#### single_type_qualifier:
*  [interpolation_qualifier](#interpolation_qualifier)
*  [invariant_qualifier](#invariant_qualifier)
*  [layout_qualifier](#layout_qualifier)
*  [precise_qualifier](#precise_qualifier)
*  [precision_qualifier](#precision_qualifier)
*  [storage_qualifier](#storage_qualifier)

#### storage_qualifier:
*  _BUFFER_
*  _CENTROID_
*  _COHERENT_
*  _CONST_
*  _INOUT_
*  _IN_
*  _OUT_
*  _PATCH_
*  _READONLY_
*  _RESTRICT_
*  _SAMPLE_
*  _SHARED_
*  _SUBROUTINE_
*  _SUBROUTINE_ _LEFT_PAREN_ [type_name_list](#type_name_list) _RIGHT_PAREN_
*  _UNIFORM_
*  _VOLATILE_
*  _WRITEONLY_

#### type_name_list:
*  [type_name_list](#type_name_list) _COMMA_ _TYPE_NAME_
*  _TYPE_NAME_

#### type_specifier:
*  [type_specifier_nonarray](#type_specifier_nonarray)
*  [type_specifier_nonarray](#type_specifier_nonarray) [array_specifier](#array_specifier)

#### array_specifier:
*  [array_specifier](#array_specifier) _LEFT_BRACKET_ [conditional_expression](#conditional_expression) _RIGHT_BRACKET_
*  [array_specifier](#array_specifier) _LEFT_BRACKET_ _RIGHT_BRACKET_
*  _LEFT_BRACKET_ [conditional_expression](#conditional_expression) _RIGHT_BRACKET_
*  _LEFT_BRACKET_ _RIGHT_BRACKET_

#### type_specifier_nonarray:
*  [struct_specifier](#struct_specifier)
*  _ATOMIC_UINT_
*  _BOOL_
*  _BVEC2_
*  _BVEC3_
*  _BVEC4_
*  _DMAT2X2_
*  _DMAT2X3_
*  _DMAT2X4_
*  _DMAT2_
*  _DMAT3X2_
*  _DMAT3X3_
*  _DMAT3X4_
*  _DMAT3_
*  _DMAT4X2_
*  _DMAT4X3_
*  _DMAT4X4_
*  _DMAT4_
*  _DOUBLE_
*  _DVEC2_
*  _DVEC3_
*  _DVEC4_
*  _FLOAT_
*  _IIMAGE1DARRAY_
*  _IIMAGE1D_
*  _IIMAGE2DARRAY_
*  _IIMAGE2DMSARRAY_
*  _IIMAGE2DMS_
*  _IIMAGE2DRECT_
*  _IIMAGE2D_
*  _IIMAGE3D_
*  _IIMAGEBUFFER_
*  _IIMAGECUBEARRAY_
*  _IIMAGECUBE_
*  _IMAGE1DARRAY_
*  _IMAGE1D_
*  _IMAGE2DARRAY_
*  _IMAGE2DMSARRAY_
*  _IMAGE2DMS_
*  _IMAGE2DRECT_
*  _IMAGE2D_
*  _IMAGE3D_
*  _IMAGEBUFFER_
*  _IMAGECUBEARRAY_
*  _IMAGECUBE_
*  _INT_
*  _ISAMPLER1DARRAY_
*  _ISAMPLER1D_
*  _ISAMPLER2DARRAY_
*  _ISAMPLER2DMSARRAY_
*  _ISAMPLER2DMS_
*  _ISAMPLER2DRECT_
*  _ISAMPLER2D_
*  _ISAMPLER3D_
*  _ISAMPLERBUFFER_
*  _ISAMPLERCUBEARRAY_
*  _ISAMPLERCUBE_
*  _IVEC2_
*  _IVEC3_
*  _IVEC4_
*  _MAT2X2_
*  _MAT2X3_
*  _MAT2X4_
*  _MAT2_
*  _MAT3X2_
*  _MAT3X3_
*  _MAT3X4_
*  _MAT3_
*  _MAT4X2_
*  _MAT4X3_
*  _MAT4X4_
*  _MAT4_
*  _SAMPLER1DARRAYSHADOW_
*  _SAMPLER1DARRAY_
*  _SAMPLER1DSHADOW_
*  _SAMPLER1D_
*  _SAMPLER2DARRAYSHADOW_
*  _SAMPLER2DARRAY_
*  _SAMPLER2DMSARRAY_
*  _SAMPLER2DMS_
*  _SAMPLER2DRECTSHADOW_
*  _SAMPLER2DRECT_
*  _SAMPLER2DSHADOW_
*  _SAMPLER2D_
*  _SAMPLER3D_
*  _SAMPLERBUFFER_
*  _SAMPLERCUBEARRAYSHADOW_
*  _SAMPLERCUBEARRAY_
*  _SAMPLERCUBESHADOW_
*  _SAMPLERCUBE_
*  _TYPE_NAME_
*  _UIMAGE1DARRAY_
*  _UIMAGE1D_
*  _UIMAGE2DARRAY_
*  _UIMAGE2DMSARRAY_
*  _UIMAGE2DMS_
*  _UIMAGE2DRECT_
*  _UIMAGE2D_
*  _UIMAGE3D_
*  _UIMAGEBUFFER_
*  _UIMAGECUBEARRAY_
*  _UIMAGECUBE_
*  _UINT_
*  _USAMPLER1DARRAY_
*  _USAMPLER1D_
*  _USAMPLER2DARRAY_
*  _USAMPLER2DMSARRAY_
*  _USAMPLER2DMS_
*  _USAMPLER2DRECT_
*  _USAMPLER2D_
*  _USAMPLER3D_
*  _USAMPLERBUFFER_
*  _USAMPLERCUBEARRAY_
*  _USAMPLERCUBE_
*  _UVEC2_
*  _UVEC3_
*  _UVEC4_
*  _VEC2_
*  _VEC3_
*  _VEC4_
*  _VOID_

#### precision_qualifier:
*  _HIGH_PRECISION_
*  _LOW_PRECISION_
*  _MEDIUM_PRECISION_

#### struct_specifier:
*  _STRUCT_ _IDENTIFIER_ _LEFT_BRACE_ [struct_declaration_list](#struct_declaration_list) _RIGHT_BRACE_
*  _STRUCT_ _LEFT_BRACE_ [struct_declaration_list](#struct_declaration_list) _RIGHT_BRACE_

#### struct_declaration_list:
*  [struct_declaration](#struct_declaration)
*  [struct_declaration_list](#struct_declaration_list) [struct_declaration](#struct_declaration)

#### struct_declaration:
*  [type_qualifier](#type_qualifier) [type_specifier](#type_specifier) [struct_declarator_list](#struct_declarator_list) _SEMICOLON_
*  [type_specifier](#type_specifier) [struct_declarator_list](#struct_declarator_list) _SEMICOLON_

#### struct_declarator_list:
*  [struct_declarator](#struct_declarator)
*  [struct_declarator_list](#struct_declarator_list) _COMMA_ [struct_declarator](#struct_declarator)

#### struct_declarator:
*  _IDENTIFIER_
*  _IDENTIFIER_ [array_specifier](#array_specifier)

#### initializer:
*  [assignment_expression](#assignment_expression)
*  _LEFT_BRACE_ [initializer_list](#initializer_list) _COMMA_ _RIGHT_BRACE_
*  _LEFT_BRACE_ [initializer_list](#initializer_list) _RIGHT_BRACE_

#### initializer_list:
*  [initializer](#initializer)
*  [initializer_list](#initializer_list) _COMMA_ [initializer](#initializer)

#### declaration_statement:
*  [declaration](#declaration)

#### statement:
*  [compound_statement](#compound_statement)
*  [simple_statement](#simple_statement)

#### simple_statement:
*  [case_label](#case_label)
*  [declaration_statement](#declaration_statement)
*  [expression_statement](#expression_statement)
*  [iteration_statement](#iteration_statement)
*  [jump_statement](#jump_statement)
*  [selection_statement](#selection_statement)
*  [switch_statement](#switch_statement)

#### compound_statement:
*  _LEFT_BRACE_ [statement_list](#statement_list) _RIGHT_BRACE_
*  _LEFT_BRACE_ _RIGHT_BRACE_

#### statement_no_new_scope:
*  [compound_statement_no_new_scope](#compound_statement_no_new_scope)
*  [simple_statement](#simple_statement)

#### compound_statement_no_new_scope:
*  _LEFT_BRACE_ [statement_list](#statement_list) _RIGHT_BRACE_
*  _LEFT_BRACE_ _RIGHT_BRACE_

#### statement_list:
*  [statement](#statement)
*  [statement_list](#statement_list) [statement](#statement)

#### expression_statement:
*  [expression](#expression) _SEMICOLON_
*  _SEMICOLON_

#### selection_statement:
*  _IF_ _LEFT_PAREN_ [expression](#expression) _RIGHT_PAREN_ [selection_rest_statement](#selection_rest_statement)

#### selection_rest_statement:
*  [statement](#statement)
*  [statement](#statement) _ELSE_ [statement](#statement)

#### condition:
*  [expression](#expression)
*  [fully_specified_type](#fully_specified_type) _IDENTIFIER_ _EQUAL_ [initializer](#initializer)

#### switch_statement:
*  _SWITCH_ _LEFT_PAREN_ [expression](#expression) _RIGHT_PAREN_ _LEFT_BRACE_ [switch_statement_list](#switch_statement_list) _RIGHT_BRACE_

#### switch_statement_list:
*  [nothing](#nothing)
*  [statement_list](#statement_list)

#### case_label:
*  _CASE_ [expression](#expression) _COLON_
*  _DEFAULT_ _COLON_

#### iteration_statement:
*  _DO_ [statement](#statement) _WHILE_ _LEFT_PAREN_ [expression](#expression) _RIGHT_PAREN_ _SEMICOLON_
*  _FOR_ _LEFT_PAREN_ [for_init_statement](#for_init_statement) [for_rest_statement](#for_rest_statement) _RIGHT_PAREN_ [statement_no_new_scope](#statement_no_new_scope)
*  _WHILE_ _LEFT_PAREN_ [condition](#condition) _RIGHT_PAREN_ [statement_no_new_scope](#statement_no_new_scope)

#### for_init_statement:
*  [declaration_statement](#declaration_statement)
*  [expression_statement](#expression_statement)

#### conditionopt:
*  [condition](#condition)
*  [nothing](#nothing)

#### nothing:

#### for_rest_statement:
*  [conditionopt](#conditionopt) _SEMICOLON_
*  [conditionopt](#conditionopt) _SEMICOLON_ [expression](#expression)

#### jump_statement:
*  _BREAK_ _SEMICOLON_
*  _CONTINUE_ _SEMICOLON_
*  _DISCARD_ _SEMICOLON_
*  _RETURN_ [expression](#expression) _SEMICOLON_
*  _RETURN_ _SEMICOLON_

#### translation_unit:
*  [external_declaration](#external_declaration)
*  [translation_unit](#translation_unit) [external_declaration](#external_declaration)

#### external_declaration:
*  [declaration](#declaration)
*  [function_definition](#function_definition)
*  _SEMICOLON_

#### function_definition:
*  [function_prototype](#function_prototype) [compound_statement_no_new_scope](#compound_statement_no_new_scope)