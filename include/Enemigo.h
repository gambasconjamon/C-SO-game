#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "SprAnimado.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


using namespace std;


class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();
        void updateEnemigo(double x, double y, sf::Time et, sf::Vector2f of);
        void drawEnemigo(sf::RenderWindow* w, double i);
        void setFrame(int f);

        vector<double> getPos();
        void setPos(sf::Vector2f posi);
        sf::Sprite getSprite();
        sf::Rect<float> getColliderTop();
        sf::Rect<float>  getColliderDown();

        void setTouchingFloor(bool t);
        void setTouchingEscalera(bool t);
        void setTouchingTrampolin(bool t);
        void setTouchingPuerta(bool t);
        void setDecidingJump(bool t);
        void setDecidingStairs(bool t);
          void setUltPuerta(int d,sf::Vector2f c);

         bool isTouchingFloor();
         bool isTouchingEscalera();
         bool isTouchingTrampolin();
         bool isTouchingPuerta();
         bool isDecidingJump();
         bool isDecidingStairs();
         int getUltPuerta();
          SprAnimado* getSprAnimado();

         /**IA**/
         int dir;



    protected:

    private:
     SprAnimado* enespr;
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
    bool DecidingJump,DecidingStairs;
    bool decidedj,decideds,sube,baja;

    vector<double> posNow,posBef,vel;
    vector<double> renderPos;

//    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
};

#endif // PLAYER_H
