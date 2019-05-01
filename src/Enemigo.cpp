#include "Enemigo.h"
#include <SFML/Graphics.hpp>
using namespace std;

Enemigo::Enemigo()
{
    enespr = new SprAnimado("resources/Sunny-land-files/PNG/sprites/enemy.png",8,1.2,true);
    enespr->setSpeed(0.1);

    enespr->addFrame(sf::IntRect(1, 2,28,25),0);//izq
    enespr->addFrame(sf::IntRect(37, 6,29,22),0);//izq
    enespr->addFrame(sf::IntRect(73, 8,32,20),0);//izq
    enespr->addFrame(sf::IntRect(109, 8,35,20),0);//izq
    enespr->addFrame(sf::IntRect(145, 8,35,20),0);//izq
    enespr->addFrame(sf::IntRect(181, 5,31,23),0);//izq

    enespr->addFrame(sf::IntRect(184, 32,28,25),1);//dcha
    enespr->addFrame(sf::IntRect(147, 36,29,22),1);//dcha
    enespr->addFrame(sf::IntRect(108, 38,32,20),1);//dcha
    enespr->addFrame(sf::IntRect(69,38,35,20),1);//dcha
    enespr->addFrame(sf::IntRect(33, 38,35,20),1);//dcha
    enespr->addFrame(sf::IntRect(1,35,31,23),1);//dcha

    enespr->addFrame(sf::IntRect(6,66,23,31),2);//abajo
    enespr->addFrame(sf::IntRect(6,98,20,35),2);//abajo
    enespr->addFrame(sf::IntRect(6,134,20,35),2);//abajo
    enespr->addFrame(sf::IntRect(6,173,20,32),2);//abajo
    enespr->addFrame(sf::IntRect(6,212,22,29),2);//abajo
    enespr->addFrame(sf::IntRect(7,249,25,28),2);//abajo

    enespr->addFrame(sf::IntRect(40,246,23,31),3);//arriba
    enespr->addFrame(sf::IntRect(43,210,20,35),3);//arriba
    enespr->addFrame(sf::IntRect(43,174,20,35),3);//arriba
    enespr->addFrame(sf::IntRect(43,138,20,32),3);//arriba
    enespr->addFrame(sf::IntRect(41,102,22,29),3);//arriba
    enespr->addFrame(sf::IntRect(37,66,25,28),3);//arriba


    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);


    colliderDown= sf::FloatRect(posNow[0],posNow[1],15,10);
    colliderTop= sf::FloatRect(posNow[0],posNow[1],15,10);

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
void Enemigo::setPos(sf::Vector2f posi)
{
    posNow[0]=posi.x;
    posNow[1]=posi.y;
    posBef=posNow;

}
SprAnimado* Enemigo::getSprAnimado()
{
    return enespr;
}

sf::Rect<float>  Enemigo::getColliderTop()
{
    return colliderTop;
}
sf::Rect<float>  Enemigo::getColliderDown()
{
    return colliderDown;
}

void Enemigo::updateEnemigo(double x, double y, sf::Time et, sf::Vector2f of)
{

    double velx=0.0, vely=0.0, pow=70;
    posBef=posNow;


    /**AI SECTION**/


    if(isDecidingJump())
    {
        sube=false;
        baja=false;
        if(!decidedj)
        {
        cout<<"Enemigo "<<this<<": Entra en decision de salto"<<endl;
            int salto = rand() % 2;
            if(!salto)
            {
                cout<<"Enemigo "<<this<<": Decide saltar"<<endl;
                vely-=pow*3.5;
            }
            else
            {

                if(x<posNow[0])
                {
                cout<<"Enemigo "<<this<<": Decide continuar a la derecha"<<endl;
                    dir=0;
                }
                else
                {
                cout<<"Enemigo "<<this<<": Decide continuar a la izquierda"<<endl;
                    dir=1;
                }


            }
            decidedj=true;


        }
        DecidingJump=false;

    }
    else
    {

        decidedj=false;
    }

    if(isDecidingStairs())
    {


        if(!decideds)
        {
          cout<<"Enemigo "<<this<<": Entra en decision de escaleras"<<endl;
            sube=false;
            baja=false;
            int escala = rand() % 2;
            if(!escala)
            {


                if(y<posNow[1])
                {
                cout<<"Enemigo "<<this<<": Decide subir"<<endl;

                    sube=true;
                    baja=false;
                }
                else
                {
                cout<<"Enemigo "<<this<<": Decide bajar"<<endl;

                    sube=false;
                    baja=true;
                }


            }
            else
            {

                if(x<posNow[0])
                {
                    dir=0;
                    cout<<"Enemigo "<<this<<": Decide continuar a la derecha"<<endl;
                }
                else
                {
                    dir=1;
                    cout<<"Enemigo "<<this<<": Decide continuar a la izquierda"<<endl;
                }


            }
            decideds=true;


        }
        if((baja==true)&&posNow[1]>434)
                    {
                    cout<<"Enemigo atascado "<<this<<": Corrige rumbo"<<endl;


                        sube=true;
                        baja=false;
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
        vely=-pow;
        velx=0;
    }
    if(baja)
    {
        vely=pow;
        velx=0;
    }

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
    cout<<"Enemigo "<<this<<": Colisiona con pared izquierda, corrige rumbo"<<endl;
        velx+=200;
        dir=1;
    }
    if(of.x>-22&&of.x<-10)
    {
    cout<<"Enemigo "<<this<<": Colisiona con pared derecha, corrige rumbo"<<endl;
        velx-=200;
        dir=0;
    }
    /**AI SECTION**/
    if(velx>0)
        enespr->setAnimation(1);
    else if(velx<0)
        enespr->setAnimation(0);
    if(baja)
        enespr->setAnimation(2);
    else if(sube)
        enespr->setAnimation(3);




    if(isTouchingFloor()||isTouchingEscalera()||isTouchingTrampolin())
    {
        if(isTouchingEscalera())//Escalera
        {

            vel[1]=vely;
            of.y=0;


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
        if(vel[1]<130)
            vel[1]+=980*et.asSeconds();

        if(vel[1]>129)///Esto simula lo de que no puede avanzar mucho en el aire
            velx=0;


    }
    vel[0]=velx;





    if(isTouchingPuerta())
    {
        if(of.x<0){
            posNow[0] = crdPuerta.x+32;
            dir=1;
            }
        else{
            posNow[0] = crdPuerta.x-32;
            dir=0;
            }

        posNow[1] = crdPuerta.y;
        posBef=posNow;

    }
    else
    {
        posNow[0] += vel[0]*et.asSeconds();
        posNow[1] += vel[1]*et.asSeconds()-of.y;
    }


}

void Enemigo::drawEnemigo(sf::RenderWindow* w, double i)
{

    //sprite.setTextureRect(frames[dir][frame]);
    /*sprite.setTextureRect(frames[0][0]);
    renderPos[0]=(posNow[0]-posBef[0])*i+posBef[0];
    renderPos[1]=(posNow[1]-posBef[1])*i+posBef[1];
    sprite.setPosition(renderPos[0],renderPos[1]);*/
    enespr->drawSprAnimado(posBef,posNow,w,i);
    //w.draw(sprite);

    colliderDown.top=enespr->getRenderPos()[1]+9;
    colliderDown.left=enespr->getRenderPos()[0]-8;
    colliderTop.top=enespr->getRenderPos()[1]-16;
    colliderTop.left=enespr->getRenderPos()[0]-8;

   /* collisionBox.setSize(sf::Vector2f(colliderDown.width,colliderDown.height));
    collisionBox.setFillColor(sf::Color(100, 250, 50));
    collisionBox.setPosition(colliderDown.left,colliderDown.top);
    w->draw(collisionBox);
    collisionBox.setPosition(colliderTop.left,colliderTop.top);
    w->draw(collisionBox);*/



}

Enemigo::~Enemigo()
{
    //dtor
}
