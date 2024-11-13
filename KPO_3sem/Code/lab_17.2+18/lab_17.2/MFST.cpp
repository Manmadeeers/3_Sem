#include "stdafx.h"

namespace MFST {
	MFSTState::MFSTState() {
		lent_position = 0;
		nrule = -1;
		nrulechain = -1;
	}
	MFSTState::MFSTState(short pposition, MFSTSTACK pst, short pnrulechain) {
		lent_position = pposition;
		st = pst;
		nrulechain = pnrulechain;
	}

	MFSTState::MFSTState(short pposition,short pnrule, short pnrulechain) {
		lent_position = pposition;
		nrule = pnrule;
		nrulechain = pnrulechain;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis() {
		lent_position = -1;
		rc_step = UNEXPECTED;
		nrule = -1;
		nrule_chain = -1;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis(short plent_position, RC_STEP prc_step, short pnrule, short pnrule_chain) {
		lent_position = plent_position;
		rc_step = prc_step;
		nrule = pnrule;
		nrule_chain = pnrule_chain;
	}
	Mfst::Mfst() {
		lent = 0;
		lent_size = lent_position = 0;
	}
	Mfst::Mfst(LT::LexTable plex, ST::Greibach pgreibach) {
		greibach = pgreibach;
		lex = plex;
		lent = new short[lent_size = lex.size];
		for (int k = 0; k < lent_size; k++) {
			lent[k] = TS(lex.table[k].lexem);
		}
		lent_position = 0;
		st.push(greibach.stbottomT);
		st.push(greibach.startN);
		nrule_chain = -1;
	}
	Mfst::RC_STEP Mfst::step() {
		RC_STEP rc = UNEXPECTED;

	}
};