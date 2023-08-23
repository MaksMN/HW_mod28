#pragma once
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

/// @brief Выводит сообщение в консоль. Кроссплатформенная.
/// @param wmesg Текст сообщения
/// @param endl true - добавить перевод строки
void printMessage(const std::string &&msg, bool endl = true);

void test_sort(uint *arr, long len);