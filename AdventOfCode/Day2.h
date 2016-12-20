#pragma once

#include "AoCDay.h"

class Day2 :
	public AoCDay
{
public:
	Day2();
	~Day2();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	int m_row, m_column;
	vector<vector<int>> m_keypadA;
	vector<vector<char>> m_keypadB;

	int nextDigitA(string code);
	char nextDigitB(string code);
};

