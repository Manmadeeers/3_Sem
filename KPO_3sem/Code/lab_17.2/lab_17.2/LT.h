#pragma once
#include "stdafx.h"
#define LEXEM_FIXSIZE 1
#define LT_MAXSIZE 4096
#define LT_NULLINDEX 0xffffffff
#define LEX_INTEGER 't'
#define LEX_STRING 't'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_SEMICOLON ';'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_RIGHT_BRACE '}'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTESIS ')'
#define LEX_PLUS 'v'
#define LEX_MINUS 'v'
#define LEX_MULTIPLICATION 'v'
#define LEX_DEVISION 'v'


namespace LT {
	struct Entry
	{
		char lexem[LEXEM_FIXSIZE];
		int src_str_num;
		int index;
	};

	struct LexTable {
		int maxsize;//lexem table capacity(less then LT_MAXSIZE)
		int size;//current lexem table size
		Entry* table;
	};
	LexTable Create(int size);
	void AddToLexTable(LexTable& LexTable, Entry entry);
	Entry GetEntry(LexTable& LexTable, int str_num);
	void DeleteLexTable(LexTable& LexTable);
	void BuildLexTable(In::IN in, LexTable& LexTable);
};