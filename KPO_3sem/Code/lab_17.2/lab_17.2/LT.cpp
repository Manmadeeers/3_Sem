#include "stdafx.h"


namespace LT {
	LexTable Create(int size) {
		LexTable newLexTable;
		newLexTable.maxsize = LT_MAXSIZE;
		newLexTable.size = 0;
		newLexTable.table = new Entry[size];
		return newLexTable;
	}

	void AddToLexTable(LexTable& LexTable, Entry entry) {
		if (LexTable.size >= LT_MAXSIZE) {
			throw ERROR_THROW(60);
		}
		LexTable.table[LexTable.size] = entry;
		LexTable.size++;
	}

	Entry GetEntry(LexTable& LexTable, int str_num) {
		if (str_num >= LT_MAXSIZE || str_num < 0) {
			throw ERROR_THROW(61);
		}
		Entry LexTableElem = LexTable.table[str_num];
		return LexTableElem;
	}

	void DeleteLexTable(LexTable& LexTable) {
		LexTable.table = nullptr;
		delete[] LexTable.table;
		LexTable.size = 0;
	}

	void BuildLexTable(In::IN in, LexTable& LexTable) {

	}

};