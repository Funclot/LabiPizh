#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)
struct Work {
    char name[50];          // наименование работы
    int plannedHours;       // выделенное количество часов
    int actualHours;        // реально затраченное время
    double cost;            // стоимость работы
};
#pragma pack(pop)

// Функция для создания тестового бинарного файла
void createWorkFile(const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка создания файла!" << endl;
        return;
    }

    vector<Work> works = {
        {"Разработка интерфейса", 40, 45, 50000},
        {"Тестирование системы", 20, 18, 25000},
        {"Написание документации", 30, 35, 30000},
        {"Оптимизация кода", 15, 15, 20000},
        {"Исправление ошибок", 10, 12, 15000}
    };

    for (const auto& work : works) {
        file.write(reinterpret_cast<const char*>(&work), sizeof(Work));
    }

    cout << "Тестовый бинарный файл создан: " << filename << endl;
}

// Функция для вывода содержимого файла
void printWorkFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "\nСодержимое файла " << filename << ":\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Наименование работы\tПлан.ч\tФакт.ч\tСтоимость\n";
    cout << "---------------------------------------------------------------\n";

    Work work;
    while (file.read(reinterpret_cast<char*>(&work), sizeof(Work))) {
        cout << left << setw(25) << work.name
            << right << setw(6) << work.plannedHours
            << setw(7) << work.actualHours
            << setw(12) << fixed << setprecision(2) << work.cost << endl;
    }
}

// Функция для корректировки стоимости
void adjustCosts(const string& filename) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    Work work;
    bool changed = false;

    while (file.read(reinterpret_cast<char*>(&work), sizeof(Work))) {
        if (work.actualHours > work.plannedHours) {
            // Сохраняем текущую позицию
            streampos pos = file.tellg();
            // Перемещаемся назад на размер структуры
            file.seekp(pos - static_cast<streamoff>(sizeof(Work)));

            // Уменьшаем стоимость на 10%
            work.cost *= 0.9;

            // Записываем измененную структуру
            file.write(reinterpret_cast<const char*>(&work), sizeof(Work));
            file.seekp(pos); // Возвращаем позицию чтения

            changed = true;
        }
    }

    if (changed) {
        cout << "\nСтоимость работ, выполненных с опозданием, уменьшена на 10%\n";
    }
    else {
        cout << "\nНет работ, выполненных с опозданием\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    const string filename = "works.bin";

    // 1. Создаем тестовый бинарный файл
    createWorkFile(filename);

    // 2. Выводим исходное содержимое файла
    printWorkFile(filename);

    // 3. Корректируем стоимость
    adjustCosts(filename);

    // 4. Выводим обновленное содержимое файла
    printWorkFile(filename);

    return 0;
}
