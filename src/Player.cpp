#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player()
{


    comy = new SprAnimado("resources/Sunny-land-files/PNG/sprites/player/player.png",8,1.2,true);
    comy->setSpeed(0.1);

    comy->addFrame(sf::IntRect(5, 10,18,22),0);//dcha
    comy->addFrame(sf::IntRect(38, 10,18,22),0);//dcha
    comy->addFrame(sf::IntRect(71, 9,17,22),0);//dcha
    comy->addFrame(sf::IntRect(102, 10,18,22),0);//dcha
    comy->addFrame(sf::IntRect(133, 10,18,22),0);//dcha
    comy->addFrame(sf::IntRect(164, 9,20,22),0);//dcha

    comy->addFrame(sf::IntRect(3, 41,23,21),1);//sdcha
    comy->addFrame(sf::IntRect(36, 39,21,22),1);//sdcha

    comy->addFrame(sf::IntRect(166, 165,18,22),2);//izda
    comy->addFrame(sf::IntRect(133, 165,18,22),2);//izda
    comy->addFrame(sf::IntRect(101, 164,17,22),2);//izda
    comy->addFrame(sf::IntRect(69, 165,18,22),2);//izda
    comy->addFrame(sf::IntRect(38, 165,18,22),2);//izda
    comy->addFrame(sf::IntRect(5, 164,20,22),2);//izda

    comy->addFrame(sf::IntRect(100, 41,23,21),3);//sizda
    comy->addFrame(sf::IntRect(69, 39,21,22),3);//sizda

    comy->addFrame(sf::IntRect(4, 75,19,21),4);//idle
    comy->addFrame(sf::IntRect(37, 74,18,22),4);//idle
    comy->addFrame(sf::IntRect(69, 75,19,21),4);//idle
    comy->addFrame(sf::IntRect(98, 76,21,20),4);//idle

    comy->addFrame(sf::IntRect(4, 101,23,26),5);//dead
    comy->addFrame(sf::IntRect(34, 102,25,25),5);//dead

    comy->addFrame(sf::IntRect(7, 135,19,23),6);//arr
    comy->addFrame(sf::IntRect(38, 135,19,24),6);//arr
    comy->addFrame(sf::IntRect(70, 134,19,24),6);//arr


    comy->addFrame(sf::IntRect(70, 134,19,24),7);//ab
    comy->addFrame(sf::IntRect(38, 135,19,24),7);//ab
    comy->addFrame(sf::IntRect(7, 135,19,23),7);//ab



    //renderPos.push_back(17.0);
    //renderPos.push_back(300.0);
    posNow.push_back(580.0),posNow.push_back(440.0);
    posBef=posNow;
    vel.push_back(0.0),vel.push_back(0.0);


    colliderDown= sf::FloatRect(posNow[0],posNow[1],15,10);
    colliderTop= sf::FloatRect(posNow[0],posNow[1],15,10);

    dir=1;
    frame=0;
    touchingFloor=false;
    dead=false;
}


void Player::setTouchingFloor(bool t)
{

    touchingFloor=t;
}
void Player::setTouchingEscalera(bool t)
{
    touchingEscalera=t;
}
void Player::setTouchingTrampolin(bool t)
{
    touchingTrampolin=t;
}
void Player::setTouchingPuerta(bool t)
{
    touchingPuerta=t;
}
void Player::setDead(bool t)
{
    dead=t;
}
void Player::setUltPuerta(int d, sf::Vector2f c)
{
    crdPuerta=c;
    ultPuerta=d;
}

bool Player::isTouchingFloor()
{
    return touchingFloor;

}
bool Player::isTouchingEscalera()
{
    return touchingEscalera;
}
bool Player::isTouchingTrampolin()
{
    return touchingTrampolin;
}
bool Player::isTouchingPuerta()
{
    return touchingPuerta;
}
bool Player::isDead()
{
    return dead;
}

int Player::getUltPuerta()
{
    return ultPuerta;
}



vector<double> Player::getPos()
{

    return posNow;

}
void Player::setPos(sf::Vector2f posi)
{
    posNow[0]=posi.x;
    posNow[1]=posi.y;
    posBef=posNow;

}
SprAnimado* Player::getSprAnimado()
{
    return comy;
}

sf::Rect<float>  Player::getColliderTop()
{
    return colliderTop;
}
sf::Rect<float>  Player::getColliderDown()
{
    return colliderDown;
}

void Player::updatePlayer(double velx, double vely, sf::Time et,sf::Vector2f of)
{


    posBef=posNow;

    if(velx>0)
    comy->setAnimation(0);
    else if(velx<0)
    comy->setAnimation(2);

    if(velx==0)
    comy->setAnimation(4);


    /**MAP DELIMITER**/
    if((velx<0)&&posNow[0]<16)
    {
        velx=0;
        dir=1;
    }
    if((velx>0)&&posNow[0]>624)
    {
        velx=0;
        dir=0;
    }
    /**MAP DELIMITER**/

    if(of.x<7&&of.x>0)
    {
        cout<<"pared izquierda?"<<endl;
        velx+=200;
    }
    if(of.x>-22&&of.x<-10)
    {
        cout<<"pared derecha?"<<endl;
        velx-=200;
    }
    if(isTouchingFloor()||isTouchingEscalera()||isTouchingTrampolin())
    {
        if(isTouchingEscalera())//Escalera
        {

            vel[1]=vely;
            of.y=0;
            if(vely<0)
            comy->setAnimation(6);
            else
            comy->setAnimation(7);


        }

        if(isTouchingFloor())//Suelo
        {
            vel[1]=vely;

        }
        if(isTouchingTrampolin()&&of.y>0)//Trampolin: Si el offset es = 0, esta a la altura del trampolin, no se activa, solo lo hace cuando cae encime, que of>0
        {

            vel[1]=-100*4.5;

        }

    }
    else//aire
    {
        //cout<<"En el aire"<<endl;
         if(velx>0)
    comy->setAnimation(1);
    else if(velx<0)
    comy->setAnimation(3);


        if(vel[1]<130)
            vel[1]+=980*et.asSeconds();

        if(vel[1]>129)///Esto simula lo de que no puede avanzar mucho en el aire
            velx=0;


    }
    vel[0]=velx;





    if(isTouchingPuerta())
    {

        if(of.x<0)
            posNow[0] = crdPuerta.x+32;
        else
            posNow[0] = crdPuerta.x-32;


        posNow[1] = crdPuerta.y;
        posBef=posNow;

    }
    else
    {
        posNow[0] += vel[0]*et.asSeconds();
        posNow[1] += vel[1]*et.asSeconds()-of.y;
    }

if(dead){
comy->setAnimation(5);
}
}

void Player::drawPlayer(sf::RenderWindow* w, double i)
{

    //sprite.setTextureRect(frames[dir][frame]);
    /*sprite.setTextureRect(frames[0][0]);
    renderPos[0]=(posNow[0]-posBef[0])*i+posBef[0];
    renderPos[1]=(posNow[1]-posBef[1])*i+posBef[1];
    sprite.setPosition(renderPos[0],renderPos[1]);*/
    comy->drawSprAnimado(posBef,posNow,w,i);
   // w.draw(sprite);

    colliderDown.top=comy->getRenderPos()[1]+9;
    colliderDown.left=comy->getRenderPos()[0]-8;
    colliderTop.top=comy->getRenderPos()[1]-16;
    colliderTop.left=comy->getRenderPos()[0]-8;

    /*collisionBox.setSize(sf::Vector2f(colliderDown.width,colliderDown.height));
    collisionBox.setFillColor(sf::Color(100, 250, 50));
    collisionBox.setPosition(colliderDown.left,colliderDown.top);
    w->draw(collisionBox);
    collisionBox.setPosition(colliderTop.left,colliderTop.top);
    w->draw(collisionBox);*/


}

Player::~Player()
{
    //dtor
}
