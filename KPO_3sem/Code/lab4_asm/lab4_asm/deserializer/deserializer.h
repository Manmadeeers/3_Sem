#pragma once
#include <iostream>
#include <fstream>
#include "generateAsm.h"
using namespace std;

class Deserializer {

public:

	void DeserializeData();
	void ConvertToAssembler();

	int intVal;
	bool boolLit;

	Deserializer() {

		this->intVal = 0;
		this->boolLit = 0;
	}


private:

	enum DataType : uint8_t {
		TYPE_INT = 0x01,
		TYPE_UINT = 0x02
	};

};

