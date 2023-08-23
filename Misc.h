#pragma once
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
typedef unsigned int uint;

/// @brief Выводит сообщение в консоль. Кроссплатформенная.
/// @param msg Текст сообщения
/// @param endl true - добавить перевод строки
void printMessage(const std::string &&msg, bool endl = true);

/// @brief Проверяет правильность сортировки в массиве
/// @param arr массив
/// @param len размер массива
void test_sort(uint *arr, long len);