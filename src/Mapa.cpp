#include "Mapa.h"

Mapa::Mapa(int id)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    blueprint += "b-------------bb-----------------------b.";
    blueprint += "b-------------bb-----------------------b.";
    blueprint += "b-------bbbbbbbb----------f------------b.";
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
    blueprint += "beppppppprflpppper-------ppppppp--pppepb.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e----------f---------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "beppr----lppppppepp--pr-------lppppppe-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "beppp--pr----lppeppppp--lp--pppppppppepb.";
    blueprint += "b--f---------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "bppppppppppppppppppppppppppppppppppppppb.";

    Bg = new sf::Texture();
    Bg->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/back.png");
    if (!Bg->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/back.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }


    Base = new sf::Texture();
    Base->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/tileset.png");
    if (!Base->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/tileset.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    sf::Sprite map_s;
    map_s.setTexture(*Base);

    Items = new sf::Texture();
    Items->loadFromFile("resources/Sunny-land-files/PNG/spritesheets/cherry.png");
    if (!Items->loadFromFile("resources/Sunny-land-files/PNG/spritesheets/cherry.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    sf::Sprite item_s;
    item_s.setTexture(*Items);


    int mx=0,my=0,i=0;
    for( i=0; i< blueprint.size(); i++)
    {
        if(blueprint.at(i) == 'p')
        {
            map_s.setTextureRect(sf::IntRect(16*3, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'l')
        {
            map_s.setTextureRect(sf::IntRect(16, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'r')
        {
            map_s.setTextureRect(sf::IntRect(16*5, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'e')
        {
            map_s.setTextureRect(sf::IntRect(112,160,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);
        }
        if(blueprint.at(i) == 'b')
        {
            map_s.setTextureRect(sf::IntRect(16,320,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);
        }

        if(blueprint.at(i) == 'f')
        {
            item_s.setTextureRect(sf::IntRect(0,3,17,15));
            item_s.setPosition(mx*16,my*16);
            items.push_back(item_s);
            cout<<items.size()<<endl;
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
void Mapa::deleteElemento(int tipo,int i )
{
    cout<<items.size()<<endl;

    if( tipo==4 && items.size()!=0)
    {
        cout<<items.size()<<endl;
        items.erase(items.begin()+i);

    }

}
vector<sf::Sprite> Mapa::getElementos(int tipo)
{
    if(tipo==0)
        return plataformas;

    if(tipo==1)
        return escaleras;

    if(tipo==2)
        return trampolines;

    if(tipo==3)
        return balancines;

    if(tipo==4)
        return items;


}

void Mapa::drawMapa(sf::RenderWindow& w, double i)
{


    for(int i=0; i<plataformas.size(); i++)
    {
        w.draw(plataformas[i]);

    }
    for(int i=0; i<escaleras.size(); i++)
    {
        w.draw(escaleras[i]);


    }
    for(int i=0; i<items.size(); i++)
    {
        w.draw(items[i]);


    }



}

Mapa::~Mapa()
{
    //dtor
}
