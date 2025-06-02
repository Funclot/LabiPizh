#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Структура для хранения матрицы
struct Matrix {
    int rows, cols;
    vector<vector<int>> data;
};

//Чтение матрицы из файла
Matrix readMatrix(ifstream& file, int m, int n) {
    Matrix mat;
    mat.rows = m;
    mat.cols = n;
    mat.data.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            file >> mat.data[i][j];
        }
    }
    return mat;
}

//Запись матрицы в файл
void writeMatrix(ofstream& file, const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            file << setw(5) << mat.data[i][j];
        }
        file << endl;
    }
    file << endl; // Разделитель между матрицами
}

// Пророверка равенства главных диагоналей
bool isDiagonalEqual(const Matrix& mat) {
    if (mat.rows != mat.cols) return false; // Только для квадратных матриц

    int first = mat.data[0][0];
    for (int i = 1; i < mat.rows; i++) {
        if (mat.data[i][i] != first) return false;
    }
    return true;
}

// Функция для вывода матрицы на экран
void printMatrix(const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            cout << setw(5) << mat.data[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Параметры матриц
    int m, n, k, l;

    // Создаем тестовые файлы (можно заменить на ввод пользователя)
    ofstream f1("file1.txt");
    f1 << "2 3\n1 2 3\n4 5 6\n\n2 3\n7 7 9\n10 11 12\n\n2 3\n13 14 15\n16 17 18";
    f1.close();

    ofstream f2("file2.txt");
    f2 << "2 3\n19 20 21\n22 23 24";
    f2.close();

    // Открываем файлы для чтения
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    // Читаем матрицы из первого файла
    vector<Matrix> matrices1;
    while (file1.peek() != EOF) {
        file1 >> m >> n;
        matrices1.push_back(readMatrix(file1, m, n));
    }

    // Читаем матрицы из второго файла
    vector<Matrix> matrices2;
    while (file2.peek() != EOF) {
        file2 >> m >> n;
        matrices2.push_back(readMatrix(file2, m, n));
    }

    file1.close();
    file2.close();

    // Находим матрицы с равными диагоналями в первом файле
    vector<Matrix> matricesToAdd;
    for (const auto& mat : matrices1) {
        if (isDiagonalEqual(mat)) {
            matricesToAdd.push_back(mat);
        }
    }

    // Добавляем найденные матрицы во второй файл
    ofstream outFile2("file2.txt", ios::app);
    for (const auto& mat : matricesToAdd) {
        writeMatrix(outFile2, mat);
    }
    outFile2.close();

    // Выводим содержимое файлов на экран
    cout << "Содержимое первого файла:\n";
    for (const auto& mat : matrices1) {
        printMatrix(mat);
    }

    cout << "Содержимое второго файла:\n";
    for (const auto& mat : matrices2) {
        printMatrix(mat);
    }
    cout << "Добавленные матрицы:\n";
    for (const auto& mat : matricesToAdd) {
        printMatrix(mat);
    }

    return 0;
}