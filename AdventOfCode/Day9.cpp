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

void trim_right(string& text) {
	while (text.back() == '\n' || text.back() == '\r') {
		text.pop_back();
	}
}

void Day9::startB(vector<string> input)
{
	unsigned long long length = 0;
	string text = input[0];

	trim_right(text);
	
	vector<compressed_string> sequence = parseSequences(text);
	

	for (auto comp : sequence) {
		length += decompress(comp);
	}

	cout << endl;
	cout << "B: The length of the decompressed data is: " << length << endl << endl;
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

long Day9::decompress(compressed_string compressed)
{
	string mark;
	marker marker;
	long result = 0;
	
	if (compressed.text.find_first_of('(') == 0) {
		mark = compressed.text.substr(1, compressed.text.find_first_of(')') - 1);
		compressed.text = compressed.text.substr(compressed.text.find_first_of(')') + 1, compressed.text.size());
		marker = parseMarker(mark);
		compressed_string comp;
		comp.range = marker.range;
		comp.repeat = marker.repeat;
		comp.text = compressed.text.substr(0, compressed.text.size());
		
		auto sequence = parseSequences(comp.text);

		for (auto seq : sequence) {
			result += decompress(seq);
		}
		return comp.repeat * result;
	}
	else{
		return compressed.text.size();
	}
}

vector<Day9::compressed_string> Day9::parseSequences(string text)
{
	size_t openBracket;
	size_t closedBracked;
	vector<compressed_string> sequence;
	string mark;

	openBracket = text.find_first_of('(');
	if (openBracket == string::npos) {
		sequence.push_back(text);
		return sequence;
	}

	sequence.push_back(compressed_string(text.substr(0, openBracket)));
	text = text.substr(openBracket, text.size());

	while (string::npos != text.find_first_of('(')) {
		openBracket = text.find_first_of('(');
		if (text.find_first_of('(') != 0) {
			sequence.push_back(compressed_string(text.substr(0, openBracket)));
			text = text.substr(openBracket, text.size());
			openBracket = text.find_first_of('(');
		}

		closedBracked = text.find_first_of(')');
		
		mark = text.substr(1, closedBracked - 1);
		marker marker = parseMarker(mark);
		
		compressed_string comp;
		comp.range = marker.range;
		comp.repeat = marker.repeat;
		comp.text = text.substr(0, comp.range + mark.size() + string("()").size());
		text = text.substr(comp.range + mark.size() + string("()").size(), text.size());
		sequence.push_back(comp);
	}
	if (text.size() > 0)
		sequence.push_back(compressed_string(text));
	
	return sequence;
}

