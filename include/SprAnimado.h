#ifndef SPRANIMADO_H
#define SPRANIMADO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


class SprAnimado
{
    public:
        SprAnimado(string ruta, int numanim, double escala, bool animado);
        void addFrame(sf::IntRect frame,int animation);
        void setSpeed(double s);
        void setPosition(sf::Vector2f pos);
        vector<double> getPosition(){return renderPos;}
        void setAnimation(int a);
        sf::Sprite* getActualSprite();
        vector<double> getRenderPos();
        void calcInter(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i);
        void drawSprAnimado(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i);
        virtual ~SprAnimado();

    protected:

    private:

    sf::Texture *textura;
    sf::Sprite *s_sprite;
    sf::Clock changer;
    vector < vector < sf::Rect <int> > > frames; ///Matriz de frames

    int animacion;
    int frame;

    double speed;
    int numeroAnimaciones;
    bool animado;

    vector<double> renderPos;


};

#endif // SPRANIMADO_H
