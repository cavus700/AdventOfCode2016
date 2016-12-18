#include "stdafx.h"
#include "Day4.h"


Day4::Day4()
{
}


Day4::~Day4()
{
}

void Day4::startA(vector<string> input)
{
	vector<vector<string>> rooms;
	parseRooms(input, &rooms);

	int result = 0;

	for (vector<string> room : rooms) {
		auto counter = countLetters(room);
		string checksum = createChecksum(counter);
		auto checkId = getCheckId(room);

		if (checkId.checksum == checksum)
			result += checkId.id;
	}

	cout << "A: The sum of the sector ID's is : " << result << endl << endl;
}

void Day4::startB(vector<string> input)
{
	vector<vector<string>> rooms;
	parseRooms(input, &rooms);

	cout << "B: Encrypted rooms:" << endl;
	for (vector<string> room : rooms) {
		auto checkId = getCheckId(room);
		
		string encrypted = encryptedRoom(room, checkId.id);
		if(encrypted != "")
			cout << encryptedRoom(room, checkId.id) << " : " << checkId.id << endl;
	}
}

void Day4::parseRooms(vector<string>& input, vector<vector<string>>* rooms)
{
	string temp = "";
	vector<string> tmpRoom;

	for (string enc : input) {
		for (char c : enc) {
			if (c == '-') {
				tmpRoom.push_back(temp);
				temp = "";
			}
			else {
				temp += c;
			}
		}
		tmpRoom.push_back(temp);
		temp = "";
		rooms->push_back(tmpRoom);
		tmpRoom = vector<string>();
	}
}

Day4::letterCounter Day4::countLetters(vector<string>& room)
{
	letterCounter counter;

	for (int part = 0; part < room.size()-1; part++) {
		for (char c : room.at(part)) {
			counter.add(c);
		}
	}
	return counter;
}

string Day4::createChecksum(letterCounter & counter)
{
	int max = 0;
	string result = "";

	while (true) {
		//search for maximum
		for (int letter : counter.letters) {
			if (letter > max)
				max = letter;
		}

		if (max == 0)
			break;

		//add maximum
		for (int letter = 0; letter < counter.letters.size(); letter++) {
			if (counter.letters[letter] == max) {
				result += static_cast<char>('a' + letter);
				counter.letters[letter] = 0;
			}
		}

		max = 0;
	}

	return result.substr(0,5);
}

Day4::check_id Day4::getCheckId(vector<string>& room)
{
	check_id result;
	string tmpId = "";

	bool id = true;

	for (char c : room.at(room.size() - 1)) {
		if (c == '[') {
			id = false;
			continue;
		}
		else if (c == ']')
			break;
		
		if (id)
			tmpId += c;
		else
			result.checksum += c;
	}

	result.id = stoi(tmpId);
	return result;
}

string Day4::encryptedRoom(vector<string>& room, int id)
{
	string result = "";
	string tmp = "";

	for (string part : room) {
		for (char enc : part) {
			tmp += (((enc - 'a') + id) % 26) + 'a';
		}

		if(tmp == "north" || tmp == "North" || tmp == "Northpole" || tmp == "northpole")
			result += tmp + " ";
		tmp = "";
	}
	return result;
}
