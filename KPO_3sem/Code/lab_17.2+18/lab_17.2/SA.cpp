#include "stdafx.h"

namespace FST {
	//FINISH!
	bool Analyser(LT::LexTable lex_table) {
		int store_prev = 0;
		for (int i = 0; i < lex_table.size; i++) {
			char* current_line = new char[20];
			int current_count = 0;
			LT::Entry current_entry = lex_table.table[i];

		}
	}

	//NEEDS REVIEW!
	bool SAnaliser(unsigned char* line) {
		FST Declare_FA(
			line,
			12,
			
			NODE(1, RELATION('d', 1)),
			NODE(1, RELATION('t', 2)),
			NODE(2, RELATION('f', 3), RELATION('i', 10)),
			NODE(1, RELATION('i', 4)),
			NODE(1,RELATION('(',5)),
			NODE(1,RELATION('t',6)),
			NODE(1,RELATION('i',7)),
			NODE(2,RELATION(',',8),RELATION(',',5)),
			NODE(2,RELATION(')',9),RELATION(')',11)),
			NODE(1,RELATION('{',11)),
			NODE(1,RELATION(';',11)),
			NODE()
		);
		if (execute(Declare_FA)) {
			return true;
		}
		FST Ident_FA(
			line,
			9,
			NODE(1,RELATION('i',1)),
			NODE(1,RELATION('=',2)),
			NODE(2,RELATION('i',3),RELATION('l',7)),
			NODE(2,RELATION(';',0),RELATION('(',4)),
			NODE(4,RELATION('i',5),RELATION('l',5),RELATION('i',6),RELATION('l',6)),
			NODE(1,RELATION(',',4)),
			NODE(1,RELATION(')',7)),
			NODE(1,RELATION(';',8)),
			NODE()
		);
		if (execute(Ident_FA)) {
			return true;
		}

		FST Print_FA(
			line,
			8,
			NODE(1,RELATION('p'),1),
			NODE(3,RELATION('i',6),RELATION('l',6),RELATION('i',2)),
			NODE(1,RELATION('(',3)),
			NODE(4,RELATION('i',4),RELATION('l',4),RELATION('i',5),RELATION('l',5)),
			NODE(1,RELATION(',',3)),
			NODE(1,RELATION(')',6)),
			NODE(1,RELATION(';',7)),
			NODE()
		);
		if (execute(Print_FA)) {
			return true;
		}

		FST Return_FA(
			line,
			4,
			NODE(1,RELATION('r',1)),
			NODE(2,RELATION('i',2),RELATION('l',2)),
			NODE(1,RELATION(';',3)),
			NODE()
		);
		if (execute(Return_FA)) {
			return true;
		}

		FST Semicol_FA(
			line,
			3,
			NODE(2,RELATION('}',1),RELATION('{',2)),
			NODE(1,RELATION(';',2)),
			NODE()
		);
		if (execute(Semicol_FA)) {
			return true;
		}

		FST Main_FA(
			line,
			3,
			NODE(2,RELATION('m',1),RELATION('m',2)),
			NODE(1,RELATION('{',2)),
			NODE()
		);
		if (execute(Main_FA)) {
			return true;
		}

		return false;
	}
};