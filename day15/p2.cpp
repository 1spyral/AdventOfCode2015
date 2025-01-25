// AoC 2015 Day 15 Problem 2

#include <iostream>
#include <fstream>
#include <string>

#define INGREDIENTS 4
#define TEASPOONS 100
#define CALORIES 500

using namespace std;

int capacity[INGREDIENTS];
int durability[INGREDIENTS];
int flavor[INGREDIENTS];
int texture[INGREDIENTS];
int calories[INGREDIENTS];

int ans = 0;

void bake(int index = 0, int remaining = TEASPOONS, int c = 0, int d = 0, int f = 0, int t = 0, int ca = 0) {
    if (index == INGREDIENTS - 1) {
        c += remaining * capacity[index];
        d += remaining * durability[index];
        f += remaining * flavor[index];
        t += remaining * texture[index];
        ca += remaining * calories[index];

        int score = 0;

        if (c < 0 || d < 0 || f < 0 || t < 0 || ca != CALORIES) {
            score = 0;
        } else {
            score = c * d * f * t;
        }
        if (score > ans) {
            ans = score;
        }
    } else {
        for (int i = 0; i <= remaining; i++) {
            bake(index + 1, remaining - i, c + i * capacity[index], d + i * durability[index], f + i * flavor[index], t + i * texture[index], ca + i * calories[index]);
        }
    }
}

int main() {
    ifstream input("input.txt");


    int index = 0;

    string word;
    while (getline(input, word, ' ')) {
        getline(input, word, ' ');
        getline(input, word, ',');
        capacity[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ',');
        durability[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ',');
        flavor[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word, ',');
        texture[index] = stoi(word);
        getline(input, word, ' ');
        getline(input, word, ' ');
        getline(input, word);
        calories[index] = stoi(word);
        index++;
    }

    bake();

    cout << ans;

    input.close();
    return 0;
}