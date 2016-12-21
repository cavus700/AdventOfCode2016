#include "stdafx.h"
#include "Day11.h"


Day11::Day11()
{
	m_floors = vector<vector<object*>>(4);
	m_floors[0].push_back(new object(e_generator, "Stronium", 0));
	m_floors[0].push_back(new object(e_generator, "Plutonium", 2));
	m_floors[0].push_back(new object(e_microchip, "Stronium", 1));
	m_floors[0].push_back(new object(e_microchip, "Plutonium", 3));

	m_floors[1].push_back(new object(e_generator, "Thulium ", 4));
	m_floors[1].push_back(new object(e_generator, "Ruthenium ", 6));
	m_floors[1].push_back(new object(e_generator, "Curium ", 8));
	m_floors[1].push_back(new object(e_microchip, "Ruthenium", 7));
	m_floors[1].push_back(new object(e_microchip, "Curium", 9));

	m_floors[2].push_back(new object(e_microchip, "Thulium", 5));

	m_elevator = new elevator();
}


Day11::~Day11()
{
	m_floors.clear(); 
	delete m_elevator;
}

void Day11::startA(vector<string> a_input)
{
	printFloors();
}

void Day11::startB(vector<string> a_input)
{
}

void Day11::printFloors()
{
	int length = 0;
	
	for (auto floor : m_floors) {
		for (auto obj : floor) {
			if (obj->position > length)
				length = obj->position;
		}
	}

	vector<vector<string>> sFloor = vector<vector<string>>(m_floors.size(), vector<string>(length+3, ". "));

	for (int floor = 0; floor < m_floors.size(); floor++) {
		sFloor[floor][0] = "F" + to_string(floor + 1);
		if (m_elevator->floor == floor)
			sFloor[floor][1] = "E ";
		for (auto obj : m_floors[floor]) {
			if(obj->type == e_generator)
				sFloor[floor][obj->position + 2] = obj->identifier.substr(0, 1) + "G";
			else

				sFloor[floor][obj->position + 2] = obj->identifier.substr(0,1) + "M";
		}
	}

	for (auto floor = --sFloor.end(); ; floor--) {
		for (auto obj : *floor) {
			cout << obj << "  ";
		}
		cout << endl;
		if (floor == sFloor.begin())
			break;
	}
}
