#include "stdafx.h"

namespace FST {
	//Works
	void Analyser(LT::LexTable lex_table) {
		int line_to_form = 0;
		char* current_line = new char[50];
		int current_line_iterator = 0;
		for (int i = 0; i < lex_table.size; i++) {
			LT::Entry current = lex_table.table[i];
			if (current.src_str_num != line_to_form) {
				current_line[current_line_iterator] = '\0';
				cout << "Line " << line_to_form;
				if (SAnaliser((unsigned char*)current_line)) {
					cout << " is correct | " << current_line << endl;
				}
				else {
					cout << " is incorrect | " << current_line << endl;
				}
				for (int i = 0; i < current_line_iterator; i++) {
					current_line[i] = (char)"";
				}
				current_line_iterator = 0;
				line_to_form = current.src_str_num;
			}
			current_line[current_line_iterator++] = current.lexem;
		}
	}

	//Ineger FA needs to be finished
	bool SAnaliser(unsigned char* line) {
		int count_main = 0;
		FST Datatype_FA(
			line,
			9,
			NODE(1,RELATION('t',1)),
			NODE(1,RELATION('f',2)),
			NODE(1,RELATION('i',3)),
			NODE(1,RELATION('(',4)),
			NODE(1,RELATION('t',5)),
			NODE(2,RELATION('i',6),RELATION('i',7)),
			NODE(1,RELATION(',',4)),
			NODE(1,RELATION(')',8)),
			NODE()
		);
		if (execute(Datatype_FA)) {
			return true;
		}

		FST Declare_FA(
			line,
			11,
			NODE(1,RELATION('d',1)),
			NODE(2,RELATION('t',2),RELATION('t',3)),
			NODE(1,RELATION('f',3)),
			NODE(2,RELATION('i',4),RELATION('i',9)),
			NODE(1,RELATION('(',5)),
			NODE(1,RELATION('t',6)),
			NODE(2,RELATION('i',7),RELATION('i',8)),
			NODE(1,RELATION(',',5)),
			NODE(1,RELATION(')',9)),
			NODE(1,RELATION(';',10)),
			NODE()
		);
		if (execute(Declare_FA)) {
			return true;
		}

		FST Main_FA(
			line,
			2,
			NODE(1,RELATION('m',1)),
			NODE()
		);
		if (execute(Main_FA)) {
			count_main++;
			if (count_main > 1) {
				return false;//need to throw an exception
			}
			return true;
		}
		
		FST Ident_FA(
			line,
			10,
			NODE(1,RELATION('i',1)),
			NODE(2,RELATION('v',2),RELATION('v',7)),
			NODE(2,RELATION('i',3),RELATION('i',8)),
			NODE(1,RELATION('(',4)),
			NODE(2,RELATION('i',6), RELATION('i', 5)),
			NODE(1,RELATION(',',4)),
			NODE(1,RELATION(')',8)),
			NODE(1,RELATION('l',8)),
			NODE(1,RELATION(';',9)),
			NODE()
		);

		if (execute(Ident_FA)) {
			return true;
		}

		FST L_Semicol_FA(
			line,
			2,
			NODE(1,RELATION('{',1)),
			NODE()
		);
		if (execute(L_Semicol_FA)) {
			return true;
		}

		FST R_Semicol_FA(
			line,
			3,
			NODE(1,RELATION('}',1)),
			NODE(1,RELATION(';',2)),
			NODE()
		);
		if (execute(R_Semicol_FA)) {
			return true;
		}

		FST Print_FA(
			line,
			9,
			NODE(2,RELATION('p',1),RELATION('p',6)),
			NODE(2,RELATION('i',2),RELATION('i',7)),
			NODE(1,RELATION('(',3)),
			NODE(2,RELATION('i',5), RELATION('i',4)),
			NODE(1,RELATION(',',3)),
			NODE(1,RELATION(')',7)),
			NODE(1,RELATION('l',7)),
			NODE(1,RELATION(';',8)),
			NODE()
		);
		if (execute(Print_FA)) {
			return true;
		}

		FST Return_FA(
			line,
			4,
			NODE(2,RELATION('r',1)),
			NODE(2,RELATION('i',2),RELATION('l',2)),
			NODE(1,RELATION(';',3)),
			NODE()
		);
		if (execute(Return_FA)) {
			return true;
		}

		return false;
	}
};