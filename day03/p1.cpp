// AoC 2015 Day 3 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ifstream input("input.txt");

    unordered_set<int> visited;

    int position = 0;

    visited.insert(position);

    char ch;
    while (input.get(ch)) {
        if (ch == '>') {
            position++;
        } else if (ch == '<') {
            position--;
        } 
        // My input size had 8193 characters
        else if (ch == '^') {
            position += 8193;
        } else {
            position -= 8193;
        }

        visited.insert(position);
    }

    cout << visited.size();

    input.close();
    return 0;
}