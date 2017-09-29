#pragma once

#include "json/json.hpp"
#include "glsl-lang.h"

namespace gliss {

class ast_t {
  
public:

  ast_t(std::shared_ptr<glsl::ast_t> ast_): ast(ast_) {}

  nlohmann::json to_json() {
    nlohmann::json json;
    assign_json(ast, json);
    return json;
  }

  void assign_json(std::shared_ptr<glsl::ast_t> &node, nlohmann::json &json) {
    json["name"] = node->get_name();
    if (glsl::ast_token_t *token = dynamic_cast<glsl::ast_token_t*>(node.get())) {
      auto text = token->get_token()->get_text();
      if (!text.empty()) {
        json["text"] = text;
      }
    }
    for (auto child: node->get_children()) {
      nlohmann::json child_json;
      assign_json(child, child_json);
      json["children"].push_back(child_json);
    }
  }

  std::vector<std::shared_ptr<glsl::ast_t>> get_children() {
    return ast->get_children();
  }

  std::string get_name() {
    return ast->get_name();
  }

  static std::shared_ptr<ast_t> make(std::shared_ptr<glsl::ast_t> ast) {
    return std::make_shared<ast_t>(ast);
  }

private:

  std::shared_ptr<glsl::ast_t> ast;

};  // ast_t

}