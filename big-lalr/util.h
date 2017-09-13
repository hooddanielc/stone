#pragma once

#include <fstream>
#include <sstream>

namespace biglr {

/* quick and dirty read file method */
const std::string get_file_contents(const std::string &path) {
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

/*
 * Takes a string and returns the the same string only if the
 * the value is not used as a reserved word in c++. Otherwise,
 * the string returned will have one or two leading underscores.
 * Any characters not allowed in c++ identifiers will result
 * in an exception. The following characters are allowed.
 *
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z _ */
std::string sanitize_cpp_identifier(const std::string &name) {
  for (auto c: name) {
    if (!isalpha(c) && c != '_') {
      throw std::runtime_error("invalid c++ identifier `" + name + '`');
    }
  }

  static std::map<std::string, std::string> reserved = {
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

}   // biglr
