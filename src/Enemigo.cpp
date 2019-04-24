#include "Enemigo.h"
#include <SFML/Graphics.hpp>
using namespace std;

Enemigo::Enemigo()
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


    renderPos.push_back(17.0);
    renderPos.push_back(300.0);
    posNow.push_back(17.0),posNow.push_back(150.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);


    colliderDown= sf::FloatRect(posNow[0],posNow[1],15,10);

    dir= rand() % 1;
//    frame=0;
    touchingFloor=false;
    DecidingJump=false;
    DecidingStairs=false;
    sube=false,baja=false;
}


void Enemigo::setFrame(int f)
{
//    frame=f;
}

void Enemigo::setTouchingFloor(bool t)
{

    touchingFloor=t;
}
void Enemigo::setTouchingEscalera(bool t)
{
    touchingEscalera=t;
}
void Enemigo::setTouchingTrampolin(bool t)
{
    touchingTrampolin=t;
}
void Enemigo::setTouchingPuerta(bool t)
{
    touchingPuerta=t;
}
void Enemigo::setDecidingJump(bool t)
{
    DecidingJump=t;
}
void Enemigo::setDecidingStairs(bool t)
{
    DecidingStairs=t;
}
void Enemigo::setUltPuerta(int d, sf::Vector2f c)
{
    crdPuerta=c;
    ultPuerta=d;
}

bool Enemigo::isTouchingFloor()
{
    return touchingFloor;

}
bool Enemigo::isTouchingEscalera()
{
    return touchingEscalera;
}
bool Enemigo::isTouchingTrampolin()
{
    return touchingTrampolin;
}
bool Enemigo::isTouchingPuerta()
{
    return touchingPuerta;
}
bool Enemigo::isDecidingJump()
{
    return DecidingJump;
}
bool Enemigo::isDecidingStairs()
{
    return DecidingStairs;
}

int Enemigo::getUltPuerta()
{
    return ultPuerta;
}



vector<double> Enemigo::getPos()
{

    return posNow;

}
sf::Sprite Enemigo::getSprite()
{
    return sprite;
}

sf::Rect<float>  Enemigo::getColliderTop()
{
    return colliderTop;
}
sf::Rect<float>  Enemigo::getColliderDown()
{
    return colliderDown;
}

void Enemigo::updateEnemigo( sf::Time et, float of)
{

    double velx=0.0, vely=0.0, pow=70;
    posBef=posNow;

    cout<<baja<<endl;
    /**AI SECTION**/


    if(isDecidingJump())
    {
     sube=false;
        baja=false;
        cout<<"zona de accion: salto"<<endl;
        if(!decidedj)
        {
            int salto = rand() % 2;
            if(!salto)
            {
                cout<<"salto"<<endl;
                vely-=pow*3.5;
            }
            else
            {
                dir= rand() % 2;
                cout<<"cambio dir"<<endl;
            }
            decidedj=true;

            cout<<"decidido"<<endl;
        }
        DecidingJump=false;

    }
    else
    {

        decidedj=false;
    }

    if(isDecidingStairs())
    {
        cout<<"zona de accion: escalera"<<endl;
        if(!decideds)
        {
            sube=false;
            baja=false;
            int escala = rand() % 2;
            if(!escala)
            {

                int subeobaja = rand() % 2;
                if(!subeobaja)
                {
                    cout<<"escala"<<endl;
                    vely-=pow;
                    sube=true;
                    baja=false;
                }
                else
                {
                    if(posNow[1]<464)
                    {
                        cout<<"baja"<<endl;
                        vely=pow;
                        sube=false;
                        baja=true;
                    }
                }
            }
            else
            {
                dir= rand() % 2;
                cout<<"cambio dir"<<endl;
            }
            decideds=true;

            cout<<"decidido"<<endl;
        }
        DecidingStairs=false;

    }
    else
    {

        decideds=false;
    }


    if(dir==1)
        velx=pow;
    else
        velx=-pow;

    if(sube)
    {
        vely-=pow;
        velx=0;
    }
    if(baja)
    {
        vely+=pow;
        velx=0;
    }


    /**AI SECTION**/



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


    if(isTouchingFloor()||isTouchingEscalera()||isTouchingTrampolin())
    {
        if(isTouchingEscalera())//Escalera
        {

            vel[1]=vely;
            of=0;


        }

        if(isTouchingFloor())//Suelo
        {
            vel[1]=vely;

        }
        if(isTouchingTrampolin()&&of>0)//Trampolin: Si el offset es = 0, esta a la altura del trampolin, no se activa, solo lo hace cuando cae encime, que of>0
        {

            vel[1]=-100*4.5;

        }

    }
    else//aire
    {
        //cout<<"En el aire"<<endl;
        if(vel[1]<130)
            vel[1]+=980*et.asSeconds();

        if(vel[1]>129)///Esto simula lo de que no puede avanzar mucho en el aire
            velx=0;


    }
    vel[0]=velx;





    if(isTouchingPuerta())
    {
        posNow[0] = crdPuerta.x-20;
        posNow[1] = crdPuerta.y;

    }
    else
    {
        posNow[0] += vel[0]*et.asSeconds();
        posNow[1] += vel[1]*et.asSeconds()-of;
    }


}

void Enemigo::drawEnemigo(sf::RenderWindow& w, double i)
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

Enemigo::~Enemigo()
{
    //dtor
}
