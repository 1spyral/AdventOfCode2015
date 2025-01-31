// AoC 2015 Day 21 Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define WEAPONS 5
#define ARMORS 6
#define RINGS 8

#define HP 100

using namespace std;

bool play(int hp, int dmg, int armor, int boss_hp, int boss_dmg, int boss_armor) {
    bool player = true;
    while (hp > 0 && boss_hp > 0) {
        if (player) {
            boss_hp -= max(dmg - boss_armor, 1);
        } else {
            hp -= max(boss_dmg - armor, 1);
        }
        player = !player;
    }
    return hp > 0;
}

int main() {
    ifstream input("input.txt");

    int weapon_dmg[WEAPONS] = { 4, 5, 6, 7, 8 };
    int weapon_cost[WEAPONS] = { 8, 10, 25, 40, 74 };

    int armor_armor[ARMORS] = { 1, 2, 3, 4, 5, 0 };
    int armor_cost[ARMORS] = { 13, 31, 53, 75, 102, 0 };

    int ring_dmg[RINGS] = { 1, 2, 3, 0, 0, 0, 0, 0 };
    int ring_armor[RINGS] = { 0, 0, 0, 1, 2, 3, 0, 0 };
    int ring_cost[RINGS] = { 25, 50, 100, 20, 40 , 80, 0, 0 };

    string word;
    getline(input, word, ' ');
    getline(input, word, ' ');
    getline(input, word);
    int boss_hp = stoi(word);
    getline(input, word, ' ');
    getline(input, word);
    int boss_dmg = stoi(word);
    getline(input, word, ' ');
    getline(input, word);
    int boss_armor = stoi(word);

    int ans = INT_MIN;

    for (int a = 0; a < WEAPONS; a++) {
        for (int b = 0; b < ARMORS; b++) {
            for (int c = 0; c < RINGS - 1; c++) {
                for (int d = c + 1; d < RINGS; d++) {
                    int hp = HP;
                    int dmg = weapon_dmg[a] + ring_dmg[c] + ring_dmg[d];
                    int armor = armor_armor[b] + ring_armor[c] + ring_armor[d];
                    int cost = weapon_cost[a] + armor_cost[b] + ring_cost[c] + ring_cost[d];
                    if (!play(hp, dmg, armor, boss_hp, boss_dmg, boss_armor)) {
                        ans = max(cost, ans);
                    }
                }
            }
        }
    }

    cout << ans;

    input.close();
    return 0;
}