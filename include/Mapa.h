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
        void deleteElemento(int tipo,int i );

    protected:

    private:
      ///MAPA
      std::string blueprint;
    sf::Texture *Base;
    sf::Texture *Items;
    sf::Texture *Bg;
   vector<sf::Sprite> plataformas; //0
    vector<sf::Sprite> escaleras; //1
    vector<sf::Sprite> trampolines;//2
    vector<sf::Sprite> balancines;//3
    vector<sf::Sprite> items;//4
    ///...
};

#endif // MAPA_H
