FROM ubuntu:18.04

RUN apt-get update
RUN apt install -y wget software-properties-common
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-6.0 main"
RUN apt-get update
RUN apt-get install -y clang-6.0
RUN wget https://raw.githubusercontent.com/JasonL9000/ib/master/ib -O /usr/bin/ib
RUN chmod +x /usr/bin/ib
