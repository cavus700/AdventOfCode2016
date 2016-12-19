#include "stdafx.h"
#include "Day8.h"


Day8::Day8()
{
}


Day8::~Day8()
{
}

void Day8::startA(vector<string> input)
{
	vector<operation> operations;
	parseCommands(input, operations);

	m_screen = list<list<char>>(6, list<char>(50, '.'));
	int count = 0;
	for (operation op : operations) {
		executeCommand(op);
	}

	cout << "A: After you swipe your card the display looks like this:" << endl;

	int pixelsOn = 0;

	for (auto vec : m_screen) {
		for(char c : vec){
			cout << c;
			if (c == '#')
				pixelsOn++;
		}
		cout << endl;
	}
	cout << "Pixels lit: " << pixelsOn << endl;
	cout << endl << endl;
}

void Day8::startB(vector<string> input)
{	
	cout << "B: Look A" << endl;
}

void Day8::parseCommands(vector<string>& input, vector<operation>& operations)
{
	string tmp;
	std::string delimiter = "x";

	for (string in : input) {
		stringstream stream(in);
		operation op;

		while (getline(stream, tmp, ' ')) {
			if (tmp == "rotate"){
				op.cmd = rotate;
			}

			else if (tmp == "rect") {
				op.cmd = rect;
			}

			//command is already determined
			else {
				if (op.cmd == rotate) {
					if (op.shift == sunknown) {
						if (tmp == "row") {
							op.shift = row;
						}
						else if (tmp == "column") {
							op.shift = column;
						}
					}
					else {
						if (op.x == -1) {
							op.x = stoi(tmp.substr(2, tmp.size()));
						}
						else if (op.y == -1 && tmp != "by") {
							op.y = stoi(tmp);
						}
					}
				}
				else if (op.cmd == rect) {
					op.x = stoi(tmp.substr(0, tmp.find(delimiter)));
					op.y = stoi(tmp.substr(tmp.find(delimiter) + delimiter.size(), tmp.size()));
				}
			}
		}

		operations.push_back(op);
	}
}

void Day8::executeCommand(operation & op)
{
	if (op.cmd == rotate) {
		if (op.shift == row) {
			auto list = m_screen.begin();
			advance(list, op.x);
			for (int shift = 0; shift < op.y; shift++) {
				list->push_front(*--list->end());
				list->erase(--list->end());
			}
		}
		else if (op.shift == column) {			
			char bottom;
			for (int shifts = 0; shifts < op.y; shifts++) {
				auto listEnd = --m_screen.end();
				auto listOffset = --m_screen.end();
				
				for (int row = 0; row < m_screen.size()-1; row++) {
					if(row != 0)
						listEnd--;
					if(listOffset != m_screen.begin())
						listOffset--;

					auto lcb = listEnd->begin();
					auto lco = listOffset->begin();
					advance(lcb, op.x);
					advance(lco, op.x);
					if (row == 0)
						bottom = *lcb;

					*lcb = *lco;
					if (row != m_screen.size() - 2)
						*lco = '.';
					else
						*lco = bottom;

					
					
				}
			}
		}
	}
	else if (op.cmd == rect) {
		auto iRow = m_screen.begin();
		auto iCol = iRow->begin();

		for (int row = 0; row < op.y; row++) {
			for (int col = 0; col < op.x; col++) {
				*iCol = '#';
				iCol++;
			}
			iRow++;
			iCol = iRow->begin();
		}
	}
}
