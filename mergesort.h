#pragma once
#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <thread>

typedef unsigned int uint;
#define ARR_LEN 100000000L
class mergesort
{
private:
    uint *arr;
    uint threads = 0;

public:
    mergesort(uint *_arr);
    ~mergesort() = default;

    void sort_mt(long l, long r);
    void sort(long l, long r);

private:
    void merge(long l, long m, long r);
};
