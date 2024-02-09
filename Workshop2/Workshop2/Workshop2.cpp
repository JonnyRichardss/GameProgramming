// Workshop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameEngine.h"
int main(int argc, char *argv[])
{
    //SDL INIT - i want to move this but I wont for now

    std::cout << "Loop started\n";

    GameEngine e;
    e.StartLoop();
    
    return 0;
}

