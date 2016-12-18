#pragma once
#include "AoCDay.h"
class Day4 :
	public AoCDay
{
public:
	Day4();
	~Day4();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
	struct letterCounter {
		explicit letterCounter() {
			letters = vector<int>(26, 0);
		}

		void add(char letter) {
			if (letter < 'a' || letter > 'z')
				throw exception("No lower case letter detected");

			letters[letter - 'a']++;
		}
		vector<int> letters;
	};

	struct check_id {
		check_id() {
			checksum = "";
			id = 0;
		}

		string checksum;
		int id;
	};

	void parseRooms(vector<string>& input, vector<vector<string>>* rooms);
	letterCounter countLetters(vector<string>& room);
	string createChecksum(letterCounter& letters);
	check_id getCheckId(vector<string>& room);

	string encryptedRoom(vector<string>& room, int id);
};

