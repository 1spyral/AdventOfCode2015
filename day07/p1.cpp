// AoC 2015 Day 7 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Command {
public:
    string type;
    string a;
    string b;
    Command(string type, string a, string b) : type(type), a(a), b(b) {}
    Command() {}
};

bool isNumber(string str) {
    bool number = false;
    for (char ch: {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}) {
        if (str[1] == ch || str[0] == ch) {
            number = true;
        }
    }
    return number;
}

int main() {
    ifstream input("input.txt");

    unordered_map<string, unsigned short> values;
    unordered_map<string, Command> commands;

    string word;
    while (getline(input, word, ' ')) {
        if (word == "NOT" || word == "\nNOT") {
            input >> word;
            string a = word;
            input >> word;
            input >> word;
            commands[word] = Command("NOT", a, "");
        } else {
            string first = word;
            input >> word;
            if (word == "->") {
                input >> word;
                if (isNumber(first)) {
                    values[word] = stoi(first);
                } else {
                    commands[word] = Command("A", first.substr(1), "");
                }
            } else {
                string type = word;
                input >> word;
                string b = word;
                input >> word;
                input >> word;
                commands[word] = Command(type, first.substr(1), b);
            }
        }
    }

    while (!commands.empty()) {
        unordered_set<string> used;

        for (const auto& pair: commands) {
            if ((pair.second.type == "A" || pair.second.type == "NOT" || pair.second.type == "LSHIFT" || pair.second.type == "RSHIFT") && values.find(pair.second.a) != values.end()) {
                if (pair.second.type == "A") {
                    values[pair.first] = values[pair.second.a];
                }
                else if (pair.second.type == "NOT") {
                    values[pair.first] = ~values[pair.second.a];
                } else if (pair.second.type == "LSHIFT") {
                    values[pair.first] = values[pair.second.a] << stoi(pair.second.b);
                } else {
                    values[pair.first] = values[pair.second.a] >> stoi(pair.second.b);
                }
                used.insert(pair.first);
            } else if ((values.find(pair.second.a) != values.end() || isNumber(pair.second.a)) && values.find(pair.second.b) != values.end()) {
                if (pair.second.type == "OR") {
                    if (isNumber(pair.second.a)) {
                        values[pair.first] = stoi(pair.second.a) | values[pair.second.b];
                    } else {
                        values[pair.first] = values[pair.second.a] | values[pair.second.b];
                    }
                } else if (pair.second.type == "AND") {
                    if (isNumber(pair.second.a)) {
                        values[pair.first] = stoi(pair.second.a) & values[pair.second.b];
                    } else {
                        values[pair.first] = values[pair.second.a] & values[pair.second.b];
                    }
                }
                used.insert(pair.first);
            }
        }

        for (const string key: used) {
            commands.erase(key);
        }
    }

    cout << values["a"] << endl;

    input.close();
    return 0;
}