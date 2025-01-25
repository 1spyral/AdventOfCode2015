// AoC 2015 Day 14 Problem 1

#include <iostream>
#include <fstream>
#include <string>

#define REINDEER 9
#define TIME 2503

using namespace std;

int main() {
    ifstream input("input.txt");

    int speeds[REINDEER];
    int duration[REINDEER];
    int rest[REINDEER];

    int distance[REINDEER] = {0};

    int index = -1;

    string word;
    while (getline(input, word, ' ')) {
        index++;
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        speeds[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        duration[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ' ');
        rest[index] = stoi(word);
        getline(input, word);
    }

    for (int i = 0; i < TIME; i++) {
        for (int reindeer = 0; reindeer < REINDEER; reindeer++) {
            if (i % (duration[reindeer] + rest[reindeer]) < duration[reindeer]) {
                distance[reindeer] += speeds[reindeer];
            }
        }
    }

    int max = 0;

    for (int reindeer = 0; reindeer < REINDEER; reindeer++) {
        if (max < distance[reindeer]) {
            max = distance[reindeer];
        }
    }

    cout << max;

    input.close();
    return 0;
}