// AoC 2015 Day 10 Problem 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lookandsay(string input) {
    int count = 1;
    char prev = input[0];
    
    string out = "";
    
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == prev) {
            count++;
        } else {
            out += to_string(count);
            out += prev;
            count = 1;
            prev = input[i];
            }
    }
    
    out += to_string(count);
    out += prev;
    
    return out;
}

int main() {
    string str = "1113122113";
    
    for (int i = 0; i < 50; i++) {
        str = lookandsay(str);
    }
    
    cout << str.length();

    return 0;
}
