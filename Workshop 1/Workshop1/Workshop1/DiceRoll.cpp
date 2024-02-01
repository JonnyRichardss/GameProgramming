#include "DiceRoll.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
int RollDie(int maxRoll) {

	return rand() % maxRoll + 1;
}
vector<string> ReadFile(string filePath) {
	std::vector<std::string> output;
	char lineBuffer[1024];
	std::ifstream myFile(filePath);

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			lineBuffer[0] = '\0'; //empty string
			myFile.getline(lineBuffer, 1024);
			output.push_back(lineBuffer);
		}
		myFile.close();
	}
	return output;
}
vector<string> Split(string input, char delim) {
	vector<string> words;
	stringstream ss(input);
	string word;
	while (getline(ss, word, delim)) {
		words.push_back(word);
	}
	return words;
}
bool tryParseLine(string input,vector<int> &nums) {
		vector<string> numsString = Split(input, 'd');
		nums.clear();
		for (auto i = numsString.begin(); i != numsString.end(); i++) {
			nums.push_back(stoi(*i));
		}
		if (nums.size() == 2) {
			return true;
		}
		return false;
	}
int totalDice(vector<int> input) {
	int total=0;
	for (int i : input) {
		total += i;
	}
	return total;
}
vector<int> GetAllRolls(string line) {
	vector<int> nums;
	
	if (tryParseLine(line, nums)) {
		vector<int> output;
		for (int i = 1; i <= nums[0]; i++) {
			output.push_back(RollDie(nums[1]));
		}
		return output;
	}
	else {
		cout << "received invalid input" << endl;
		return vector<int>();
	}
}
string strFromRolls(vector<int> input) {
	stringstream ss;
	for (int i : input) {
		ss << i << " ";
	}
	return ss.str();
}
int DiceMain()
{
	srand(time(NULL));
	vector<string> lines = ReadFile("input.txt");

	for (int i = 0; i < lines.size();i++) {
		string line = lines[i];
		vector<int> allRolls = GetAllRolls(line);
		cout << totalDice(allRolls) << ": " << strFromRolls(allRolls) << endl;
	}
	return 0;
}
