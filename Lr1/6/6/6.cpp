#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //тестовый файл f
    ofstream fout("f.txt");
    fout << "3 5 -2 -4 1 7 -6 -8 2 9 -1 -3";
    fout.close();

    ifstream fin("f.txt");
    ofstream h("h.txt");
    ofstream g("g.txt");

    if (!fin.is_open() || !h.is_open() || !g.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    int num;
    vector<int> positive, negative;

    // Чтение и разделение чисел из f
    while (fin >> num) {
        if (num > 0)
            positive.push_back(num);
        else if (num < 0)
            negative.push_back(num);
    }

    // Проверки
    if (positive.size() != negative.size()) {
        cerr << "Ошибка: количество положительных и отрицательных чисел не совпадает!" << endl;
        return 1;
    }

    if ((positive.size() + negative.size()) % 4 != 0) {
        cerr << "Ошибка: общее количество чисел не кратно 4!" << endl;
        return 1;
    }

    // Запись в файл h
    for (int p : positive) h << p << " ";
    for (int n : negative) h << n << " ";
    h.close();

    // Читение из  файла h
    ifstream hin("h.txt");
    vector<int> allNumbers;
    while (hin >> num) allNumbers.push_back(num);
    hin.close();

    // вывод результата в g
    int half = allNumbers.size() / 2;
    for (size_t i = 0; i < half; i += 2) {
        //по два положительных
        g << allNumbers[i] << " " << allNumbers[i + 1] << " ";
        //по два отрицательных
        g << allNumbers[half + i] << " " << allNumbers[half + i + 1] << " ";
    }

    cout << "Числа успешно переупорядочены в файле g.txt" << endl;

    fin.close();
    g.close();

    return 0;
}