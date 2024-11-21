#pragma once
#include "stdafx.h"
typedef short ALPHABET;
#define GRB_ERROR_SERIES 600
#define NS(n) GRB::Rule::Chain::N(n)
#define TS(n) GRB::Rule::Chain::T(n)
#define ISNS(n)	GRB::Rule::Chain::isN(n)
namespace GRB {
	struct Rule {
		ALPHABET nn;
		int iderror;
		short size;
		struct Chain {
			short size;
			ALPHABET* nt;
			Chain() { this->size = 0; this->nt = 0; };
			Chain(short psize, ALPHABET s, ...);
			char* getCChain(char* b0);
			static ALPHABET T(char t) { return ALPHABET(t); };
			static ALPHABET N(char n) { return -ALPHABET(n); };
			static bool isT(ALPHABET s) { return s > 0; };
			static bool isN(ALPHABET s) { return !isT(s); };
			static char alph_to_char(ALPHABET s) { return isT(s) ? char(s) : char(-s); };
		}*chains;
		Rule() { this->nn = 0x00; this->size = 0; };
		Rule(ALPHABET pnn, int iderror, short psize, Chain c, ...);
		char* getCRule(char* b, short nchain);
		short getNextChain(ALPHABET t, Rule::Chain& pchain, short j);

	};
	struct Greibach {
		short size;
		ALPHABET startN;
		ALPHABET stbottomT;
		Rule* rules;
		Greibach() { this->size = 0; this->startN = 0; this->stbottomT = 0; this->rules = 0; };
		Greibach(ALPHABET pstartN, ALPHABET pstbottomT, short psize, Rule r, ...);
		short getRule(ALPHABET pnn, Rule& prule);
		Rule getRule(short n);
	};
	Greibach getGreibach();
}
