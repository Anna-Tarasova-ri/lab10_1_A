// Print.h — виведення даних на екран
#pragma once
#include <string>
#include "student.h"

// виводить масив студентів у вигляді таблиці (із заголовком і шапкою)
void Print(const Student* p, const int N, const std::string specialnosti[]);

// виводить для кожного студента прізвище і середній бал (таблиця)
void PrintSerednijBal(const Student* p, const int N);