#include "stdafx.h"
#include "Day7.h"


Day7::Day7()
{
}


Day7::~Day7()
{
}

void Day7::startA(vector<string> input)
{
	int ipCounter = 0;
	for (string ip : input) {
		IPv7 ipv7;
		parseIPv7(ip, ipv7);
		if (isIPv7(ipv7))
			ipCounter++;
	}
	
	cout << "A: The document contains " << ipCounter << " IPv7 addresses." << endl << endl;
}

void Day7::startB(vector<string> input)
{
	int ipCounter = 0;
	for (string ip : input) {
		IPv7 ipv7;
		parseIPv7(ip, ipv7);
		if (hasSSL(ipv7))
			ipCounter++;
	}

	cout << "B: The document contains " << ipCounter << " IPv7 addresses which support SSL." << endl << endl;
}

void Day7::parseIPv7(string ip, IPv7& ipv7)
{
	bool first = true, second = false;
	string tmp = "";

	for (char c : ip) {
		if (c == '[') {
			ipv7.legal.push_back(tmp);
			tmp = "";
		}
		else if (c == ']') {
			ipv7.illegal.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += c;
		}
	}
	ipv7.legal.push_back(tmp);
}

bool Day7::isIPv7(IPv7 & ipv7)
{
	char tmp1, tmp2, tmp3, tmp4;

	for (string illegal : ipv7.illegal) {
		for (int pos = 0; pos < illegal.size() - 3; pos++) {
			tmp1 = illegal.at(pos);
			tmp2 = illegal.at(pos + 1);
			tmp3 = illegal.at(pos + 2);
			tmp4 = illegal.at(pos + 3);

			if (tmp2 == tmp3 && tmp1 == tmp4) {
				return false;
			}
		}
	}
	

	for (string legal : ipv7.legal) {
		for (int pos = 0; pos < legal.size() - 3; pos++) {
			tmp1 = legal.at(pos);
			tmp2 = legal.at(pos + 1);
			tmp3 = legal.at(pos + 2);
			tmp4 = legal.at(pos + 3);

			if (tmp1 == tmp2  && tmp1 == tmp3 && tmp1 == tmp4 && tmp2 == tmp3 && tmp2 == tmp4 && tmp3 == tmp4) {
				return false;
			}

			if (tmp2 == tmp3 && tmp1 == tmp4) {
				return true;
			}
		}
	}

	return false;
}

bool Day7::hasSSL(IPv7 & ipv7)
{
	char tmp1, tmp2, tmp3;

	for (string legal : ipv7.legal) {
		for (int pos = 0; pos < legal.size() - 2; pos++) {
			tmp1 = legal.at(pos);
			tmp2 = legal.at(pos + 1);
			tmp3 = legal.at(pos + 2);

			if (tmp1 == tmp3 && tmp2 != tmp1) {
				for (string illegal : ipv7.illegal) {
					for (int pos2 = 0; pos2 < illegal.size() - 2; pos2++) {
						if (tmp2 == illegal.at(pos2) && tmp2 == illegal.at(pos2 + 2) && tmp1 == illegal.at(pos2 + 1))
							return true;
					}
				}
			}						
		}
	}
	return false;
}
