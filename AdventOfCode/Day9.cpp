#include "stdafx.h"
#include "Day9.h"


Day9::Day9()
{
}


Day9::~Day9()
{
}

void Day9::startA(vector<string> input)
{
	string result = "";
	string text = input[0];
	string mark;

	marker marker;

	size_t openBracket;
	size_t closedBracked;

	while (string::npos != text.find_first_of('(')) {
		openBracket = text.find_first_of('(');
		result += text.substr(0, openBracket);
		text = text.substr(openBracket, text.size());

		closedBracked = text.find_first_of(')');

		mark = text.substr(1, closedBracked-1);

		text = text.substr(closedBracked+1, text.size());

		marker = parseMarker(mark);

		if (marker.legal) {
			for (int rep = 0; rep < marker.repeat; rep++) {
				result += text.substr(0, marker.range);
			}
			text = text.substr(marker.range, text.size());
		}
	}
	result += text;

	cout << "A: The lenght of the decompressed data is: " << result.size() << endl << endl;
}

void Day9::startB(vector<string> input)
{
	long length = 0;
	string text = input[0];
	string mark;

	marker marker;

	size_t openBracket;
	size_t closedBracked;

	while (string::npos != text.find_first_of('(')) {
		openBracket = text.find_first_of('(');
		length += text.substr(0, openBracket).size();
		text = text.substr(openBracket, text.size());

		closedBracked = text.find_first_of(')');

		mark = text.substr(1, closedBracked - 1);

		text = text.substr(closedBracked + 1, text.size());

		marker = parseMarker(mark);

		if (marker.legal) {
			for (int rep = 1; rep < marker.repeat; rep++) {
				text = text.substr(0, marker.range) + text;
			}
		}
	}
	cout << endl;
	length += text.size();

	cout << "B: The lenght of the decompressed data is: " << length << endl << endl;
}

Day9::marker Day9::parseMarker(string mark)
{
	string delimiter = "x";
	marker marker;
	marker.legal = false;

	try {
		marker.range = stoi(mark.substr(0, mark.find(delimiter)));
		marker.repeat = stoi(mark.substr(mark.find(delimiter) + delimiter.size(), mark.size()));
		marker.legal = true;
	}
	catch (...) {
		return marker;
	}
	return marker;
}
