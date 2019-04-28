#ifndef MAPA_H
#define MAPA_H

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
        void updateBalancin(int id);
        bool getBalancinTog(int id);
        sf::Vector2f getSpawn(int id);
        int getNumSpawns(){return spawn.size();}

    protected:

    private:
      ///MAPA
      std::string blueprint;

    sf::Texture *Base;
    sf::Texture *Items;
    sf::Texture *Props;
    sf::Texture *Bg;
    sf::Sprite sbg;


    vector<sf::Sprite> plataformas; //1
    vector<sf::Sprite> escaleras; //2
    vector<sf::Sprite> trampolines;//3
    vector<sf::Sprite> puertas;//4
    vector<sf::Sprite> paredes; //5
    vector<sf::Sprite> items;//6

    vector<sf::Sprite> balancines;//6
    vector<bool> b_toggles;//5.1
    vector< sf::Rect<float> > b_rights;//5.2
    vector< sf::Rect<float> > b_lefts;//5.3

    vector< sf::Rect<float> > a_escalera;
    vector< sf::Rect<float> > a_salto;

    vector<sf::Vector2f> spawn;
    ///...
};

#endif // MAPA_H
