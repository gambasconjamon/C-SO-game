#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player()
{
    //inicializamos matriz de frames
    frames.resize(4);
    for (int i = 0 ; i < 4 ; i++)
        frames[i].resize(2);

    frames[0][0]=sf::IntRect(0, 0,32, 32);//Frente 0----0
    //La carga de texturas podria ser otra clase
    texture.loadFromFile("resources/Sunny-land-files/PNG/sprites/player/player.png");
    if (!texture.loadFromFile("resources/Sunny-land-files/PNG/sprites/player/player.png"))
    {
        std::cerr << "Error cargando la imagen player.png";
        exit(0);
    }

    sprite.setTexture(texture);
    sprite.setOrigin(28/2,44/2);
    sprite.setTextureRect(frames[0][0]);
    sprite.scale(1.2,1.2);


    renderPos.push_back(0.0);
    renderPos.push_back(0.0);
    posNow.push_back(300.0),posNow.push_back(200.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);


    colliderDown= sf::FloatRect(posNow[0],posNow[1],15,10);

    dir=1;
    frame=0;
    touchingFloor=false;
}


void Player::setFrame(int f)
{
    frame=f;
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

int Player::getUltPuerta()
{
    return ultPuerta;
}



vector<double> Player::getPos()
{

    return posNow;

}
sf::Sprite Player::getSprite()
{
    return sprite;
}

sf::Rect<float>  Player::getColliderTop()
{
    return colliderTop;
}
sf::Rect<float>  Player::getColliderDown()
{
    return colliderDown;
}

void Player::updatePlayer(double velx, double vely, sf::Time et, float of)
{


    posBef=posNow;

    if(isTouchingFloor()||isTouchingEscalera()||isTouchingTrampolin())
    {
        if(isTouchingEscalera())//Escalera
        {
            cout<<"Tocando el suelo o escalera"<<endl;
            vel[1]=vely;
            of=0;

        }

        if(isTouchingFloor())//Suelo
        {
            vel[1]=vely;

        }
        if(isTouchingTrampolin()&&of>0)//Trampolin: Si el offset es = 0, esta a la altura del trampolin, no se activa, solo lo hace cuando cae encime, que of>0
        {
        cout<<"Offset del trampolin: "<<of<<endl;
            vel[1]=-100*4.5;

        }

    }
    else//aire
    {
        //cout<<"En el aire"<<endl;
        if(vel[1]<150)
            vel[1]+=980*et.asSeconds();
    }
    vel[0]=velx;





    if(isTouchingPuerta()){
     posNow[0] = crdPuerta.x;
    posNow[1] = crdPuerta.y;

    }else{
    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds()-of;
    }


}

void Player::drawPlayer(sf::RenderWindow& w, double i)
{

    //sprite.setTextureRect(frames[dir][frame]);
    sprite.setTextureRect(frames[0][0]);
    renderPos[0]=(posNow[0]-posBef[0])*i+posBef[0];
    renderPos[1]=(posNow[1]-posBef[1])*i+posBef[1];
    sprite.setPosition(renderPos[0],renderPos[1]);
    w.draw(sprite);

    colliderDown.top=renderPos[1]+9;
    colliderDown.left=renderPos[0]-8;

    collisionBox.setSize(sf::Vector2f(colliderDown.width,colliderDown.height));
    collisionBox.setFillColor(sf::Color(100, 250, 50));
    collisionBox.setPosition(colliderDown.left,colliderDown.top);
    w.draw(collisionBox);


}

Player::~Player()
{
    //dtor
}
