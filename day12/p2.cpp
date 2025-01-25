// Shoutout to: https://github.com/nlohmann/json

// AoC 2015 Day 12 Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int handle(json item) {
    int sum = 0;
    int exclude = false;
    if (item.is_array()) {
        for (const auto& value: item) {
            if (value.is_object() || value.is_array()) {
                sum += handle(value);
            } else if (value.is_number_integer()) {
                sum += (int)value;
            }
        }
    } else {
        for (auto& [key, value] : item.items()) {
            if (value == "red") {
                exclude = true;
            } else if (value.is_number_integer()) {
                sum += (int)value;
            } else if (value.is_object() || value.is_array()) {
                sum += handle(value);
            }
        }
    }
    if (exclude) {
        return 0;
    } else {
        return sum;
    }
}

int main() {
    ifstream input("input.txt");

    json data = json::parse(input);

    cout << handle(data);

    input.close();
    return 0;
}