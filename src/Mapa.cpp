#include "Mapa.h"

Mapa::Mapa(int id)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    blueprint += "b-------------bb-----------------------b.";
    blueprint += "b-------------bb-----------------------b.";
    blueprint += "b-------bbbbbbbb-----------------------b.";
    blueprint += "b---------bbbbbb-----------------------b.";
    blueprint += "b---------bbbbbbepppppr------lpppppppepb.";
    blueprint += "b-------bbbbbbbbe--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbbbe--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbbbe--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbbbe--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbbbeppppppppp--r-------lepb.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "beppppppr--lpppper-------ppppppp--pppepb.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "beppr----lppppppepp--pr-------lppppppe-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "beppp--pr----lppeppppp--lp--pppppppppepb.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "bppppppppppppppppppppppppppppppppppppppb.";



    Base.loadFromFile("resources/Sunny-land-files/PNG/environment/layers/tileset.png");
    if (!Base.loadFromFile("resources/Sunny-land-files/PNG/environment/layers/tileset.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    sf::Sprite s;
    s.setTexture(Base);


    int mx=0,my=0,i=0;
    for( i=0; i< blueprint.size(); i++)
    {
        if(blueprint.at(i) == 'p')
        {
            s.setTextureRect(sf::IntRect(16*3, 16,16,16));
            s.setPosition(mx*16,my*16);
            plataformas.push_back(s);
        }
        if(blueprint.at(i) == 'l')
        {
            s.setTextureRect(sf::IntRect(16, 16,16,16));
            s.setPosition(mx*16,my*16);
            plataformas.push_back(s);
        }
        if(blueprint.at(i) == 'r')
        {
            s.setTextureRect(sf::IntRect(16*5, 16,16,16));
            s.setPosition(mx*16,my*16);
            plataformas.push_back(s);
        }
        if(blueprint.at(i) == 'e')
        {
            s.setTextureRect(sf::IntRect(112,160,16,16));
            s.setPosition(mx*16,my*16);
            escaleras.push_back(s);
        }
        if(blueprint.at(i) == 'b')
        {
            s.setTextureRect(sf::IntRect(16,320,16,16));
            s.setPosition(mx*16,my*16);
            escaleras.push_back(s);
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
    if(tipo==0)
    return plataformas;

    if(tipo==1)
    return escaleras;


}

void Mapa::drawMapa(sf::RenderWindow& w, double i)
{


for(int i=0;i<plataformas.size();i++){
    w.draw(plataformas[i]);

}
for(int i=0;i<escaleras.size();i++){
    w.draw(escaleras[i]);

}

}

Mapa::~Mapa()
{
    //dtor
}
