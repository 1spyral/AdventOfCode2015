// AoC 2015 Day 17 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#define EGGNOG 150
#define CONTAINERS 20

using namespace std;

int ans = 0;
int containers[CONTAINERS];

void fill(int index = 0, int total = 0) {
    if (total == EGGNOG) {
        ans++;
        return;
    }
    if (index == CONTAINERS) {
        return;
    }
    fill(index + 1, total + containers[index]);
    fill(index + 1, total);
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