#pragma once
#define IN_MAX_LEN_TEXT 1024*1024//max length of text in the file	
#define IN_CODE_ENDL '\n'
//table of symbols
// 
//according to the lab 15 task '\n' symbol (0A in ASCII) should be replaced with '|' symbol
// 
//	      0       1      2      3      4      5      6      7      8      9      A      B      C      D      E      F
#define IN_CODE_TABLE {\
/*0*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T,  '|' , IN::T, IN::T,	IN::I, IN::T, IN::T,\
/*1*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*2*/	IN::S,	IN::T, IN::F, IN::T, IN::F,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*3*/	IN::T,	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*4*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::I, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*5*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::I,	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*6*/	IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T	,\
/*7*/	IN::T ,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
																													\
/*8*/	IN::T,	IN::T, IN::T, IN::T, IN::I,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*9*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*A*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*B*/	IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*C*/   IN::T,  IN::T, IN::I, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::I,\
/*D*/	IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T,\
/*E*/   IN::T,	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*F*/   IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T ,IN::T, IN::T,	IN::T, IN::T, IN::T, IN::T,	IN::T, IN::T, IN::T\
}

#include "stdafx.h";
namespace In {
	struct IN {
		enum { T = 1024, F = 2048, I = 4096, S = 8192 };
		int size;
		int lines;
		int ignore;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;
	};
	IN getin(wchar_t infile[]);
};