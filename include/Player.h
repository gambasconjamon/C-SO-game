#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "physicsState.h"
using namespace std;


class Player
{
    public:
        Player();
        virtual ~Player();
        void updatePlayer(double velx, double vely, sf::Time et);
        void drawPlayer(sf::RenderWindow& w, double i);
        void setFrame(int f);
        void setDir(int d,int f);

    protected:

    private:
    sf::Texture  texture;
    sf::Sprite sprite;
    vector<double> renderPos;
    physicsState ps;

    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
};

#endif // PLAYER_H
