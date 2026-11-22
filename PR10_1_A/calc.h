// Calc.h — опрацювання масиву: обчислення (без виведення на екран)
#pragma once
#include "student.h"

// повертає середній бал одного студента (з трьох предметів)
double SerednijBal(const Student& s);

// повертає відсоток студентів, які отримали з фізики оцінку "5" або "4"
double PercentFizyka4abo5(const Student* p, const int N);