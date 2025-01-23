// AoC 2015 Day 8 Problem 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    int ans = 0;

    string line;
    while (getline(input, line)) {
        int len = 2;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '\"' || line[i] == '\\') {
                len += 2;
            } else {
                len++;
            }
        }
        ans += len - line.length();
    }

    cout << ans;

    input.close();
    return 0;
}