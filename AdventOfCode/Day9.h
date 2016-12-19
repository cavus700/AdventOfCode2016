#pragma once
#include "AoCDay.h"
class Day9 :
	public AoCDay
{
public:
	Day9();
	~Day9();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	struct marker {
		bool legal;
		int range;
		int repeat;
	};

	marker parseMarker(string);
};

