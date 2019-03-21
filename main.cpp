#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
   Game * CSO = new Game(640,480,"C-SO! Remix");
    CSO->Gloop();
    return 0;
}

