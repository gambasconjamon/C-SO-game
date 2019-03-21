#include "physicsState.h"

physicsState::physicsState()
{

    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);

}

vector<double> physicsState::getPosBef()
{
    return posBef;
}

vector<double> physicsState::getPosNow()
{
    return posNow;
}


void physicsState::setPosNow(double x, double y)
{
    posNow[0]=x,posNow[1]=y;
}
void physicsState::setPosBef(double x, double y)
{
    posBef[0]=x,posBef[1]=y;
}
void physicsState::setVel(double ax, double ay)
{
        vel[0]=ax;
        vel[1]=ay;
}

void physicsState::updateState(sf::Time et)
{

    posBef=posNow;

    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds();









}

physicsState::~physicsState()
{
    //dtor
}
