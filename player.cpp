#include "Player.h"


void player::stepsForward()
{
    std::cout << "You move forward!\n";
    steps++;
    std::cout << "Your steps is " << steps << std::endl;
}