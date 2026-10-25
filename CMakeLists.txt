cmake_minimum_required(VERSION 3.16)
project(bfd CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bfd
        src/main.cpp
        src/bfd.cpp
        src/FERcalculate.cpp
        src/channel.cpp
        src/code.cpp
)

target_include_directories(bfd PRIVATE includes)
target_compile_options(bfd PRIVATE -Wall -Wextra)
