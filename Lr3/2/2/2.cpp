#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <Windows.h>
using namespace std;



// Функция для исправления слов с двойными заглавными буквами
string fixDoubleCapitals(const string& text) {
    string result;
    bool newWord = true;

    for (size_t i = 0; i < text.size(); i++) {
        char current = text[i];

        if (newWord && isalpha(current)) {
            // ПОиск начала слова
            bool isDoubleCap = false;

            // Проверка следующей буквы, если она есть
            if (i + 1 < text.size() && isalpha(text[i + 1])) {
                if (isupper(current) && isupper(text[i + 1])) {
                    isDoubleCap = true;
                }
            }

            if (isDoubleCap) {
                //Первая буква заглавная, остальные строчные
                result += current;
                i++; // Пропуск след. буквы
                if (i < text.size()) {
                    result += tolower(text[i]);
                }
            }
            else {
                result += current;
            }

            newWord = false;
        }
        else {
            result += current;
            if (!isalpha(current)) {
                newWord = true;
            }
        }
    }

    return result;
}

int main() {
    cout << "Введите текст с ошибками (двойные заглавные в начале слов):\n";
    cout << "Для завершения ввода нажмите Enter дважды\n\n";

    // Чтение ввода
    string text;
    string line;
    while (getline(cin, line) && !line.empty()) {
        text += line + "\n";
    }

    if (text.empty()) {
        cout << "Текст не был введен!\n";
        return 1;
    }

    // Исправление текста
    string fixedText = fixDoubleCapitals(text);

    // Вывод 
    cout << "\nИсходный текст:\n" << text << endl;
    cout << "Исправленный текст:\n" << fixedText << endl;
    return 0;
}