// AdventOfCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
//#include "Day12.h"
//#include "Day13.h"
//#include "Day14.h"
//#include "Day15.h"
//#include "Day16.h"
//#include "Day17.h"
//#include "Day18.h"
//#include "Day19.h"
//#include "Day20.h"
//#include "Day21.h"
//#include "Day22.h"
//#include "Day23.h"
//#include "Day24.h"
//#include "Day25.h"

//#define INPUT_TEXT "../input/day1.txt"
//#define INPUT_TEXT "../input/day2.txt"
//#define INPUT_TEXT "../input/day3.txt"
//#define INPUT_TEXT "../input/day4.txt"
//#define INPUT_TEXT "../input/day5.txt"
//#define INPUT_TEXT "../input/day6.txt"
//#define INPUT_TEXT "../input/day7.txt"
//#define INPUT_TEXT "../input/day8.txt"
//#define INPUT_TEXT "../input/day9.txt"
//#define INPUT_TEXT "../input/day10.txt"
#define INPUT_TEXT "../input/day11.txt"
//#define INPUT_TEXT "../input/day12.txt"
//#define INPUT_TEXT "../input/day13.txt"
//#define INPUT_TEXT "../input/day14.txt"
//#define INPUT_TEXT "../input/day15.txt"
//#define INPUT_TEXT "../input/day16.txt"
//#define INPUT_TEXT "../input/day17.txt"
//#define INPUT_TEXT "../input/day18.txt"
//#define INPUT_TEXT "../input/day19.txt"
//#define INPUT_TEXT "../input/day20.txt"
//#define INPUT_TEXT "../input/day21.txt"
//#define INPUT_TEXT "../input/day22.txt"
//#define INPUT_TEXT "../input/day23.txt"
//#define INPUT_TEXT "../input/day24.txt"
//#define INPUT_TEXT "../input/day25.txt"

using namespace std;
using namespace chrono;

int main(int argc, char** argv)
{
	vector<string> input;
	string tmpIn;
	ifstream reader(INPUT_TEXT);
	time_point<high_resolution_clock> start, end;

	if (!reader.is_open())
		return -1;

	while (getline(reader, tmpIn))
		input.push_back(tmpIn);

	reader.close();

	//Day1 day;
	//Day2 day;
	//Day3 day;
	//Day4 day;
	//Day5 day;
	//Day6 day;
	//Day7 day;
	//Day8 day;
	//Day9 day;
	//Day10 day;
	Day11 day;
	//Day12 day;
	//Day13 day;
	//Day14 day;
	//Day15 day;
	//Day16 day;
	//Day17 day;
	//Day18 day;
	//Day19 day;
	//Day20 day;
	//Day21 day;
	//Day22 day;
	//Day23 day;
	//Day24 day;
	//Day25 day;
	
	start = chrono::high_resolution_clock::now();
	day.startA(input);
	end = chrono::high_resolution_clock::now();
	duration<float> secs = end - start;
	cout << "Part A lasted " << secs.count() << " seconds or " << duration_cast<milliseconds>(secs).count() << " milliseconds." << endl << endl;

	start = chrono::high_resolution_clock::now();
	day.startB(input);
	end = chrono::high_resolution_clock::now();
	secs = end - start;
	cout << "Part B lasted " << secs.count() << " seconds or " << duration_cast<milliseconds>(secs).count() << " milliseconds." << endl << endl;
	
	system("pause");
	return 0;
}

