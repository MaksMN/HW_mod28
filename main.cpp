#include "mergesort.h"

typedef unsigned int uint;
int main()
{
    // генерируем массив
    uint arr[ARR_LEN]{6, 5, 12, 10, 9, 1};
    // std::srand(time(NULL));
    // for (uint i{0}; i < ARR_LEN; i++)
    // {
    //     arr[i] = std::abs(std::rand()) % 500;
    // }

    mergesort msort(arr);
    msort.sort(0, ARR_LEN - 1);

    return 0;
}