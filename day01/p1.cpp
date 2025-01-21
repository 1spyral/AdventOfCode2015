// AoC 2015 Day 1 Problem 1

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");

    int level = 0;

    char ch;

    while (input.get(ch)) {
        if (ch == '(') {
            level++;
        } else {
            level--;
        }
    }

    cout << level;
    return 0;
}