// AoC 2015 Day 5 Problem 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool isIllegal(char a, char b) {
    return a == 'a' && b == 'b' || a == 'c' && b == 'd' || a == 'p' && b == 'q' || a == 'x' && b == 'y';
}

bool check(string str) {
    int vowels = 0;
    bool dub = false;

    char prev = str[0];

    if (isVowel(prev)) {
        vowels++;
    }

    for (int i = 1; i < str.length(); i++) {
        if (isVowel(str[i])) {
            vowels++;
        }
        if (str[i] == prev) {
            dub = true;
        }
        if (isIllegal(prev, str[i])) {
            return false;
        }
        prev = str[i];
    }

    return dub && vowels >= 3;
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