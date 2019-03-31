#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
   Game * CSO = new Game(640,480,"C-SO! Remix"); //tiles de 20px -32ancho -22alto
    CSO->Gloop();
    return 0;
}

