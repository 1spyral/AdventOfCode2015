// AoC 2015 Day 19 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define PAIRS 43

using namespace std;

int main() {
    ifstream input("input.txt");

    unordered_map<string, vector<string>> assign;
    unordered_set<string> seen;

    string word;
    for (int i = 0; i < PAIRS; i++) {
        getline(input, word, ' ');
        string first = word;
        getline(input, word, ' ');
        getline(input, word);
        if (assign.count(first) == 0) {
            assign[first] = vector<string>();
        }
        assign[first].push_back(word);
    }
    
    getline(input, word);

    string text;
    getline(input, text);

    int index = 0;
    char prev = ' ';

    while (index < text.length()) {
        if (assign.count(string(1, text[index])) > 0) {
            for (int i = 0; i < assign[string(1, text[index])].size(); i++) {
                seen.insert(text.substr(0, index) + assign[string(1, text[index])][i] + text.substr(index + 1));
            }
        } else if (assign.count(string(1, prev) + string(1, text[index])) > 0) {
            for (int i = 0; i < assign[string(1, prev) + string(1, text[index])].size(); i++) {
                seen.insert(text.substr(0, index - 1) + assign[string(1, prev) + string(1, text[index])][i] + text.substr(index + 1));
            }
        }
        prev = text[index];
        index++;
    }

    cout << seen.size();

    input.close();
    return 0;
}