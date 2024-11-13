#pragma once
#include "stdafx.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
class MFSTSTACK :public stack<short> {
public:
	using stack<short>::c;
};

namespace MFST {
	struct MFSTState {
		short lent_position;
		short nrule;
		short nrulechain;
		MFSTSTACK st;
		MFSTState();
		MFSTState(short pposition, MFSTSTACK pst, short pnrulechain);
		MFSTState(short pposition, short pnrule, short pnrulechain);
	};

	class MFSTSTATE :public stack<MFSTState> {
	public:
		using stack<MFSTState>::c;
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
		short nrule_chain;
		short lent_size;
		ST::Greibach greibach;
		LT::LexTable lex;
		MFSTSTACK st;
		MFSTSTATE storestable;
		Mfst();
		Mfst(LT::LexTable plex, ST::Greibach pgreibach);
		char* getCSt(char* buf);
		char* getCLent(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool savestate();
		bool reststate();
		bool push_chain(ST::Rule::Chain chain);
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