#include <iostream>
#include <lick/lick.h>
#include <gliss/ast-nodes/struct-specifier.h>
#include <gliss/ast-nodes/type-qualifier-struct-declaration-list-identifier.h>
#include <gliss/ast-nodes/struct-declarator-array.h>
#include <gliss/ast-nodes/selection-rest-statement-else.h>
#include <gliss/ast-nodes/postfix-expression.h>

using namespace gliss;

FIXTURE(multiline_comment) {
  std::cout << "it compiled" << std::endl;
}
