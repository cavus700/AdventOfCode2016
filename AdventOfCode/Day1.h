#pragma once
#include "AoCDay.h"

class Day1 : public AoCDay
{
public:
	Day1();
	~Day1();
	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	enum direction {
		north = 0,
		east = 1,
		south = 2,
		west = 3
	};

	struct position {
		int horizontal;
		int vertical;

		position(int hori, int vert) {
			horizontal = hori;
			vertical = vert;
		}

		bool operator== (position pos) {
			return horizontal == pos.horizontal && vertical == pos.vertical;
		}
	};

	int m_horizontal;
	int m_vertical;
	direction m_direction;
	vector<position> m_positions;

	vector<string> parseInput(string input);

	void incDriection();
	void decDirection();
	
	bool contains(position pos);
};

