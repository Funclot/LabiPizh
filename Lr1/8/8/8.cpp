#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

#pragma pack(push, 1)
// Функция создания исходника

// Структура для информации из файлов
struct DairyProduct {
    char name[50];          // название продукта
    char receiptDate[11];   // дата поступления (ГГГГ-ММ-ДД)
    int storageDays;        // срок хранения в днях
    char checkDate[11];     // дата проверки (ГГГГ-ММ-ДД)
};

void createBinar() {
    std::ofstream binar("dairy.dat", std::ios::binary);
    if (!binar) {
        std::cerr << "Ошибка создания файла!" << std::endl;
        return;
    }
    // исходные данные
    DairyProduct products[] = {
        {"Молоко", "2023-10-01", 7, "2023-10-05"},
        {"Сыр", "2023-10-02", 14, "2023-10-10"},
        {"Йогурт", "2023-09-28", 5, "2023-10-03"}
    };

    binar.write(reinterpret_cast<char*>(products), sizeof(products));
    
}

#pragma pack(pop)

// даты 

time_t dateToDays(const char* dateStr) {
    tm tm = {};
    istringstream iss(dateStr);
    iss >> get_time(&tm, "%Y-%m-%d");
    return mktime(&tm) / (60 * 60 * 24);
}

void checkExpiredProducts(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "\nПросроченные продукты:\n";
    cout << "------------------------------------------------------------------\n";
    cout << left << setw(12) << "Название"
        << setw(20) << "Дата поступления"
        << setw(20) << "Срок хранения"
        << setw(12) << "Дата проверки" << endl;
    cout << "------------------------------------------------------------------\n";

    DairyProduct product;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&product), sizeof(DairyProduct))) {
        time_t receiptDays = dateToDays(product.receiptDate);
        time_t checkDays = dateToDays(product.checkDate);
        int daysInStore = checkDays - receiptDays;

        if (daysInStore > product.storageDays) {
            cout << left << setw(12) << product.name
                << setw(20) << product.receiptDate
                << setw(20) << product.storageDays << " дней"
                << setw(12) << product.checkDate << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Просроченных продуктов не найдено." << endl;
    }
}

int main() {

    createBinar();

    setlocale(LC_ALL, "Russian");      
#ifdef _WIN32
    system("chcp 1251 > nul"); 
#endif
    const string filename = "dairy.dat"; // Предполагаем существование этого файла

    // Проверяем просроченные продукты
    checkExpiredProducts(filename);

    return 0;
}
