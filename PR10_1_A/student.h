// Student.h — опис структури Student та допоміжні функції для спеціальностей
#pragma once
#include <string>

// інформація про студента (рівень А)
struct Student
{
    std::string prizv;         // прізвище
    int         kurs = 1;   // курс (ціле число)
    int         specialnist = 0;   // номер спеціальності у масиві спеціальностей
    int         fizyka = 0;   // оцінка з фізики
    int         matematyka = 0;   // оцінка з математики
    int         informatyka = 0;   // оцінка з інформатики
};

// Шукає спеціальність nazva у масиві specialnosti.
// Якщо її ще немає — додає в кінець масиву (збільшує kilkistSpec).
// Повертає номер спеціальності у масиві або -1, якщо масив заповнений.
int ZnajtyAboDodatySpecialnist(std::string specialnosti[], int& kilkistSpec,
    const int maxSpec, const std::string& nazva);