#pragma once
#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <thread>
#include "Misc.h"

typedef unsigned int uint;

class mergesort
{
private:
    const long arr_len;
    const uint max_threads;
    uint *arr;
    uint threads = 0;

public:
    explicit mergesort(uint *_arr, long &_arr_len, uint &_max_threads);
    ~mergesort() = default;

    /// @brief многопоточная сортировка
    void sort_mt(long l, long r);

    /// @brief Однопоточная сортировка
    void sort(long l, long r);

    void test_sort();

private:
    void merge(long l, long m, long r);
};

// https://stackoverflow.com/questions/24130307/performance-problems-in-parallel-mergesort-c