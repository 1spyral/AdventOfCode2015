// AoC 2015 Day 23 Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define OPERATIONS 46

using namespace std;

int main() {
    ifstream input("input.txt");

    unsigned int a = 1;
    unsigned int b = 0;

    string operations[OPERATIONS];
    char reg[OPERATIONS];
    int offset[OPERATIONS];

    string word;
    for (int i = 0; i < OPERATIONS; i++) {
        getline(input, word, ' ');
        operations[i] = word;
        if (word == "jie" || word == "jio") {
            getline(input, word, ' ');
            reg[i] = word[0];
            getline(input, word);
            offset[i] = stoi(word);
            continue;
        }
        getline(input, word);
        if (operations[i] == "jmp") {
            offset[i] = stoi(word);
            continue;
        }
        reg[i] = word[0];
    }

    int index = 0;

    while (index < OPERATIONS && index >= 0) {
        unsigned int* p;
        if (reg[index] == 'a') {
            p = &a;
        } else {
            p = &b;
        }
        if (operations[index] == "hlf") {
            *p >>= 1;
        } else if (operations[index] == "tpl") {
            *p *= 3;
        } else if (operations[index] == "inc") {
            (*p)++;
        } else if (
            operations[index] == "jmp" ||
            operations[index] == "jie" && *p % 2 == 0 ||
            operations[index] == "jio" && *p == 1
            ) {
            index += offset[index];
            continue;
            }
        index++;
    }

    cout << b;

    input.close();
    return 0;
}
