// AoC 2015 Day 1 Problem 2

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");

    int level = 0;
    int position = 0;

    char ch;

    while (input.get(ch)) {
        position++;
        if (ch == '(') {
            level++;
        } else {
            level--;
        }
        
        if (level < 0) {
            cout << position;
            break;
        }
    }
    
    return 0;
}