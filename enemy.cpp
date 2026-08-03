#include "player.h"
#include "enemy.h"
#include <string>
#include <iostream>
#include <cstdlib>

enemy createOrc(player& hero)
    {
    enemy Orc;
    Orc.name = "Orc";
    Orc.hp = 40 + hero.steps;
    Orc.dmg = 10 + hero.steps/2;
    Orc.giveExp = 25;
    Orc.giveGold = 10;
    Orc.deathCount = 0;

    return Orc;
    }
enemy createSkeleton(player& hero)
    {
    enemy Skeleton;

    Skeleton.name = "Skeleton";
    Skeleton.hp = 20 + hero.steps;
    Skeleton.dmg = 20 + hero.steps;
    Skeleton.giveExp = 20;
    Skeleton.giveGold = 5;
    Skeleton.deathCount = 0;
    return Skeleton;
    }
    enemy createGoblin(player& hero)
    {
    enemy Goblin;

    Goblin.name = "Goblin";
    Goblin.hp = 40 + hero.steps;
    Goblin.dmg = 7 + hero.steps;
    Goblin.giveExp = 15;
    Goblin.giveGold = 0;
    Goblin.deathCount = 0;
    return Goblin;
    }
    enemy enemySpawn(player& hero){
    int type = rand() % 3 + 1;
    if (type == 1)
    {
    std::cout << "Goblin has been spawned! " << std::endl;
    return createGoblin(hero);
    }

    else if (type == 2)
    {
        std::cout << "Skeleton has been spawned! " << std::endl;
    return createSkeleton(hero);
    }

    else
    {
    std::cout << "Orc has been spawned! " << std::endl;
    return createOrc(hero);
    }
    }