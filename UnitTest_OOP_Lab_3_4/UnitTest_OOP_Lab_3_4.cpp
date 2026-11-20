#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_3_4/SymString.cpp"
#include "../OOP_Lab_3_4/OctString.cpp"
#include "../OOP_Lab_3_4/Factory.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab34
{
	TEST_CLASS(UnitTestOOPLab34)
	{
	public:
        // Віднімання для SymString (видалення підрядка)
        TEST_METHOD(TestSymStringSubtraction)
        {
            SymString s1("s1", "Hello World");
            SymString s2("s2", " World");
            SymString res = s1 - s2;
            Assert::AreEqual(string("Hello"), res.getValue());

            // Якщо підрядка немає — повертається початковий рядок
            SymString s3("s3", "XYZ");
            SymString res2 = s1 - s3;
            Assert::AreEqual(string("Hello World"), res2.getValue());
        }

        // Валідація вісімкового рядка
        TEST_METHOD(TestOctStringValidation)
        {
            OctString valid("o1", "752");
            Assert::AreEqual(string("752"), valid.getValue());

            // Цифра 8 недопустима у вісімковій системі — має скинутися на "0"
            OctString invalid("o2", "789");
            Assert::AreEqual(string("0"), invalid.getValue());
        }

        // Віднімання для OctString (числове)
        TEST_METHOD(TestOctStringSubtraction)
        {
            OctString o1("o1", "17"); // 15 у десятковій
            OctString o2("o2", "7");  // 7 у десятковій
            OctString res = o1 - o2;  // 8 у десятковій = 10 у вісімковій

            Assert::AreEqual(string("10"), res.getValue());
        }

        // Перевірка Factory (створення та видалення з обнуленням вказівника)
        TEST_METHOD(TestFactoryLifecycle)
        {
            SymString* obj = Factory::createOctString("f1", "12");
            Assert::IsNotNull(obj);
            Assert::AreEqual(string("12"), obj->getValue());

            Factory::deleteObject(obj);
            Assert::IsNull(obj);
        }
    };
}