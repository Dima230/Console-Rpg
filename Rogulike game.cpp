#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//==============================
// Функции меню
//==============================
void showMenustart();
void showMenuGame();
void showMenuFight();
void showMenuUpp();
//==============================
// КЛАССЫ
//==============================
class player{
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
    void stepsForward(){
        cout << "You move forward! " << endl;
        steps++;
        cout << "Your steps is " << steps << endl;
    }
};
class enemy{
    public:
    string name;
    int hp;
    int dmg;
    int giveExp;
    int giveGold;
    int deathCount;
};
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
    cout << "Goblin has been spawned! " << endl;
    return createGoblin(hero);
    }

    if (type == 2)
    {
    cout << "Skeleton has been spawned! " << endl;
    return createSkeleton(hero);

    }   

    if (type == 3)
    {
    cout << "Orc has been spawned! " << endl;
    return createOrc(hero);
    }
    }
class weapon{
    public:
    int dmg;
    int durabiliti;
    int cost;
};
weapon woodenSword(){
    weapon woodenSword;
    woodenSword.dmg = 10;
    woodenSword.cost = 100;
    return woodenSword;
}

void showStatistik(const player& hero){
        cout << "Hero xp: " << hero.exp << endl;
        cout << "Hero lvl:" << hero.lvl << endl;
        cout << "Hero freelvlpoint:" << hero.lvlpoint << endl;
        cout << "Hero hp:" << hero.hp << endl;
        cout << "Hero maxhp:" << hero.maxhp;
        cout << "Hero dmg:" << hero.dmg << endl;
        cout << "Hero kills:" << hero.kills << endl;
        cout << "Hero gold:" << hero.gold << endl;
    }
//==============================
// Main
//==============================
int main(){
    srand(time(0));
    vector<string>inventory;
    int choice;
    bool gamestart = false;
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
                break;
            case 0:
                cout << "exit\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while ((choice != 0) xor (gamestart == true));
    int choicegame;
    player hero;
    bool fight = false;
    bool upp = false;
    int choiceUpp;
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
                            
                            cout << "Your hp: " << hero.hp << endl;
                            cout << "Enemy: " << currentEnemy.name << endl;
                            cout << "Enemy hp:" << currentEnemy.hp << endl;
                            currentEnemy.hp -= hero.dmg;
                            cout << "You hit enemy on " << hero.dmg << endl;
                            hero.hp -=  currentEnemy.dmg;
                            cout << "You has been hited on " << currentEnemy.dmg << endl;
                            cout << "Your hp: " << hero.hp << endl;
                            cout << "Enemy hp:" << currentEnemy.hp << endl;
                            if (currentEnemy.hp <= 0)
                            {
                                cout << "You win!!!" << endl;
                                hero.gold +=currentEnemy.giveGold;
                                hero.exp += currentEnemy.giveExp;
                                hero.kills ++;
                                currentEnemy.deathCount++;
                                cout << "You kill for all time: " << hero.kills << endl;
                                cout << "This enemy tipe killd " << currentEnemy.deathCount << endl;
                                fight = false;
                                break;

                            }
                            if(hero.hp <=0 ){
                                cout << "You die skill isue" << endl;
                                fight = false;
                                return 0;
                            }
                            break;
                        }
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                        }
                    } while (fight);
                }
                }
                
                
            case 2:
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
                    hero.currentExpPerLvl = 100 + hero.lvl*3;
                    int freeexp = hero.exp;
                    freeexp -= hero.currentExpPerLvl;
                    if (freeexp >= 0)
                    {   hero.exp -= hero.currentExpPerLvl;
                        hero.lvl++;
                        hero.lvlpoint++;
                        cout << "You lvl up !!! Your exp: " << hero.exp << "Xp per lvl: " << hero.currentExpPerLvl << endl;
                    
                    }
                    else{
                        cout << "Error you have no xp,you xp: " << hero.exp << "Xp per lvl: " << hero.currentExpPerLvl << endl;
                    }
                    break;
                }
                case 2:{
                    cout << "2. Hp up\n";
                    int freepoIint = hero.lvlpoint;
                    freepoIint -= 1;
                    if (freepoIint >=0)
                    {   hero.maxhp += 5;
                        hero.hp += 5;
                        hero.lvlpoint -= 1;
                        cout << "You hp up !!! Your freelvlpoints: " << hero.lvlpoint << endl;
                        cout << "Your hp now: " << hero.hp << endl;

                    }
                    else{
                        cout << "Error you have no free lvlpoints,you xp: " << hero.lvlpoint << endl;
                    }
                    break;
                }
                case 3:{
                    cout << "3. Dmg Up\n";
                    int freepoint = hero.lvlpoint;
                    freepoint -= 1;
                    if (freepoint >=0)
                    {
                        hero.dmg += 3;
                        hero.lvlpoint -= 1;
                        cout << "You dmg up !!! Your freelvlpoints: " << hero.lvlpoint << endl;
                        cout << "Your dmg now: " << hero.dmg << endl;

                    }
                    else{
                        cout << "Error you have no free lvlpoints,you xp: " << hero.lvlpoint << endl;
                    }
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
                break;
            case 5:
                cout << "5. statistic\n";
                showStatistik(hero);
                break;
            case 6:
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
void showMenustart() {
    cout << "\n========== Menu ==========\n";
    cout << "1. New game\n";
    cout << "2. Load game\n";
    cout << "0. exit\n";
    cout << "===========================\n";
    cout << "Your choice: ";
}
void showMenuGame() {
    cout << "\n========== Game Menu ==========\n";
    cout << "1. Step forward\n";
    cout << "2. Shop\n";
    cout << "3. Upgrade\n";
    cout << "4. Weapon\n";
    cout << "5. statistic\n";
    cout << "6. save\n";
    cout << "7. inventory\n";
    cout << "0. exit\n";
    cout << "===========================\n";
    cout << "Your choice: ";
}
void showMenuFight(){
    cout << "\n========== Fight Menu ==========\n";
    cout << "1. Hit\n";
    cout << "2. Shop\n";
    cout << "3. Upgrade\n";
    cout << "4. Weapon\n";
    cout << "===========================\n";
    cout << "Your choice: ";

}
void showMenuUpp(){
    cout << "\n========== Fight Menu ==========\n";
    cout << "1. Lvl up curren exp\n";
    cout << "2. Hp up\n";
    cout << "3. Dmg Up\n";
    cout << "0. exit\n";
    cout << "===========================\n";
    cout << "Your choice: ";
}