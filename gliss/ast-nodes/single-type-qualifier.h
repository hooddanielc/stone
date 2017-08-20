#pragma once

#include <vector>
#include "ast-node.h"

#include "storage-qualifier.h"
#include "layout-qualifier.h"
#include "precision-qualifier.h"
#include "interpolation-qualifier.h"
#include "invariant-qualifier.h"
#include "precise-qualifier.h"

class storage_qualifier_t;
class layout_qualifier_t;
class precision_qualifier_t;
class interpolation_qualifier_t;
class invariant_qualifier_t;
class precise_qualifier_t;

namespace gliss {

class single_type_qualifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  single_type_qualifier_t(
    const storage_qualifier_t &
  ) {}

  single_type_qualifier_t(
    const layout_qualifier_t &
  ) {}

  single_type_qualifier_t(
    const precision_qualifier_t &
  ) {}

  single_type_qualifier_t(
    const interpolation_qualifier_t &
  ) {}

  single_type_qualifier_t(
    const invariant_qualifier_t &
  ) {}

  single_type_qualifier_t(
    const precise_qualifier_t &
  ) {}

};  // single_type_qualifier_t

const std::vector<std::vector<any_pattern_item_t>> single_type_qualifier_t::patterns = {
  {
    pattern_item_t<storage_qualifier_t>::get()
  }, {
    pattern_item_t<layout_qualifier_t>::get()
  }, {
    pattern_item_t<precision_qualifier_t>::get()
  }, {
    pattern_item_t<interpolation_qualifier_t>::get()
  }, {
    pattern_item_t<invariant_qualifier_t>::get()
  }, {
    pattern_item_t<precise_qualifier_t>::get()
  }
};

}   // gliss
