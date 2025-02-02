// AoC 2015 Day 25 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#define FIRST 20151125
#define MULTIPLY 252533
#define MOD 33554393

#define ROW 2981
#define COL 3075

using namespace std;

int row = 1;
int col = 1;

void next() {
    if (row == 1) {
        row = col + 1;
        col = 1;
    } else {
        row--;
        col++;
    }
}

int main() {
    long long curr = FIRST;

    while (row != ROW || col != COL) {
        next();
        curr *= MULTIPLY;
        curr %= MOD;
    }

    cout << curr;

    return 0;
}