#include "deserializer.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Deserializer deserializer = Deserializer();
    deserializer.DeserializeData();
    deserializer.ConvertToAssembler();

    return 0;
}


