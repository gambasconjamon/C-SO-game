#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
   Game * CSO = new Game(640,480,"C-SO! Remix"); //tiles de 20px -32ancho -22alto
    if(CSO->Gloop()!=0)
    cout<<"-----------"<<endl<<"Has perdido"<<endl<<"-----------------";
    else{
    cout<<"-----------"<<endl<<"Has ganado"<<endl<<"-----------------";
    }

    return 0;
}

