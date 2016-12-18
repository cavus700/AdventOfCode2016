#include "stdafx.h"
#include "day6.h"


Day6::Day6()
{
}


Day6::~Day6()
{
}



#pragma warning( push )
#pragma warning( disable : 4018)
void Day6::startA(vector<string> input)
{
	if (input.size() == 0)
		return;

	vector<letterCounter> counters(input[0].size());

	for (string message : input) {
		for (int c = 0; c < input[0].size(); c++) {
			counters[c].add(message.at(c));
		}
	}

	int max = 0;
	string result = "";

	for (letterCounter counter : counters) {
		//search for maximum
		for (int letter : counter.letters) {
			if (letter > max)
				max = letter;
		}

		//add maximum
		for (int letter = 0; letter < counter.letters.size(); letter++) {
			if (counter.letters[letter] == max) {
				result += static_cast<char>('a' + letter);
				break;
			}
		}
		max = 0;
	}

	cout << "A: The original transmitied message is:" << endl << result << endl << endl;
}

void Day6::startB(vector<string> input)
{
	if (input.size() == 0)
		return;

	vector<letterCounter> counters(input[0].size());

	for (string message : input) {
		for (int c = 0; c < input[0].size(); c++) {
			counters[c].add(message.at(c));
		}
	}

	int min = 999999;
	string result = "";

	for (letterCounter counter : counters) {
		//search for maximum
		for (int letter : counter.letters) {
			if (letter < min && letter != 0)
				min = letter;
		}

		//add maximum
		for (int letter = 0; letter < counter.letters.size(); letter++) {
			if (counter.letters[letter] == min) {
				result += static_cast<char>('a' + letter);
				break;
			}
		}
		min = 999999;
	}

	cout << "A: The original transmitied message is:" << endl << result << endl << endl;
}

#pragma warning( pop ) 