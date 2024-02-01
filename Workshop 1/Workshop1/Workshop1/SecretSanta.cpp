#include "SecretSanta.h"
#include "DiceRoll.h"
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
struct Pairing {
    string name1;
    string name2;
    string Output() {
        stringstream ss;
        ss << name1 << "->" << name2;
        return ss.str();
    }
    bool operator==(const Pairing& other) {
        return name1 == other.name1 && name2 == other.name2;
    }
    Pairing(string n1, string n2) {
        name1 = n1;
        name2 = n2;
    }
};
void GeneratePairs(vector<string> allNames,vector<Pairing> &output) {
    while (allNames.size() > 1) {
        int i1 = rand() % allNames.size();
        int i2 = rand() % allNames.size();
        if (i1 == i2) continue;
        output.push_back(Pairing(allNames[i1], allNames[i2]));
        vector<string> namesCopy;
        for (int i = 0; i < allNames.size(); i++) {
            if (i == i1 || i == i2) continue;
            namesCopy.push_back(allNames[i]);
        }
        allNames = namesCopy;
    }
}
vector<Pairing> GenerateBannedPairings(vector<string> allLines) {
    vector<Pairing> output;
    for (string line : allLines) {
        vector<string> lineNames = Split(line, ' ');
        for (string name : lineNames) {
            for (string name2 : lineNames) {
                output.push_back(Pairing(name, name2));
            }
        }
    }
    return output;
}

vector<string> GrabNames(vector<string> lines) {
    vector<string> output;
    for (string line : lines) {
        vector<string> lineNames = Split(line, ' ');
        for (string name : lineNames) {
            output.push_back(name);
        }
    }
    return output;
}
bool Contains(Pairing pair, vector<Pairing> banned) {
    for (Pairing p : banned) {
        if (pair == p) return true;
    }
    return false;
}
bool ValidatePairings(vector<Pairing> pairs,vector<Pairing> bannedPairs,vector<int> &invalids) {
    for (Pairing p : pairs) {
        if (Contains(p, bannedPairs)) return false;
    }
    return true;
}
int SantaMain()
{
    srand(time(NULL));
    vector<string> lines = ReadFile("input3.txt");

    vector<Pairing> BannedPairings = GenerateBannedPairings(lines);
    vector<string> OutstandingNames = GrabNames(lines);
    vector<Pairing> FinalPairs;
    GeneratePairs(OutstandingNames, FinalPairs);
    vector<int> invalidFinalIndices;
    //delete banned AND a random line add names back to new pool
    while (!ValidatePairings(FinalPairs,BannedPairings,invalidFinalIndices)) {
        OutstandingNames.clear();
        for (int i : invalidFinalIndices) {

            OutstandingNames.push_back(FinalPairs[i].name1);
            OutstandingNames.push_back(FinalPairs[i].name2);
            FinalPairs.erase(std::next(FinalPairs.begin(), i), std::next(FinalPairs.begin(), i+1));

            int randIndex = rand() % FinalPairs.size();
            OutstandingNames.push_back(FinalPairs[randIndex].name1);
            OutstandingNames.push_back(FinalPairs[randIndex].name2);
            FinalPairs.erase(std::next(FinalPairs.begin(), randIndex), std::next(FinalPairs.begin(), randIndex + 1));
        }
        GeneratePairs(OutstandingNames, FinalPairs);
    }
    for (Pairing p : FinalPairs) {
        cout << p.Output() << endl;
    }
    return 0;
}
