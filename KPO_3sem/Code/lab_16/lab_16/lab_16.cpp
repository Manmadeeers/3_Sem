#include "FST.h"

void main()
{
	setlocale(LC_ALL, "rus");
	char string1[]{ PROC,BLANK,LAMBDA,BLANK ,END };
	FST::FST fst1(
		string1,
		4,
		FST::NODE(1,FST::RELATION(PROC,1)),
		FST::NODE(1,FST::RELATION(BLANK,2)),
		FST::NODE(2,FST::RELATION(BLANK,2),FST::RELATION(),

	);
	if (FST::execute(fst1)) {
		cout << "Цепочка " << fst1.chain<< " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst1.chain << " не распознана" << endl;
	}
	char string2[]{ "afbccp" };
	FST::FST fst2(
		string2,
		6,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('f', 1), FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('f', 2), FST::RELATION('c', 3), FST::RELATION('r', 3)),
		FST::NODE(4, FST::RELATION('r', 3), FST::RELATION('c', 3), FST::RELATION('f', 4), FST::RELATION('d', 5)),
		FST::NODE(2, FST::RELATION('f', 4), FST::RELATION('d', 5)),
		FST::NODE());
	if (FST::execute(fst2)) {
		cout << "Цепочка " << fst2.chain << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst2.chain << " не распознана" << endl;
	}
}