
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    // чтение файла a1.txt
    ifstream a1("a1.txt");
    if(!a1){
        cerr << "Не удалось открыть файл a.txt" << endl;
        return 1;
    }
    
    // запись отрицательных чисел из a1 в переменную sumnum
    double num1; 
    double sumnum = 0.0; // сумма отрицательных чисел
    while (a1 >> num1) {
        if (num1 < 0){ 
            sumnum += num1; 
        }
        
    }
    a1.close();
    // чтение файла a2.txt
    ifstream a2("a2.txt");
    if (!a2) {
        cerr << "Не удалось открыть файл a.txt" << endl;
        return 1;
    }
    

    double num2;
    // запись отрицательных чисел из a2 в переменную sumnum
    while (a2 >> num2) {
        if (num2 < 0) {
            sumnum += num2;
        }
    }
    a2.close();
    // Вывод
    cout << "Сумма отрицательных чисел: " << sumnum << endl;
    return 0;
}

