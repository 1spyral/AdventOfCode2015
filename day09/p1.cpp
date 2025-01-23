// AoC 2015 Day 9 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#define CITIES 8

using namespace std;

int ans = INT_MAX;
int dist[CITIES][CITIES];
unordered_set<int> visited;

void travel(int city, int total = 0) {
    visited.insert(city);
    for (int i = 0; i < CITIES; i++) {
        if (visited.find(i) == visited.end()) {
            travel(i, total + dist[city][i]);
        }
    }
    if (visited.size() == CITIES && total < ans) {
        ans = total;
    }
    visited.erase(city);
}

int main() {
    ifstream input("input.txt");

    int city = 0;
    unordered_map<string, int> ids;

    string word;
    while (getline(input, word, ' ')) {
        string start = word;
        getline(input, word, ' ');
        getline(input, word, ' ');
        string end = word;
        getline(input, word, ' ');
        getline(input, word);
        if (ids.find(start) == ids.end()) {
            ids[start] = city;
            city++;
        }
        if (ids.find(end) == ids.end()) {
            ids[end] = city;
            city++;
        }
        dist[ids[start]][ids[end]] = stoi(word);
        dist[ids[end]][ids[start]] = stoi(word);
    }

    for (int i = 0; i < CITIES; i++) {
        travel(i);
    }

    cout << ans;

    input.close();
    return 0;
}