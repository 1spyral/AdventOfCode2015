// AoC 2015 Day 20 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool check(int num, const int target) {
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        int count = 0;
        while (num % i == 0) {
            count++;
            num /= i;
        }
        if (count > 0) {
            sum *= (pow(i, count + 1) - 1) / (i - 1);
        }
    }
    if (num != 1) {
        sum *= (num * num - 1) / (num - 1);
    }

    return sum >= target;
}

int main() {
    ifstream input("input.txt");

    string line;
    getline(input, line);

    const int target = stoi(line) / 10;

    int ans;

    for (ans = 1; !check(ans, target); ans++) {}

    cout << ans;

    input.close();
    return 0;
}