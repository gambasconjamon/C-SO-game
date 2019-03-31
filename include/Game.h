#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Mapa.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace std;


class Game
{
    public:
        Game(int resol_x, int resol_y, string gamename);
        virtual ~Game();
        void Gloop();
        void updateGameState(sf::Time et);
        void handleEvents();
        void handleInputs(sf::Keyboard::Key key, bool isPressed);
        float handleCollision();
        void render(double i);//Se le pasa la interpolacion



    protected:

    private:
    static const sf::Time	timePerFrame;


    ///JUGADOR
    Player *player;
    ///...
    ///MAPA
    Mapa *mapa;
    ///...



    sf::Clock updateClock;
    sf::Time elapsedTime;
    sf::RenderWindow * window;

    bool			eJump;
    bool			eDown;
    bool			eRight;
    bool			eLeft;
    bool            eUp;

    double interpolation;
    double gravity;


};

#endif // GAME_H
