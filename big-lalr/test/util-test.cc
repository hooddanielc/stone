#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <lick/lick.h>
#include <big-lalr/util.h>

using namespace biglr;

FIXTURE(get_random_string_result) {
  auto str1 = get_random_str(10);
  auto str2 = get_random_str(10);
  EXPECT_NE(str1, str2);
  EXPECT_EQ(str1.size(), str2.size());
  EXPECT_EQ(str1.size(), size_t(10));
}

FIXTURE(get_tmp_path_result) {
  auto tmp1 = get_tmp_path();
  auto tmp2 = get_tmp_path();
  auto tmp3 = get_tmp_path("custom-prefix-");
  EXPECT_EQ(tmp1.size(), size_t(24));
  EXPECT_EQ(tmp2.size(), size_t(24));
  EXPECT_EQ(tmp3.size(), size_t(29));
}

FIXTURE(read_a_file) {
  std::string path = get_project_path("/big-lalr/test/fixtures/pets.biglr");
  auto str = get_file_contents(path);
  EXPECT_EQ(str.size(), size_t(133));
}

FIXTURE(write_a_file) {
  auto content = "my name is tony, and i stole your sandwhich";
  auto path = get_tmp_path("write-test-");
  write_file_contents(path, content);
  auto read = get_file_contents(path);
  std::remove(path.c_str());
  EXPECT_EQ(read, content);
}

FIXTURE(sanitize_cpp_ids) {
  EXPECT_EQ(sanitize_cpp_identifier("alignas"), "alignas_");
  EXPECT_EQ(sanitize_cpp_identifier("xor"), "xor_");
}

FIXTURE(make_child_process) {
  auto proc = child_process_t::make();
  EXPECT_EQ(proc->get_cmd(), std::string(""));
  EXPECT_EQ(proc->get_args().size(), size_t(0));

  proc->set_cmd("/usr/bin/gcc");
  proc->set_args({"--help"});

  EXPECT_EQ(proc->get_cmd(), std::string("/usr/bin/gcc"));
  EXPECT_EQ(proc->get_args().size(), size_t(1));
  EXPECT_EQ(proc->get_args()[0], std::string("--help"));

  pid_t pid_returned = 0;
  int total_chars_received = 0;
  int exit_code = -1;

  proc->on_start([&](pid_t pid) {
    pid_returned = pid;
  });

  proc->on_stdout([&](const std::string &str) {
    total_chars_received += str.size();
  });

  proc->on_stderr([&](const std::string &str) {
    total_chars_received += str.size();
  });

  proc->on_exit([&](int status) {
    exit_code = status;
  });

  proc->exec_sync();

  EXPECT_NE(pid_returned, pid_t(0));
  EXPECT_NE(exit_code, -1);
  EXPECT_NE(total_chars_received, 0);
}

FIXTURE(child_process_output) {
  auto proc = child_process_t::make();
  proc->set_cmd("/bin/bash");
  proc->set_args({"-c", ">&2 echo 'illusion of choice' && sleep 1 && echo 'works'"});
  std::string stdout;
  std::string stderr;

  proc->on_stdout([&](const std::string &str) {
    stdout += str;
  });

  proc->on_stderr([&](const std::string &str) {
    stderr += str;
  });

  proc->on_exit([&](int status) {
    EXPECT_EQ(status, 0);
    EXPECT_EQ(stderr, "illusion of choice\n");
    EXPECT_EQ(stdout, "works\n");
    EXPECT_FALSE(stdout.back() != '\n');
  });

  proc->exec_sync();
}