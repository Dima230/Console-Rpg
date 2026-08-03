#include <iostream>
#include "player.h"
#include "enemy.h"
#include "menu.h"
#include "save.h"
#include "fight.h"
#include "weapon.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//==============================
// КЛАССЫв
//==============================
void smallHealhp(player& hero,int& countpoution){
    if (hero.hp < hero.maxhp and countpoution > 0)
    {   
        countpoution -= 1;
        hero.hp += 35;
        if (hero.hp > hero.maxhp)
        {
            hero.hp = hero.maxhp;
        }
        cout << "You has been heald " <<  endl;
        cout << "Count Potion: " << countpoution << endl;
        cout << "Your hp: " << hero.hp << endl;
    }
    else{
        cout << "You have max hp!!" << endl;
    }
}   




//==============================
// Функции
//==============================


void weaponff(player& hero,bool& ekvip);
//==============================
// Main
//==============================
int main(){
    srand(time(0));
    vector<string>inventory;
    int choice;
    player hero;
    bool gamestart = false;
    int choicegame;
    bool fight = false;
    bool upp = false;
    int choiceUpp;
    int smallPoutionCount = 0;
    bool ekvip = false;
    do{
        showMenustart();
        cin >> choice; 
        switch (choice) {
            case 1:
                cout << "New game\n";
                gamestart = true;
                break;
            case 2:
                cout << "Load game\n";
                load(hero,smallPoutionCount);
                gamestart = true;
                break;
            case 0:
                cout << "exit\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while ((choice != 0) xor (gamestart == true));
    if(gamestart){
        do
        {
            showMenuGame();
            cin >> choicegame;
            switch (choicegame)
            {
            case 1:{
                cout << "1. Step forward\n";
                hero.stepsForward();
                enemy currentEnemy = enemySpawn(hero);
                fight = true;
                int choicefight;
                if (fight)
                {
                    do
                    {showMenuFight();
                        cin >> choicefight;
                        switch (choicefight)
                        {
                        case 1:{
                            cout << "Hit\n";
                            int result = afight(hero,currentEnemy,smallPoutionCount);
                            if(result == 1){
                                return 0;
                            }
                            if (result == 0)
                            {
                                fight = false;
                                break;
                            }
                            break;
                        }
                        case 2:
                            smallHealhp(hero,smallPoutionCount);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                        }
                    } while (fight);
                } 
                break;
                }
            case 2:
                cout << "Shop\n";
                buy(hero,smallPoutionCount);

                break;

            case 3:
                cout << "3. Upgrade\n";
                upp = true;
                do
                {
                showMenuUpp();
                cin >> choiceUpp;
                switch (choiceUpp)
                {
                case 1:{
                    cout << "1. Lvl up curren exp\n";
                    lvlup(hero);
                    break;
                }
                case 2:{
                    cout << "2. Hp up\n";
                    hpup(hero);
                    break;
                }
                case 3:{
                    cout << "3. Dmg Up\n";
                    dmgup(hero);
                    break;
                }
                case 0:
                cout << "0. exit\n";
                default:
                    break;
                }
                } while (choice != 0 xor upp);
                break;
            case 4:
                cout << "4. weapon\n";
                weaponff(hero,ekvip);

                break;
            case 5:
                cout << "5. statistic\n";
                showStatistik(hero);
                break;
            case 6:
                cout << "6. save\n";
                    save(hero,smallPoutionCount);
                break;
            case 7:
                break;
            case 0:
                break;
            
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choicegame !=0);
    }
    return 0;
}
//==============================
// Main over
//==============================

void weaponff(player& hero,bool& ekvip){
    int choice;
    do
    {
        showMenWeapon();
        cin >> choice;
        switch (choice)
        {
        case 1:{
            cout << "1. wooden sword\n";
            weapon wood = woodenSword(hero);
            if (!ekvip)
            {
                hero.dmg += wood.dmg;
                ekvip = true;
                break;
            }
            if (ekvip)
            {
                cout << "You ekvipt him befor!!" << endl;
                break;
            }
            
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        /* code */
    } while (choice != 0);
    
}