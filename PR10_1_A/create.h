// Create.h — формування (введення) масиву структур
#pragma once
#include <string>
#include "student.h"
using namespace std;

// Заповнює масив студентів.
// Прізвище береться з масиву prizvyshcha (якщо елемент заповнений),
// інакше вводиться з клавіатури. Спеціальність вводиться з клавіатури
// й запам'ятовується у масиві specialnosti. Решта полів — з клавіатури.
void Create(Student* p, const int N,
    const string prizvyshcha[], const int kilkistPrizvyshch,
    string specialnosti[], int& kilkistSpec, const int maxSpec);