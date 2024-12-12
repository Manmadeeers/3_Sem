#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Serializer {
public:
	static void Serialize(int intVal, ofstream& ofile);
	static void Serialize(bool boolLit, ofstream& ofile);


private:
	enum DataType : uint8_t {
		TYPE_INT = 0x01,
		TYPE_UINT = 0x02
	};
};

