// AoC 2015 Day 22 Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define HP 50
#define MANA 500

#define MISSILE 53
#define DRAIN 73
#define SHIELD 113
#define POISON 173
#define RECHARGE 229

using namespace std;

int ans = INT_MAX;

void play(int boss_hp, int boss_dmg, int hp = HP, int mana = MANA, bool turn = true, int cost = 0, int shield = 0, int poison = 0, int recharge = 0) {
    if (poison > 0) {
        boss_hp -= 3;
    }
    if (recharge > 0) {
        mana += 101;
    }
    if (boss_hp <= 0) {
        ans = min(ans, cost);
        return;
    }
    if (turn) {
        if (mana >= RECHARGE && recharge <= 1) {
            play(boss_hp, boss_dmg, hp, mana - RECHARGE, false, cost + RECHARGE, shield - 1, poison - 1, 5);
        }
        if (mana >= POISON && poison <= 1) {
            play(boss_hp, boss_dmg, hp, mana - POISON, false, cost + POISON, shield - 1, 6, recharge - 1);
        }
        if (mana >= SHIELD && shield <= 1) {
            play(boss_hp, boss_dmg, hp, mana - SHIELD, false, cost + SHIELD, 6, poison - 1, recharge - 1);
        }
        if (mana >= DRAIN) {
            if (boss_hp - 2 <= 0) {
                ans = min(ans, cost + DRAIN);
                return;
            }
            play(boss_hp - 2, boss_dmg, hp + 2, mana - DRAIN, false, cost + DRAIN, shield - 1, poison - 1, recharge - 1);
        }
        if (mana >= MISSILE) {
            boss_hp -= 4;
            if (boss_hp <= 0) {
                ans = min(ans, cost + MISSILE);
                return;
            }
            play(boss_hp, boss_dmg, hp, mana - MISSILE, false, cost + MISSILE, shield - 1, poison - 1, recharge - 1);
        }
    } else {
        int dmg = boss_dmg;
        if (shield > 0) {
            dmg -= 7;
        }
        hp -= max(dmg, 1);
        if (hp <= 0) {
            return;
        }
        play(boss_hp, boss_dmg, hp, mana, true, cost, shield - 1, poison - 1, recharge - 1);
    }
}

int main() {
    ifstream input("input.txt");

    string word;
    getline(input, word, ' ');
    getline(input, word, ' ');
    getline(input, word);
    int boss_hp = stoi(word);
    getline(input, word, ' ');
    getline(input, word);
    int boss_dmg = stoi(word);

    play(boss_hp, boss_dmg);

    cout << ans;

    input.close();
    return 0;
}
