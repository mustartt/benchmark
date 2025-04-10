#include <benchmark/benchmark.h>
#include <cstring>

constexpr int START = 0;
constexpr int END = 1;


static void BM_wcslen(benchmark::State& state) {
    size_t len = state.range(0);
    std::wstring wstr(len, L'a');
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(wcslen(wstr.c_str()));
    }
}

static void BM_wcsloop(benchmark::State& state) {
    size_t len = state.range(0);
    std::wstring wstr(len, L'a');
    
    for (auto _ : state) {
        auto* curr = wstr.c_str();
        auto* start = curr;
        while (*curr != L'\0') {
          ++curr;
        }
        benchmark::DoNotOptimize(curr - start);
    }
}

static void BM_strlen(benchmark::State& state) {
    size_t len = state.range(0);
    std::string str(len, 'a');
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(strlen(str.c_str()));
    }
}

static void BM_strloop(benchmark::State& state) {
    size_t len = state.range(0);
    std::string str(len, 'a');
    
    for (auto _ : state) {
        auto* curr = str.c_str();
        auto* start = curr;
        while (*curr != '\0') {
          ++curr;
        }
        benchmark::DoNotOptimize(curr - start);
    }
}

BENCHMARK(BM_wcslen)->DenseRange(0, 31)->Range(32, 10000);
BENCHMARK(BM_wcsloop)->DenseRange(0, 31)->Range(32, 10000);
BENCHMARK(BM_strlen)->DenseRange(0, 31)->Range(32, 10000);
BENCHMARK(BM_strloop)->DenseRange(0, 31)->Range(32, 10000);

BENCHMARK_MAIN();
