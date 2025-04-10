#include <benchmark/benchmark.h>
#include <cstring>

extern "C" void convert_vec(void* result, const void* value);
extern "C" void convert_no_vec(void* result, const void* value);

static void BM_ConvertVec(benchmark::State& state) {
    alignas(1) char result[16];
    alignas(2) char value[16];

    std::memset(value, 42, sizeof(value));

    for (auto _ : state) {
        convert_vec(result, value);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_ConvertNoVec(benchmark::State& state) {
    alignas(1) char result[16];
    alignas(2) char value[16];

    std::memset(value, 42, sizeof(value));

    for (auto _ : state) {
        convert_no_vec(result, value);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_ConvertVec);
BENCHMARK(BM_ConvertNoVec);

BENCHMARK_MAIN();
