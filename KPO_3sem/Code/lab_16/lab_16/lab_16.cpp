#include "FST.h"
//<-------------------->
// 
//Explanations to chains below
// P - PROC
// B - BLANK
// L - LAMBDA
// S - START
// C - COS
// I - SIN
// E - ENDP
// 
//
//<-------------------->

void main()
{
	setlocale(LC_ALL, "russian");
	char string1[] = {PROC,BLANK,LAMBDA,BLANK,ENDP,'\0'};
	char stringT;
	FST::FST fst1(
		string1,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
		);

	if (FST::execute(fst1)) {
		cout << "Chain " << fst1.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst1.chain << " is not determined" << endl;
	}

	char string2[] = "PBSCLBBE";
	FST::FST fst2(
		string2,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst2)) {
		cout << "Chain " << fst2.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst2.chain << " is not determined" << endl;
	}


	char string3[] = "PBLBBBBBE";
	FST::FST fst3(
		string3,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst3)) {
		cout << "Chain " << fst3.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst3.chain << " is not determined" << endl;
	}


	char string4[] = "PBSCYBBE";
	FST::FST fst4(
		string4,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4),FST::RELATION(Y,6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst4)) {
		cout << "Chain " << fst4.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst4.chain << " is not determined" << endl;
	}



	char string5[] = "PBBBSIXXXBBBE";
	FST::FST fst5(
		string5,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst5)) {
		cout << "Chain " << fst5.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst5.chain << " is not determined" << endl;
	}



	char string6[] = "PBBBSIXXXSCYYLBBBE";
	FST::FST fst6(
		string6,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst6)) {
		cout << "Chain " << fst6.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst6.chain << " is not determined" << endl;
	}



	char string7[] = "PBBBLSIXXXBBBE";
	FST::FST fst7(
		string7,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst7)) {
		cout << "Chain " << fst7.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst7.chain << " is not determined" << endl;
	}



	char string8[] = "PBSSYBE";
	FST::FST fst8(
		string8,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst8)) {
		cout << "Chain " << fst8.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst8.chain << " is not determined" << endl;
	}


	char string9[] = "PBLBBBB";
	FST::FST fst9(
		string9,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst9)) {
		cout << "Chain " << fst9.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst9.chain << " is not determined" << endl;
	}


	char string10[] = "PBAE";
	FST::FST fst10(
		string10,
		9,
		FST::NODE(1, FST::RELATION(PROC, 1)),
		FST::NODE(1, FST::RELATION(BLANK, 2)),
		FST::NODE(3, FST::RELATION(START, 3), FST::RELATION(BLANK, 2), FST::RELATION(LAMBDA, 6)),
		FST::NODE(2, FST::RELATION(SIN, 5), FST::RELATION(COS, 4)),
		FST::NODE(3, FST::RELATION(LAMBDA, 6), FST::RELATION(Y, 4), FST::RELATION(Y, 6)),
		FST::NODE(2, FST::RELATION(X, 6), FST::RELATION(X, 5)),
		FST::NODE(2, FST::RELATION(BLANK, 7), FST::RELATION(START, 3)),
		FST::NODE(2, FST::RELATION(ENDP, 8), FST::RELATION(BLANK, 7)),
		FST::NODE()
	);

	if (FST::execute(fst10)) {
		cout << "Chain " << fst10.chain << " is determined" << endl;
	}
	else
	{
		cout << "Chain " << fst10.chain << " is not determined" << endl;
	}
}