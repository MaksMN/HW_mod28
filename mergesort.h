#pragma once
#include <iostream>
#include <string>

typedef unsigned int uint;
#define ARR_LEN 6

class mergesort
{
private:
    uint (&arr)[ARR_LEN];

public:
    mergesort(uint (&_arr)[ARR_LEN]);
    ~mergesort() = default;

    void sort(int l, int r);

private:
    void merge(int l, int m, int r);
};
