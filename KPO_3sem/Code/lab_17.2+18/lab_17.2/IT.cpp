#include "stdafx.h"

namespace IT {
	IDTable Create(int size) {
		if (size > IT_MAXSIZE) {
			throw ERROR_THROW(68);
		}
		IDTable newIDTable;
		newIDTable.size = 0;
		newIDTable.table = new Entry[size];
		newIDTable.maxsize = ID_MAXSIZE;
		newIDTable.lits = new char* [LT_MAXSIZE];
		for (int i = 0; i < LT_MAXSIZE; i++) {
			newIDTable.lits[i] = new char[MAX_WORD_LENGTH];
		}
		return newIDTable;
	}

	void AddToIDTable(IDTable& idtable, Entry entry) {
		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(IDTable& idtable, int str_num) {
		if (str_num >= ID_MAXSIZE || str_num < 0) {
			throw ERROR_THROW(67);
		}
		Entry IDTableElem = idtable.table[str_num];
		return IDTableElem;
	}

	int IsId(IDTable& idtable, char id[ID_MAXSIZE]) {
		for (int i = 0; i < idtable.size; i++) {
			if (idtable.table[i].id == id) {
				return i;
			}
		}
		return NULL_INDEX;
	}
	bool CheckLiteralPresense(IDTable idtable,Entry ID) {
		if (ID.IDDataType == IT::STR) {
			for (int i = 0; i < LT_MAXSIZE; i++) {
				if (ID.value.vint = (int)idtable.lits[i]) {
					return true;
				}
			}
			return false;
		}
		else {
			for (int i = 0; i < LT_MAXSIZE; i++) {
				if (ID.value.vstr.str == idtable.lits[i]) {
					return true;
				}
			}
			return false;
		}
	}
	                                 
	void DeleteIdTable(IDTable& idtable) {
		idtable.table = nullptr;
		delete[] idtable.table;
		idtable.size = 0;
	}

};
