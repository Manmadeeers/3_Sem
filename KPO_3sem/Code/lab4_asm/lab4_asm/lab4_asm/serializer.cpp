#include "serializer.h"

void Serializer::Serialize(int intVal, ofstream& ofile)
{

	uint8_t dataType = TYPE_INT;
	uint32_t dataLength = sizeof(intVal);

	ofile.write(reinterpret_cast<const char*> (&dataType), sizeof(dataType));
	ofile.write(reinterpret_cast<const char*> (&dataLength), sizeof(dataLength));
	ofile.write(reinterpret_cast<const char*> (&intVal), sizeof(dataLength));
}

void Serializer::Serialize(bool boolLit, ofstream& ofile)
{

	uint8_t dataType = TYPE_UINT;
	uint32_t dataLength = sizeof(boolLit);

	ofile.write(reinterpret_cast<const char*>(&dataType), sizeof(dataType));
	ofile.write(reinterpret_cast<const char*> (&dataLength), sizeof(dataLength));
	ofile.write(reinterpret_cast<const char*> (&boolLit), dataLength);
}

