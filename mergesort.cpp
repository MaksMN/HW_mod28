#include "mergesort.h"

mergesort::mergesort(uint *_arr, long &_arr_len, uint &_max_threads)
    : arr(_arr), arr_len(_arr_len), max_threads(_max_threads) {}

void mergesort::sort_mt(long l, long r)
{
    if (l >= r)
        return;
    long m = (l + r - 1) / 2;

    auto len = abs(r - l);
    auto N = std::thread::hardware_concurrency() / 2;
    if (N < 2 || threads >= max_threads || len < 10000)
    {
        sort(l, r);
        return;
    }

    auto f1 = std::async(std::launch::async, [&]()
                         {
                             threads++;
                             sort_mt(l, m);
                             threads--; });
    sort_mt(m + 1, r);
    f1.wait();
    merge(l, m, r);
}

void mergesort::sort(long l, long r)
{
    if (l >= r)
        return;
    long m = (l + r - 1) / 2;

    sort(l, m);
    sort(m + 1, r);

    merge(l, m, r);
}

void mergesort::test_sort()
{
    long prev = 0;
    long k = 0;
    bool sort_unsuccessfully = false;
    for (long i{0}; i < arr_len; i++)
    {
        if (arr[i] < prev)
        {
            sort_unsuccessfully = true;
            break;
        }
        else
        {
            prev = arr[i];
        }
        k = i;
    }
    if (sort_unsuccessfully)
    {
        printMessage("Массив не отсортирован.", true);
    }
    else
    {
        printMessage("Массив отсортирован без ошибок. " + std::to_string(k + 1) + " элементов", true);
    }
}

void mergesort::merge(long l, long m, long r)
{
    long nl = m - l + 1;
    long nr = r - m;

    // создаем временные массивы
    uint *left{new uint[nl]}, *right{new uint[nr]};

    // копируем данные во временные массивы
    for (long i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (long j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    long i = 0, j = 0;
    long k = l; // начало левой части

    while (i < nl && j < nr)
    {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}
