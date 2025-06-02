#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //список городов
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

    // Вывод списка
    cout << "Список городов:\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << i + 1 << ". " << cities[i] << endl;
    }

    // Поиск (по условию)
    int lastIndex = -1;
    for (int i = cities.size() - 1; i >= 0; i--) {
        int countN = 0;
        for (char c : cities[i]) {
            if (c == 'н' || c == 'Н') {  //учёт обеих регистровые формы
                countN++;
            }
        }
        if (countN > 1) {
            lastIndex = i;
            break;
        }
    }

    // Результат
    if (lastIndex != -1) {
        cout << "\nПоследний город с более чем одной буквой 'н':\n";
        cout << "Номер: " << lastIndex + 1 << "\n";
        cout << "Название: " << cities[lastIndex] << endl;
    }
    else {
        cout << "\nГородов с более чем одной буквой 'н' не найдено.\n";
    }

    return 0;
}