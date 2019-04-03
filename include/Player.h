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
        void updatePlayer(double velx, double vely, sf::Time et, float of);
        void drawPlayer(sf::RenderWindow& w, double i);
        void setFrame(int f);

        vector<double> getPos();
        sf::Sprite getSprite();
        sf::Rect<float> getColliderTop();
        sf::Rect<float>  getColliderDown();

        void setTouchingFloor(bool t);
         void setTouchingEscalera(bool t);
          void setTouchingTrampolin(bool t);

         bool isTouchingFloor();
         bool isTouchingEscalera();
         bool isTouchingTrampolin();



    protected:

    private:
    sf::Texture  texture;
    sf::Sprite sprite;
    sf::Rect<float>  colliderTop;
    sf::Rect<float>  colliderDown;
    sf::RectangleShape collisionBox;


    bool touchingFloor;
    bool touchingEscalera;
    bool touchingTrampolin;
    bool touchingLeft;
    bool touchingRight;

    vector<double> posNow,posBef,vel;
    vector<double> renderPos;

    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
};

#endif // PLAYER_H
