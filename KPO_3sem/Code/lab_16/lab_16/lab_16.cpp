#include "FST.h"

void main()
{
	char string1[]{PROC,BLANK,LAMBDA,BLANK,BLANK,ENDP};
	FST::FST fst1(
		string1,
		6,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(BLANK, 5)),
		FST::NODE(2, FST::RELATION(COS, 4), FST::RELATION(SIN, 4)),
		FST::NODE(2, FST::RELATION(BLANK, 5), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(BLANK, 5), FST::RELATION(ENDP, 6),
			FST::NODE()));

	if (FST::execute(fst1)) {
		cout << "Chain " << fst1.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst1.chain << " is not determined" << endl;
	}
	char string2[]{PROC, BLANK,LAMBDA,BLANK,END};
	FST::FST fst2(
		string2,
		6,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(BLANK, 5)),
		FST::NODE(2, FST::RELATION(COS, 4), FST::RELATION(SIN, 4)),
		FST::NODE(2, FST::RELATION(BLANK, 5), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(BLANK, 5), FST::RELATION(ENDP, 6),
			FST::NODE()));

	if (FST::execute(fst2)) {
		cout << "Chain " << fst2.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst2.chain << " is not determined" << endl;
	}
}