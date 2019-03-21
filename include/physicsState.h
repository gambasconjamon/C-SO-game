#ifndef PHYSICSSTATE_H
#define PHYSICSSTATE_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class physicsState
{
      public:
        physicsState();
        virtual ~physicsState();

    vector<double> getPosBef();
    vector<double> getPosNow();
    vector<double> getVel();

    void setPosBef(double x, double y);
    void setPosNow(double x, double y);
    void setVel(double ax,double ay);


    void updateState(sf::Time et);

    protected:


    private:
    vector<double> posNow,posBef;
    vector<double> vel;
};

#endif // PHYSICSSTATE_H
