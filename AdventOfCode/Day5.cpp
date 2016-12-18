#include "stdafx.h"
#include "Day5.h"
#include "MD5.h"


Day5::Day5()
{
}


Day5::~Day5()
{
}

void Day5::startA(vector<string> input)
{
	int index = 0;
	string id = input[0];
	string tmpHash;
	int counter = 0;

	cout << "A: The password for the security door is: " << endl;

	while (true) {
		tmpHash = id + to_string(index++);
		string md5Hash = md5(tmpHash);
		
		if (md5Hash[0] == '0' && md5Hash[1] == '0' && md5Hash[2] == '0' && md5Hash[3] == '0' && md5Hash[4] == '0') {
			cout << md5Hash.at(5);
			counter++;
		}
		if (counter == 8)
			break;
	}

	cout << endl << endl;
}

void Day5::startB(vector<string> input)
{
	int index = 0;
	string id = input[0];
	string tmpHash;
	int counter = 0;
	string password = "________";

	cout << "B: The password for the second security door is: " << endl;
	cout << "Password: " << password;
	while (true) {
		tmpHash = id + to_string(index++);
		string md5Hash = md5(tmpHash);

		if (md5Hash[0] == '0' && md5Hash[1] == '0' && md5Hash[2] == '0' && md5Hash[3] == '0' && md5Hash[4] == '0') {
			if (md5Hash.at(5) < '8' && md5Hash.at(5) >= '0') {
				if (password.at(md5Hash.at(5) - '0') != '_')
					continue;
				password.at(md5Hash.at(5) - '0') = md5Hash.at(6);
				counter++;
				cout << '\r' << "Password: " << password;
			}
		}
		if (counter == 8)
			break;
	}

	cout << endl << endl;
}
