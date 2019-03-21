#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player(): ps()
{
    //inicializamos matriz de frames
    frames.resize(4);
    for (int i = 0 ; i < 4 ; i++)
        frames[i].resize(2);

    frames[0][0]=sf::IntRect(10, 4,28, 44);//Frente 0----0
    frames[0][1]=sf::IntRect(58, 6,28, 42);//Frente 1----1
    frames[1][0]=sf::IntRect(8,146,32, 46);//Detras 0----2
    frames[1][1]=sf::IntRect(56, 148,32, 44);//Detras 1--3
    frames[2][0]=sf::IntRect(6, 98,40, 46);//SideR 0-----4
    frames[2][1]=sf::IntRect(54, 100,40, 44);//SideR 1---5
    frames[3][0]=sf::IntRect(2, 50,40, 46);//SideL 0-----6
    frames[3][1]=sf::IntRect(50, 52,40, 44);//SideL 1----7

    //La carga de texturas podria ser otra clase
    texture.loadFromFile("resources/sp_alien_texture.png");
    if (!texture.loadFromFile("resources/sp_alien_texture.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    sprite.setTexture(texture);
    sprite.setOrigin(28/2,44/2);
    sprite.setTextureRect(frames[0][0]);
    sprite.scale(1.5,1.5);
    renderPos.push_back(0.0);
    renderPos.push_back(0.0);


    dir=1;
    frame=0;
}


void Player::setFrame(int f)
{
    frame=f;
}
void Player::setDir(int d,int f)
{
    if(d>=0&&f>=0)
    {
        dir=d;
        frame=f;
    }
}

void Player::updatePlayer(double velx, double vely, sf::Time et)
{

    ps.setVel(velx,vely);//Cambia el booleano para quitar aceleracion o ponerla
    ps.updateState(et);

}

void Player::drawPlayer(sf::RenderWindow& w, double i)
{

    sprite.setTextureRect(frames[dir][frame]);

    renderPos[0]=(ps.getPosNow()[0]-ps.getPosBef()[0])*i+ps.getPosBef()[0];
    renderPos[1]=(ps.getPosNow()[1]-ps.getPosBef()[1])*i+ps.getPosBef()[1];
    sprite.setPosition(renderPos[0],renderPos[1]);
    w.draw(sprite);

}

Player::~Player()
{
    //dtor
}
