#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;


class Player
{
    public:
        Player();
        virtual ~Player();
        void updatePlayer(double velx, double vely, sf::Time et);
        void drawPlayer(sf::RenderWindow& w, double i);
        void setFrame(int f);
        vector<double> getPos();
        sf::Sprite getSprite();
        void setTouchingFloor(bool t);

        void setDir(int d,int f);

    protected:

    private:
    sf::Texture  texture;
    sf::Sprite sprite;


    bool touchingFloor;
    vector<double> posNow,posBef,vel;
    vector<double> renderPos;

    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
};

#endif // PLAYER_H
