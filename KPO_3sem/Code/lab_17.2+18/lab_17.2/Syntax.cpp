#include "stdafx.h"
namespace ST {
	Rule::Chain::Chain(short psize, ALPHABET s, ...) {
		nt = new ALPHABET[size = psize];
		int* p = (int*)&s;
		for (short i = 0; i < psize; ++i) {
			nt[i] = (ALPHABET)p[i];
		}
	}

	Rule::Rule(ALPHABET pnn, int piderror, short psize, Chain c, ...) {
		nn = pnn;
		iderror = piderror;
		chains = new Chain[size = psize];
		Chain* p = &c;
		for (int i = 0; i < size; i++) {
			chains[i] = p[i];
		}
	}
	Greibach::Greibach(ALPHABET pstartN, ALPHABET pstbottom, short psize, Rule r, ...) {
		startN = pstartN;
		stbottomT = pstbottom;
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i = 0; i < size; i++) {
			rules[i] = p[i];
		}
	}
	//fix
	Greibach getGreibach() {

	}
	//
	short Greibach::getRule(ALPHABET pnn, Rule& rule) {
		short rc = -1;
		short k = 0;
		while (k < size && rules[k].nn != pnn) {
			k++;
		}
		if (k < size) {
			rule = rules[rc = k];
		}
		return rc;
	}
	Rule Greibach::getRule(short n) {
		Rule rc;
		if (n < size) {
			rc = rules[n];
		}
		return rc;
	}

	char* Rule::getCRule(char* b, short nchain) {
		char bchain[200];
		b[0] = Chain::alph_to_char(nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		chains[nchain].getCChain(bchain);
		strcat_s(b, sizeof(bchain) + 5, bchain);
	}

	short Rule::getNextChain(ALPHABET t, Rule::Chain& pchain, short j) {
		short rc = -1;
		while (j < size && chains[j].nt[0] != t) {
			++j;
		}
		rc = (j < size ? j : -1);
		if (rc >= 0) {
			pchain = chains[rc];
		}
		return rc;
	}
	char* Rule::Chain::getCChain(char* b) {
		for (int i = 0; i < size; i++) {
			b[i] = Chain::alph_to_char(nt[i]);
			b[size] = 0x00;
		}
		return b;
	}


};