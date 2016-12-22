#include "stdafx.h"
#include "Day11.h"


Day11::Day11()
{
	m_floors = vector<vector<object_t>>(4);
	m_floors[0] = vector<object_t>(10, object_t());
	m_floors[1] = vector<object_t>(10, object_t());
	m_floors[2] = vector<object_t>(10, object_t());
	m_floors[3] = vector<object_t>(10, object_t());

	m_floors[0][0] = object_t(e_generator, "Stronium", 0);
	m_floors[0][2] = object_t(e_generator, "Plutonium", 2);
	m_floors[0][1] = object_t(e_microchip, "Stronium", 1);
	m_floors[0][3] = object_t(e_microchip, "Plutonium", 3);

	m_floors[1][4] = object_t(e_generator, "Thulium ", 4);
	m_floors[1][6] = object_t(e_generator, "Ruthenium ", 6);
	m_floors[1][8] = object_t(e_generator, "Curium ", 8);
	m_floors[1][7] = object_t(e_microchip, "Ruthenium", 7);
	m_floors[1][9] = object_t(e_microchip, "Curium", 9);

	m_floors[2][5] = object_t(e_microchip, "Thulium", 5);

	m_currentFloor = 0;
	m_elevator = new elevator();
	m_totalNumberOfObjects = 10;
}


Day11::~Day11()
{
	m_floors.clear(); 
	delete m_elevator;
}

void Day11::startA(vector<string> a_input)
{
	makeMove();
	printFloors();
}

void Day11::startB(vector<string> a_input)
{
}

bool Day11::isLegalState(vector<object_t>& a_obsOnFloor)
{
	for (auto obj : a_obsOnFloor) {
		//if microship check if another generator is on the floor
		if (obj.type == e_microchip) {
			for (auto illGen : a_obsOnFloor) {
				if (illGen.type == e_microchip || illGen.type == e_unknown)
					continue;

				//if correspondig generator is on the floor continue
				if (illGen.type == e_generator && illGen.identifier == obj.identifier)
					break;
				
				//if another generator is on the floor
				if(illGen.type == e_generator && illGen.identifier != obj.identifier){
					bool isSafe = false;
					//search for corresponding generator that chip won´t be fried
					for (auto legGen : a_obsOnFloor) {
						if (legGen.type == e_generator && legGen.identifier == obj.identifier) {
							isSafe = true;
							break;
						}
					}
					if (!isSafe)
						return false;
				}
			}
		}
	}

	return true;
}

bool Day11::isValidSolution(floor_t a_floor, vector<object_t>& a_obsOnFloor)
{
	return a_floor == 3 && a_obsOnFloor.size() == m_totalNumberOfObjects;
}

bool Day11::fillElevator(object_t a_objA)
{
	m_elevator->obj1 = a_objA;
	m_floors[m_currentFloor][a_objA.position] = object_t();
	if (isLegalState(m_floors[m_currentFloor])) {
		m_elevator->floor--;
		return true;
	}

	m_floors[m_currentFloor][a_objA.position] = a_objA;
	m_elevator->obj1 = object_t(); 

	return false;
}

bool Day11::fillElevator(object_t a_objA, object_t a_objB)
{
	if (a_objA == a_objB)
		return false;

	m_elevator->obj1 = a_objA;
	m_floors[m_currentFloor][a_objA.position] = object_t();
	m_elevator->obj2 = a_objB;
	m_floors[m_currentFloor][a_objB.position] = object_t();
	if (isLegalState(m_floors[m_currentFloor])) {
		m_elevator->floor++;
		return true;
	}

	m_floors[m_currentFloor][a_objA.position] = a_objA;
	m_floors[m_currentFloor][a_objB.position] = a_objB;
	m_elevator->obj1 = object_t();
	m_elevator->obj2 = object_t();

	return false;
}

void Day11::clearElevator()
{
	m_floors[m_currentFloor][m_elevator->obj1.position] = m_elevator->obj1;
	if (m_elevator->obj2) {
		m_floors[m_currentFloor][m_elevator->obj2.position] = m_elevator->obj2;
		m_elevator->floor--;
	}
	else
		m_elevator->floor++;
	m_elevator->obj1 = object_t();
	m_elevator->obj2 = object_t();
}

int Day11::makeMove()
{
	vector<object_t> obsOnFloor = m_floors[m_currentFloor];
	if(m_elevator->obj1) obsOnFloor[m_elevator->obj1.position] = m_elevator->obj1;
	if(m_elevator->obj2) obsOnFloor[m_elevator->obj2.position] = m_elevator->obj2;
	
	if (!isLegalState(obsOnFloor))
		return 0;

	if (isValidSolution(m_currentFloor, obsOnFloor)) {
		return 1;
	}

	/*
	//Only in first step
	else if (m_elevator->isEmpty()) {
		for (auto iterObjA = m_floors[m_currentFloor].begin(); iterObjA != --m_floors[m_currentFloor].end(); iterObjA++) {
			auto iterObjB = iterObjA++;
			iterObjA--;

			for (iterObjB; iterObjB != m_floors[m_currentFloor].end(); iterObjB++) {
				if (!*iterObjA || !*iterObjB)
					continue;

				if (!fillElevator(*iterObjA, *iterObjB))
					continue;
				m_currentFloor++;

				int move = makeMove();
				if (move != 0) {
					printFloors();
					return 1 + move;
				}
				
				m_currentFloor--;
				clearElevator();
			}
		}
	}*/

	/*
	//Try to find next step
	else {
		//Try to reach the next floor
		int move = 0;
		m_currentFloor++;
		move = makeMove();
		if (move != 0) {
			printFloors();
			return 1 + move;
		}
		
		//clear elevator and search for next step
		m_currentFloor--;
		clearElevator();
		
		//load elevator to upper floor
		for (auto iterObjA = m_floors[m_currentFloor].begin(); iterObjA != --m_floors[m_currentFloor].end(); iterObjA++) {
			for (auto iterObjB = iterObjA++; iterObjB != m_floors[m_currentFloor].end(); iterObjB++) {
				if (!*iterObjA || !*iterObjB)
					continue;
				iterObjA--;
				if (!fillElevator(*iterObjA, *iterObjB))
					continue;
				m_currentFloor++;

				int move = makeMove();
				if (move != 0) {
					printFloors();
					return 1 + move;
				}

				m_currentFloor--;
				clearElevator();
			}
		}

		//no legal upper floor combination found try lower
		for (auto iterObj = m_floors[m_currentFloor].begin(); iterObj != --m_floors[m_currentFloor].end(); iterObj++) {
			if (!*iterObj)
				continue;
			if (!fillElevator(*iterObj))
				continue;
			m_currentFloor--;

			int move = makeMove();
			if (move != 0)
				return 1 + move;

			m_currentFloor++;
			clearElevator();
		}
	}
	*/

	return 0;
} 

void Day11::printFloors()
{
	int length = 0;
	
	for (auto floor : m_floors) {
		for (auto obj : floor) {
			if (obj.position > length)
				length = obj.position;
		}
	}

	vector<vector<string>> sFloor = vector<vector<string>>(m_floors.size(), vector<string>(length+3, ". "));

	for (int floor = 0; floor < m_floors.size(); floor++) {
		sFloor[floor][0] = "F" + to_string(floor + 1);
		if (m_elevator->floor == floor)
			sFloor[floor][1] = "E ";
		for (auto obj : m_floors[floor]) {
			if(obj)
				sFloor[floor][obj.position + 2] = obj.getShortcut();
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

	cout << endl << endl;
}
