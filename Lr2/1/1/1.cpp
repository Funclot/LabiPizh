#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Elstat {
private:
    double volt;    // Напряжение (В)
    double resistance; // Сопротивление (Ом)

public:
    // инициализация объекта
    Elstat(double v, double r) : volt(v), resistance(r) {} //конструктор класса

    // Функция формирования строки с информацией об объекте
    string getInfo() const {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "Напряжение: " << volt << " В" << endl;
        ss << "Сопротивление: " << resistance << " Ом" << endl;
        ss << "Ток: " << calculateCurrent() << " А";
        return ss.str();
    }

    // Расчет тока
    double calculateCurrent() const { // переменная для расчета тока
        
            return volt / resistance;
    }
    
};

int main() {
    setlocale(LC_ALL, "RU");
    vector<Elstat> circuits;
    char choice;

    do {
        double voltage, resistance;

        cout << "Введите напряжение (В): ";
        cin >> voltage;

        cout << "Введите сопротивление (Ом): ";
        cin >> resistance;

        // объект класса
        Elstat circuit(voltage, resistance);

        // Добавение в вектор
        circuits.push_back(circuit);

        cout << "\nДобавлена цепь:\n" << circuit.getInfo() << endl;

        cout << "\nХотите добавить еще одну цепь? (y/n): ";
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода
    } while (tolower(choice) == 'y');

    // Вывод информации о всех цепях
    cout << "\nРезультаты для всех цепей:\n";
    cout << "-------------------------\n";
    for (const auto& circuit : circuits) {
        cout << circuit.getInfo() << endl;
        cout << "-------------------------\n";
    }

    return 0;
}