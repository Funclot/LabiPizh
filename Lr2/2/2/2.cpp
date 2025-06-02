#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

class Book {
private:
    string title;       // Название книги
    int pageCount;      // Количество страниц
    double price;       // Цена книги

public:
    // 1. Конструктор по умолчанию
    Book() : title("Без названия"), pageCount(0), price(0.0) {
        cout << "Создана книга по умолчанию" << endl;
    }

    // 2. Конструктор с параметрами
    Book(string t, int pc, double p) : title(t), pageCount(pc), price(p) {
        cout << "Создана книга: " << title << endl;
    }

    // 3. Деструктор
    ~Book() {
        cout << "Уничтожена книга: " << title << endl;
    }

    // 4. Метод обработки данных 1: Увеличить количество страниц на 10
    void increasePages() {
        pageCount += 10;
    }

    // 5. Метод обработки данных 2: Уменьшить цену в 2 раза если страниц > 100
    void Price() {
        if (pageCount > 100) {
            price /= 2.0;
        }
    }

    // 6. Метод формирования строки информации об объекте
    string getInfo() const {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "Название: " << title << endl;
        ss << "Страниц: " << pageCount << endl;
        ss << "Цена: " << price << " руб." << endl;
        return ss.str();
    }

    // Геттеры для полей 
    string getTitle() const { return title; }
    int getPageCount() const { return pageCount; }
    double getPrice() const { return price; }

    // Сеттеры для полей 
    void setTitle(string t) { title = t; }
    void setPageCount(int pc) { pageCount = pc; }
    void setPrice(double p) { price = p; }
};

// Функция для демонстрации работы класса 
void demoBookClass() {
    vector<Book> books;

    // 1.книга с константными значениями
    Book book1("Война и мир",100, 100);
    books.push_back(book1);

    // 2. книга с вводом данных 
    string title;
    int pages;
    double price;

    cout << "\nВведите данные о книге:" << endl;
    cout << "Название: ";
    getline(cin, title);

    cout << "Количество страниц: ";
    cin >> pages;

    cout << "Цена: ";
    cin >> price;
    cin.ignore(); // Очистка буфера

    Book book2(title, pages, price);
    books.push_back(book2);

    // 3. Обработка данных
    for (auto& book : books) {
        cout << "\nДо обработки:" << endl;
        cout << book.getInfo() << endl;

        book.increasePages();
        book.Price();

        cout << "После обработки:" << endl;
        cout << book.getInfo() << endl;
    }

    // 4.Вывод в Memo
    cout << "\nСодержимое Memo (все книги):" << endl;
    cout << "============================" << endl;
    for (const auto& book : books) {
        cout << book.getInfo() << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251); // для вывода

    SetConsoleCP(1251);       // для ввода
    demoBookClass();
    return 0;
    
}