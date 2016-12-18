#pragma once
#include "AoCDay.h"
class Day7 :
	public AoCDay
{
public:
	Day7();
	~Day7();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	struct IPv7 {
		vector<string> legal, illegal;
	};

	void parseIPv7(string ip, IPv7& ipv7);
	bool isIPv7(IPv7& ipv7);
};

