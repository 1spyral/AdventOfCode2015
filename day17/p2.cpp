// AoC 2015 Day 17 Problem 2

#include <iostream>
#include <fstream>
#include <string>

#define EGGNOG 150
#define CONTAINERS 20

using namespace std;

int ans = 0;
int smallest = INT_MAX;
int containers[CONTAINERS];

void fill(int index = 0, int total = 0, int taken = 0) {
    if (total == EGGNOG) {
        if (taken < smallest) {
            smallest = taken;
            ans = 1;
        } else if (taken == smallest) {
            ans++;
        }
        return;
    }
    if (index == CONTAINERS) {
        return;
    }
    fill(index + 1, total + containers[index], taken + 1);
    fill(index + 1, total, taken);
}

int main() {
    ifstream input("input.txt");

    string line;
    for (int i = 0; i < CONTAINERS; i++) {
        getline(input, line);
        containers[i] = stoi(line);
    }

    fill();

    cout << ans;

    input.close();
    return 0;
}