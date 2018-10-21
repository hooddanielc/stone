#pragma once

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>

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
 * 0 1 2 3 4 5 6 7 8 9 _
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z */
inline std::string sanitize_cpp_identifier(const std::string &name) {
  if (isdigit(name.at(0))) {
    throw std::runtime_error("invalid c++ identifier `" + name + '`');
  }

  for (auto c: name) {
    if (!isalnum(c) && c != '_') {
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

  using data_cb_t = std::function<void(const std::string &)>;

  /* execute child process synchronously */
  void exec_sync() {
    pid_t child_pid;

    if (pipe(stdin_pipe) < 0) {
      throw std::runtime_error("allocating pipe for child input redirect");
    }

    if (pipe(stdout_pipe) < 0 || pipe(stderr_pipe) < 0) {
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdin_pipe[child_process_t::pipe_write]);
      throw std::runtime_error("allocating pipe for child output redirect");
    }


    child_pid = fork();
    if (child_pid == 0) {
      // child continues here

      if (!inherit) {
        // redirect stdin
        if (dup2(stdin_pipe[child_process_t::pipe_read], STDIN_FILENO) == -1) {
          exit(errno);
        }

        // redirect stdout
        if (dup2(stdout_pipe[child_process_t::pipe_write], STDOUT_FILENO) == -1) {
          exit(errno);
        }

        // redirect stderr
        if (dup2(stderr_pipe[child_process_t::pipe_write], STDERR_FILENO) == -1) {
          exit(errno);
        }

        // all these are for use by parent only
        cleanup_pipes();
      }

      // run child process image
      // replace this with any exec* function find easier to use ("man exec")
      std::vector<char *> c_str_array;
      c_str_array.push_back(strdup(cmd.c_str()));
      for (const auto &str: args) {
        c_str_array.push_back(strdup(str.c_str()));
      }
      c_str_array.push_back(nullptr);
      int exit_code = execv(c_str_array.front(), c_str_array.data());

      // if we get here at all, an error occurred, but we are in the child
      // process, so just exit
      exit(exit_code);
    } else if (child_pid > 0) {
      // parent continues here
      emit_on_start(child_pid);

      // close unused file descriptors, these are for child only
      close(stdin_pipe[child_process_t::pipe_read]);
      close(stdout_pipe[child_process_t::pipe_write]);
      close(stderr_pipe[child_process_t::pipe_write]);

      int exit_code = -1;
      bool exited = false;
      for (;;) {
        if (!exited) {
          int status = -1;
          if (waitpid(0, &status, 0) < 0) {
            throw std::runtime_error { "waitpid error" };
          }
          if (WIFSIGNALED(status)) {
            throw std::runtime_error { "child signaled?" };
          }
          if (WIFEXITED(status)) {
            exit_code = WEXITSTATUS(status);
            exited = true;
          }
        }

        // read stdout
        std::stringstream ss_out;
        std::stringstream ss_err;

        ssize_t stdout_size = read_pipe(stdout_pipe[child_process_t::pipe_read], buff_size, ss_out);
        emit_on_data(ss_out.str(), on_stdout_cbs);

        ssize_t stderr_size = read_pipe(stderr_pipe[child_process_t::pipe_read], buff_size, ss_err);
        emit_on_data(ss_err.str(), on_stderr_cbs);

        if (!stdout_size && !stderr_size && exited) {
          break;
        }
      }  // for

      // closing since child process exited and we are done talking to it
      close(stdin_pipe[child_process_t::pipe_write]);
      close(stdout_pipe[child_process_t::pipe_read]);
      close(stderr_pipe[child_process_t::pipe_read]);

      emit_on_exit(exit_code);
    } else {
      // failed to create child
      cleanup_pipes();
      throw std::runtime_error("failed to create child process");
    }
  }

  void cleanup_pipes() {
    close(stdin_pipe[child_process_t::pipe_read]);
    close(stdin_pipe[child_process_t::pipe_write]);
    close(stdout_pipe[child_process_t::pipe_read]);
    close(stdout_pipe[child_process_t::pipe_write]);
    close(stderr_pipe[child_process_t::pipe_read]);
    close(stderr_pipe[child_process_t::pipe_write]);
  }

  ssize_t read_pipe(const int &fd, const ssize_t &size, std::ostream &strm) {
    char buff[size];
    ssize_t num_returned = read(fd, buff, sizeof(buff));
    if (num_returned < 0) {
      throw std::runtime_error("read error");
    } else if (num_returned) {
      for (ssize_t i = 0; i < num_returned; ++i) {
        strm.put(buff[i]);
      }
    }
    return num_returned;
  }

  void set_cmd(const std::string &cmd_) {
    if (running) {
      throw std::runtime_error("cannot modify executable while process is running");
    }

    cmd = cmd_;
  }

  void set_buffer_size(const size_t &size) {
    if (running) {
      throw std::runtime_error("cannot modify executable while process is running");
    }

    buff_size = size;
  }

  void set_args(const std::vector<std::string> &args_) {
    if (running) {
      throw std::runtime_error("cannot modify executable while process is running");
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
    return running;
  }

  static std::shared_ptr<child_process_t> make(
    const std::string &cmd = "",
    const std::vector<std::string> &args = {}
  ) {
    auto child = new child_process_t(cmd, args);
    std::shared_ptr<child_process_t> result(child);
    return result;
  }

  void on_stdout(const data_cb_t &cb) {
    on_stdout_cbs.push_back(cb);
  }

  void on_stderr(const data_cb_t &cb) {
    on_stderr_cbs.push_back(cb);
  }

  void on_exit(const std::function<void(int)> &cb) {
    on_exit_cbs.push_back(cb);
  }

  void on_start(const std::function<void(pid_t pid)> &cb) {
    on_start_cbs.push_back(cb);
  }

private:

  size_t buff_size;

  int stdin_pipe[2];

  int stdout_pipe[2];

  int stderr_pipe[2];

  std::string cmd;

  std::vector<std::string> args;

  bool running;

  bool inherit;

  static const int pipe_read = 0;

  static const int pipe_write = 1;

  std::vector<data_cb_t> on_stdout_cbs;

  std::vector<data_cb_t> on_stderr_cbs;

  std::vector<std::function<void(int exit_code)>> on_exit_cbs;

  std::vector<std::function<void(pid_t pid)>> on_start_cbs;

  child_process_t(const std::string &cmd_, const std::vector<std::string> &args_, bool inherit_ = true):
    buff_size(1),
    cmd(cmd_),
    args(args_),
    running(false),
    inherit(inherit_) {}

  void emit_on_exit(int exit_code) const {
    for (const auto &cb: on_exit_cbs) {
      cb(exit_code);
    }
  }

  void emit_on_data(const std::string &str, const std::vector<data_cb_t> list) const {
    for (const auto &cb: list) {
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
