#pragma once
#include "stdafx.h"
//#include "Rules.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
#define MFST_TRACE_START std::cout<< std::setw(4)<<std::left<<"Step"<<":"\
								  << std::setw(20)<<std::left<<"Rule"\
								  << std::setw(30)<<std::left<<"Incoming lent"\
								  << std::setw(20)<<std::left<<"Stack"\
								  << std::endl;

#define MFST_TRACE1 std::cout<< std::setw(4)<<std::left<<++FST_TRACE_n<<": "\
								  << std::setw(20)<<std::left<<rule.getCRule(rbuf,nrulechain)\
								  << std::setw(30)<<std::left<<getCLent(lbuf,lent_position)\
								  << std::setw(20)<<std::left<<getCSt(sbuf)\
								  << std::endl;

#define MFST_TRACE2		 std::cout<< std::setw(4)<<std::left<<FST_TRACE_n<<": "\
								  << std::setw(20)<<std::left<<" "\
								  << std::setw(30)<<std::left<<getCLent(lbuf,lent_position)\
								  << std::setw(20)<<std::left<<getCSt(sbuf)\
								  << std::endl;

#define MFST_TRACE3		 std::cout<< std::setw(4)<<std::left<<++FST_TRACE_n<<": "\
								  << std::setw(20)<<std::left<<" "\
								  << std::setw(30)<<std::left<<getCLent(lbuf,lent_position)\
								  << std::setw(20)<<std::left<<getCSt(sbuf)\
								  << std::endl;

#define MFST_TRACE4(c)		std::cout<<std::setw(4)<<std::left << ++FST_TRACE_n << ": "<<std::setw(20)<< std::left <<c<<std::endl;

#define MFST_TRACE5(c)		std::cout<<std::setw(4)<<std::left << FST_TRACE_n << ": "<<std::setw(20)<< std::left <<c<<std::endl;

#define MFST_TRACE6(c,k)	std::cout<<std::setw(4)<<std::left << FST_TRACE_n << ": "<<std::setw(20)<< std::left << c << k <<std::endl;

#define MFST_TRACE7			std::cout<<std::setw(4)<<std::left << state.lent_position << ": "\
							<<std::setw(20)<< std::left << rule.getCRule(rbuf,state.nrulechain)\
							<<std::endl;

class MFST_STACK :public std::stack<short> {
public:
	using stack<short>::c;
};
static int FST_TRACE_n = -1;
static char rbuf[205], sbuf[205], lbuf[1024];

namespace MFST {
	struct MfstState {
		short lent_position;
		short nrule;
		short nrulechain;
		MFST_STACK st;
		MfstState();
		MfstState(short pposition, MFST_STACK pst, short pnrulechain);
		MfstState(short pposition,MFST_STACK pst, short pnrule, short pnrulechain);
	};

	class MFST_STATE :public std::stack<MfstState> {
	public:
		using std::stack<MfstState>::c;
	};

	struct Mfst {
		enum RC_STEP {
			NS_OK,
			NS_NORULE,
			NS_NORULECHAIN,
			NS_ERROR,
			TS_OK,
			TS_NOK,
			LENT_END,
			UNEXPECTED
		};
		struct MfstDiagnosis {
			short lent_position;
			RC_STEP rc_step;
			short nrule;
			short nrule_chain;
			MfstDiagnosis();
			MfstDiagnosis(short plent_position, RC_STEP prc_step, short pnrule, short pnrule_chain);
		}diagnosis[MFST_DIAGN_NUMBER];
		ALPHABET* lent;
		short lent_position;
		short nrule;
		short nrulechain;
		short lent_size;
		GRB::Greibach grebach;
		LT::LexTable lex;
		MFST_STACK st;
		MFST_STATE storestate;
		Mfst();
		Mfst(LT::LexTable plex, GRB::Greibach pgreibach);
		char* getCSt(char* buf);
		char* getCLent(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool savestate();
		bool resetstate();
		bool push_chain(GRB::Rule::Chain chain);
		RC_STEP step();
		bool start();
		bool savediagnosis(RC_STEP pprc_step);
		void printrules();
		struct Deducation {
			short size;
			short* nrules;
			short* nrulechains;
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };
		}deducation;
		bool savededucation();
	};
};