#pragma once

#include <iostream>

using namespace std;

class AoCDay {

public:
	virtual void startA(vector<string> input) = 0;
	virtual void startB(vector<string> input) = 0;
};