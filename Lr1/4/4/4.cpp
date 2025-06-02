
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	ifstream a("a.txt");
	if (!a) {
		cerr << "не удалось открыть файл a.txt..." << endl;
		return 1;
	}
	int zero = 0;
	int num;
	int pos = 0;
	//счётчик нулей и чётных позиций
	while (a >> num) {
		if (pos % 2 == 0 && num == 0) { //условие задания
			zero++;
		}
		pos++;

	}
	a.close();
	cout << "Количество нулей на чётных позициях: " << zero << endl;


	return 0;
}

