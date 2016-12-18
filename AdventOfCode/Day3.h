#pragma once
#include "AoCDay.h"
class Day3 : public AoCDay
{
public:
	Day3();
	~Day3();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	bool isTriangle(int a, int b, int c);
};

