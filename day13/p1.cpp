// AoC 2015 Day 13 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#define PEOPLE 8

using namespace std;

int ans = 0;
int dist[PEOPLE][PEOPLE];
unordered_set<int> visited;

void travel(int person, int total = 0) {
    visited.insert(person);
    for (int i = 0; i < PEOPLE; i++) {
        if (visited.find(i) == visited.end()) {
            travel(i, total + dist[person][i] + dist[i][person]);
        }
    }
    int fin = total + dist[0][person] + dist[person][0];
    if (visited.size() == PEOPLE && fin > ans) {
        ans = fin;
    }
    visited.erase(person);
}

int main() {
    ifstream input("input.txt");

    int person = 0;
    unordered_map<string, int> ids;

    string word;
    while (getline(input, word, ' ')) {
        string one = word;
        getline(input, word, ' ');
        getline(input, word, ' ');
        bool pos = word == "gain";
        getline(input, word, ' ');
        int diff = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, '.');
        if (ids.find(one) == ids.end()) {
            ids[one] = person;
            person++;
        }
        if (ids.find(word) == ids.end()) {
            ids[word] = person;
            person++;
        }
        if (pos) {
            dist[ids[one]][ids[word]] = diff;
        } else {
            dist[ids[one]][ids[word]] = -diff;
        }
        getline(input, word);
    }

    travel(0);

    cout << ans;

    input.close();
    return 0;
}
