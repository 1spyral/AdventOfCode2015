// AoC 2015 Day 2 Problem 2

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

        sum += min(min(a + b, b + c), a + c) * 2;
        sum += a * b * c;
    }

    cout << sum;

    input.close();
    return 0;
}