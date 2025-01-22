// AoC 2015 Day 6 Problem 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    short lights[1000][1000] = { 0 };

    int command;
    int x1;
    int y1;
    int x2;
    int y2;

    string word;
    while (input >> word) {
        if (word == "toggle") {
            command = 0;
        } else {
            input >> word;
            if (word == "off") {
                command = 1;
            } else {
                command = 2;
            }
        }
        getline(input, word, ',');
        x1 = stoi(word);
        input >> word;
        y1 = stoi(word);
        input >> word;
        getline(input, word, ',');
        x2 = stoi(word);
        getline(input, word);
        y2 = stoi(word);
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (command == 0) {
                    lights[x][y] += 2;
                } else if (command == 1) {
                    if (lights[x][y] > 0) {
                        lights[x][y]--;
                    }
                } else {
                    lights[x][y]++;
                }
            }
        }
    }

    int ans = 0;

    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            ans += lights[x][y];
        }
    }

    cout << ans;

    input.close();
    return 0;
}