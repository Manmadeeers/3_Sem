#pragma once
#include "stdafx.h"

namespace OUT {
	struct Out {
		wchar_t outfile[PARM_MAX_SIZE];//out fle parametr
		ofstream* stream;//stream to write down to file
		//unsigned char* FailedText = new unsigned char[IN_MAX_LEN_TEXT];
	};
	static const Out INITOUT{ L"", NULL };//initialize Out
	Out getout(wchar_t outfile[]);//create an Out structure
	void WriteOUT(In::IN in, wchar_t outfile[]);//write info down to Out file
	void WriteERROR(ERROR::ERROR error, Out out);//writing down info about errors to the out file
	void Close(Out out);//close .out files
};