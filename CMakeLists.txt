cmake_minimum_required(VERSION 4.1)
project(bfd)

set(CMAKE_CXX_STANDARD 17)

add_executable(bfd main.cpp
        includes/bfd.h
        bfd.cpp
        FERcalculate.cpp
        includes/FERcalculate.h
        src/channel.cpp
        includes/channel.h
        src/code.cpp
        includes/code.h
        includes/matrix.h
)
