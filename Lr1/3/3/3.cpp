

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    // первый файла (a) - ввод
    ifstream a("a.txt"); // существующий файл
    if (!a) {
        cerr << "не удалось найти файл a.txt";
        return 1;
    }
    //файл с результатом(b) - вывод
    ofstream b("b.txt");
    if (!b) {
        cerr << "Ошибка: не удалось создать output.txt" << endl;
        return 1;
    }
    // условие задания
    double num;
    while (a >> num) {
        if (num > 0) {
            b << sqrt(num) << " ";
        }
        else if (num < 0){
            b << pow(num, 2) << " ";
        }
        else {
            b << num << " ";
        }
    }

    a.close();
    b.close();
    cout << "Результат записан в b.txt" << endl;

    return 0;
}
