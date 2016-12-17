#include "stdafx.h"
#include "Day1.h"


Day1::Day1()
{
}


Day1::~Day1()
{
}

void Day1::startA(vector<string> input)
{
	//initialization
	m_horizontal = 0;
	m_vertical = 0;
	m_direction = north;

	vector<string> parsed = parseInput(input[0]);

	for (string move : parsed) {
		if (move.at(0) == 'R')
			incDriection();
		else
			decDirection();

		switch (m_direction) {
		case north: m_vertical += stoi(move.substr(1, move.size())); break;
		case east: m_horizontal += stoi(move.substr(1, move.size())); break;
		case south: m_vertical -= stoi(move.substr(1, move.size())); break;
		case west: m_horizontal -= stoi(move.substr(1, move.size())); break;
		}
	}

	if (m_vertical < 0)
		m_vertical *= -1;
	if (m_horizontal < 0)
		m_horizontal *= -1;

	cout << "A: Easter Bunny HQ is " << m_horizontal + m_vertical << " blocks away." << endl << endl;
}

void Day1::startB(vector<string> input)
{
	//initialization
	m_horizontal = 0;
	m_vertical = 0;
	m_direction = north;

	vector<string> parsed = parseInput(input[0]);

	for (string move : parsed) {
		if (move.at(0) == 'R')
			incDriection();
		else
			decDirection();

		int distance = stoi(move.substr(1, move.size()));

		for (int i = 1; i <= distance; i++) {
			switch (m_direction) {
			case north: m_vertical += 1; break;
			case east: m_horizontal += 1; break;
			case south: m_vertical -= 1; break;
			case west: m_horizontal -= 1; break;
			}

			position pos = { m_horizontal, m_vertical };

			if (contains(pos)) {
				int horizontal, vertical;

				if (pos.horizontal < 0)
					horizontal = pos.horizontal * -1;
				else
					horizontal = pos.horizontal;

				if (pos.vertical < 0)
					vertical = pos.vertical * -1;
				else
					vertical = pos.vertical;

				cout << "B: Easter Bunny HQ is " << horizontal + vertical << " blocks away." << endl << endl;

				return;
			}
			else {
				m_positions.push_back(pos);
			}
		}
		
	}
}

vector<string> Day1::parseInput(string input)
{
	vector<string> result;
	stringstream stream;
	stream.str(input);
	std::string item;
	while (getline(stream, item, ',')) {
		auto offset = item.find_first_not_of(" ");
		result.push_back(item.substr(offset, item.size()));
	}
	return result;
}

void Day1::incDriection()
{
	switch (m_direction) {
	case north: m_direction = east; break;
	case east: m_direction = south; break;
	case south: m_direction = west; break;
	case west: m_direction = north; break;
	}
}

void Day1::decDirection()
{
	switch (m_direction) {
	case north: m_direction = west; break;
	case east: m_direction = north; break;
	case south: m_direction = east; break;
	case west: m_direction = south; break;
	}
}

bool Day1::contains(position pos)
{
	for(position p : m_positions){
		if (p == pos)
			return true;
	}
	return false;
}
