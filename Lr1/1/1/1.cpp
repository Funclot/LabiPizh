#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //файл для чтения
    ifstream a("a.txt");
    if (!a) {
        cerr << "Не удалось открыть файл a.txt" << endl;
        return 1;
    }

    // Чтение чисел из файла
    vector<double> numbers;
    double num;
    while (a >> num) {
        numbers.push_back(num);
    }
    a.close();

    // файл для записи положительных чисел
    ofstream b("b.txt");
    if (!b) {
        cerr << "Не удалось создать файл b.txt" << endl;
        return 1;
    }

    // Записm положительных чисeл
    for (double number : numbers) {
        if (number > 0) {
            b << number << " ";
        }
    }
    b.close();

    cout << "Положительные числа успешно записаны в файл b.txt" << endl;
    return 0;
}