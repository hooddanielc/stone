#pragma once

#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

namespace biglr {

#define PASTE(name) PASTE_2(name)
#define PASTE_2(name) #name

inline std::string get_src_root() noexcept {
  return PASTE(IB_SRC_ROOT);
}

inline std::string get_project_path(const std::string &relative) noexcept {
  std::stringstream ss;
  ss << get_src_root();
  if (relative.at(0) != '/') {
    ss << "/";
  }
  ss << relative;
  return ss.str();
}

inline std::string get_out_root() noexcept {
  return PASTE(IB_OUT_ROOT);
}

// Ok, magic time over.  Get back to work.
#undef PASTE_2
#undef PASTE

/* quick and dirty read file method */
inline const std::string get_file_contents(const std::string &path) {
  std::ifstream t(path.c_str());

  if (!t.good()) {
    std::stringstream ss;
    ss << "file doesn't exist: " << path;
    throw std::runtime_error(ss.str());
  }

  std::string str;
  t.seekg(0, std::ios::end);
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);
  str.assign((std::istreambuf_iterator<char>(t)),
              std::istreambuf_iterator<char>());
  return str;
}

/* quick and dirty write file method */
inline void write_file_contents(const std::string &path, const std::string &src) {
  std::ofstream ofs(path.c_str(), std::ofstream::out);
  if (!ofs.good()) {
    std::stringstream ss;
    ss << "error opening file for write: " << path;
    throw std::runtime_error(ss.str());
  }
  ofs << src;
  ofs.close();
}

/* check if a file exists */
inline bool file_exists(const std::string &path) {
  std::ifstream f(path.c_str());
  auto result = f.good();
  f.close();
  return result;
}

/* get a random string */
std::string get_random_str(const int len) {
  std::string result;
  static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < len; ++i) {
    result += alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  return result;
}

/* get a random file path */
std::string get_tmp_path(const std::string &prefix = "tmp-file-", const std::string &ext = "", const int len = 10) {
  std::string result;

  do {
    result = "/tmp/";
    result += prefix;
    result += get_random_str(len);
    result += ext;
  } while(file_exists(result));

  return result;
}

/*
 * Takes a string and returns the the same string only if the
 * the value is not used as a reserved word in c++. Otherwise,
 * the string returned will have one or two leading underscores.
 * Any characters not allowed in c++ identifiers will result
 * in an exception. The following characters are allowed.
 *
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z _ */
inline std::string sanitize_cpp_identifier(const std::string &name) {
  for (auto c: name) {
    if (!isalpha(c) && c != '_') {
      throw std::runtime_error("invalid c++ identifier `" + name + '`');
    }
  }

  static std::unordered_map<std::string, std::string> reserved = {
    { "alignas", "alignas_" },
    { "alignof", "alignof_" },
    { "and", "and_" },
    { "and_eq", "and_eq_" },
    { "asm", "asm_" },
    { "auto", "auto_" },
    { "bitand", "bitand_" },
    { "bitor", "bitor_" },
    { "bool", "bool_" },
    { "break", "break_" },
    { "case", "case_" },
    { "catch", "catch_" },
    { "char", "char_" },
    { "char16_t", "char16_t_" },
    { "char32_t", "char32_t_" },
    { "class", "class_" },
    { "compl", "compl_" },
    { "concept", "concept_" },
    { "const", "const_" },
    { "constexpr", "constexpr_" },
    { "const_cast", "const_cast_" },
    { "continue", "continue_" },
    { "decltype", "decltype_" },
    { "default", "default_" },
    { "delete", "delete_" },
    { "do", "do_" },
    { "double", "double_" },
    { "dynamic_cast", "dynamic_cast_" },
    { "else", "else_" },
    { "enum", "enum_" },
    { "explicit", "explicit_" },
    { "export", "export_" },
    { "extern", "extern_" },
    { "false", "false_" },
    { "float", "float_" },
    { "for", "for_" },
    { "friend", "friend_" },
    { "goto", "goto_" },
    { "if", "if_" },
    { "import", "import_" },
    { "inline", "inline_" },
    { "int", "int_" },
    { "long", "long_" },
    { "module", "module_" },
    { "mutable", "mutable_" },
    { "namespace", "namespace_" },
    { "new", "new_" },
    { "noexcept", "noexcept_" },
    { "not", "not_" },
    { "not_eq", "not_eq_" },
    { "nullptr", "nullptr_" },
    { "operator", "operator_" },
    { "or", "or_" },
    { "or_eq", "or_eq_" },
    { "private", "private_" },
    { "protected", "protected_" },
    { "public", "public_" },
    { "register", "register_" },
    { "reinterpret_cast", "reinterpret_cast_" },
    { "requires", "requires_" },
    { "return", "return_" },
    { "short", "short_" },
    { "signed", "signed_" },
    { "sizeof", "sizeof_" },
    { "static", "static_" },
    { "static_assert", "static_assert_" },
    { "static_cast", "static_cast_" },
    { "struct", "struct_" },
    { "switch", "switch_" },
    { "template", "template_" },
    { "this", "this_" },
    { "thread_local", "thread_local_" },
    { "throw", "throw_" },
    { "true", "true_" },
    { "try", "try_" },
    { "typedef", "typedef_" },
    { "typeid", "typeid_" },
    { "typename", "typename_" },
    { "union", "union_" },
    { "unsigned", "unsigned_" },
    { "using", "using_" },
    { "virtual", "virtual_" },
    { "void", "void_" },
    { "volatile", "volatile_" },
    { "wchar_t", "wchar_t_" },
    { "while", "while_" },
    { "xor", "xor_" },
    { "xor_eq", "xor_eq_" }
  };

  if (!reserved.count(name)) {
    return name;
  }

  return reserved[name];
}

class child_process_t {

public:

  /* execute child process synchronously */
  void exec_sync() {
    int stdin_pipe[2];
    int stdout_pipe[2];
    pid_t child_pid;

    if (pipe(stdin_pipe) < 0) {
      throw std::runtime_error("allocating pipe for child input redirect");
    }

    if (pipe(stdout_pipe) < 0) {
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdin_pipe[child_process_t::pipe_write]);
      throw std::runtime_error("allocating pipe for child output redirect");
    }

    child_pid = fork();
    if (child_pid == 0) {
      // child continues here

      // redirect stdin
      if (dup2(stdin_pipe[child_process_t::pipe_read], STDIN_FILENO) == -1) {
        exit(errno);
      }

      // redirect stdout
      if (dup2(stdout_pipe[child_process_t::pipe_write], STDOUT_FILENO) == -1) {
        exit(errno);
      }

      // redirect stderr
      if (dup2(stdout_pipe[child_process_t::pipe_write], STDERR_FILENO) == -1) {
        exit(errno);
      }

      // all these are for use by parent only
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdin_pipe[child_process_t::pipe_write]);
      close(stdout_pipe[child_process_t::pipe_read]);
      close(stdout_pipe[child_process_t::pipe_write]); 

      // run child process image
      // replace this with any exec* function find easier to use ("man exec")
      std::vector<char *> c_str_array;
      c_str_array.push_back(const_cast<char*>(cmd.c_str()));
      for (const auto &str: args) {
        c_str_array.push_back(const_cast<char*>(str.c_str()));
      }

      int exit_code = execv(cmd.c_str(), &c_str_array[0]);

      // if we get here at all, an error occurred, but we are in the child
      // process, so just exit
      exit(exit_code);
    } else if (child_pid > 0) {
      // parent continues here
      emit_on_start(child_pid);

      // close unused file descriptors, these are for child only
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdout_pipe[child_process_t::pipe_write]);

      int status = -1;
      size_t buff_size = 100;
      char buff[buff_size];
      size_t num_read = 0;
      while (waitpid(child_pid, &status, WNOHANG|WUNTRACED) == 0) {
        while ((num_read = read(stdout_pipe[child_process_t::pipe_read], &buff, buff_size)) > 0) {
          emit_on_data(std::string{ buff, num_read });
        }
      }

      // closing since child process exited and we are done talking to it
      close(stdin_pipe[child_process_t::pipe_write]);
      close(stdout_pipe[child_process_t::pipe_read]);
      emit_on_exit(status);
    } else {
      // failed to create child
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdin_pipe[child_process_t::pipe_write]);
      close(stdout_pipe[child_process_t::pipe_read]);
      close(stdout_pipe[child_process_t::pipe_write]);
      throw std::runtime_error("failed to create child process");
    }
  }

  void set_cmd(const std::string &cmd_) {
    if (started) {
      throw std::runtime_error("cannot modify executable after process started");
    }

    cmd = cmd_;
  }

  void set_args(const std::vector<std::string> &args_) {
    if (started) {
      throw std::runtime_error("cannot modify executable after process started");
    }

    args = args_;
  }

  std::string get_cmd() const {
    return cmd;
  }

  std::vector<std::string> get_args() const {
    return args;
  }

  bool is_running() const {
    return started;
  }

  static std::shared_ptr<child_process_t> make(
    const std::string &cmd = "",
    const std::vector<std::string> &args = {}
  ) {
    auto child = new child_process_t(cmd, args);
    std::shared_ptr<child_process_t> result(child);
    return result;
  }

  void on_data(const std::function<void(const std::string &)> &cb) {
    on_data_cbs.push_back(cb);
  }

  void on_exit(const std::function<void(int)> &cb) {
    on_exit_cbs.push_back(cb);
  }

  void on_start(const std::function<void(pid_t pid)> &cb) {
    on_start_cbs.push_back(cb);
  }

private:

  std::string cmd;

  std::vector<std::string> args;

  bool started;

  static const int pipe_read = 0;

  static const int pipe_write = 1;

  std::vector<std::function<void(const std::string &data)>> on_data_cbs;

  std::vector<std::function<void(int exit_code)>> on_exit_cbs;

  std::vector<std::function<void(pid_t pid)>> on_start_cbs;

  child_process_t(const std::string &cmd_, const std::vector<std::string> &args_):
    cmd(cmd_),
    args(args_),
    started(false) {}

  void emit_on_exit(int exit_code) const {
    for (const auto &cb: on_exit_cbs) {
      cb(exit_code);
    }
  }

  void emit_on_data(const std::string &str) const {
    for (const auto &cb: on_data_cbs) {
      cb(str);
    }
  }

  void emit_on_start(pid_t pid) const {
    for (const auto &cb: on_start_cbs) {
      cb(pid);
    }
  }

};  // child_process_t

std::ostream &operator<<(std::ostream &strm, const child_process_t &child) {
  strm << "child_process_t(" << child.get_cmd();
  for (const auto &str: child.get_args()) {
    strm << " " << str;
  }
  if (child.is_running()) {
    strm << ", running";
  } else {
    strm << ", idle";
  }
  strm << ")";
  return strm;
}

std::ostream &operator<<(std::ostream &strm, const child_process_t *child) {
  strm << *child;
  return strm;
}

}   // biglr
