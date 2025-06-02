#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //список фамилий
    vector<string> surnames = {
        "Иванова", "Петров", "Сидорова", "Кузнецов", "Смирнова",
        "Васильев", "Попова", "Новиков", "Федорова", "Морозов",
        "Волкова", "Алексеев", "Лебедева", "Семенов", "Егоров",
        "Павлова", "Козлов", "Степанова", "Николаев", "Орлова"
    };

    // Вывод исходного списка
    cout << "Исходный список фамилий:\n";
    for (const auto& surname : surnames) {
        cout << surname << endl;
    }

    //новый список для фамилий, оканчивающихся на "ова" или "ova"
    vector<string> filteredSurnames;

    for (const auto& surname : surnames) {
        // Проверка окончания фамилии (минимум 3 символа)
        if (surname.size() >= 3) {
            string last3 = surname.substr(surname.size() - 3);
            if (last3 == "ова" || last3 == "ова") {
                filteredSurnames.push_back(surname);
            }
        }
    }

    // Сортировка
    sort(filteredSurnames.begin(), filteredSurnames.end());

    //результ
    cout << "\nФамилии, оканчивающиеся на 'ова' или 'ova' (отсортированные):\n";
    for (const auto& surname : filteredSurnames) {
        cout << surname << endl;
    }

    return 0;
}