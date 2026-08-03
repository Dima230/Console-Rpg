#include "player.h"
#include "enemy.h"
#include "menu.h"
#include "save.h"
#include <iostream>

int afight(player& hero,enemy& currentEnemy,int& smallPoutionCount){
    std::cout << "Your hp: " << hero.hp << std::endl;
    std::cout << "Enemy: " << currentEnemy.name << std::endl;
    std::cout << "Enemy hp:" << currentEnemy.hp << std::endl;
    currentEnemy.hp -= hero.dmg;
    std::cout << "You hit enemy on " << hero.dmg << std::endl;
    hero.hp -=  currentEnemy.dmg;
    std::cout << "You has been hited on " << currentEnemy.dmg << std::endl;
    std::cout << "Your hp: " << hero.hp << std::endl;
    std::cout << "Enemy hp:" << currentEnemy.hp << std::endl;
    if (currentEnemy.hp <= 0)
    {
        std::cout << "You win!!!" << std::endl;
        hero.gold +=currentEnemy.giveGold;
        hero.exp += currentEnemy.giveExp;
        hero.kills ++;
        currentEnemy.deathCount++;
        std::cout << "You kill for all time: " << hero.kills << std::endl;
        std::cout << "This enemy tipe killd " << currentEnemy.deathCount << std::endl;

        return 0;

    }
    if(hero.hp <=0 ){
        std::cout << "You die skill isue" << std::endl;
        int choice;
        bool gamestart = false;
        do{
        showMenustart();
        std::cin >> choice; 
        switch (choice) {
            case 1:
                std::cout << "New game\n";
                gamestart = true;
                hero.maxhp = 100;
                hero.hp = 100;
                hero.lvl = 1;
                hero.dmg = 10;
                hero.gold = 0;
                hero.exp = 0;
                hero.steps = 0;
                hero.kills = 0;
                hero.currentExpPerLvl = 0;
                hero.lvlpoint = 0;
                    break;
                case 2:
                std::cout << "Load game\n";
                load(hero,smallPoutionCount);
                gamestart = true;
                break;
            case 0:
                std::cout << "exit\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while ((choice != 0) xor (gamestart == true));
    }
    else{
        return 2;
    }
}