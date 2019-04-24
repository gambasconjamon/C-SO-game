#ifndef MAPA_H
#define MAPA_H
#include "Balancin.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

using namespace std;


class Mapa
{
    public:
        Mapa(int id);
        virtual ~Mapa();
        void drawMapa(sf::RenderWindow& w, double i);
        sf::Sprite getElemento(int id,int tipo);
        vector<sf::Sprite> getElementos(int tipo);
        vector< sf::Rect<float> > getAccion(int tipo);
        void deleteElemento(int tipo,int i );

    protected:

    private:
      ///MAPA
      std::string blueprint;

    sf::Texture *Base;
    sf::Texture *Items;
    sf::Texture *Props;
    sf::Texture *Bg;
    sf::Sprite sbg;
    vector<sf::Sprite> plataformas; //0
    vector<sf::Sprite> escaleras; //1
    vector<sf::Sprite> trampolines;//2
    vector<sf::Sprite> puertas;//3
    vector<sf::Sprite> items;//4

    vector<sf::Sprite> balancines;//5
    vector<bool> b_toggles;//5.1
    vector< sf::Rect<float> > b_rights;//5.2
    vector< sf::Rect<float> > b_lefts;//5.3

    vector< sf::Rect<float> > a_escalera;
    vector< sf::Rect<float> > a_salto;
    ///...
};

#endif // MAPA_H
