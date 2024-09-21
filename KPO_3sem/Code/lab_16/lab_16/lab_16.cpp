#include "stdafx.h"
#include <vector>

void main()
{
	char line1[] = {PROC, BLANK, LAMBDA ,BLANK, END};
	FST::FST fst1(line1,
		5,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(1, FST::RELATION(LAMBDA, 3)),
		FST::NODE(1, FST::RELATION(BLANK, 4)),
		FST::NODE(1,FST::RELATION(END,5)),
		FST::NODE()
		);
	if (FST::execute(fst1)) {
		cout << "Chain " << fst1.chain << " has been determined" << endl;
	}
	else {
		cout << "Chain " << fst1.chain << " has not been determined" << endl;
	}
}