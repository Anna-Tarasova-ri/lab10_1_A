// Print.cpp — реалізація виведення даних на екран
#include <iostream>
#include <iomanip>
#include <string>
#include "print.h"
#include "calc.h"
using namespace std;

// Повертає кількість СИМВОЛІВ у рядку (а не байтів).
// Якщо рядок у кодуванні UTF-8 (кирилиця = 2 байти), рахуємо символи;
// інакше (наприклад, win-1251, де 1 символ = 1 байт) повертаємо size().
static int DovzhynaSymvoliv(const string& s)
{
    int symvoly = 0;
    for (size_t i = 0; i < s.size(); )
    {
        unsigned char c = (unsigned char)s[i];
        int dovzhyna;
        if (c < 0x80)                dovzhyna = 1;
        else if ((c & 0xE0) == 0xC0) dovzhyna = 2;
        else if ((c & 0xF0) == 0xE0) dovzhyna = 3;
        else if ((c & 0xF8) == 0xF0) dovzhyna = 4;
        else return (int)s.size();                    // не UTF-8

        if (i + dovzhyna > s.size())
            return (int)s.size();                     // не UTF-8
        for (int k = 1; k < dovzhyna; k++)
            if (((unsigned char)s[i + k] & 0xC0) != 0x80)
                return (int)s.size();                 // не UTF-8

        i += dovzhyna;
        symvoly++;
    }
    return symvoly;
}

// Повертає рядок s, доповнений пробілами справа до ширини width символів
static string Zliva(const string& s, const int width)
{
    int dovzhyna = DovzhynaSymvoliv(s);
    return s + string(dovzhyna < width ? width - dovzhyna : 0, ' ');
}

void Print(const Student* p, const int N, const string specialnosti[])
{
    const string TwoLines(96, '=');
    const string OneLine(96, '-');

    cout << endl << "Таблиця 1. Відомості про студентів та їхні оцінки" << endl;
    cout << TwoLines << endl;
    cout << "| " << Zliva("№", 3)
        << " | " << Zliva("Прізвище", 18)
        << " | " << Zliva("Курс", 4)
        << " | " << Zliva("Спеціальність", 22)
        << " | " << Zliva("Фізика", 6)
        << " | " << Zliva("Математика", 10)
        << " | " << Zliva("Інформатика", 11)
        << " |" << endl;
    cout << OneLine << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << Zliva(p[i].prizv, 18)
            << " | " << setw(4) << right << p[i].kurs
            << " | " << Zliva(specialnosti[p[i].specialnist], 22)
            << " | " << setw(6) << right << p[i].fizyka
            << " | " << setw(10) << right << p[i].matematyka
            << " | " << setw(11) << right << p[i].informatyka
            << " |" << endl;
    }
    cout << TwoLines << endl << endl;
}

void PrintSerednijBal(const Student* p, const int N)
{
    const string TwoLines(41, '=');
    const string OneLine(41, '-');

    cout << endl << "Таблиця 2. Середній бал студентів" << endl;
    cout << TwoLines << endl;
    cout << "| " << Zliva("№", 3)
        << " | " << Zliva("Прізвище", 18)
        << " | " << Zliva("Сер. бал", 10)
        << " |" << endl;
    cout << OneLine << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << Zliva(p[i].prizv, 18)
            << " | " << setw(10) << right << fixed << setprecision(2)
            << SerednijBal(p[i])
            << " |" << endl;
    }
    cout << TwoLines << endl << endl;
}