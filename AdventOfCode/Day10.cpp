#include "stdafx.h"
#include "Day10.h"

vector<Day10::chip_t> Day10::outputs;

Day10::~Day10()
{
}

void Day10::startA(vector<string> a_input)
{
	string firstWord;
	botId_t maxBN = 0;
	vector<Bot*> tmpBots;
	Bot* pTmpBot;

	for(string in: a_input){
		stringstream stream(in);
		getline(stream, firstWord, ' ');
		if (firstWord == "bot") {
			pTmpBot = parseBot(in);
			if (pTmpBot->getId() > maxBN)
				maxBN = pTmpBot->getId();
			tmpBots.push_back(pTmpBot);
			
		}
		else if(firstWord == "value")
			m_orders.push_back(parseOrder(in));
	}
	
	m_bots = vector<Bot*>(maxBN+1);

	for (auto bot : tmpBots)
		m_bots[bot->getId()] = bot;

	for (auto order : m_orders) {
		if (m_bots[order.botId]->addChip(order.chip))
			break;
	}

	
}

void Day10::startB(vector<string> a_input)
{
	int result = 1;
	for (auto chip : outputs) {
		result *= chip;
	}
	cout << "B: The result is " << result << endl << endl;
	
}

Day10::Bot* Day10::parseBot(string a_botText)
{
	Bot* pBot = nullptr;
	stringstream stream(a_botText);
	string lastWord, word;
	bool toOutput = false;
	int number;

	while (getline(stream, word, ' ')) {
		if (word == "bot" && !pBot)
			lastWord = word;
		else if (word == "low")
			lastWord = word;
		else if (word == "high")
			lastWord = word;
		else if (word == "output")
			toOutput = true;
		else {
			try {
				number = stoi(word);
				if (lastWord == "bot") {
					pBot = new Bot(number, &m_bots);
				}
				else if (lastWord == "low") {
					pBot->setRuleToLower(number, toOutput);
					if (toOutput)
						toOutput = false;
				}
				else if (lastWord == "high") {
					pBot->setRuleToHigher(number, toOutput);
					if (toOutput)
						toOutput = false;
				}
			}
			catch(...){}
		}
	}
	return pBot;
}

Day10::order Day10::parseOrder(string a_botText)
{
	order ord;
	stringstream stream(a_botText);
	string lastWord, word;
	int number;

	while (getline(stream, word, ' ')) {
		if (word == "value")
			lastWord = word;
		else if (word == "bot")
			lastWord = word;
		else {
			try {
				number = stoi(word);
				if (lastWord == "value") {
					ord.chip = number;
				}
				else if (lastWord == "bot") {
					ord.botId = number;
				}
			}
			catch (...) {}
		}
	}
	return ord;
}

bool Day10::Bot::addChip(chip_t a_chip)
{
	m_chips.addChip(a_chip);
	if (m_chips.isFull()) {
		if (m_chips.isSearchedCombi()) {
			cout << "A: Bot " << m_id << " compared chips with value 61 and value 17!" << endl << endl;;
			return true;
		}
		if (m_toLowIsOutput) {
			if (m_giveLowerTo >= 0 && m_giveLowerTo < 3) {
				Day10::outputs.push_back(m_chips.lower);
			}
		}
		else
			(*m_pBots)[m_giveLowerTo]->addChip(m_chips.lower);
		m_chips.clearLower();

		if (m_toHighIsOutput) {
			if (m_giveHigherTo >= 0 && m_giveHigherTo < 3) {
				Day10::outputs.push_back(m_chips.higher);
			}
		}
		else
			(*m_pBots)[m_giveHigherTo]->addChip(m_chips.higher);
		m_chips.clearHigher();

		return false;
	}
}
