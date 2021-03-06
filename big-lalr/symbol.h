#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <sstream>
#include "util.h"

namespace biglr {

class symbol_t {

public:

  symbol_t(const std::string &name_)
      :name(name_), id(next_id++) {}

  virtual ~symbol_t() = default;

  std::string get_name() const {
    return name;
  }

  virtual std::string get_description() const {
    std::stringstream ss;
    ss << "Symbol(" << name << ")";
    return ss.str();
  }

  virtual bool operator<(const symbol_t &other) {
    return get_name() < other.get_name();
  }

  virtual bool operator>(const symbol_t &other) {
    return get_name() > other.get_name();
  }

  virtual bool is_reduction() const { return false; }

  virtual bool is_token() const { return false; }

  virtual bool is_break() const { return false; }

  virtual bool is_epsilon() const { return false; }

  virtual std::string get_cpp_identifier() const = 0;

  int get_id() const {
    return id;
  }

  void set_id(int new_id) {
    id = new_id;
  }

  static void clear() {
    next_id = 1;
  }

protected:

  static int next_id;

  std::string name;

  int id;

};  // symbol_t

int symbol_t::next_id = 1;

std::ostream &operator<<(std::ostream &strm, const symbol_t *symbol) {
  strm << symbol->get_description();
  return strm;
}

class token_t: public symbol_t {

public:

  token_t(const std::string &name): symbol_t(name) {}

  virtual ~token_t() = default;

  static std::shared_ptr<token_t> make(const std::string &name) {
    if (auto cached_ptr = store[name].lock()) {
      return cached_ptr;
    }

    auto symbol = new token_t(name);
    std::shared_ptr<token_t> ptr(symbol);
    store[name] = ptr;
    return ptr;
  }

  virtual std::string get_description() const override {
    std::stringstream ss;
    ss << "Token(" << name << ")";
    return ss.str();
  }

  virtual bool is_token() const override { return true; }

  virtual std::string get_cpp_identifier() const override {
    return sanitize_cpp_identifier(name);
  }

  static void flush() {
    store.clear();
  }

  static bool exists(const std::string &name) {
    return bool(store[name].lock());
  }

  static std::vector<std::shared_ptr<token_t>> get_store() {
    std::vector<std::shared_ptr<token_t>> tokens;
    for (auto it = store.begin(); it != store.end(); ++it) {
      if (auto ptr = it->second.lock()) {
        tokens.push_back(ptr);
      }
    }
    return tokens;
  }

  static void clear_store() {
    std::unordered_map<std::string, std::weak_ptr<token_t>> empty;
    std::swap(store, empty);
  }

protected:

  static std::unordered_map<std::string, std::weak_ptr<token_t>> store;

  std::string cpp_identifier;

};  // token_t

std::unordered_map<std::string, std::weak_ptr<token_t>> token_t::store;

class reduction_t: public symbol_t {

public:

  reduction_t(const std::string &name): symbol_t(name) {}

  virtual ~reduction_t() = default;

  static std::shared_ptr<reduction_t> make(const std::string &name) {
    if (auto cached_ptr = store[name].lock()) {
      return cached_ptr;
    }

    auto symbol = new reduction_t(name);
    std::shared_ptr<reduction_t> ptr(symbol);
    store[name] = ptr;
    return ptr;
  }

  virtual std::string get_description() const override {
    std::stringstream ss;
    ss << "Reduction(" << name << ")";
    return ss.str();
  }

  virtual bool is_reduction() const override { return true; }

  static void flush() {
    store.clear();
  }

  virtual std::string get_cpp_identifier() const override {
    return sanitize_cpp_identifier(name);
  }

  static bool exists(const std::string &name) {
    return bool(store[name].lock());
  }

  static std::vector<std::shared_ptr<reduction_t>> get_store() {
    std::vector<std::shared_ptr<reduction_t>> reductions;
    for (auto it = store.begin(); it != store.end(); ++it) {
      if (auto ptr = it->second.lock()) {
        reductions.push_back(ptr);
      }
    }
    return reductions;
  }

  static void clear_store() {
    std::unordered_map<std::string, std::weak_ptr<reduction_t>> empty;
    std::swap(store, empty);
  }

protected:

  static std::unordered_map<std::string, std::weak_ptr<reduction_t>> store;

};  // reduction_t

std::unordered_map<std::string, std::weak_ptr<reduction_t>> reduction_t::store;

class top_t: public reduction_t {

public:

  top_t(const std::string &name): reduction_t(name) {}

  virtual ~top_t() = default;

  static std::shared_ptr<top_t> make() {
    if (auto cached_ptr = cached.lock()) {
      return cached_ptr;
    }

    auto symbol = new top_t("TOP");
    std::shared_ptr<top_t> ptr(symbol);
    cached = ptr;
    return ptr;
  }

  virtual std::string get_cpp_identifier() const override {
    return "__omega__";
  }

  virtual std::string get_description() const override {
    return "__omega__";
  }

  static void clear_store() {
    cached.reset();
  }

protected:

  static std::weak_ptr<top_t> cached;


};  // top_t

std::weak_ptr<top_t> top_t::cached;

class break_t: public token_t {

public:

  break_t(const std::string &name): token_t(name) {}

  virtual ~break_t() = default;

  static std::shared_ptr<break_t> make() {
    if (auto cached_ptr = cached.lock()) {
      return cached_ptr;
    }

    auto symbol = new break_t("--");
    std::shared_ptr<break_t> ptr(symbol);
    cached = ptr;
    return ptr;
  }

  virtual bool is_break() const override {
    return true;
  }

  virtual std::string get_cpp_identifier() const override {
    return "__break__";
  }

  virtual std::string get_description() const override {
    return "__break__";
  }

  static void clear_store() {
    cached.reset();
  }

protected:

  static std::weak_ptr<break_t> cached;

};  // break_t

std::weak_ptr<break_t> break_t::cached;


class epsilon_t: public token_t {

public:

  epsilon_t(const std::string &name): token_t(name) {}

  virtual ~epsilon_t() = default;

  static std::shared_ptr<epsilon_t> make() {
    if (auto cached_ptr = cached.lock()) {
      return cached_ptr;
    }

    auto symbol = new epsilon_t("--");
    std::shared_ptr<epsilon_t> ptr(symbol);
    cached = ptr;
    return ptr;
  }

  virtual std::string get_cpp_identifier() const override {
    return "__epsilon__";
  }

  virtual std::string get_description() const override {
    return "__epsilon__";
  }

  virtual bool is_epsilon() const override { return true; }

  static void clear_store() {
    cached.reset();
  }

protected:

  static std::weak_ptr<epsilon_t> cached;

};  // epsilon_t

std::weak_ptr<epsilon_t> epsilon_t::cached;

}   // biglr
