#pragma once
#include "player.h"
#include <string>

class enemy{
    public:
    std::string name;
    int hp;
    int dmg;
    int giveExp;
    int giveGold;
    int deathCount = 0;
};
enemy createOrc(player& hero);
enemy createSkeleton(player& hero);
enemy createGoblin(player& hero);
enemy enemySpawn(player& hero);