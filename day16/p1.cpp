// AoC 2015 Day 16 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#define SUE 500
#define CHILDREN 3
#define CATS 7
#define SAMOYEDS 2
#define POMERANIANS 3
#define AKITAS 0
#define VIZSLAS 0
#define GOLDFISH 5
#define TREES 3
#define CARS 2
#define PERFUMES 1

using namespace std;

bool check(string category, int count) {
    if (category == "children") {
        return count == CHILDREN;
    } else if (category == "cats") {
        return count == CATS;
    } else if (category == "samoyeds") {
        return count == SAMOYEDS;
    } else if (category == "pomeranians") {
        return count == POMERANIANS;
    } else if (category == "akitas") {
        return count == AKITAS;
    } else if (category == "vizslas") {
        return count == VIZSLAS;
    } else if (category == "goldfish") {
        return count == GOLDFISH;
    } else if (category == "trees") {
        return count == TREES;
    } else if (category == "cars") {
        return count == CARS;
    } else {
        return count == PERFUMES;
    }
}

int main() {
    ifstream input("input.txt");

    int index = 0;

    string word;
    while (getline(input, word, ' ')) {
        index++;
        getline(input, word, ' ');
        getline(input, word, ':');
        string category = word;
        getline(input, word, ' ');
        getline(input, word, ',');
        int count = stoi(word);
        if (!check(category, count)) {
            getline(input, word);
            continue;
        }
        getline(input, word, ' ');
        getline(input, word, ':');
        category = word;
        getline(input, word, ' ');
        getline(input, word, ',');
        count = stoi(word);
        if (!check(category, count)) {
            getline(input, word);
            continue;
        }
        getline(input, word, ' ');
        getline(input, word, ':');
        category = word;
        getline(input, word, ' ');
        getline(input, word);
        count = stoi(word);
        if (!check(category, count)) {
            continue;
        }
        cout << index;
        break;
    }

    input.close();
    return 0;
}