#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <Windows.h>

using namespace std;


string processText(const string& input) {

    string result = input;
    size_t pos = 0;

    // Заменяем "Pascal" на "C++"
    while ((pos = result.find("Pascal", pos)) != string::npos) {
        result.replace(pos, 6, "C++");
        pos += 3; // Перемещаем позицию после вставки "C++"
    }

    // Удаляем символы '*'
    result.erase(remove(result.begin(), result.end(), '*'), result.end());

    // Заменяем цифры на пробелы
    for (char& c : result) {
        if (isdigit(c)) {
            c = ' ';
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);       
    string text;

    cout << "Введите текст:\n";

    // Чтение многострочного ввода
    string line;
    while (getline(cin, line) && !line.empty()) {
        text += line + "\n";
    }

    // Обработка текста
    string processedText = processText(text);

    // Вывод результатов
    cout << "\nИсходный текст:\n" << text << endl;
    cout << "Обработанный текст:\n" << processedText << endl;

    return 0;
}