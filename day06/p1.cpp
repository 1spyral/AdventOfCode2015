// AoC 2015 Day 6 Problem 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    bool lights[1000][1000] = {false};

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
                    lights[x][y] = !lights[x][y];
                } else if (command == 1) {
                    lights[x][y] = false;
                } else {
                    lights[x][y] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            if (lights[x][y]) {
                ans++;
            }
        }
    }

    cout << ans;

    input.close();
    return 0;
}