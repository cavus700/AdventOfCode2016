#include "stdafx.h"
#include "Day3.h"


Day3::Day3()
{
}


Day3::~Day3()
{
}

void Day3::startA(vector<string> input)
{
	vector<vector<int>> triangles(input.size(), vector<int>(0));

	for (int line = 0; line < input.size(); line++) {
		stringstream stream;
		stream.str(input.at(line));
		std::string item;
		while (getline(stream, item, ' ')) {
			if(item != "")
				triangles[line].push_back(stoi(item));
		}
	}

	int possible = 0;
	for (vector<int> tri : triangles) {
		if (isTriangle(tri[0], tri[1], tri[2]))
			possible++;
	}

	cout << "A: From the " << input.size() << " \"triangles\" " << possible << " are correct triangles." << endl << endl;
}

void Day3::startB(vector<string> input)
{
	int offset0 = 0;
	int offset1 = input.size() / 3; 
	int offset2 = (input.size() / 3) * 2;

	vector<vector<int>> triangles(input.size(), vector<int>(0));

	int entry = 0;
	
	for (int line = 0; line < input.size(); line++) {
		if (line != 0 && line % 3 == 0) {
			offset0++;
			offset1++;
			offset2++;
		}

		stringstream stream;
		stream.str(input.at(line));
		std::string item;

		while (getline(stream, item, ' ')) {
			if (item != "") {
				if(entry == 0)
					triangles[offset0].push_back(stoi(item)); 
				if(entry == 1)
					triangles[offset1].push_back(stoi(item));
				if(entry == 2)
					triangles[offset2].push_back(stoi(item));

				entry = ++entry % 3;
			}
		}
	}

	int possible = 0;
	for (vector<int> tri : triangles) {
		if (isTriangle(tri[0], tri[1], tri[2]))
			possible++;
	}

	cout << "B: From the " << input.size() << " \"triangles\" " << possible << " are correct triangles." << endl << endl;
}

bool Day3::isTriangle(int a, int b, int c)
{
	if (a + b <= c)
		return false;
	if (a + c <= b)
		return false;
	if (b + c <= a)
		return false;
	return true;
}
