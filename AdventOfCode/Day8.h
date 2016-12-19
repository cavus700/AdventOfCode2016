#pragma once
#include "AoCDay.h"

class Day8 :
	public AoCDay
{
public:
	Day8();
	~Day8();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	enum command {
		rect, rotate, cunknown
	};

	enum shift {
		row, column, sunknown
	};

	struct operation {
		operation() {
			cmd = cunknown;
			shift = sunknown;
			x = y = -1;
		}
		command cmd;
		shift shift;
		int x, y;
	};

	list<list<char>> m_screen;

	void parseCommands(vector<string>&, vector<operation>&);
	void executeCommand(operation&);
};

