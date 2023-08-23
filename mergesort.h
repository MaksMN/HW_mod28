#pragma once
#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <thread>

typedef unsigned int uint;
#define ARR_LEN 100000000L
#define THREADS 4
class mergesort
{
private:
    uint *arr;
    uint threads = 0;

public:
    mergesort(uint *_arr);
    ~mergesort() = default;

    /// @brief многопоточная сортировка
    void sort_mt(long l, long r);

    /// @brief Однопоточная сортировка
    void sort(long l, long r);

private:
    void merge(long l, long m, long r);
};
