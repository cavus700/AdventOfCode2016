#include "stdafx.h"
#include "Day2.h"


Day2::Day2()
{
}


Day2::~Day2()
{
}

void Day2::startA(vector<string> input)
{
	m_row = 1;
	m_column = 1;

	m_keypadA.push_back(vector<int>(3));
	m_keypadA.push_back(vector<int>(3));
	m_keypadA.push_back(vector<int>(3));

	m_keypadA[0][0] = 1;
	m_keypadA[0][1] = 2;
	m_keypadA[0][2] = 3;

	m_keypadA[1][0] = 4;
	m_keypadA[1][1] = 5;
	m_keypadA[1][2] = 6;

	m_keypadA[2][0] = 7;
	m_keypadA[2][1] = 8;
	m_keypadA[2][2] = 9;

	vector<int> result;
	for (string s : input) {
		result.push_back(nextDigitA(s));
	}

	cout << "A: Code for the bathroom is: ";
	for (int digit : result)
		cout << digit;
	cout << endl << endl;
}

void Day2::startB(vector<string> input)
{
	m_row = 2;
	m_column = 2;

	m_keypadB.push_back(vector<char>(5, 'X'));
	m_keypadB.push_back(vector<char>(5, 'X'));
	m_keypadB.push_back(vector<char>(5, 'X'));
	m_keypadB.push_back(vector<char>(5, 'X'));
	m_keypadB.push_back(vector<char>(5, 'X'));

	m_keypadB[0][2] = '1';

	m_keypadB[1][1] = '2';
	m_keypadB[1][2] = '3';
	m_keypadB[1][3] = '4';

	m_keypadB[2][0] = '5';
	m_keypadB[2][1] = '6';
	m_keypadB[2][2] = '7';
	m_keypadB[2][3] = '8';
	m_keypadB[2][4] = '9';

	m_keypadB[3][1] = 'A';
	m_keypadB[3][2] = 'B';
	m_keypadB[3][3] = 'C';

	m_keypadB[4][2] = 'D';

	vector<char> result;
	for (string s : input) {
		result.push_back(nextDigitB(s));
	}

	cout << "B: Code for the bathroom is: ";
	for (char digit : result)
		cout << digit;
	cout << endl << endl;
}

int Day2::nextDigitA(string code)
{
	for (char dir : code) {
		if (dir == 'U') {
			if (m_row > 0)
				m_row--;
		}
		else if (dir == 'D') {
			if (m_row < 2)
				m_row++;
		}
		else if (dir == 'L') {
			if (m_column > 0)
				m_column--;
		}
		else if (dir == 'R') {
			if (m_column < 2)
				m_column++;
		}
		else
			throw exception("Unknown letter in sequence");
	}
	return m_keypadA[m_row][m_column];
}

char Day2::nextDigitB(string code)
{
	for (char dir : code) {
		if (dir == 'U') {
			if (m_row > 0 && m_keypadB[m_row - 1][m_column] != 'X')
				m_row--;
		}
		else if (dir == 'D') {
			if (m_row < 4 && m_keypadB[m_row + 1][m_column] != 'X')
				m_row++;
		}
		else if (dir == 'L') {
			if (m_column > 0 && m_keypadB[m_row][m_column - 1] != 'X')
				m_column--;
		}
		else if (dir == 'R') {
			if (m_column < 4 && m_keypadB[m_row][m_column + 1] != 'X')
				m_column++;
		}
		else
			throw exception("Unknown letter in sequence");
	}
	return m_keypadB[m_row][m_column];
}
