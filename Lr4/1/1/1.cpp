#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // список городов
    vector<string> cities = {
        "Москва",
        "Санкт-Петербург",
        "Новосибирск",
        "Екатеринбург",
        "Казань",
        "Нижний Новгород",
        "Челябинск",
        "Самара",
        "Омск",
        "Ростов-на-Дону"
    };

    // Вывод  списка
    cout << "Исходный список городов:\n";
    for (const auto& city : cities) {
        cout << city << endl;
    }

    // Поиск города с более чем 7 буквами (кроме первого)
    int swapIndex = -1;
    for (size_t i = 1; i < cities.size(); i++) {
        // Подсчет букв 
        int letterCount = 0;
        for (char c : cities[i]) {
            if (isalpha(c)) {
                letterCount++;
            }
        }

        if (letterCount > 7) {
            swapIndex = i;
            break;
        }
    }

    // Смена местами найденого с первым
    if (swapIndex != -1) {
        cout << "\nМеняем местами первый город и '" << cities[swapIndex] << "'\n";
        swap(cities[0], cities[swapIndex]);
    }
    else {
        cout << "\nГорода с более чем 7 буквами не найдены\n";
    }

    // Вывод 
    cout << "\nИзмененный список городов:\n";
    for (const auto& city : cities) {
        cout << city << endl;
    }

    return 0;
}