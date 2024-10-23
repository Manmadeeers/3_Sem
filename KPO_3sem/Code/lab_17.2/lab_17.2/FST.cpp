#include "stdafx.h"



namespace FST
{
	RELATION::RELATION(char c, short nn)
	{
		symbol = c;
		nnode = nn;
	}
	NODE::NODE()
	{
		n_relation = 0;
		RELATION* relations = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		for (int i = 0; i < n; i++)
		{
			relations[i] = p[i];
		}
	}
	FST::FST(unsigned char* s, short ns, NODE n, ...)
	{
		chain = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int i = 0; i < ns; i++)
		{
			nodes[i] = p[i];
		}
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	}

	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.chain[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				}
		}
		return rc;
	}

	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen((const char*)fst.chain);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}
		delete[] rstates;
		return(rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}



	void GetLexem(LT::LexTable& lextable, IT::IDTable& idtable, In::IN in) {

		unsigned char* lexem;
		for (int i = 0; i < in.words_size; i++) {
			lexem = in.words[i];
		}



		//finite automatas
		FST integer_au(
			lexem,
			8,
			NODE(1, RELATION('i', 1)),
			NODE(1, RELATION('n', 2)),
			NODE(1, RELATION('t', 3)),
			NODE(1, RELATION('e', 4)),
			NODE(1, RELATION('g', 5)),
			NODE(1, RELATION('e', 6)),
			NODE(1, RELATION('r', 7)),
			NODE()
		);

		FST string_au(
			lexem,
			7,
			NODE(1,RELATION('s',1)),
			NODE(1,RELATION('t',2)),
			NODE(1,RELATION('r',3)),
			NODE(1,RELATION('i',4)),
			NODE(1,RELATION('n',5)),
			NODE(1,RELATION('g',6)),
			NODE()
		);

		FST function_au(
			lexem,
			9,
			NODE(1,RELATION('f',1)),
			NODE(1,RELATION('u',2)),
			NODE(1,RELATION('n',3)),
			NODE(1,RELATION('c',4)),
			NODE(1,RELATION('t',5)),
			NODE(1,RELATION('i',6)),
			NODE(1,RELATION('o',7)),
			NODE(1,RELATION('n',8)),
			NODE()
		);

		FST declare_au(
			lexem,
			8,
			NODE(1, RELATION('d', 1)),
			NODE(1, RELATION('e', 2)),
			NODE(1, RELATION('c', 3)),
			NODE(1, RELATION('l', 4)),
			NODE(1, RELATION('a', 5)),
			NODE(1, RELATION('r', 6)),
			NODE(1, RELATION('e', 7)),
			NODE()
		);

		FST return_au(
			lexem,
			7,
			NODE(1, RELATION('r', 1)),
			NODE(1, RELATION('e', 2)),
			NODE(1, RELATION('t', 3)),
			NODE(1, RELATION('u', 4)),
			NODE(1, RELATION('r', 5)),
			NODE(1, RELATION('n', 6)),
			NODE()
		);
		
		FST print_au(
			lexem,
			6,
			NODE(1, RELATION('p', 1)),
			NODE(1, RELATION('r', 2)),
			NODE(1, RELATION('i', 3)),
			NODE(1, RELATION('n', 4)),
			NODE(1, RELATION('t', 5)),
			NODE()
		);

		FST main_au(
			lexem,
			5,
			NODE(1, RELATION('m', 1)),
			NODE(1, RELATION('a', 2)),
			NODE(1, RELATION('i', 3)),
			NODE(1, RELATION('n', 4)),
			NODE()
		);

	}
}