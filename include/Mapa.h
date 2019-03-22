#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Mapa
{
    public:
        Mapa(int id);
        virtual ~Mapa();
        void drawMapa(sf::RenderWindow& w, double i);
        sf::Sprite getElemento(int id,int tipo);

    protected:

    private:
      ///MAPA
    sf::Texture Base;
   vector<sf::Sprite> plataformas; //1
    vector<sf::Sprite> escaleras; //2
    vector<sf::Sprite> trampolines;//3
    vector<sf::Sprite> balancines;//4*/
    ///...
};

#endif // MAPA_H