#pragma once
#include "AoCDay.h"

class Day10 :
	public AoCDay
{
public:
private:
	class Bot;
	struct order;
	typedef int rule_t;
	typedef int chip_t;
	typedef int botId_t;

public:
	static vector<chip_t> outputs;

	Day10() { outputs = vector<chip_t>(); }
	~Day10();

	void startA(vector<string> a_input);
	void startB(vector<string> a_input);

private:
	vector<Bot*> m_bots;
	vector<order> m_orders;
	
	struct chipTuple {
		chipTuple() {
			lower = higher = -1;
		}
		void addChip(chip_t a_chip) {
			if (lower == -1) {
				lower = a_chip;
			}
			else {
				if (lower < a_chip) {
					higher = a_chip;
				}
				else {
					higher = lower;
					lower = a_chip;
				}
			}
		}

		bool isFull() {
			return lower != -1 && higher != -1;
		}

		void clearLower() {
			lower = -1;
		}

		void clearHigher() {
			higher = -1;
		}

		bool isSearchedCombi() {
			if ((lower == 61 && higher == 17) || (lower == 17 && higher == 61))
				return true;
			return false;
		}

		chip_t lower, higher;
	};

	struct order {
		chip_t chip;
		botId_t botId;
	};

	Bot* parseBot(string a_botText);
	order parseOrder(string a_botText);

	class Bot {
		
	public:
		Bot(int id, vector<Bot*>* bots) {
			m_pBots = bots;
			m_id = id;
			m_toHighIsOutput = m_toLowIsOutput = false;
		}

		botId_t getId() { return m_id; }

		void setRuleToLower(rule_t a_rule, bool a_toOutput) { m_giveLowerTo = a_rule; m_toLowIsOutput = a_toOutput; }
		void setRuleToHigher(rule_t a_rule, bool a_toOutput) { m_giveHigherTo = a_rule; m_toHighIsOutput = a_toOutput; }
		bool addChip(chip_t a_chip);
		void print() { cout << "Bot " << m_id << " has lower chip " << m_chips.lower << " and higher chip " << m_chips.higher << endl; }

	private:
		int m_id;
		vector<Bot*>* m_pBots;
		chipTuple m_chips;
		bool m_toLowIsOutput, m_toHighIsOutput;
		rule_t m_giveLowerTo, m_giveHigherTo;
	};
};

