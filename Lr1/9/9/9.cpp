#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>  

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Функция для создания и заполнения массива
void createArray(char arr[ROWS][COLS]) {
    char counter = 'A';
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = counter++;
        }
    }
}

// Функция для вывода массива в консоль 
void printArray(char arr[ROWS][COLS]) {
    cout << "Двумерный массив 5x5:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}

// Запись массива по столбцам в бинарный файл
void writeToBinaryFile(const char* filename, char arr[ROWS][COLS]) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка создания бинарного файла '" << filename << "'!" << endl;
        return;
    }

    // Записываем по столбцам
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            file.write(&arr[i][j], sizeof(char));
        }
    }

    cout << "\nМассив записан в бинарный файл '" << filename << "' по столбцам" << endl;
}

// Чтение из бинарного файла и запись в текстовый
void binaryToTextFile(const char* binFilename, const char* textFilename) {
    ifstream binFile(binFilename, ios::binary);
    ofstream textFile(textFilename);

    if (!binFile.is_open() || !textFile.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }

    // Читаем по столбцам (как записывали)
    for (int j = 0; j < COLS; j++) {
        string column;
        char ch;

        for (int i = 0; i < ROWS; i++) {
            binFile.read(&ch, sizeof(char));
            column += ch;
        }

        textFile << column << endl;
    }

    cout << "Данные из бинарного файла записаны в текстовый файл '" << textFilename << "'" << endl;
}

// Вывод содержимого текстового файла
void printTextFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия текстового файла '" << filename << "'!" << endl;
        return;
    }

    cout << "\nСодержимое текстового файла '" << filename << "':\n";
    string line;
    while (getline(file, line)) {  
        cout << line << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    char array[ROWS][COLS];

    // 1. Создаем и выводим массив
    createArray(array);
    printArray(array);

    // 2. Записываем в бинарный файл по столбцам
    const char* binFile = "array_data.bin";
    writeToBinaryFile(binFile, array);

    // 3. Конвертируем бинарный файл в текстовый
    const char* textFile = "array_data.txt";
    binaryToTextFile(binFile, textFile);

    // 4. Выводим содержимое текстового файла
    printTextFile(textFile);

    return 0;
}