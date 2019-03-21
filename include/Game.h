#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Level.h"
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
        void render(double i);//Se le pasa la interpolacion


    protected:

    private:
     /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/
    Player *player;
    Level *lvl;

    sf::Clock updateClock;
    sf::Time elapsedTime;

    sf::RenderWindow * window;

    bool			eUp;
    bool			eDown;
    bool			eRight;
    bool			eLeft;

    double interpolation;


};

#endif // GAME_H
