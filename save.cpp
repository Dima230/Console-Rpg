#include "Player.h"
#include "save.h"
#include <iostream>
#include <fstream>

void save(const player& hero,const int& countPotion){
    std::ofstream saved("save.txt");
    if (!saved)
    {
        std::cout << "Error saved.";
        return;
    }
    saved << hero.exp << std::endl;
    saved << hero.dmg << std::endl;
    saved << hero.lvl << std::endl;
    saved << hero.lvlpoint << std::endl;
    saved << hero.hp << std::endl;
    saved << hero.maxhp << std::endl;
    saved << hero.steps << std::endl;
    saved << hero.gold << std::endl;
    saved << hero.kills << std::endl;
    saved << countPotion << std::endl;
    std::cout << "SAVED!!" << std::endl;
    saved.close();
}

void load(player& hero,int& countPotion){
    std::ifstream saved("save.txt");
    if (!saved)
    {
        std::cout << "Error loaded.";
        return;
    }  
    saved >> hero.exp;
    saved >> hero.dmg;
    saved >> hero.lvl;
    saved >> hero.lvlpoint ;
    saved >> hero.hp;
    saved >> hero.maxhp;
    saved >> hero.steps;
    saved >> hero.gold;
    saved >> hero.kills;
    saved >> countPotion;
}