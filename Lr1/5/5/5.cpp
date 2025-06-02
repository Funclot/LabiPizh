#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Film {
    string title;
    string directorLastName;
    string directorFirstName;
    int year;
    string country;
    double cost;
    double revenue;
    double profit;
};

// Функция для удаления пробелов в начале и конце строки
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t"); //в начале
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t"); // в конце
    return str.substr(first, (last - first + 1));
}
// динамический масив для названий фильмов
vector<Film> readFilms(const string& filename) {
    vector<Film> films;
    ifstream input(filename);

    if (!input) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return films;
    }

    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        Film film;
        string token;

        // Чтение данных с разделителем ';'
        getline(ss, film.title, ';');
        getline(ss, film.directorLastName, ';');
        getline(ss, film.directorFirstName, ';');
        getline(ss, token, ';'); film.year = stoi(trim(token));
        getline(ss, film.country, ';');
        getline(ss, token, ';'); film.cost = stod(trim(token));
        getline(ss, token, ';'); film.revenue = stod(trim(token));
        getline(ss, token);       film.profit = stod(trim(token));

        // Удаление лишних пробелов
        film.title = trim(film.title);
        film.directorLastName = trim(film.directorLastName);
        film.directorFirstName = trim(film.directorFirstName);
        film.country = trim(film.country);

        films.push_back(film);
    }

    input.close();
    return films;
}

void writeHoffmanFilms(const vector<Film>& films, const string& filename) {
    ofstream out(filename);

    if (!out) {
        cerr << "Ошибка создания файла " << filename << endl;
        return;
    }

    // Настройка вывода чисел
    out << fixed << setprecision(2);

    out << "Фильмы Ежи Гофмана:" << endl;
    out << "------------------------------------------------------------" << endl;
    out << left << setw(25) << "Название"
        << setw(8) << "Год"
        << setw(15) << "Страна"
        << setw(15) << "Стоимость"
        << setw(15) << "Доход"
        << setw(15) << "Прибыль" << endl;

    for (const auto& film : films) {
        if (film.directorLastName == "Гофман" && film.directorFirstName == "Ежи") {
            out << left << setw(25) << film.title
                << setw(8) << film.year
                << setw(15) << film.country
                << setw(15) << film.cost
                << setw(15) << film.revenue
                << setw(15) << film.profit << endl;
        }
    }

    out.close();
}

// создание исходника
void createSampleFile(const string& filename) {
    ofstream output(filename);
    output << "Огнём и мечом; Гофман; Ежи; 1999; Польша; 8000000; 14000000; 6000000\n"
        << "Пан Тадеуш; Гофман; Ежи; 1999; Польша; 6500000; 12000000; 5500000\n"
        << "Старая сказка; Кавалерович; Ежи; 1986; Польша; 3000000; 5000000; 2000000\n"
        << "Потоп; Гофман; Ежи; 1974; Польша; 5000000; 9000000; 4000000\n"
        << "Земля обетованная; Вайда; Анджей; 1975; Польша; 4500000; 8000000; 3500000";
    output.close();
}

int main() {
    setlocale(LC_ALL, "Ru");

    const string input_file = "films.txt";
    const string output_file = "hoffman_films.txt";

    // Создаем тестовый файл
    createSampleFile(input_file);

    // Чтение и обработка данных
    vector<Film> films = readFilms(input_file);
    writeHoffmanFilms(films, output_file);

    cout << "Результаты сохранены в '" << output_file << "'" << endl;

    return 0;
}