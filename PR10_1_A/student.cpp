// Student.cpp — реалізація допоміжних функцій для типу Student
#include "student.h"
using namespace std;

int ZnajtyAboDodatySpecialnist(string specialnosti[], int& kilkistSpec,
    const int maxSpec, const string& nazva)
{
    for (int i = 0; i < kilkistSpec; i++)      // така спеціальність вже є?
        if (specialnosti[i] == nazva)
            return i;

    if (kilkistSpec >= maxSpec)                // масив заповнений
        return -1;

    specialnosti[kilkistSpec] = nazva;         // додаємо нову спеціальність
    return kilkistSpec++;
}