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

    long arr_len = 100000000L;
    uint max_threads = 8;

    printMessage("Укажите размер массива(ноль = 100000000): ", false);
    std::cin >> arr_len;
    if (arr_len == 0)
        arr_len = 100000000;
    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }
    printMessage("Приложение не будет открывать новые потоки если их количество в рекурсии превысит ниже указанное значение", true);
    printMessage("Укажите максимальное количество потоков (ноль = 8): ", false);
    std::cin >> max_threads;
    if (max_threads == 0)
        max_threads = 4;
    std::cin.clear();
    while (std::cin.get() != '\n')
    {
    }

    /* Многопоточная */
    printMessage("Многопоточная сортировка: массив " + std::to_string(arr_len) + " элементов.", true);
    uint *arr{new uint[arr_len]};
    std::srand(time(NULL));
    for (long i{0}; i < arr_len; i++)
    {
        arr[i] = std::abs(std::rand()) % 500000;
    }
    mergesort msort_mt(arr, arr_len, max_threads);
    msort_mt.test_sort();
    time(&start);
    msort_mt.sort_mt(0, arr_len - 1);
    time(&end);
    seconds = difftime(end, start);
    printMessage("Многопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);
    msort_mt.test_sort();
    delete[] arr;

    /* Однопоточная */
    printMessage("\nОднопоточная сортировка: массив " + std::to_string(arr_len) + " элементов.", true);
    uint *arr2{new uint[arr_len]};
    for (long i{0}; i < arr_len; i++)
    {
        arr2[i] = std::abs(std::rand()) % 500000;
    }

    mergesort msort(arr2, arr_len, max_threads);
    msort.test_sort();
    time(&start);
    msort.sort(0, arr_len - 1);
    time(&end);
    seconds = difftime(end, start);
    printMessage("Однопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);
    msort.test_sort();
    delete[] arr2;

#if defined(_WIN64) || defined(_WIN32)
    system("pause");
#endif

    return 0;
}
