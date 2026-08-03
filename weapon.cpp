#include "player.h"
#include "weapon.h"

weapon woodenSword(player& hero){
    weapon woodenSword;
    woodenSword.dmg = 10;
    woodenSword.cost = 100;
    return woodenSword;
}