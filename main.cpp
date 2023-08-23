#include "mergesort.h"
#include "Misc.h"

#if defined(_WIN64) || defined(_WIN32)
#include <io.h>
#include <fcntl.h>
#endif
typedef unsigned int uint;

int main()
{
#if defined(_WIN64) || defined(_WIN32)
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif
    time_t start, end;
    double seconds;

    /* Многопоточная */
    printMessage("Многопоточная сортировка: массив " + std::to_string(ARR_LEN) + " элементов.", true);
    uint *arr{new uint[ARR_LEN]};
    std::srand(time(NULL));
    for (long i{0}; i < ARR_LEN; i++)
    {
        arr[i] = std::abs(std::rand()) % 500000;
    }

    mergesort msort_mt(arr);
    time(&start);
    msort_mt.sort_mt(0, ARR_LEN - 1);
    time(&end);
    seconds = difftime(end, start);
    printMessage("Многопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);
    test_sort(arr, ARR_LEN);
    delete[] arr;

    /* Однопоточная */
    printMessage("Однопоточная сортировка: массив " + std::to_string(ARR_LEN) + " элементов.", true);
    uint *arr2{new uint[ARR_LEN]};
    for (long i{0}; i < ARR_LEN; i++)
    {
        arr2[i] = std::abs(std::rand()) % 500000;
    }

    mergesort msort(arr2);
    time(&start);
    msort.sort(0, ARR_LEN - 1);
    time(&end);
    seconds = difftime(end, start);
    printMessage("Однопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);
    test_sort(arr2, ARR_LEN);

#if defined(_WIN64) || defined(_WIN32)
    system("pause");
#endif

    return 0;
}

// https://www.programmersought.com/article/16147494828/
// https://stackoverflow.com/questions/24130307/performance-problems-in-parallel-mergesort-c