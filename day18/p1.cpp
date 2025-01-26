// AoC 2015 Day 18 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#define DIM 100

using namespace std;

bool now[DIM][DIM] = {false};
bool after[DIM][DIM];

bool valid(int x, int y) {
    return x >= 0 && x < DIM && y >= 0 && y < DIM;
}

void toggle(int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (!(i == x && j == y) && valid(i, j) && now[i][j]) {
                count++;
            }
        }
    }
    if (now[x][y]) {
        if (count == 2 || count == 3) {
            after[x][y] = true;
        } else {
            after[x][y] = false;
        }
    } else {
        if (count == 3) {
            after[x][y] = true;
        } else {
            after[x][y] = false;
        }
    }
}

void getNext() {
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            toggle(x, y);
        }
    }
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            now[x][y] = after[x][y];
        }
    }
}

int main() {
    ifstream input("input.txt");

    string line;
    for (int j = 0; j < DIM; j++) {
        getline(input, line);
        for (int i = 0; i < DIM; i++) {
            if (line[i] == '#') {
                now[i][j] = true;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        getNext();
    }

    int ans = 0;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (now[i][j]) {
                ans++;
            }
        }
    }

    cout << ans;

    input.close();
    return 0;
}