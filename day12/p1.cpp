// AoC 2015 Day 12 Problem 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isDigit(char ch) {
    for (char num: { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }) {
        if (ch == num) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream input("input.txt");

    int sum = 0;

    bool negative;
    int curr = 0;

    char ch;
    while (input.get(ch)) {
        if (!isDigit(ch)) {
            if (negative) {
                sum -= curr;
            } else {
                sum += curr;
            }
            negative = ch == '-';
            curr = 0;
        } else {
            curr *= 10;
            curr += ch - '0';
        }
    }
    if (negative) {
        sum -= curr;
    } else {
        sum += curr;
    }

    cout << sum;

    input.close();
    return 0;
}