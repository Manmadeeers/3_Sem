#include "stdafx.h"
namespace MFST {
	MfstState::MfstState() {
		this->lent_position = 0;
		this->nrule = -1;
		this->nrulechain = -1;
	}
	MfstState::MfstState(short pposition, MFST_STACK pst, short pnrulechain) {
		this->lent_position = pposition;
		this->st = pst;
		this->nrulechain = pnrulechain;
	}
	MfstState::MfstState(short pposition, MFST_STACK pst, short pnrule, short pnrulechain) {
		this->lent_position = pposition;
		this->st = pst;
		this->nrule = pnrule;
		this->nrulechain = pnrulechain;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis() {
		this->lent_position = -1;
		this->rc_step = UNEXPECTED;
		this->nrule = -1;
		this->nrule_chain = -1;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis(short plent_position, RC_STEP prc_step, short pnrule, short pnrule_chain) {
		this->lent_position = plent_position;
		this->rc_step = prc_step;
		this->nrule = pnrule;
		this->nrule_chain = pnrule_chain;
	}
	Mfst::Mfst() { this->lent = 0; this->lent_size = this->lent_position = 0; }
	Mfst::Mfst(LT::LexTable plex, GRB::Greibach pgreibach) {
		this->grebach = pgreibach;
		this->lex = plex;
		this->lent = new short[lent_size = lex.size];
		for (int k = 0; k < lent_size; k++) {
			lent[k] = TS(lex.table[k].lexem);
		}
		this->lent_position = 0;
		st.push(grebach.stbottomT);
		st.push(grebach.startN);
		this->nrulechain = -1;
	}
    Mfst::RC_STEP Mfst::step()
    {
        RC_STEP rc = UNEXPECTED;
        if (lent_position < lent_size)
        {
            if (GRB::Rule::Chain::isN(st.top()))
            {
                GRB::Rule rule;
                if ((nrule = grebach.getRule(st.top(), rule)) >= 0)
                {
                    GRB::Rule::Chain chain;
                    if ((nrulechain = rule.getNextChain(lent[lent_position], chain, nrulechain + 1)) >= 0)
                    {
                        MFST_TRACE1
                            savestate();
                        st.pop();
                        push_chain(chain);
                        rc = NS_OK;
                        MFST_TRACE2
                    }
                    else
                    {
                        MFST_TRACE4("TNS_NORULECHAIN/NS_NORULE")
                            rc = resetstate() ? NS_NORULECHAIN : NS_NORULE;
                    };
                }
                else
                {
                    rc = NS_ERROR;
                }
            }
            else if ((st.top() == lent[lent_position]))
            {
                lent_position++;
                st.pop();
                nrulechain = -1;
                rc = TS_OK;
                MFST_TRACE3
            }
            else
            {
                MFST_TRACE4(TS_NOK / NS_NORULECHAIN)
                    rc = resetstate() ? TS_NOK : NS_NORULECHAIN;
            }
        }
        else
        {
            rc = LENT_END;
            MFST_TRACE4(LENT_END)
        };
        return rc;
    }
    bool Mfst::push_chain(GRB::Rule::Chain chain) {
        for (int k = chain.size - 1; k >= 0; k--) {
            st.push(chain.nt[k]);
        }
        return true;
    }

    bool Mfst::savestate() {
        storestate.push(MfstState(lent_position, st, nrule, nrulechain));
        MFST_TRACE6("SAVESTATE:", storestate.size());
        return true;
    }

    bool Mfst::resetstate() {
        bool rc = false;
        MfstState state;
        if (rc = (storestate.size() > 0)) {
            state = storestate.top();
            lent_position = state.lent_position;
            st = state.st;
            nrule = state.nrule;
            nrulechain = state.nrulechain;
            storestate.pop();
            MFST_TRACE5("RESSTATE");
            MFST_TRACE2;
        }
        return rc;
    }

    bool Mfst::savediagnosis(RC_STEP prc_step) {
        bool rc = false;
        short k = 0;
        while (k < MFST_DIAGN_NUMBER && lent_position <= diagnosis[k].lent_position) {
            k++;
        }
        if (rc = (k < MFST_DIAGN_NUMBER)) {
            diagnosis[k] = MfstDiagnosis(lent_position, prc_step, nrule, nrulechain);
            for (short j = k + 1; j < MFST_DIAGN_NUMBER; j++) {
                diagnosis[j].lent_position = -1;
            }
        }
        return rc;
    }

    bool Mfst::start() {
        bool rc = false;
        RC_STEP rc_step = UNEXPECTED;
        char buf[MFST_DIAGN_MAXSIZE];
        rc_step = step();
        while (rc_step == NS_OK || rc_step == NS_NORULECHAIN || rc_step == TS_OK || rc_step == TS_NOK) {
            rc_step = step();
        }
        switch (rc_step) {
        case LENT_END:
            MFST_TRACE4("------>LENT_END");
            cout << "------------------------------------------------------------------------------------------   ------" << endl;
            sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d: Total amount of lines: %d, syntaxical analysis proceeded without errors", 0, lent_size);
            cout << setw(4) << left << 0 << ": Total amount of lines " << lent_size << " , syntaxical analysis proceeded without errors" << endl;
            rc = true;
            break;
        case NS_NORULE:
            MFST_TRACE4("------>NS_NORULE");
            cout << "------------------------------------------------------------------------------------------   ------" << endl;
            cout << getDiagnosis(0, buf) << endl;
            cout << getDiagnosis(1, buf) << endl;
            cout << getDiagnosis(2, buf) << endl;
            break;
        case NS_NORULECHAIN:
            MFST_TRACE4("------>NS_NORULEORRULECHAIN");
            break;
        case NS_ERROR:
            MFST_TRACE4("------>NS_ERROR");
            break;
        case UNEXPECTED:
            MFST_TRACE4("------>UNEXPECTED");
            break;
        }
        return rc;
    }

    char* Mfst::getCSt(char* buf) {
        for (int k = (signed)st.size() - 1; k >= 0; --k) {
            short p = st.c[k];
            buf[st.size() - 1 - k] = GRB::Rule::Chain::alph_to_char(p);
        }
        buf[st.size()] = 0x00;
        return buf;
    }

    char* Mfst::getCLent(char* buf, short pos, short n) {
        short i, k = (pos + n < lent_size) ? pos + n : lent_size;
        for (i = pos; i < k; i++) {
            buf[i - pos] = GRB::Rule::Chain::alph_to_char(lent[i]);
        }
        buf[i - pos] = 0x00;
        return buf;
    }

    char* Mfst::getDiagnosis(short n, char* buf) {
        char* rc = (char*)"";
        int errid = 0;
        int lpos = -1;
        if (n < MFST_DIAGN_NUMBER && (lpos = diagnosis[n].lent_position) >= 0) {
            errid = grebach.getRule(diagnosis[n].nrule).iderror;
            ERROR::ERROR err = ERROR::geterror(errid);
            sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d: line %d, %s", err.id, lex.table[lpos].src_str_num, err.message);
            rc = buf;
        }
        return rc;
    }

    void Mfst::printrules() {
        MfstState state;
        GRB::Rule rule;
        for (unsigned short k = 0; k < storestate.size(); k++) {
            state = storestate.c[k];
            rule = grebach.getRule(state.nrule);
            MFST_TRACE7;
        }
    }

    bool Mfst::savededucation() {
        MfstState state;
        GRB::Rule rule;
        deducation.nrules = new short[deducation.size = storestate.size()];
        deducation.nrulechains = new short[deducation.size];
        for (unsigned short k = 0; k < storestate.size(); k++) {
            state = storestate.c[k];
            deducation.nrules[k] = state.nrule;
            deducation.nrulechains[k] = state.nrulechain;
        }
        return true;
    }
};