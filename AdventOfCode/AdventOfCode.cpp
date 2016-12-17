// AdventOfCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Day1.h"

#define INPUT_TEXT "../input/day1a.txt"

using namespace std;

int main(int argc, char** argv)
{
	vector<string> input;
	string tmpIn;
	ifstream reader(INPUT_TEXT);

	if (!reader.is_open())
		return -1;

	while (getline(reader, tmpIn))
		input.push_back(tmpIn);

	reader.close();

	Day1 day;
	day.startA(input);
	day.startB(input);

	system("pause");
	return 0;
}

