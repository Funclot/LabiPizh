#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string str1, str2, combined;

    // Ввод двух строк от пользователя
    cout << "Введите первую строку: ";
    getline(cin, str1);

    cout << "Введите вторую строку: ";
    getline(cin, str2);

    // Объединение строк (в произвольном порядке)
    combined = str1 + str2;

    // Сортировка символов в объединенной строке по ASCII
    sort(combined.begin(), combined.end());

    // Вывод результатов
    cout << "\nПервая строка: " << str1 << endl;
    cout << "Вторая строка: " << str2 << endl;
    cout << "Объединенная строка: " << str1 + str2 << endl;
    cout << "Отсортированная строка: " << combined << endl;

    
    return 0;
}