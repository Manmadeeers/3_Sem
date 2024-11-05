#include "stdafx.h"
//#include "Windows.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

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
	try { throw ERROR_THROW_IN(111, 7, 7, (unsigned char*)"text"); }//throw a typical error in line 7 column 7 for example
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
		
		cout<<endl << "<-----Source text----->" << endl << endl;;
		int src_line_counter = 0;
		cout << src_line_counter << ' ';

		for (int i = 0; i < in.words_size; i++) {

			
			if (in.words[i][0] == '|') {
				cout << endl;
				cout << ++src_line_counter<< " ";
			}
			else {
				cout << in.words[i] << ' ';
			}
		}
		LOG::WriteIN(log, in);
		OUT::WriteOUT(in, parm.out);

		LT::LexTable LexTable = LT::Create(in.words_size);
		IT::IDTable IDTable = IT::Create(in.words_size);

		FST::GetLexem(LexTable, IDTable, in);
		cout<<endl << ';' << in.words[0] << ';' << endl;
		cout << endl << endl << "<-----Lexem table----->" << endl;
		
		int store_prev=0;
		cout<<"0" << store_prev<<" ";
		for (int i = 0; i < LexTable.size; i++) {
			LT::Entry current = LT::GetEntry(LexTable, i);
			
			if (current.src_str_num!=store_prev) {

				cout << endl;
				if (current.src_str_num <= 9) {
					cout<<'0' << current.src_str_num << ' ';
				}
				else {
					cout << current.src_str_num << ' ';
				}
				
			}
			else {
				
				cout<< current.lexem;
			}
			store_prev = current.src_str_num;
			
		}
		cout << endl << endl;

		cout << "<-----Identifier table----->" << endl;
		for (int i = 0; i < IDTable.size; i++) {
			IT::Entry current = IDTable.table[i];
			if (current.first_line_ID <= 9) {
				cout<<"0" << current.first_line_ID << " "<<"Identifier: " << current.id <<" Data type: " << current.IDDataType<<" Type: " << current.IDType << endl;
			}
			else {
				cout << current.first_line_ID << " " << current.id << current.IDDataType << current.IDType << endl;
			}
		}
			
		cout << endl << endl;
		


	}
	catch (ERROR::ERROR exception) {
		LOG::WriteERROR(log, exception);
		OUT::WriteERROR(exception, out);
		LOG::Close(log);
		OUT::Close(out);
	}


	system("pause");
	return 0;
}