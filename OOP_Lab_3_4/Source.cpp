#define NOMINMAX
#include <iostream>
#include <limits>
#include <windows.h>
#include "Factory.h"

using namespace std;

const int MAX_OBJECTS = 100;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showAll(SymString* objects[], int count) {
    if (count == 0) {
        cout << "Список об'єктів порожній." << endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        cout << i << ": ";
        objects[i]->Show();
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SymString* objects[MAX_OBJECTS] = { nullptr };
    int count = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "\n================ МЕНЮ (ЛР 3.4, Варіант 8) ================" << endl;
        cout << "1. Створити SymString" << endl;
        cout << "2. Створити OctString" << endl;
        cout << "3. Показати всі об'єкти" << endl;
        cout << "4. Видалити об'єкт за індексом" << endl;
        cout << "5. Показати двійкове зображення (ShowBin для OctString)" << endl;
        cout << "6. Виконати віднімання (operator -)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Некоректний ввід. Спробуйте ще раз." << endl;
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: {
            if (count >= MAX_OBJECTS) {
                cout << "Досягнуто максимальну кількість об'єктів." << endl;
                break;
            }
            string id, val;
            cout << "Введіть ID: ";
            getline(cin, id);
            cout << "Введіть символьний рядок: ";
            getline(cin, val);
            objects[count++] = Factory::createSymString(id, val);
            cout << "Об'єкт SymString створено." << endl;
            break;
        }
        case 2: {
            if (count >= MAX_OBJECTS) {
                cout << "Досягнуто максимальну кількість об'єктів." << endl;
                break;
            }
            string id, val;
            cout << "Введіть ID: ";
            getline(cin, id);
            cout << "Введіть вісімкове число (цифри 0-7): ";
            getline(cin, val);
            objects[count++] = Factory::createOctString(id, val);
            cout << "Об'єкт OctString створено." << endl;
            break;
        }
        case 3: {
            showAll(objects, count);
            break;
        }
        case 4: {
            showAll(objects, count);
            if (count == 0) break;
            int idx;
            cout << "Введіть індекс об'єкта для видалення: ";
            if (cin >> idx && idx >= 0 && idx < count) {
                Factory::deleteObject(objects[idx]);
                for (int i = idx; i < count - 1; ++i) {
                    objects[i] = objects[i + 1];
                }
                objects[--count] = nullptr;
                cout << "Об'єкт видалено." << endl;
            }
            else {
                cout << "Некоректний індекс." << endl;
            }
            clearInput();
            break;
        }
        case 5: {
            showAll(objects, count);
            if (count == 0) break;
            int idx;
            cout << "Введіть індекс об'єкта OctString: ";
            if (cin >> idx && idx >= 0 && idx < count) {
                OctString* octObj = dynamic_cast<OctString*>(objects[idx]);
                if (octObj != nullptr) {
                    octObj->ShowBin();
                }
                else {
                    cout << "Помилка: ShowBin() доступний лише для OctString." << endl;
                }
            }
            else {
                cout << "Некоректний індекс." << endl;
            }
            clearInput();
            break;
        }
        case 6: {
            showAll(objects, count);
            if (count < 2) {
                cout << "Потрібно щонайменше 2 об'єкти." << endl;
                break;
            }
            int i1, i2;
            cout << "Введіть індекс першого об'єкта (s1): ";
            cin >> i1;
            cout << "Введіть індекс другого об'єкта (s2): ";
            cin >> i2;
            clearInput();

            if (i1 < 0 || i1 >= count || i2 < 0 || i2 >= count) {
                cout << "Некоректні індекси." << endl;
                break;
            }

            OctString* o1 = dynamic_cast<OctString*>(objects[i1]);
            OctString* o2 = dynamic_cast<OctString*>(objects[i2]);

            if (o1 != nullptr && o2 != nullptr) {
                OctString res = (*o1) - (*o2);
                cout << "Результат віднімання OctString:" << endl;
                res.Show();
                res.ShowBin();
            }
            else if (o1 == nullptr && o2 == nullptr) {
                SymString res = (*objects[i1]) - (*objects[i2]);
                cout << "Результат віднімання SymString:" << endl;
                res.Show();
            }
            else {
                cout << "Помилка: обидва об'єкти мають бути одного типу (або SymString, або OctString)." << endl;
            }
            break;
        }
        case 0:
            cout << "Завершення роботи..." << endl;
            break;
        default:
            cout << "Невідомий пункт меню." << endl;
            break;
        }
    }

    // Очищення пам'яті перед виходом
    for (int i = 0; i < count; ++i) {
        Factory::deleteObject(objects[i]);
    }

    return 0;
}