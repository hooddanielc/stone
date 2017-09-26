#pragma once

#include "symbol.h"
#include "state.h"
#include "rule.h"

namespace biglr {

struct action_t {

  enum kind_t {
    blank,
    restart,
    reduce,
    shift
  };

  std::shared_ptr<symbol_t> symbol;

  action_t(std::shared_ptr<symbol_t> symbol_): symbol(symbol_) {}

  action_t() = default;

  virtual bool is_blank() const { return true; }

  virtual std::string get_label() const {
    return "  ";
  }

  virtual kind_t get_kind() const {
    return kind_t::blank;
  }

  virtual nlohmann::json to_json() const {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "blank";
    return j;
  }

  virtual std::string get_ref() const {
    return "error";
  }

  virtual int16_t get_param() const {
    return INT16_MAX;
  }

};  // action_t

struct restart_action_t: public action_t {

  restart_action_t(std::shared_ptr<symbol_t> symbol_): action_t(symbol_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    return "\u21BA";
  }

  virtual kind_t get_kind() const override {
    return kind_t::restart;
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "restart";
    return j;
  }

  virtual std::string get_ref() const override {
    return "r1";
  }

  virtual int16_t get_param() const override {
    return 0;
  }

};  // restart_action_t

struct shift_action_t: public action_t {

  std::shared_ptr<state_t> state;

  shift_action_t(
    std::shared_ptr<symbol_t> symbol_,
    std::shared_ptr<state_t> state_
  ): action_t(symbol_), state(state_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    std::stringstream ss;
    ss << "s" << state->get_id();
    return ss.str();
  }

  virtual kind_t get_kind() const override {
    return kind_t::shift;
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "shift";
    j["state"] = state->get_id();
    return j;
  }

  virtual std::string get_ref() const override {
    std::stringstream ss;
    ss << "s" << state->get_id();
    return ss.str();
  }

  virtual int16_t get_param() const override {
    return state->get_id() + 1;
  }

};  // shift_action_t

struct reduce_action_t: public action_t {

  std::shared_ptr<rule_t> rule;

  reduce_action_t(
    std::shared_ptr<symbol_t> symbol_,
    std::shared_ptr<rule_t> rule_
  ): action_t(symbol_), rule(rule_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    std::stringstream ss;
    ss << "r" << rule->get_id();
    return ss.str();
  }

  virtual kind_t get_kind() const override {
    return kind_t::reduce;
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "reduce";
    j["rule"] = rule->get_id();
    return j;
  }

  virtual std::string get_ref() const override {
    std::stringstream ss;
    ss << "r" << rule->get_id();
    return ss.str();
  }

  virtual int16_t get_param() const override {
    return rule->get_id() * -1;
  }

};  // reduce_action_t

}