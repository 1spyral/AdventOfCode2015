// AoC 2015 Day 14 Problem 2

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

    int points[REINDEER] = {0};

    for (int i = 0; i < TIME; i++) {
        int furthest = 0;
        for (int reindeer = 0; reindeer < REINDEER; reindeer++) {
            if (i % (duration[reindeer] + rest[reindeer]) < duration[reindeer]) {
                distance[reindeer] += speeds[reindeer];
            }
            if (furthest < distance[reindeer]) {
                furthest = distance[reindeer];
            }
        }
        for (int reindeer = 0; reindeer < REINDEER; reindeer++) {
            if (furthest == distance[reindeer]) {
                points[reindeer]++;
            }
        } 
    }

    int max = 0;

    for (int reindeer = 0; reindeer < REINDEER; reindeer++) {
        if (max < points[reindeer]) {
            max = points[reindeer];
        }
    }

    cout << max;

    input.close();
    return 0;
}