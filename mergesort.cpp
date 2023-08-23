#include "mergesort.h"

mergesort::mergesort(uint *_arr)
{
    arr = _arr;
}

void mergesort::sort_mt(long l, long r)
{
    if (l >= r)
        return;
    long m = (l + r - 1) / 2;

    auto len = abs(r - l);
    auto N = std::thread::hardware_concurrency() / 2;

    if (threads > 4)
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
