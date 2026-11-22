// UnitTest1.cpp — модульні тести для лабораторної роботи № 10, варіант 27
// Тестуються функції без введення/виведення:
//   SerednijBal, PercentFizyka4abo5 (модуль Calc),
//   ZnajtyAboDodatySpecialnist (модуль Student).
#include "pch.h"
#include "CppUnitTest.h"

// підключаємо тестовані модулі з основного проєкту
// (шлях підстав під свою структуру папок рішення)
#include "../PR10_1_A/student.cpp"
#include "../PR10_1_A/calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    // ---------- SerednijBal ----------
    TEST_CLASS(SerednijBalTests)
    {
    public:
        TEST_METHOD(ZvychajniOcinky)
        {
            Student s;
            s.fizyka = 5; s.matematyka = 4; s.informatyka = 3;
            Assert::AreEqual(4.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(DrobovyjSerednijBal)
        {
            Student s;
            s.fizyka = 5; s.matematyka = 5; s.informatyka = 4;
            Assert::AreEqual(14.0 / 3.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(UsiMinimalni)
        {
            Student s;
            s.fizyka = 1; s.matematyka = 1; s.informatyka = 1;
            Assert::AreEqual(1.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(UsiMaksymalni)
        {
            Student s;
            s.fizyka = 5; s.matematyka = 5; s.informatyka = 5;
            Assert::AreEqual(5.0, SerednijBal(s), 1e-9);
        }
    };

    // ---------- PercentFizyka4abo5 ----------
    TEST_CLASS(PercentFizyka4abo5Tests)
    {
    public:
        TEST_METHOD(PolovynaStudentiv)
        {
            Student p[4];
            p[0].fizyka = 5; p[1].fizyka = 4; p[2].fizyka = 3; p[3].fizyka = 2;
            Assert::AreEqual(50.0, PercentFizyka4abo5(p, 4), 1e-9);
        }

        TEST_METHOD(UsiMajutP_yatirkyAboChetvirky)
        {
            Student p[3];
            p[0].fizyka = 5; p[1].fizyka = 5; p[2].fizyka = 4;
            Assert::AreEqual(100.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(ZhodenNeMaje)
        {
            Student p[3];
            p[0].fizyka = 3; p[1].fizyka = 2; p[2].fizyka = 1;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(TrijkaNeRahujetsya)
        {
            Student p[1];
            p[0].fizyka = 3;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 1), 1e-9);
        }

        TEST_METHOD(DrobovyjProcent)
        {
            Student p[3];
            p[0].fizyka = 5; p[1].fizyka = 3; p[2].fizyka = 2;
            Assert::AreEqual(100.0 / 3.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(OdynStudentChetvirka)
        {
            Student p[1];
            p[0].fizyka = 4;
            Assert::AreEqual(100.0, PercentFizyka4abo5(p, 1), 1e-9);
        }

        TEST_METHOD(NulStudentivNeDilytNaNul)
        {
            Student* p = nullptr;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 0), 1e-9);
        }

        TEST_METHOD(OcinkyIZInshyhPredmetivNeVplyvajut)
        {
            Student p[2];
            p[0].fizyka = 2; p[0].matematyka = 5; p[0].informatyka = 5;
            p[1].fizyka = 5; p[1].matematyka = 1; p[1].informatyka = 1;
            Assert::AreEqual(50.0, PercentFizyka4abo5(p, 2), 1e-9);
        }
    };

    // ---------- ZnajtyAboDodatySpecialnist ----------
    TEST_CLASS(SpecialnostiTests)
    {
    public:
        TEST_METHOD(PershaSpecialnistDodajetsyaNaPochatok)
        {
            string spec[5] = { };
            int kilkist = 0;

            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");

            Assert::AreEqual(0, nomer);
            Assert::AreEqual(1, kilkist);
            Assert::AreEqual(string("F6"), spec[0]);
        }

        TEST_METHOD(ZnovuTaSamaNeDodajetsya)
        {
            string spec[5] = { };
            int kilkist = 0;

            ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");
            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");

            Assert::AreEqual(0, nomer);
            Assert::AreEqual(1, kilkist);
        }

        TEST_METHOD(NovaSpecialnistOtrymujeNastupnyjNomer)
        {
            string spec[5] = { };
            int kilkist = 0;

            ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");
            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F5");

            Assert::AreEqual(1, nomer);
            Assert::AreEqual(2, kilkist);
            Assert::AreEqual(string("F5"), spec[1]);
        }

        TEST_METHOD(ZnahodytyIsnuyuchuPislyInshyh)
        {
            string spec[5] = { };
            int kilkist = 0;

            ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");
            ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F5");
            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 5, "F6");

            Assert::AreEqual(0, nomer);
            Assert::AreEqual(2, kilkist);
        }

        TEST_METHOD(ZapovnenyjMasyvPovertajeMinusOdyn)
        {
            string spec[2] = { };
            int kilkist = 0;

            ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F6");
            ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F5");
            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F3");

            Assert::AreEqual(-1, nomer);
            Assert::AreEqual(2, kilkist);             // масив не змінився
        }

        TEST_METHOD(ZapovnenyjMasyvVseOdnoZnahodytyIsnuyuchu)
        {
            string spec[2] = { };
            int kilkist = 0;

            ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F6");
            ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F5");
            int nomer = ZnajtyAboDodatySpecialnist(spec, kilkist, 2, "F5");

            Assert::AreEqual(1, nomer);
            Assert::AreEqual(2, kilkist);
        }
    };
}