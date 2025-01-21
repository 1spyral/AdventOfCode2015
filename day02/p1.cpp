// AoC 2015 Day 2 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");

    int sum = 0;

    string in;
    while (getline(input, in, 'x')) {
        int a = stoi(in);
        getline(input, in, 'x');
        int b = stoi(in);
        getline(input, in);
        int c = stoi(in);

        sum += 2 * a * b;
        sum += 2 * b * c;
        sum += 2 * a * c;
        sum += min(min(a * b, b * c), a * c);
    }

    cout << sum;

    input.close();
    return 0;
}