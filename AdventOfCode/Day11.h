#pragma once
#include "AoCDay.h"
class Day11 :
	public AoCDay
{
private:
	struct object;
	struct elevator;

public:
	Day11();
	~Day11();

	void startA(vector<string> a_input);
	void startB(vector<string> a_input);

private:
	typedef string identifier_t;

	vector<vector<object*>> m_floors;
	elevator* m_elevator;

	void printFloors();

	enum objType{
		e_generator, e_microchip
	};

	struct elevator {
		elevator() {
			obj1 = obj2 = nullptr;
			floor = 0;
		}
		object *obj1, *obj2;
		int floor;
	};

	struct object {
		object(objType a_ot, identifier_t a_identifier, int pos) {
			position = pos;
			type = a_ot;
			identifier = a_identifier;
		}

		string getShortcut() {
			if (type == e_generator)
				return string(identifier.at(0) + "G");
			else
				return string(identifier.at(0) + "M");
		}

		int position;
		objType type;
		identifier_t identifier;
	};
};

