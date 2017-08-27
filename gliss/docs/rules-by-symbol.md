# Rules By Symbol
#### IDENTIFIER - 27 rules

  __variable_identifier__
    - IDENTIFIER

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
    - type_qualifier IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER identifier_list SEMICOLON

  __identifier_list__
    - COMMA IDENTIFIER
    - identifier_list COMMA IDENTIFIER

  __function_header__
    - fully_specified_type IDENTIFIER LEFT_PAREN

  __parameter_declarator__
    - type_specifier IDENTIFIER
    - type_specifier IDENTIFIER array_specifier

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER
    - init_declarator_list COMMA IDENTIFIER array_specifier
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
    - init_declarator_list COMMA IDENTIFIER EQUAL initializer

  __single_declaration__
    - fully_specified_type IDENTIFIER
    - fully_specified_type IDENTIFIER array_specifier
    - fully_specified_type IDENTIFIER array_specifier EQUAL initializer
    - fully_specified_type IDENTIFIER EQUAL initializer

  __layout_qualifier_id__
    - IDENTIFIER
    - IDENTIFIER EQUAL constant_expression

  __struct_specifier__
    - STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE

  __struct_declarator__
    - IDENTIFIER
    - IDENTIFIER array_specifier

  __condition__
    - fully_specified_type IDENTIFIER EQUAL initializer


#### SEMICOLON - 22 rules

  __declaration__
    - function_prototype SEMICOLON
    - init_declarator_list SEMICOLON
    - PRECISION precision_qualifier type_specifier SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
    - type_qualifier SEMICOLON
    - type_qualifier IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER identifier_list SEMICOLON

  __struct_declaration__
    - type_specifier struct_declarator_list SEMICOLON
    - type_qualifier type_specifier struct_declarator_list SEMICOLON

  __expression_statement__
    - SEMICOLON
    - expression SEMICOLON

  __iteration_statement__
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON

  __for_rest_statement__
    - conditionopt SEMICOLON
    - conditionopt SEMICOLON expression

  __jump_statement__
    - CONTINUE SEMICOLON
    - BREAK SEMICOLON
    - RETURN SEMICOLON
    - RETURN expression SEMICOLON
    - DISCARD SEMICOLON

  __external_declaration__
    - SEMICOLON


#### COMMA - 14 rules

  __function_call_header_with_parameters__
    - function_call_header_with_parameters COMMA assignment_expression

  __expression__
    - expression COMMA assignment_expression

  __identifier_list__
    - COMMA IDENTIFIER
    - identifier_list COMMA IDENTIFIER

  __function_header_with_parameters__
    - function_header_with_parameters COMMA parameter_declaration

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER
    - init_declarator_list COMMA IDENTIFIER array_specifier
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
    - init_declarator_list COMMA IDENTIFIER EQUAL initializer

  __layout_qualifier_id_list__
    - layout_qualifier_id_list COMMA layout_qualifier_id

  __type_name_list__
    - type_name_list COMMA TYPE_NAME

  __struct_declarator_list__
    - struct_declarator_list COMMA struct_declarator

  __initializer__
    - LEFT_BRACE initializer_list COMMA RIGHT_BRACE

  __initializer_list__
    - initializer_list COMMA initializer


#### RIGHT_BRACE - 12 rules

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON

  __struct_specifier__
    - STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
    - STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE

  __initializer__
    - LEFT_BRACE initializer_list RIGHT_BRACE
    - LEFT_BRACE initializer_list COMMA RIGHT_BRACE

  __compound_statement__
    - LEFT_BRACE RIGHT_BRACE
    - LEFT_BRACE statement_list RIGHT_BRACE

  __compound_statement_no_new_scope__
    - LEFT_BRACE RIGHT_BRACE
    - LEFT_BRACE statement_list RIGHT_BRACE

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE


#### LEFT_BRACE - 12 rules

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON

  __struct_specifier__
    - STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
    - STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE

  __initializer__
    - LEFT_BRACE initializer_list RIGHT_BRACE
    - LEFT_BRACE initializer_list COMMA RIGHT_BRACE

  __compound_statement__
    - LEFT_BRACE RIGHT_BRACE
    - LEFT_BRACE statement_list RIGHT_BRACE

  __compound_statement_no_new_scope__
    - LEFT_BRACE RIGHT_BRACE
    - LEFT_BRACE statement_list RIGHT_BRACE

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE


#### expression - 12 rules

  __primary_expression__
    - LEFT_PAREN expression RIGHT_PAREN

  __integer_expression__
    - expression

  __conditional_expression__
    - logical_or_expression QUESTION expression COLON assignment_expression

  __expression__
    - expression COMMA assignment_expression

  __expression_statement__
    - expression SEMICOLON

  __selection_statement__
    - IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement

  __condition__
    - expression

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE

  __case_label__
    - CASE expression COLON

  __iteration_statement__
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON

  __for_rest_statement__
    - conditionopt SEMICOLON expression

  __jump_statement__
    - RETURN expression SEMICOLON


#### RIGHT_PAREN - 11 rules

  __primary_expression__
    - LEFT_PAREN expression RIGHT_PAREN

  __function_call_generic__
    - function_call_header_with_parameters RIGHT_PAREN
    - function_call_header_no_parameters RIGHT_PAREN

  __function_prototype__
    - function_declarator RIGHT_PAREN

  __layout_qualifier__
    - LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN

  __storage_qualifier__
    - SUBROUTINE LEFT_PAREN type_name_list RIGHT_PAREN

  __selection_statement__
    - IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE

  __iteration_statement__
    - WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### type_qualifier - 11 rules

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
    - type_qualifier SEMICOLON
    - type_qualifier IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER identifier_list SEMICOLON

  __parameter_declaration__
    - type_qualifier parameter_declarator
    - type_qualifier parameter_type_specifier

  __fully_specified_type__
    - type_qualifier type_specifier

  __type_qualifier__
    - type_qualifier single_type_qualifier

  __struct_declaration__
    - type_qualifier type_specifier struct_declarator_list SEMICOLON


#### array_specifier - 10 rules

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON

  __parameter_declarator__
    - type_specifier IDENTIFIER array_specifier

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER array_specifier
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer

  __single_declaration__
    - fully_specified_type IDENTIFIER array_specifier
    - fully_specified_type IDENTIFIER array_specifier EQUAL initializer

  __type_specifier__
    - type_specifier_nonarray array_specifier

  __array_specifier__
    - array_specifier LEFT_BRACKET RIGHT_BRACKET
    - array_specifier LEFT_BRACKET conditional_expression RIGHT_BRACKET

  __struct_declarator__
    - IDENTIFIER array_specifier


#### LEFT_PAREN - 10 rules

  __primary_expression__
    - LEFT_PAREN expression RIGHT_PAREN

  __function_call_header__
    - function_identifier LEFT_PAREN

  __function_header__
    - fully_specified_type IDENTIFIER LEFT_PAREN

  __layout_qualifier__
    - LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN

  __storage_qualifier__
    - SUBROUTINE LEFT_PAREN type_name_list RIGHT_PAREN

  __selection_statement__
    - IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE

  __iteration_statement__
    - WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### type_specifier - 9 rules

  __function_identifier__
    - type_specifier

  __declaration__
    - PRECISION precision_qualifier type_specifier SEMICOLON

  __parameter_declarator__
    - type_specifier IDENTIFIER
    - type_specifier IDENTIFIER array_specifier

  __parameter_type_specifier__
    - type_specifier

  __fully_specified_type__
    - type_specifier
    - type_qualifier type_specifier

  __struct_declaration__
    - type_specifier struct_declarator_list SEMICOLON
    - type_qualifier type_specifier struct_declarator_list SEMICOLON


#### unary_expression - 8 rules

  __unary_expression__
    - INC_OP unary_expression
    - DEC_OP unary_expression
    - unary_operator unary_expression

  __multiplicative_expression__
    - unary_expression
    - multiplicative_expression STAR unary_expression
    - multiplicative_expression SLASH unary_expression
    - multiplicative_expression PERCENT unary_expression

  __assignment_expression__
    - unary_expression assignment_operator assignment_expression


#### initializer - 7 rules

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
    - init_declarator_list COMMA IDENTIFIER EQUAL initializer

  __single_declaration__
    - fully_specified_type IDENTIFIER array_specifier EQUAL initializer
    - fully_specified_type IDENTIFIER EQUAL initializer

  __initializer_list__
    - initializer
    - initializer_list COMMA initializer

  __condition__
    - fully_specified_type IDENTIFIER EQUAL initializer


#### fully_specified_type - 7 rules

  __function_header__
    - fully_specified_type IDENTIFIER LEFT_PAREN

  __single_declaration__
    - fully_specified_type
    - fully_specified_type IDENTIFIER
    - fully_specified_type IDENTIFIER array_specifier
    - fully_specified_type IDENTIFIER array_specifier EQUAL initializer
    - fully_specified_type IDENTIFIER EQUAL initializer

  __condition__
    - fully_specified_type IDENTIFIER EQUAL initializer


#### relational_expression - 7 rules

  __relational_expression__
    - relational_expression LEFT_ANGLE shift_expression
    - relational_expression RIGHT_ANGLE shift_expression
    - relational_expression LE_OP shift_expression
    - relational_expression GE_OP shift_expression

  __equality_expression__
    - relational_expression
    - equality_expression EQ_OP relational_expression
    - equality_expression NE_OP relational_expression


#### EQUAL - 7 rules

  __assignment_operator__
    - EQUAL

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
    - init_declarator_list COMMA IDENTIFIER EQUAL initializer

  __single_declaration__
    - fully_specified_type IDENTIFIER array_specifier EQUAL initializer
    - fully_specified_type IDENTIFIER EQUAL initializer

  __layout_qualifier_id__
    - IDENTIFIER EQUAL constant_expression

  __condition__
    - fully_specified_type IDENTIFIER EQUAL initializer


#### shift_expression - 7 rules

  __shift_expression__
    - shift_expression LEFT_OP additive_expression
    - shift_expression RIGHT_OP additive_expression

  __relational_expression__
    - shift_expression
    - relational_expression LEFT_ANGLE shift_expression
    - relational_expression RIGHT_ANGLE shift_expression
    - relational_expression LE_OP shift_expression
    - relational_expression GE_OP shift_expression


#### assignment_expression - 7 rules

  __function_call_header_with_parameters__
    - function_call_header assignment_expression
    - function_call_header_with_parameters COMMA assignment_expression

  __conditional_expression__
    - logical_or_expression QUESTION expression COLON assignment_expression

  __assignment_expression__
    - unary_expression assignment_operator assignment_expression

  __expression__
    - assignment_expression
    - expression COMMA assignment_expression

  __initializer__
    - assignment_expression


#### multiplicative_expression - 6 rules

  __multiplicative_expression__
    - multiplicative_expression STAR unary_expression
    - multiplicative_expression SLASH unary_expression
    - multiplicative_expression PERCENT unary_expression

  __additive_expression__
    - multiplicative_expression
    - additive_expression PLUS multiplicative_expression
    - additive_expression DASH multiplicative_expression


#### struct_declaration_list - 6 rules

  __declaration__
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
    - type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON

  __struct_specifier__
    - STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
    - STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE

  __struct_declaration_list__
    - struct_declaration_list struct_declaration


#### postfix_expression - 6 rules

  __postfix_expression__
    - postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET
    - postfix_expression DOT FIELD_SELECTION
    - postfix_expression INC_OP
    - postfix_expression DEC_OP

  __function_identifier__
    - postfix_expression

  __unary_expression__
    - postfix_expression


#### statement - 6 rules

  __statement_list__
    - statement
    - statement_list statement

  __selection_rest_statement__
    - statement ELSE statement
    - statement ELSE statement
    - statement

  __iteration_statement__
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON


#### init_declarator_list - 5 rules

  __declaration__
    - init_declarator_list SEMICOLON

  __init_declarator_list__
    - init_declarator_list COMMA IDENTIFIER
    - init_declarator_list COMMA IDENTIFIER array_specifier
    - init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
    - init_declarator_list COMMA IDENTIFIER EQUAL initializer


#### LEFT_BRACKET - 5 rules

  __postfix_expression__
    - postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET

  __array_specifier__
    - LEFT_BRACKET RIGHT_BRACKET
    - LEFT_BRACKET conditional_expression RIGHT_BRACKET
    - array_specifier LEFT_BRACKET RIGHT_BRACKET
    - array_specifier LEFT_BRACKET conditional_expression RIGHT_BRACKET


#### RIGHT_BRACKET - 5 rules

  __postfix_expression__
    - postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET

  __array_specifier__
    - LEFT_BRACKET RIGHT_BRACKET
    - LEFT_BRACKET conditional_expression RIGHT_BRACKET
    - array_specifier LEFT_BRACKET RIGHT_BRACKET
    - array_specifier LEFT_BRACKET conditional_expression RIGHT_BRACKET


#### additive_expression - 5 rules

  __additive_expression__
    - additive_expression PLUS multiplicative_expression
    - additive_expression DASH multiplicative_expression

  __shift_expression__
    - additive_expression
    - shift_expression LEFT_OP additive_expression
    - shift_expression RIGHT_OP additive_expression


#### equality_expression - 4 rules

  __equality_expression__
    - equality_expression EQ_OP relational_expression
    - equality_expression NE_OP relational_expression

  __and_expression__
    - equality_expression
    - and_expression AMPERSAND equality_expression


#### conditional_expression - 4 rules

  __assignment_expression__
    - conditional_expression

  __constant_expression__
    - conditional_expression

  __array_specifier__
    - LEFT_BRACKET conditional_expression RIGHT_BRACKET
    - array_specifier LEFT_BRACKET conditional_expression RIGHT_BRACKET


#### statement_list - 4 rules

  __compound_statement__
    - LEFT_BRACE statement_list RIGHT_BRACE

  __compound_statement_no_new_scope__
    - LEFT_BRACE statement_list RIGHT_BRACE

  __statement_list__
    - statement_list statement

  __switch_statement_list__
    - statement_list


#### logical_xor_expression - 3 rules

  __logical_xor_expression__
    - logical_xor_expression XOR_OP logical_and_expression

  __logical_or_expression__
    - logical_xor_expression
    - logical_or_expression OR_OP logical_xor_expression


#### logical_and_expression - 3 rules

  __logical_and_expression__
    - logical_and_expression AND_OP inclusive_or_expression

  __logical_xor_expression__
    - logical_and_expression
    - logical_xor_expression XOR_OP logical_and_expression


#### exclusive_or_expression - 3 rules

  __exclusive_or_expression__
    - exclusive_or_expression CARET and_expression

  __inclusive_or_expression__
    - exclusive_or_expression
    - inclusive_or_expression VERTICAL_BAR exclusive_or_expression


#### function_call_header - 3 rules

  __function_call_header_no_parameters__
    - function_call_header VOID
    - function_call_header

  __function_call_header_with_parameters__
    - function_call_header assignment_expression


#### logical_or_expression - 3 rules

  __logical_or_expression__
    - logical_or_expression OR_OP logical_xor_expression

  __conditional_expression__
    - logical_or_expression
    - logical_or_expression QUESTION expression COLON assignment_expression


#### and_expression - 3 rules

  __and_expression__
    - and_expression AMPERSAND equality_expression

  __exclusive_or_expression__
    - and_expression
    - exclusive_or_expression CARET and_expression


#### TYPE_NAME - 3 rules

  __type_name_list__
    - TYPE_NAME
    - type_name_list COMMA TYPE_NAME

  __type_specifier_nonarray__
    - TYPE_NAME


#### struct_declarator_list - 3 rules

  __struct_declaration__
    - type_specifier struct_declarator_list SEMICOLON
    - type_qualifier type_specifier struct_declarator_list SEMICOLON

  __struct_declarator_list__
    - struct_declarator_list COMMA struct_declarator


#### initializer_list - 3 rules

  __initializer__
    - LEFT_BRACE initializer_list RIGHT_BRACE
    - LEFT_BRACE initializer_list COMMA RIGHT_BRACE

  __initializer_list__
    - initializer_list COMMA initializer


#### COLON - 3 rules

  __conditional_expression__
    - logical_or_expression QUESTION expression COLON assignment_expression

  __case_label__
    - CASE expression COLON
    - DEFAULT COLON


#### inclusive_or_expression - 3 rules

  __inclusive_or_expression__
    - inclusive_or_expression VERTICAL_BAR exclusive_or_expression

  __logical_and_expression__
    - inclusive_or_expression
    - logical_and_expression AND_OP inclusive_or_expression


#### DEC_OP - 2 rules

  __postfix_expression__
    - postfix_expression DEC_OP

  __unary_expression__
    - DEC_OP unary_expression


#### identifier_list - 2 rules

  __declaration__
    - type_qualifier IDENTIFIER identifier_list SEMICOLON

  __identifier_list__
    - identifier_list COMMA IDENTIFIER


#### function_header - 2 rules

  __function_declarator__
    - function_header

  __function_header_with_parameters__
    - function_header parameter_declaration


#### function_header_with_parameters - 2 rules

  __function_declarator__
    - function_header_with_parameters

  __function_header_with_parameters__
    - function_header_with_parameters COMMA parameter_declaration


#### parameter_declaration - 2 rules

  __function_header_with_parameters__
    - function_header parameter_declaration
    - function_header_with_parameters COMMA parameter_declaration


#### INC_OP - 2 rules

  __postfix_expression__
    - postfix_expression INC_OP

  __unary_expression__
    - INC_OP unary_expression


#### parameter_declarator - 2 rules

  __parameter_declaration__
    - type_qualifier parameter_declarator
    - parameter_declarator


#### parameter_type_specifier - 2 rules

  __parameter_declaration__
    - type_qualifier parameter_type_specifier
    - parameter_type_specifier


#### DASH - 2 rules

  __unary_operator__
    - DASH

  __additive_expression__
    - additive_expression DASH multiplicative_expression


#### external_declaration - 2 rules

  __translation_unit__
    - external_declaration
    - translation_unit external_declaration


#### layout_qualifier_id - 2 rules

  __layout_qualifier_id_list__
    - layout_qualifier_id
    - layout_qualifier_id_list COMMA layout_qualifier_id


#### SHARED - 2 rules

  __layout_qualifier_id__
    - SHARED

  __storage_qualifier__
    - SHARED


#### single_type_qualifier - 2 rules

  __type_qualifier__
    - single_type_qualifier
    - type_qualifier single_type_qualifier


#### SUBROUTINE - 2 rules

  __storage_qualifier__
    - SUBROUTINE
    - SUBROUTINE LEFT_PAREN type_name_list RIGHT_PAREN


#### type_name_list - 2 rules

  __storage_qualifier__
    - SUBROUTINE LEFT_PAREN type_name_list RIGHT_PAREN

  __type_name_list__
    - type_name_list COMMA TYPE_NAME


#### precision_qualifier - 2 rules

  __declaration__
    - PRECISION precision_qualifier type_specifier SEMICOLON

  __single_type_qualifier__
    - precision_qualifier


#### type_specifier_nonarray - 2 rules

  __type_specifier__
    - type_specifier_nonarray
    - type_specifier_nonarray array_specifier


#### STRUCT - 2 rules

  __struct_specifier__
    - STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
    - STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE


#### struct_declaration - 2 rules

  __struct_declaration_list__
    - struct_declaration
    - struct_declaration_list struct_declaration


#### PLUS - 2 rules

  __unary_operator__
    - PLUS

  __additive_expression__
    - additive_expression PLUS multiplicative_expression


#### struct_declarator - 2 rules

  __struct_declarator_list__
    - struct_declarator
    - struct_declarator_list COMMA struct_declarator


#### VOID - 2 rules

  __function_call_header_no_parameters__
    - function_call_header VOID

  __type_specifier_nonarray__
    - VOID


#### declaration - 2 rules

  __declaration_statement__
    - declaration

  __external_declaration__
    - declaration


#### simple_statement - 2 rules

  __statement__
    - simple_statement

  __statement_no_new_scope__
    - simple_statement


#### declaration_statement - 2 rules

  __simple_statement__
    - declaration_statement

  __for_init_statement__
    - declaration_statement


#### expression_statement - 2 rules

  __simple_statement__
    - expression_statement

  __for_init_statement__
    - expression_statement


#### function_prototype - 2 rules

  __declaration__
    - function_prototype SEMICOLON

  __function_definition__
    - function_prototype compound_statement_no_new_scope


#### compound_statement_no_new_scope - 2 rules

  __statement_no_new_scope__
    - compound_statement_no_new_scope

  __function_definition__
    - function_prototype compound_statement_no_new_scope


#### function_call_header_with_parameters - 2 rules

  __function_call_generic__
    - function_call_header_with_parameters RIGHT_PAREN

  __function_call_header_with_parameters__
    - function_call_header_with_parameters COMMA assignment_expression


#### nothing - 2 rules

  __switch_statement_list__
    - nothing

  __conditionopt__
    - nothing


#### WHILE - 2 rules

  __iteration_statement__
    - WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON


#### condition - 2 rules

  __iteration_statement__
    - WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope

  __conditionopt__
    - condition


#### statement_no_new_scope - 2 rules

  __iteration_statement__
    - WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### conditionopt - 2 rules

  __for_rest_statement__
    - conditionopt SEMICOLON
    - conditionopt SEMICOLON expression


#### RETURN - 2 rules

  __jump_statement__
    - RETURN SEMICOLON
    - RETURN expression SEMICOLON


#### layout_qualifier_id_list - 2 rules

  __layout_qualifier__
    - LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN

  __layout_qualifier_id_list__
    - layout_qualifier_id_list COMMA layout_qualifier_id


#### AND_ASSIGN - 1 rules

  __assignment_operator__
    - AND_ASSIGN


#### XOR_ASSIGN - 1 rules

  __assignment_operator__
    - XOR_ASSIGN


#### OR_ASSIGN - 1 rules

  __assignment_operator__
    - OR_ASSIGN


#### DOT - 1 rules

  __postfix_expression__
    - postfix_expression DOT FIELD_SELECTION


#### FIELD_SELECTION - 1 rules

  __postfix_expression__
    - postfix_expression DOT FIELD_SELECTION


#### BANG - 1 rules

  __unary_operator__
    - BANG


#### PRECISION - 1 rules

  __declaration__
    - PRECISION precision_qualifier type_specifier SEMICOLON


#### TILDE - 1 rules

  __unary_operator__
    - TILDE


#### function_definition - 1 rules

  __external_declaration__
    - function_definition


#### STAR - 1 rules

  __multiplicative_expression__
    - multiplicative_expression STAR unary_expression


#### SLASH - 1 rules

  __multiplicative_expression__
    - multiplicative_expression SLASH unary_expression


#### PERCENT - 1 rules

  __multiplicative_expression__
    - multiplicative_expression PERCENT unary_expression


#### INTCONSTANT - 1 rules

  __primary_expression__
    - INTCONSTANT


#### function_call_or_method - 1 rules

  __function_call__
    - function_call_or_method


#### function_declarator - 1 rules

  __function_prototype__
    - function_declarator RIGHT_PAREN


#### LEFT_OP - 1 rules

  __shift_expression__
    - shift_expression LEFT_OP additive_expression


#### RIGHT_OP - 1 rules

  __shift_expression__
    - shift_expression RIGHT_OP additive_expression


#### function_call_generic - 1 rules

  __function_call_or_method__
    - function_call_generic


#### LEFT_ANGLE - 1 rules

  __relational_expression__
    - relational_expression LEFT_ANGLE shift_expression


#### RIGHT_ANGLE - 1 rules

  __relational_expression__
    - relational_expression RIGHT_ANGLE shift_expression


#### LE_OP - 1 rules

  __relational_expression__
    - relational_expression LE_OP shift_expression


#### single_declaration - 1 rules

  __init_declarator_list__
    - single_declaration


#### GE_OP - 1 rules

  __relational_expression__
    - relational_expression GE_OP shift_expression


#### INVARIANT - 1 rules

  __invariant_qualifier__
    - INVARIANT


#### SMOOTH - 1 rules

  __interpolation_qualifier__
    - SMOOTH


#### FLAT - 1 rules

  __interpolation_qualifier__
    - FLAT


#### NOPERSPECTIVE - 1 rules

  __interpolation_qualifier__
    - NOPERSPECTIVE


#### LAYOUT - 1 rules

  __layout_qualifier__
    - LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN


#### UINTCONSTANT - 1 rules

  __primary_expression__
    - UINTCONSTANT


#### EQ_OP - 1 rules

  __equality_expression__
    - equality_expression EQ_OP relational_expression


#### constant_expression - 1 rules

  __layout_qualifier_id__
    - IDENTIFIER EQUAL constant_expression


#### NE_OP - 1 rules

  __equality_expression__
    - equality_expression NE_OP relational_expression


#### PRECISE - 1 rules

  __precise_qualifier__
    - PRECISE


#### function_call_header_no_parameters - 1 rules

  __function_call_generic__
    - function_call_header_no_parameters RIGHT_PAREN


#### storage_qualifier - 1 rules

  __single_type_qualifier__
    - storage_qualifier


#### layout_qualifier - 1 rules

  __single_type_qualifier__
    - layout_qualifier


#### interpolation_qualifier - 1 rules

  __single_type_qualifier__
    - interpolation_qualifier


#### invariant_qualifier - 1 rules

  __single_type_qualifier__
    - invariant_qualifier


#### precise_qualifier - 1 rules

  __single_type_qualifier__
    - precise_qualifier


#### CONST - 1 rules

  __storage_qualifier__
    - CONST


#### INOUT - 1 rules

  __storage_qualifier__
    - INOUT


#### IN - 1 rules

  __storage_qualifier__
    - IN


#### OUT - 1 rules

  __storage_qualifier__
    - OUT


#### CENTROID - 1 rules

  __storage_qualifier__
    - CENTROID


#### PATCH - 1 rules

  __storage_qualifier__
    - PATCH


#### SAMPLE - 1 rules

  __storage_qualifier__
    - SAMPLE


#### UNIFORM - 1 rules

  __storage_qualifier__
    - UNIFORM


#### BUFFER - 1 rules

  __storage_qualifier__
    - BUFFER


#### COHERENT - 1 rules

  __storage_qualifier__
    - COHERENT


#### VOLATILE - 1 rules

  __storage_qualifier__
    - VOLATILE


#### RESTRICT - 1 rules

  __storage_qualifier__
    - RESTRICT


#### READONLY - 1 rules

  __storage_qualifier__
    - READONLY


#### WRITEONLY - 1 rules

  __storage_qualifier__
    - WRITEONLY


#### AMPERSAND - 1 rules

  __and_expression__
    - and_expression AMPERSAND equality_expression


#### primary_expression - 1 rules

  __postfix_expression__
    - primary_expression


#### CARET - 1 rules

  __exclusive_or_expression__
    - exclusive_or_expression CARET and_expression


#### FLOATCONSTANT - 1 rules

  __primary_expression__
    - FLOATCONSTANT


#### FLOAT - 1 rules

  __type_specifier_nonarray__
    - FLOAT


#### DOUBLE - 1 rules

  __type_specifier_nonarray__
    - DOUBLE


#### INT - 1 rules

  __type_specifier_nonarray__
    - INT


#### UINT - 1 rules

  __type_specifier_nonarray__
    - UINT


#### BOOL - 1 rules

  __type_specifier_nonarray__
    - BOOL


#### VEC2 - 1 rules

  __type_specifier_nonarray__
    - VEC2


#### VEC3 - 1 rules

  __type_specifier_nonarray__
    - VEC3


#### VEC4 - 1 rules

  __type_specifier_nonarray__
    - VEC4


#### DVEC2 - 1 rules

  __type_specifier_nonarray__
    - DVEC2


#### DVEC3 - 1 rules

  __type_specifier_nonarray__
    - DVEC3


#### DVEC4 - 1 rules

  __type_specifier_nonarray__
    - DVEC4


#### BVEC2 - 1 rules

  __type_specifier_nonarray__
    - BVEC2


#### BVEC3 - 1 rules

  __type_specifier_nonarray__
    - BVEC3


#### BVEC4 - 1 rules

  __type_specifier_nonarray__
    - BVEC4


#### IVEC2 - 1 rules

  __type_specifier_nonarray__
    - IVEC2


#### variable_identifier - 1 rules

  __primary_expression__
    - variable_identifier


#### IVEC4 - 1 rules

  __type_specifier_nonarray__
    - IVEC4


#### UVEC2 - 1 rules

  __type_specifier_nonarray__
    - UVEC2


#### UVEC3 - 1 rules

  __type_specifier_nonarray__
    - UVEC3


#### UVEC4 - 1 rules

  __type_specifier_nonarray__
    - UVEC4


#### MAT2 - 1 rules

  __type_specifier_nonarray__
    - MAT2


#### MAT3 - 1 rules

  __type_specifier_nonarray__
    - MAT3


#### MAT4 - 1 rules

  __type_specifier_nonarray__
    - MAT4


#### MAT2X2 - 1 rules

  __type_specifier_nonarray__
    - MAT2X2


#### MAT2X3 - 1 rules

  __type_specifier_nonarray__
    - MAT2X3


#### MAT2X4 - 1 rules

  __type_specifier_nonarray__
    - MAT2X4


#### MAT3X2 - 1 rules

  __type_specifier_nonarray__
    - MAT3X2


#### MAT3X3 - 1 rules

  __type_specifier_nonarray__
    - MAT3X3


#### MAT3X4 - 1 rules

  __type_specifier_nonarray__
    - MAT3X4


#### MAT4X2 - 1 rules

  __type_specifier_nonarray__
    - MAT4X2


#### MAT4X3 - 1 rules

  __type_specifier_nonarray__
    - MAT4X3


#### MAT4X4 - 1 rules

  __type_specifier_nonarray__
    - MAT4X4


#### DMAT2 - 1 rules

  __type_specifier_nonarray__
    - DMAT2


#### DMAT3 - 1 rules

  __type_specifier_nonarray__
    - DMAT3


#### DMAT4 - 1 rules

  __type_specifier_nonarray__
    - DMAT4


#### DMAT2X2 - 1 rules

  __type_specifier_nonarray__
    - DMAT2X2


#### DMAT2X3 - 1 rules

  __type_specifier_nonarray__
    - DMAT2X3


#### DMAT2X4 - 1 rules

  __type_specifier_nonarray__
    - DMAT2X4


#### DMAT3X2 - 1 rules

  __type_specifier_nonarray__
    - DMAT3X2


#### DMAT3X3 - 1 rules

  __type_specifier_nonarray__
    - DMAT3X3


#### DMAT3X4 - 1 rules

  __type_specifier_nonarray__
    - DMAT3X4


#### DMAT4X2 - 1 rules

  __type_specifier_nonarray__
    - DMAT4X2


#### DMAT4X3 - 1 rules

  __type_specifier_nonarray__
    - DMAT4X3


#### DMAT4X4 - 1 rules

  __type_specifier_nonarray__
    - DMAT4X4


#### ATOMIC_UINT - 1 rules

  __type_specifier_nonarray__
    - ATOMIC_UINT


#### SAMPLER1D - 1 rules

  __type_specifier_nonarray__
    - SAMPLER1D


#### SAMPLER2D - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2D


#### SAMPLER3D - 1 rules

  __type_specifier_nonarray__
    - SAMPLER3D


#### SAMPLERCUBE - 1 rules

  __type_specifier_nonarray__
    - SAMPLERCUBE


#### SAMPLER1DSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLER1DSHADOW


#### SAMPLER2DSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DSHADOW


#### SAMPLERCUBESHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLERCUBESHADOW


#### SAMPLER1DARRAY - 1 rules

  __type_specifier_nonarray__
    - SAMPLER1DARRAY


#### SAMPLER2DARRAY - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DARRAY


#### SAMPLER1DARRAYSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLER1DARRAYSHADOW


#### SAMPLER2DARRAYSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DARRAYSHADOW


#### SAMPLERCUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - SAMPLERCUBEARRAY


#### SAMPLERCUBEARRAYSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLERCUBEARRAYSHADOW


#### ISAMPLER1D - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER1D


#### ISAMPLER2D - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER2D


#### ISAMPLER3D - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER3D


#### ISAMPLERCUBE - 1 rules

  __type_specifier_nonarray__
    - ISAMPLERCUBE


#### ISAMPLER1DARRAY - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER1DARRAY


#### ISAMPLER2DARRAY - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER2DARRAY


#### ISAMPLERCUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - ISAMPLERCUBEARRAY


#### USAMPLER1D - 1 rules

  __type_specifier_nonarray__
    - USAMPLER1D


#### USAMPLER2D - 1 rules

  __type_specifier_nonarray__
    - USAMPLER2D


#### USAMPLER3D - 1 rules

  __type_specifier_nonarray__
    - USAMPLER3D


#### USAMPLERCUBE - 1 rules

  __type_specifier_nonarray__
    - USAMPLERCUBE


#### USAMPLER1DARRAY - 1 rules

  __type_specifier_nonarray__
    - USAMPLER1DARRAY


#### USAMPLER2DARRAY - 1 rules

  __type_specifier_nonarray__
    - USAMPLER2DARRAY


#### USAMPLERCUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - USAMPLERCUBEARRAY


#### SAMPLER2DRECT - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DRECT


#### SAMPLER2DRECTSHADOW - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DRECTSHADOW


#### ISAMPLER2DRECT - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER2DRECT


#### USAMPLER2DRECT - 1 rules

  __type_specifier_nonarray__
    - USAMPLER2DRECT


#### SAMPLERBUFFER - 1 rules

  __type_specifier_nonarray__
    - SAMPLERBUFFER


#### ISAMPLERBUFFER - 1 rules

  __type_specifier_nonarray__
    - ISAMPLERBUFFER


#### USAMPLERBUFFER - 1 rules

  __type_specifier_nonarray__
    - USAMPLERBUFFER


#### SAMPLER2DMS - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DMS


#### ISAMPLER2DMS - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER2DMS


#### USAMPLER2DMS - 1 rules

  __type_specifier_nonarray__
    - USAMPLER2DMS


#### SAMPLER2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - SAMPLER2DMSARRAY


#### ISAMPLER2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - ISAMPLER2DMSARRAY


#### USAMPLER2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - USAMPLER2DMSARRAY


#### IMAGE1D - 1 rules

  __type_specifier_nonarray__
    - IMAGE1D


#### IIMAGE1D - 1 rules

  __type_specifier_nonarray__
    - IIMAGE1D


#### UIMAGE1D - 1 rules

  __type_specifier_nonarray__
    - UIMAGE1D


#### IMAGE2D - 1 rules

  __type_specifier_nonarray__
    - IMAGE2D


#### IIMAGE2D - 1 rules

  __type_specifier_nonarray__
    - IIMAGE2D


#### UIMAGE2D - 1 rules

  __type_specifier_nonarray__
    - UIMAGE2D


#### IMAGE3D - 1 rules

  __type_specifier_nonarray__
    - IMAGE3D


#### IIMAGE3D - 1 rules

  __type_specifier_nonarray__
    - IIMAGE3D


#### UIMAGE3D - 1 rules

  __type_specifier_nonarray__
    - UIMAGE3D


#### IMAGE2DRECT - 1 rules

  __type_specifier_nonarray__
    - IMAGE2DRECT


#### IIMAGE2DRECT - 1 rules

  __type_specifier_nonarray__
    - IIMAGE2DRECT


#### UIMAGE2DRECT - 1 rules

  __type_specifier_nonarray__
    - UIMAGE2DRECT


#### IMAGECUBE - 1 rules

  __type_specifier_nonarray__
    - IMAGECUBE


#### IIMAGECUBE - 1 rules

  __type_specifier_nonarray__
    - IIMAGECUBE


#### UIMAGECUBE - 1 rules

  __type_specifier_nonarray__
    - UIMAGECUBE


#### IMAGEBUFFER - 1 rules

  __type_specifier_nonarray__
    - IMAGEBUFFER


#### IIMAGEBUFFER - 1 rules

  __type_specifier_nonarray__
    - IIMAGEBUFFER


#### UIMAGEBUFFER - 1 rules

  __type_specifier_nonarray__
    - UIMAGEBUFFER


#### IMAGE1DARRAY - 1 rules

  __type_specifier_nonarray__
    - IMAGE1DARRAY


#### IIMAGE1DARRAY - 1 rules

  __type_specifier_nonarray__
    - IIMAGE1DARRAY


#### UIMAGE1DARRAY - 1 rules

  __type_specifier_nonarray__
    - UIMAGE1DARRAY


#### IMAGE2DARRAY - 1 rules

  __type_specifier_nonarray__
    - IMAGE2DARRAY


#### IIMAGE2DARRAY - 1 rules

  __type_specifier_nonarray__
    - IIMAGE2DARRAY


#### UIMAGE2DARRAY - 1 rules

  __type_specifier_nonarray__
    - UIMAGE2DARRAY


#### IMAGECUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - IMAGECUBEARRAY


#### IIMAGECUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - IIMAGECUBEARRAY


#### UIMAGECUBEARRAY - 1 rules

  __type_specifier_nonarray__
    - UIMAGECUBEARRAY


#### IMAGE2DMS - 1 rules

  __type_specifier_nonarray__
    - IMAGE2DMS


#### IIMAGE2DMS - 1 rules

  __type_specifier_nonarray__
    - IIMAGE2DMS


#### UIMAGE2DMS - 1 rules

  __type_specifier_nonarray__
    - UIMAGE2DMS


#### IMAGE2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - IMAGE2DMSARRAY


#### IIMAGE2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - IIMAGE2DMSARRAY


#### UIMAGE2DMSARRAY - 1 rules

  __type_specifier_nonarray__
    - UIMAGE2DMSARRAY


#### struct_specifier - 1 rules

  __type_specifier_nonarray__
    - struct_specifier


#### HIGH_PRECISION - 1 rules

  __precision_qualifier__
    - HIGH_PRECISION


#### MEDIUM_PRECISION - 1 rules

  __precision_qualifier__
    - MEDIUM_PRECISION


#### LOW_PRECISION - 1 rules

  __precision_qualifier__
    - LOW_PRECISION


#### VERTICAL_BAR - 1 rules

  __inclusive_or_expression__
    - inclusive_or_expression VERTICAL_BAR exclusive_or_expression


#### BOOLCONSTANT - 1 rules

  __primary_expression__
    - BOOLCONSTANT


#### AND_OP - 1 rules

  __logical_and_expression__
    - logical_and_expression AND_OP inclusive_or_expression


#### integer_expression - 1 rules

  __postfix_expression__
    - postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET


#### XOR_OP - 1 rules

  __logical_xor_expression__
    - logical_xor_expression XOR_OP logical_and_expression


#### function_identifier - 1 rules

  __function_call_header__
    - function_identifier LEFT_PAREN


#### compound_statement - 1 rules

  __statement__
    - compound_statement


#### OR_OP - 1 rules

  __logical_or_expression__
    - logical_or_expression OR_OP logical_xor_expression


#### QUESTION - 1 rules

  __conditional_expression__
    - logical_or_expression QUESTION expression COLON assignment_expression


#### DOUBLECONSTANT - 1 rules

  __primary_expression__
    - DOUBLECONSTANT


#### selection_statement - 1 rules

  __simple_statement__
    - selection_statement


#### switch_statement - 1 rules

  __simple_statement__
    - switch_statement


#### case_label - 1 rules

  __simple_statement__
    - case_label


#### iteration_statement - 1 rules

  __simple_statement__
    - iteration_statement


#### jump_statement - 1 rules

  __simple_statement__
    - jump_statement


#### function_call - 1 rules

  __postfix_expression__
    - function_call


#### assignment_operator - 1 rules

  __assignment_expression__
    - unary_expression assignment_operator assignment_expression


#### unary_operator - 1 rules

  __unary_expression__
    - unary_operator unary_expression


#### IF - 1 rules

  __selection_statement__
    - IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement


#### selection_rest_statement - 1 rules

  __selection_statement__
    - IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement


#### ELSE - 1 rules

  __selection_rest_statement__
    - statement ELSE statement


#### SWITCH - 1 rules

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE


#### switch_statement_list - 1 rules

  __switch_statement__
    - SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE


#### MUL_ASSIGN - 1 rules

  __assignment_operator__
    - MUL_ASSIGN


#### CASE - 1 rules

  __case_label__
    - CASE expression COLON


#### DEFAULT - 1 rules

  __case_label__
    - DEFAULT COLON


#### DIV_ASSIGN - 1 rules

  __assignment_operator__
    - DIV_ASSIGN


#### MOD_ASSIGN - 1 rules

  __assignment_operator__
    - MOD_ASSIGN


#### ADD_ASSIGN - 1 rules

  __assignment_operator__
    - ADD_ASSIGN


#### DO - 1 rules

  __iteration_statement__
    - DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON


#### FOR - 1 rules

  __iteration_statement__
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### for_init_statement - 1 rules

  __iteration_statement__
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### for_rest_statement - 1 rules

  __iteration_statement__
    - FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope


#### SUB_ASSIGN - 1 rules

  __assignment_operator__
    - SUB_ASSIGN


#### CONTINUE - 1 rules

  __jump_statement__
    - CONTINUE SEMICOLON


#### BREAK - 1 rules

  __jump_statement__
    - BREAK SEMICOLON


#### LEFT_ASSIGN - 1 rules

  __assignment_operator__
    - LEFT_ASSIGN


#### DISCARD - 1 rules

  __jump_statement__
    - DISCARD SEMICOLON


#### RIGHT_ASSIGN - 1 rules

  __assignment_operator__
    - RIGHT_ASSIGN


#### translation_unit - 1 rules

  __translation_unit__
    - translation_unit external_declaration


#### IVEC3 - 1 rules

  __type_specifier_nonarray__
    - IVEC3

