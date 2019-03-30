#include "Mapa.h"

Mapa::Mapa(int id)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    blueprint += "--------------------------------.";
    blueprint += "--------------------------------.";
    blueprint += "--------------------------------.";
    blueprint += "--------------------------------.";
    blueprint += "--------------------------------.";
    blueprint += "--------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "pppppppp-----------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "pppppp-------ppppppppppppp------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "p-------------------------------.";
    blueprint += "pppppppppppppppppppppppppppppppp.";



    Base.loadFromFile("resources/tiles.png");
    if (!Base.loadFromFile("resources/tiles.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    sf::Sprite s;
    s.setTexture(Base);
    s.scale(1,1);

    int mx=0,my=0,i=0;
    for( i=0; i< blueprint.size(); i++)
    {
        if(blueprint.at(i) == 'p')
        {

            s.setTextureRect(sf::IntRect(8*20, 0,20,20));
            s.setPosition(mx*20,my*20);
            plataformas.push_back(s);
        }

        mx++;
        if(blueprint.at(i) == '.')
        {
            my++;
            mx=0;
        }
    }

}

sf::Sprite Mapa::getElemento(int id, int tipo)
{

    return plataformas[id];

}
vector<sf::Sprite> Mapa::getElementos(int tipo)
{

    return plataformas;

}

void Mapa::drawMapa(sf::RenderWindow& w, double i)
{


for(int i=0;i<plataformas.size();i++){
    w.draw(plataformas[i]);

}

}

Mapa::~Mapa()
{
    //dtor
}
