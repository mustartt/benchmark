cmake_minimum_required(VERSION 3.10)
project(StrlenBenchmark)

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark)

add_executable(strlen-static benchmark.cpp)
target_link_libraries(strlen-static benchmark::benchmark)
target_link_options(strlen-static PUBLIC "-static")

add_executable(strlen-dynamic benchmark.cpp)
target_link_libraries(strlen-dynamic benchmark::benchmark)
target_link_options(strlen-dynamic PUBLIC "-dynamic")

