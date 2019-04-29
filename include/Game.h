#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Mapa.h"
#include "Enemigo.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics.hpp>

using namespace std;


class Game
{
    public:
        Game(int resol_x, int resol_y, string gamename);
        virtual ~Game();
        int Gloop();
        void drawDataScore();
        void updateGameState(sf::Time et);
        void handleEvents();
        void generateEnemigos();
        void handleInputs(sf::Keyboard::Key key, bool isPressed);
        float handleBalancin();
        sf::Vector2f handleCollision();
        sf::Vector2f  handleECollision(int i);
        void render(double i);//Se le pasa la interpolacion



    protected:

    private:
    sf::Time	timePerFrame;
     float Gscale;
     int time_limit;

    ///JUGADOR
    Player *player;
    ///...
    ///MAPA
    Mapa *mapa;
    ///...
    vector < Enemigo* > enemigos;
    sf::Clock Spawn;
    sf::Clock Death;



    sf::Clock updateClock;
    sf::Clock Timer;

    sf::Time elapsedTime;
    sf::RenderWindow * window;

    int i_score,i_hiscore,i_round,i_time,i_en,i_bal,i_lives;
    sf::Font font;
    sf::Text t_score,t_hiscore,t_round,t_time,t_en,t_bal,t_lives;

    bool			eJump;
    bool			eDown;
    bool			eRight;
    bool			eLeft;
    bool            eUp;

    double interpolation;
    double gravity;


};

#endif // GAME_H
