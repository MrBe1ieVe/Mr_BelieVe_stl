cmake_minimum_required(VERSION 3.16)
project(Mr_BelieVe_stl)

set(CMAKE_CXX_STANDARD 11)

add_executable(Mr_BelieVe_stl main.cpp stl_alloc.h stl_config.h stl_iterator.h stl_iterator_base.h)
