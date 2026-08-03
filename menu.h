#pragma once
#include "player.h"
void showMenustart();
void showMenuGame();
void showMenuFight();
void showMenuUpp();
void showMenuShop();
void showMenWeapon();
void lvlup(player& hero);
void hpup(player& hero);
void dmgup(player& hero);
void buy(player& hero,int& smallPoutionCount);
void showStatistik(const player& hero);