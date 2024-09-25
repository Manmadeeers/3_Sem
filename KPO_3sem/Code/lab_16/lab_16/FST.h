#pragma once
#include<iostream>
using namespace std;

#define PROC 'P'
#define BLANK 'B'
#define LAMBDA 'L'
#define END 'E'
#define START 'S'
#define COS 'C'
#define SIN 'I'
#define ENDP 'E'
#define X 'X'
#define Y 'Y'

namespace FST
{
	struct RELATION
	{
		char symbol;
		short nnode;
		RELATION(
			char c = 0x00,
			short ns = 0
		);
	};

	struct NODE
	{
		short n_relation;
		RELATION* relations;
		NODE();
		NODE(short n, RELATION rel, ...);
	};

	struct FST
	{
		char* chain;
		short position;
		short nstates;
		NODE* nodes;
		short* rstates;
		FST(char* s, short ns, NODE n, ...);
	};

	bool execute(FST& fst);
	bool step(FST& fst, short*& rstates);
}