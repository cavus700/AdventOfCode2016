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

	struct compressed_string {
		compressed_string() {
			range = repeat = 0;
			text = "";
		}
		compressed_string(string s) {
			text = s;
			range = repeat = 0;
		}
		int range;
		int repeat;
		string text;
	};
	marker parseMarker(string);
	long decompress(compressed_string);
	vector<compressed_string> parseSequences(string compressee);
};

