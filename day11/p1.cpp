// AoC 2015 Day 11 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<char> alpha = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int idx(char ch) {
    auto it = find(alpha.begin(), alpha.end(), ch);
    return distance(alpha.begin(), it);
}

bool valid(string text) {
    bool stair = false;
    bool pair1 = false;
    char pair1letter;
    bool pair2 = false;

    int a = 26;
    int b = 26;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'i' || text[i] == 'o' || text[i] == 'l') {
            return false;
        }
        if (idx(text[i]) == b) {
            if (!pair1) {
                pair1 = true;
                pair1letter = text[i];
            } else if (pair1 && pair1letter != text[i]) {
                pair2 = true;
            }
        }
        if (idx(text[i]) == b + 1 && b == a + 1) {
            stair = true;
        }
        a = b;
        b = idx(text[i]);
    }

    return pair1 && pair2 && stair;
}

void getNext(string &text) {
    int index = text.length() - 1;
    while (true) {
        int nextNum = idx(text[index]) + 1;
        if (nextNum == 26) {
            text[index] = 'a';
            index--;
        } else {
            text[index] = alpha[nextNum];
            return;
        }
    }
}

int main() {
    ifstream input("input.txt");

    string text;
    getline(input, text);
    int hi;
    while (!valid(text)) {
       getNext(text);
    }

    cout << text;

    input.close();
    return 0;
}