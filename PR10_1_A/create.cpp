// Create.cpp — реалізація формування масиву структур
#include <iostream>
#include <string>
#include "create.h"
using namespace std;

// Вводить ціле число з клавіатури, доки воно не потрапить у діапазон [min; max]
static int VvestyVDiapazoni(const string& pidkazka, const int min, const int max)
{
    int x;
    while (true)
    {
        cout << pidkazka;
        if (cin >> x && x >= min && x <= max)
            return x;

        cout << "     Помилка! Введіть ціле число від " << min
            << " до " << max << "." << endl;
        cin.clear();                              // скидаємо стан помилки потоку
        cin.ignore(10000, '\n');                  // видаляємо зайві символи
    }
}

void Create(Student* p, const int N,
    const string prizvyshcha[], const int kilkistPrizvyshch,
    string specialnosti[], int& kilkistSpec, const int maxSpec)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        // прізвище: з масиву (якщо заповнений), інакше — з клавіатури
        if (i < kilkistPrizvyshch && !prizvyshcha[i].empty())
        {
            p[i].prizv = prizvyshcha[i];
            cout << "     прізвище: " << p[i].prizv << endl;
        }
        else
        {
            cout << "     прізвище: ";
            cin >> ws;                            // пропускаємо залишки у буфері
            getline(cin, p[i].prizv);
        }

        p[i].kurs = VvestyVDiapazoni("     курс (1-4): ", 1, 4);

        // спеціальність вводиться з клавіатури і запам'ятовується у масиві
        string spec;
        while (true)
        {
            cout << "     спеціальність: ";
            cin >> ws;
            if (!getline(cin, spec))
                return;                           // потік вводу закрито

            int nomer = ZnajtyAboDodatySpecialnist(specialnosti, kilkistSpec,
                maxSpec, spec);
            if (nomer >= 0)
            {
                p[i].specialnist = nomer;
                break;
            }
            cout << "     Помилка! Масив спеціальностей заповнений." << endl;
        }

        p[i].fizyka = VvestyVDiapazoni("     оцінка з фізики (1-5): ", 1, 5);
        p[i].matematyka = VvestyVDiapazoni("     оцінка з математики (1-5): ", 1, 5);
        p[i].informatyka = VvestyVDiapazoni("     оцінка з інформатики (1-5): ", 1, 5);

        cout << endl;
    }
}