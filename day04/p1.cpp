// AoC 2015 Day 4 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#include "md5.cpp"

using namespace std;

bool check(string str) {
    for (int i = 0; i < 5; i++) {
        if (str[i] != '0') {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream input("input.txt");

    string line;
    getline(input, line);

    int i = 1;

    while (true) {
        string str = line + to_string(i);

        void* sig = hashing::md5::hash(str);

        if (check(hashing::md5::sig2hex(sig))) {
            break;
        }

        i++;
    }

    cout << i;

    input.close();
    return 0;
}