#include "serializer.h"

int main() {

	setlocale(LC_ALL, "rus");
	int intVar = 10;
	bool boolLiteral = 0;

	cout << "Введите int переменную: ";
	cin >> intVar;

	cout << "\nВведите bool переменную: ";
	cin >> boolLiteral;

	Serializer Serializer;

	ofstream output;

	output.open("serialization.bin", ios::binary);

	if (output.is_open()) {

		Serializer.Serialize(intVar, output);
		Serializer.Serialize(boolLiteral, output);
		cout << "Сериализация произшла успешно!";
	}

	else {

		cout << "Не удалось открывать файл для записи";
	}

	output.close();

	return 0;
}
