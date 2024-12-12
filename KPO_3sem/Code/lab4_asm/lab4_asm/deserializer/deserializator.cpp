#include "deserializer.h"

void Deserializer::DeserializeData()
{

	ifstream ifile = ifstream("..\\lab4_asm\\serialization.bin");

	if (ifile.is_open()) {

		uint8_t dataType;
		uint32_t dataLength;

		while (!ifile.eof()) {

			ifile.read(reinterpret_cast<char*>(&dataType), sizeof(dataType));
			ifile.read(reinterpret_cast<char*>(&dataLength), sizeof(dataLength));

			switch (dataType) {

			case TYPE_INT:
				ifile.read(reinterpret_cast<char*>(&intVal), dataLength);
				break;

			case TYPE_UINT:

				ifile.read(reinterpret_cast<char*>(&boolLit), dataLength);
				break;

			default:
				cout << "Неизвестный тип данных" << endl;
				break;
			}
		}

		ifile.close();

		cout << "Результат десереализации: " << "\nInt переменная: " << intVal << "\t" << "\nbool литерал: " <<boolLit << endl;

	}

	else {
		cout << "Не удалось открыть файл для чтения!";
	}
}

void Deserializer::ConvertToAssembler()
{

	ofstream ofile = ofstream("..\\Asm\\asm_04.asm");

	if (ofile.is_open()) {

		ofile ASM_HEAD;

		ofile << "INT_VAL \t SDWORD " << intVal << endl;
		ofile << "BOOL_LIT \t BYTE " << boolLit << endl;

		ofile ASM_FOOTER;

		ofile.close();
	}

	else {
		cout << "Не удалось открыть файл для записи!";
	}
}


