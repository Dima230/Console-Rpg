#include "menu.h"
#include <iostream>

void showMenustart() {
    std::cout << "\n========== Menu ==========\n";
    std::cout << "1. New game\n";
    std::cout << "2. Load game\n";
    std::cout << "0. exit\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";
}
void showMenuGame() {
    std::cout << "\n========== Game Menu ==========\n";
    std::cout << "1. Step forward\n";
    std::cout << "2. Shop\n";
    std::cout << "3. Upgrade\n";
    std::cout << "4. Weapon\n";
    std::cout << "5. statistic\n";
    std::cout << "6. save\n";
    std::cout << "7. inventory\n";
    std::cout << "0. exit\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";
}
void showMenuFight(){
    std::cout << "\n========== Fight Menu ==========\n";
    std::cout << "1. Hit\n";
    std::cout << "2. heal\n";
    std::cout << "3. Upgrade\n";
    std::cout << "4. Weapon\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";

}
void showMenuUpp(){
    std::cout << "\n========== Upgrade Menu ==========\n";
    std::cout << "1. Lvl up curren exp\n";
    std::cout << "2. Hp up\n";
    std::cout << "3. Dmg Up\n";
    std::cout << "0. exit\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";
}
void showMenuShop(){
    std::cout << "\n========== Shop Menu ==========\n";
    std::cout << "1. heal Potion 25 gold cost\n";
    std::cout << "0. exit\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";
}
void showMenWeapon(){
    std::cout << "\n========== Weapon Menu ==========\n";
    std::cout << "1. wooden sword\n";
    std::cout << "0. exit\n";
    std::cout << "===========================\n";
    std::cout << "Your choice: ";
}
void lvlup(player& hero){
    hero.currentExpPerLvl = 100 + hero.lvl*3;
    int freeexp = hero.exp;
    freeexp -= hero.currentExpPerLvl;
    if (freeexp >= 0)
    {   hero.exp -= hero.currentExpPerLvl;
        hero.lvl++;
        hero.lvlpoint++;
        std::cout << "You lvl up !!! Your exp: " << hero.exp << "Xp per lvl: " << hero.currentExpPerLvl << std::endl;
    
    }
    else{
        std::cout << "Error you have no xp,you xp: " << hero.exp << "Xp per lvl: " << hero.currentExpPerLvl << std::endl;
    }
}
void hpup(player& hero){
    int freepoIint = hero.lvlpoint;
   freepoIint -= 1;
   if (freepoIint >=0)
   {   hero.maxhp += 5;
       hero.hp += 5;
       hero.lvlpoint -= 1;
       std::cout << "You hp up !!! Your freelvlpoints: " << hero.lvlpoint << std::endl;
       std::cout << "Your hp now: " << hero.hp << std::endl;

   }
   else{
       std::cout << "Error you have no free lvlpoints,you xp: " << hero.lvlpoint <<std::endl;
   }
}
void dmgup(player& hero){
    int freepoint = hero.lvlpoint;
    freepoint -= 1;
    if (freepoint >=0)
    {
        hero.dmg += 3;
        hero.lvlpoint -= 1;
        std::cout << "You dmg up !!! Your freelvlpoints: " << hero.lvlpoint << std::endl;
        std::cout << "Your dmg now: " << hero.dmg << std::endl;

    }
    else{
        std::cout << "Error you have no free lvlpoints,you xp: " << hero.lvlpoint << std::endl;
    }
}


void buy(player& hero,int& smallPoutionCount){
    int choice;
    
    do
    {
        showMenuShop();
        std::cin >> choice;
        switch (choice)
        {
        case 1:{
            std::cout << "1. heal Potion 25 gold cost\n";
            if (hero.gold >= 25)
            {
                smallPoutionCount += 1;
                std::cout << "You have potions: " << smallPoutionCount << std::endl;
                std::cout << "You buy small heal poution" << std::endl;
                hero.gold -= 25;
                break;
            }
            else{
                std::cout << "Ti nishieb\n";
                break;
            }
            break;
        }
        case 0:
            break;
        default:
                std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice !=0);
    
}
void showStatistik(const player& hero){
        std::cout << "Hero xp: " << hero.exp << std::endl;
        std::cout << "Hero lvl:" << hero.lvl << std::endl;
        std::cout << "Hero freelvlpoint:" << hero.lvlpoint << std::endl;
        std::cout << "Hero hp:" << hero.hp << std::endl;
        std::cout << "Hero maxhp:" << hero.maxhp << std::endl;
        std::cout << "Hero dmg:" << hero.dmg << std::endl;
        std::cout << "Hero kills:" << hero.kills << std::endl;
        std::cout << "Hero gold:" << hero.gold << std::endl;
    }