// AoC 2015 Day 8 Problem 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    int ans = 0;

    string line;
    while (getline(input, line)) {
        int mem = 0;
        int i = 0;
        while (i < line.length()) {
            if (line[i] == '\"') {
                i++;
                continue;
            } else if (line[i] == '\\') {
                i++;
                mem++;
                if (line[i] == 'x') {
                    i += 3;
                } else {
                    i++;
                }
            } else {
                i++;
                mem++;
            }
        }
        ans += line.length() - mem;
    }

    cout << ans;

    input.close();
    return 0;
}