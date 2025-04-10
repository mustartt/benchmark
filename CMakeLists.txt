cmake_minimum_required(VERSION 3.10)
project(StrlenBenchmark)

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark REQUIRED)

add_executable(strlen strlen.cpp)
target_link_libraries(strlen benchmark::benchmark)

set(BSWAP_OBJS bswap/bswap_vec.o bswap/bswap_no_vec.o)
add_executable(bswap bswap.cpp ${BSWAP_OBJS})
target_link_libraries(bswap benchmark::benchmark)

set_source_files_properties(
    ${BSWAP_OBJS}
    PROPERTIES
    EXTERNAL_OBJECT true
    GENERATED true
)


