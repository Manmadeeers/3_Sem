#pragma once
#include "stdafx.h"

namespace FST {
	//edge: symbol -> vertex of a transition graph
	struct RELATION {
		char symbol;
		short nnode;
		RELATION(char c = 0x00, short ns = NULL);
	};
	//constructor
	RELATION::RELATION(char c, short ns) {
		symbol = c;
		nnode = ns;
	}
	//vertex of a transition graph
	struct NODE {
		short n_relation;
		RELATION* relations;
		NODE();
		NODE(short n, RELATION rel, ...);
	};
	NODE::NODE() {
		n_relation = 0;
		RELATION* relations = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...) {
		n_relation = n;
		RELATION* pointer = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++) {
			relations[i] = pointer[i];
		}
	}
	//undetermined finit automata
	struct FST {
		char* chain;
		short position;
		short nstates;
		NODE* nodes;
		short* rstates;
		FST(char* ch, short ns, NODE n, ...);
	};
	FST::FST(char* ch, short ns, NODE n, ...) {
		chain = ch;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* pointer = &n;
		for (short k = 0; k < ns; k++) {
			nodes[k] = pointer[k];
		}
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	}

	//execute chain determination
	bool execute(FST& fst);
	bool step(FST& fst, short*& rstates);
};