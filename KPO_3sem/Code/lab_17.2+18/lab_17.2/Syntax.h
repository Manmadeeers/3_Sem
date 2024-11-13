#pragma once
#include "stdafx.h"
typedef short ALPHABET;

namespace ST {


	struct Rule {
		ALPHABET nn;
		int iderror;
		short size;
		struct Chain {
			short size;
			ALPHABET* nt;
			Chain() { size = 0; nt = 0; };
			Chain(short psize,ALPHABET s,...);
			char* getCChain(char* b);
			static ALPHABET T(char t) { return ALPHABET(t); };
			static ALPHABET N(char n) { return -ALPHABET(n); };
			static bool isT(ALPHABET s) { return s > 0; };
			static bool isN(ALPHABET s) { return !isT(s); };
			static char alph_to_char(ALPHABET s) { return isT(s) ? char(s) : char(-s); };

		}*chains;
		Rule() { nn = 0x00; size = 0; }
		Rule(ALPHABET nn, int iderror, short psize, Chain c, ...);
		char* getCRule(char* b, short nchain);
		short getNextChain(ALPHABET t, Rule::Chain& pchain, short j);
	};


	struct Greibach {
		short size;
		ALPHABET startN;
		ALPHABET stbottomT;
		Rule* rules;
		Greibach() { short size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(ALPHABET pstartN, ALPHABET pstbottomT, short psize, Rule r, ...);
		short getRule(ALPHABET pnn, Rule& rule);
		Rule getRule(short n);
	};


	Greibach getGreibach();


};