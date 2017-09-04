#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

namespace biglr {

class symbol_t {

public:

  std::string get_name() const {
    return name;
  }

  virtual std::string get_description() const {
    std::stringstream ss;
    ss << "Symbol(" << name << ")";
    return ss.str();
  }

protected:

  std::string name;

  symbol_t(const std::string &name_)
      :name(name_) {}

};  // symbol_t

std::ostream &operator<<(std::ostream &strm, const symbol_t *symbol) {
  strm << symbol->get_description();
  return strm;
}

class token_t: public symbol_t {

public:

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

  static void flush() {
    store.clear();
  }

protected:

  static std::unordered_map<std::string, std::weak_ptr<token_t>> store;

  token_t(const std::string &name): symbol_t(name) {}

};  // token_t

std::unordered_map<std::string, std::weak_ptr<token_t>> token_t::store;

class reduction_t: public symbol_t {

public:

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

  static void flush() {
    store.clear();
  }

protected:

  static std::unordered_map<std::string, std::weak_ptr<reduction_t>> store;

  reduction_t(const std::string &name): symbol_t(name) {}

};  // reduction_t

std::unordered_map<std::string, std::weak_ptr<reduction_t>> reduction_t::store;

class top_t: public symbol_t {

public:

  static std::shared_ptr<top_t> make() {
    if (auto cached_ptr = cached.lock()) {
      return cached_ptr;
    }

    auto symbol = new top_t("TOP");
    std::shared_ptr<top_t> ptr(symbol);
    cached = ptr;
    return ptr;
  }

  virtual std::string get_description() const override {
    return "TOP";
  }

protected:

  static std::weak_ptr<top_t> cached;

  top_t(const std::string &name): symbol_t(name) {}

};  // top_t

std::weak_ptr<top_t> top_t::cached;

class break_t: public symbol_t {

public:

  static std::shared_ptr<break_t> make() {
    if (auto cached_ptr = cached.lock()) {
      return cached_ptr;
    }

    auto symbol = new break_t("--");
    std::shared_ptr<break_t> ptr(symbol);
    cached = ptr;
    return ptr;
  }

  virtual std::string get_description() const override {
    return "--";
  }

protected:

  static std::weak_ptr<break_t> cached;

  break_t(const std::string &name): symbol_t(name) {}

};  // break_t

std::weak_ptr<break_t> break_t::cached;

}   // biglr
