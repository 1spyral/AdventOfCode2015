// AoC 2015 Day 3 Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ifstream input("input.txt");

    unordered_set<int> visited;

    int santa = 0;
    int robot = 0;

    bool turn = false;

    visited.insert(0);

    char ch;
    while (input.get(ch)) {
        if (turn) {
            if (ch == '>') {
                robot++;
            } else if (ch == '<') {
                robot--;
            } else if (ch == '^') {
                robot += 8193;
            } else {
                robot -= 8193;
            }

            visited.insert(robot);
        } else {
            if (ch == '>') {
                santa++;
            } else if (ch == '<') {
                santa--;
            } 
            // My input size had 8193 characters
            else if (ch == '^') {
                santa += 8193;
            } else {
                santa -= 8193;
            }

            visited.insert(santa);
        }
        turn = !turn;
    }

    cout << visited.size();

    input.close();
    return 0;
}