#include "Mapa.h"

Mapa::Mapa(int id)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    Base.loadFromFile("resources/TileSet.png");
    if (!Base.loadFromFile("resources/TileSet.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    sf::Sprite s;
    s.setTexture(Base);
    s.setOrigin(240/2,75/2);
    s.setTextureRect(sf::IntRect(640, 240,240, 75));
    s.scale(0.2,0.2);
    s.setPosition(100,350);
    plataformas.push_back(s);



}

sf::Sprite Mapa::getElemento(int id, int tipo){

return plataformas[id];

}

void Mapa::drawMapa(sf::RenderWindow& w, double i){



    w.draw(plataformas[0]);
}

Mapa::~Mapa()
{
    //dtor
}
