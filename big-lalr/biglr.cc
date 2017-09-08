#include <iostream>
#include <string>
#include "grammar.h"

using namespace biglr;
using args_t = std::vector<std::string>;

void print_help() {
  std::cout << R"(
    usage: biglr [-h] [--rules path]

    required arguments:
      -r, --rules   path to grammar file

    optional arguments:
      -h, --help    show this help message and exit
      -o, --out     defaults to --rules parent dir
  )" << std::endl;
}

bool has_flag(const std::string &small, const std::string &big, const args_t &args) {
  for (auto arg: args) {
    if (small == arg || big == arg) {
      return true;
    }
  }
  return false;
}

std::string get_value(
  const std::string &small,
  const std::string &big,
  const args_t &args,
  const std::string &default_value = ""
) {
  bool found = false;
  for (auto arg: args) {
    if (found) {
      return arg;
    }
    if (small == arg || big == arg) {
      found = true;
    }
  }
  return default_value;
}

std::vector<std::string> normalize_args(int argc, char *argv[]) {
  std::vector<std::string> result;
  for (int i = 1; i < argc; ++i) {
    std::string tmp(argv[i]);
    std::string arg;
    bool has_equal = false;
    for (size_t j = 0; j < tmp.size(); ++j) {
      if (!has_equal && tmp.at(j) == '=') {
        has_equal = true;
        result.push_back(arg);
        arg.clear();
      } else {
        arg += tmp.at(j);
      }
    }
    result.push_back(arg);
  }
  return result;
}

void make_parser(const std::string &rules, const std::string &out) {
  auto grammar = grammar_t::from_file(rules);
  auto parser = grammar->get_full_parse_table([](size_t todo, size_t done) {
    std::cout << "todo: " << todo << " done: " << done << std::endl;
  });
  parser->write_html(out + ".html");
  parser->write_json(out + ".json");
  parser->write_dot(out + ".dot");
}

std::string get_file_name(const std::string &path) {
  std::string tmp = "";
  for (auto c: path) {
    if (c == '.') {
      return tmp;
    }
    tmp += c;
  }
  return "";
}

std::string get_file_dir(const std::string &path) {
  std::string tmp = "";
  std::string result = "";
  for (auto c: path) {
    if (c == '/' && !tmp.empty()) {
      result += tmp;
      tmp.clear();
    }
    tmp += c;
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    print_help();
    return 1;
  }

  auto args = normalize_args(argc, argv);

  if (has_flag("-h", "--help", args)) {
    print_help();
    return 0;
  }

  bool needs_help = true;
  auto rules = get_value("-r", "--rules", args);
  auto out = get_value("-o", "--out", args, get_file_name(rules));

  if (!rules.empty()) {
    needs_help = false;
    try {
      make_parser(rules, out);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
      return 1;
    }
  }

  if (!needs_help) {
    return 0;
  }

  print_help();
  return 1;
}
