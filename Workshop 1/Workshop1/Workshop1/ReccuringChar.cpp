#include "ReccuringChar.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "DiceRoll.h"
using namespace std;

bool Contains(vector<char> chars, char input) {
	for (char c : chars) {
		if (input == c) return true;
	}
	return false;
}
char FindChar(string line) {
	vector<char> allChars;
	for (char c : line) {
		if (Contains(allChars, c)) {
			return c;
		}
		else {
			allChars.push_back(c);
		}
	}
	cout << "No reccuring character" << endl;
	return ' ';
}
int CharMain()
{
	vector<string> lines = ReadFile("input2.txt");
	for (string line : lines) {
		cout << FindChar(line) << endl;
	}
    return 0;
}
