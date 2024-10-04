#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

#ifdef GETERROR_TEST
	//test geteror function
	cout << "<----------testing geterror---------->" << endl << endl;
	try { throw ERROR_THROW(100); }
	catch (ERROR::ERROR exception) {//catching exceptions
		cout << "Error " << exception.id << "  " << exception.message << endl << endl;
	}
#endif
#ifdef GETERRORIN_TEST
	//testing geterrorin function
	cout << "<----------testing geterrorin---------->" << endl << endl;
	try { throw ERROR_THROW_IN(111, 7, 7,(unsigned char *)"text" ); }//throw a typical error in line 7 column 7 for example
	catch (ERROR::ERROR exception) {
		cout << "Error " << exception.id << "  " << exception.message << " in line " << exception.err_spec.line << " column " << exception.err_spec.col << endl << endl;
	}
#endif
#ifdef GETPARM_TEST
	cout << "<----------testing getparm---------->" << endl << endl;
	try { throw ERROR_THROW(104) }
	catch (ERROR::ERROR exception) {
		cout << "Error " << exception.id << " " << exception.message << endl << endl;
	}
#endif
#ifdef GETIN_TEST
	cout << "<----------testing getin---------->" << endl << endl;
	try {
		PARM::PARM parm = PARM::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "Amount of symbols: " << in.size << endl;
		cout << "Amount of lines: " << in.lines << endl;
		cout << "Amount of ignored symbols: " << in.ignore << endl;
	}
	catch (ERROR::ERROR exception) {
		cout << "Error " << " " << exception.id << " " << exception.message << endl << endl;
	};
#endif
#ifdef GETIN_TEST_2
	try {
		PARM::PARM parm = PARM::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "Amount of symbols: " << in.size << endl;
		cout << "Amount of lines: " << in.lines << endl;
		cout << "Amount of ignored symbols: " << in.ignore << endl;
	}
	catch (ERROR::ERROR exception) {
		cout << "Error " << " " << exception.id << " " << exception.message << endl << endl;
	};
#endif
	LOG::Log log = LOG::INITLOG;
	PARM::PARM parm = PARM::getparm(argc, argv);
	OUT::Out out;
	try {
		out = OUT::getout(parm.out);
		log = LOG::getlog(parm.log);
		LOG::WriteLine(log, (char*)"Test: ", (char*)" without errors \n", "");
		LOG::WriteLine_W(log, (wchar_t*)L"Test: ", (wchar_t*)L" without errors \n", L"");
		LOG::WriteLog(log);
		LOG::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		LOG::WriteIN(log, in);
		OUT::WriteOUT(in, parm.out);
	}
	catch (ERROR::ERROR exception) {
		LOG::WriteERROR(log,exception);
		OUT::WriteERROR(exception,out);
		LOG::Close(log);
		OUT::Close(out);
	}


	system("pause");
	return 0;
}