#ifndef PLAYER_H
#define PLAYER_H
#include "SprAnimado.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


using namespace std;


class Player
{
    public:
        Player();
        virtual ~Player();
        void updatePlayer(double velx, double vely, sf::Time et, sf::Vector2f of);
        void drawPlayer(sf::RenderWindow* w, double i);


        vector<double> getPos();
         void setPos(sf::Vector2f posi);
        SprAnimado* getSprAnimado();
        sf::Rect<float> getColliderTop();
        sf::Rect<float>  getColliderDown();

        void setTouchingFloor(bool t);
        void setTouchingEscalera(bool t);
        void setTouchingTrampolin(bool t);
        void setTouchingPuerta(bool t);
        void setDead(bool t);
          void setUltPuerta(int d,sf::Vector2f c);

         bool isTouchingFloor();
         bool isDead();
         bool isTouchingEscalera();
         bool isTouchingTrampolin();
         bool isTouchingPuerta();
         int getUltPuerta();



    protected:

    private:
    SprAnimado* comy;
    sf::Rect<float>  colliderTop;
    sf::Rect<float>  colliderDown;
    sf::RectangleShape collisionBox;

    int ultPuerta;
    sf::Vector2f crdPuerta;

    bool touchingFloor;
    bool touchingEscalera;
    bool touchingTrampolin;
    bool touchingPuerta;
    bool touchingLeft;
    bool touchingRight;
    bool dead;

    vector<double> posNow,posBef,vel;
    vector<double> renderPos;

    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
};

#endif // PLAYER_H
