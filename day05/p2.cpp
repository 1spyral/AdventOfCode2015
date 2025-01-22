// AoC 2015 Day 5 Problem 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool check(string str) {
    bool middle = false;

    for (int i = 2; i < str.length(); i++) {
        if (str[i] == str[i - 2]) {
            middle = true;
            break;
        }
    }

    if (!middle) {
        return false;
    }

    for (int i = 1; i < str.length(); i++) {
        for (int j = i + 2; j < str.length(); j++) {
            if (str[j] == str[i] && str[j - 1] == str[i - 1]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ifstream input("input.txt");

    int ans = 0;

    string line;
    while (getline(input, line)) {
        if (check(line)) {
            ans++;
        }
    }

    cout << ans;

    input.close();
    return 0;
}