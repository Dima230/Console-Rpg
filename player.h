#pragma once
#include <iostream>

class player
{
public:
    int maxhp = 100;
    int hp = 100;
    int lvl = 1;
    int dmg = 10;
    int gold = 0;
    int exp = 0;
    int steps = 0;
    int kills = 0;
    int currentExpPerLvl = 0;
    int lvlpoint = 0;

    void stepsForward();
};