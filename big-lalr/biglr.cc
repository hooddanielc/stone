#include <iostream>
#include <string>
#include "picosha2/picosha2.h"
#include "grammar.h"
#include "util.h"

using namespace biglr;
using args_t = std::vector<std::string>;

void print_help() {
  std::cout << R"(
    usage: biglr [-h] [--rules path]

    required arguments:
      -r, --rules   path to grammar file

    optional arguments:
      -f, --force   ignore sha256 hash indicating successful generation
      -s, --server  launch web server for viewing web documentation
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

auto gui = get_project_path("big-lalr/tools/dist/react-report.js");
auto tools = get_project_path("big-lalr/tools");
auto server = get_project_path("big-lalr/tools/dist/server.js");

void build_gui_if_needed() {
  if (!file_exists(gui)) {
    // need to rebuild webpack project
    std::cout << "building webpack application for first time" << std::endl;
    std::cout << "this might take a while please be patient" << std::endl;
    auto exec_compiled_file = child_process_t::make("/bin/sh", {
      "-c",
      "cd " + tools + " && npm install && npm run build"
    });
    exec_compiled_file->on_data([&](auto str) {
      std::cout << str;
    });
    exec_compiled_file->on_exit([&](auto code) {
      if (code != 0) {
        throw std::runtime_error("incorrect exit code");
      }
    });
    exec_compiled_file->exec_sync();
  }
}

void make_parser(
  const std::string &rules,
  const std::string &out,
  std::vector<std::string> args = {}
) {
  bool should_generate = true;

  if (has_flag("-f", "--force", args)) {
    std::remove((out + ".sha256").c_str());
  }

  // generate hash from grammar file
  std::ifstream ifs(rules, std::ios::binary);
  std::vector<unsigned char> hash(32);
  picosha2::hash256(
    std::istreambuf_iterator<char>(ifs),
    std::istreambuf_iterator<char>(),
    hash.begin(),
    hash.end()
  );
  std::string hash_string(hash.begin(), hash.end());
  write_file_contents(out + ".sha256_temp", hash_string);

  if (file_exists(out + ".sha256")) {
    // get the saved hash
    auto saved_hash = get_file_contents(out + ".sha256");

    if (saved_hash == hash_string) {
      std::cout << "Hashes are the same, skipping... ";
      std::cout << "Use -f, --force flag to override" << std::endl;
      std::cout << "Use -s, --server to launch generated docs" << std::endl;
      should_generate = false;
    }
  }

  if (should_generate) {
    build_gui_if_needed();
    auto grammar = grammar_t::from_file(rules);
    auto parser = grammar->get_full_parse_table([](size_t todo, size_t done) {
      std::cout << "todo: " << todo << " done: " << done << std::endl;
    });

    // get basename of output
    std::string out_name = "";
    for (const auto &c: out) {
      if (c == '/') {
        out_name = "";
      } else {
        out_name += c;
      }
    }

    parser->write_html(out + ".html", out_name + ".js");
    parser->write_json(out + ".json");
    parser->write_dot(out + ".dot");

    // copy the javascript next to generated html
    std::ifstream  src(gui, std::ios::binary);
    std::ofstream  dst(out + ".js", std::ios::binary);
    dst << src.rdbuf();

    // mark generated grammar successful
    write_file_contents(out + ".sha256", get_file_contents(out + ".sha256_temp"));
    std::remove((out + ".sha256_temp").c_str());
  }

  if (file_exists(out + ".sha256_temp")) {
    std::remove((out + ".sha256_temp").c_str());
  }

  // launch web server?
  if (has_flag("-s", "--server", args)) {
    build_gui_if_needed();
    std::cout << "Launching Web Server" << std::endl;
    auto exec_server = child_process_t::make("/bin/sh", {
      "-c",
      "node " + server + " -d " + out + ".html"
    });
    exec_server->on_data([&](auto str) {
      std::cout << str;
    });
    exec_server->on_exit([&](auto code) {
      if (code != 0) {
        throw std::runtime_error("incorrect exit code");
      }
    });
    exec_server->exec_sync();
  } else if (should_generate) {
    std::cout << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Success!" << std::endl;
    std::cout << std::endl;
    std::cout << "To view the documentation, rerun command with -s" << std::endl;
    std::cout << "================================================" << std::endl;
  }
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
      make_parser(rules, out, args);
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
