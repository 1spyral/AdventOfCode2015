// AoC 2015 Day 24 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cmath>

#define BOXES 28

using namespace std;

long long weights[BOXES];
int sum = 0;

long long qe = LONG_LONG_MAX;

unordered_set<int> first;

bool find_second(int index = BOXES, int total = 0) {
    if (total > sum) {
        return false;
    }
    if (total == sum) {
        return true;
    }
    if (index == 0) {
        return false;
    }
    if (first.count(index - 1) == 0 && find_second(index - 1, total + weights[index - 1])) {
        return true;
    }
    if (find_second(index - 1, total)) {
        return true;
    }
    return false;
}

void find_first(int index = BOXES, int total = 0, int len = 0, long long q = 1, int target = 1) {
    if (len == target) {
        if (total == sum && find_second()) {
            qe = min(q, qe);
        }
        return;
    }
    if (index == 0) {
        return;
    }
    first.insert(index - 1);
    find_first(index - 1, total + weights[index - 1], len + 1, q * weights[index - 1], target);
    first.erase(index - 1);
    find_first(index - 1, total, len, q, target);
}


int main() {
    ifstream input("input.txt");

    string line;
    for (long long &weight : weights) {
        getline(input, line);
        weight = stol(line);
        sum += weight;
    }

    sum /= 3;

    int target = 1;

    while (qe == LONG_LONG_MAX) {
        find_first(BOXES, 0, 0, 1, target);
        target++;
    }

    cout << qe;

    input.close();
    return 0;
}