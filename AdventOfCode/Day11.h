#pragma once
#include "AoCDay.h"
class Day11 :
	public AoCDay
{
private:
	struct object_t;
	struct elevator;

public:
	Day11();
	~Day11();

	void startA(vector<string> a_input);
	void startB(vector<string> a_input);

private:
	typedef string identifier_t;
	typedef int floor_t;
	vector<vector<object_t>> m_floors;
	elevator* m_elevator;
	floor_t m_currentFloor;
	int m_totalNumberOfObjects;

	bool isLegalState(vector<object_t>& a_obsOnFloor);
	bool isValidSolution(floor_t a_floor, vector<object_t>& a_obsOnFloor);
	bool fillElevator(object_t a_objA);
	bool fillElevator(object_t a_objA, object_t a_objB);
	void clearElevator();
	int makeMove();
	void printFloors();

	enum objType{
		e_unknown, e_generator, e_microchip
	};


	struct object_t {
		object_t() {
			position = 0;
			type = e_unknown;
			identifier = "";
		}

		object_t(objType a_ot, identifier_t a_identifier, int pos) {
			position = pos;
			type = a_ot;
			identifier = a_identifier;
		}

		string getShortcut() {
			if (type == e_generator)
				return string(identifier.substr(0, 1) + "G");
			else if (type == e_microchip)
				return string(identifier.substr(0, 1) + "M");
			else
				return ". ";
		}

		operator bool() {
			return identifier != "";
		}
		bool operator== (object_t i) {
			return getShortcut() == i.getShortcut();
		}

		int position;
		objType type;
		identifier_t identifier;
	};

	struct elevator {
		elevator() {
			floor = 0;
		}
		bool isEmpty() {
			return !obj1 && !obj2 ;
		}

		object_t obj1, obj2;
		int floor;
	};

};

