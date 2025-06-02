#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Исходный список фамилий (20 элементов)
    vector<string> surnames = {
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов",
        "Васильев", "Попов", "Новиков", "Федоров", "Морозов",
        "Волков", "Алексеев", "Лебедев", "Семенов", "Егоров",
        "Павлов", "Козлов", "Степанов", "Николаев", "Орлов"
    };

    // Вывод исходного списка
    cout << "Исходный список фамилий:\n";
    for (const auto& surname : surnames) {
        cout << surname << endl;
    }

    // Поиск самой длинной и самой короткой фамилии
    size_t min_len = surnames[0].length();
    size_t max_len = surnames[0].length();
    int min_index = 0;
    int max_index = 0;

    for (size_t i = 1; i < surnames.size(); i++) {
        size_t current_len = surnames[i].length();

        if (current_len < min_len) {
            min_len = current_len;
            min_index = i;
        }

        if (current_len > max_len) {
            max_len = current_len;
            max_index = i;
        }
    }

    // Меняем местами самую длинную и самую короткую фамилии
    if (min_index != max_index) {
        cout << "\nМеняем местами:\n";
        cout << "Самая короткая фамилия (" << surnames[min_index] << ", "
            << min_len << " букв)\n";
        cout << "Самая длинная фамилия (" << surnames[max_index] << ", "
            << max_len << " букв)\n";

        swap(surnames[min_index], surnames[max_index]);
    }
    else {
        cout << "\nВсе фамилии одинаковой длины\n";
    }

    // Вывод измененного списка
    cout << "\nИзмененный список фамилий:\n";
    for (const auto& surname : surnames) {
        cout << surname << endl;
    }

    return 0;
}