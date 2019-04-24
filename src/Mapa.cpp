#include "Mapa.h"

Mapa::Mapa(int id)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    blueprint += "bwwwwwwwwwwwwbbb-----------------------b.";
    blueprint += "bwwwwwwwwwwwwbbb-----------------------b.";
    blueprint += "bwwwwwwwbbbbbbbb----------f------------b.";
    blueprint += "bbwwwwwwwbbbbbbbE-----j------j------dE-b.";
    blueprint += "bwwwwwwwbbbbbbbbepppppr------lpppppppepb.";
    blueprint += "bwwwwwwwwbbbbbbbe--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbbbe--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------E-------j---j--------E-b.";
    blueprint += "b---------------eppppppppp^-r-------lepb.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b-------j-j-----E--------j-----j--j--E-b.";
    blueprint += "beppppppr-flpppper-------ppppppp^-pppepb.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e----------f---------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--j----j------E----j--------j-d----E-b.";
    blueprint += "beppr----lppppppepp^-pr-------lppppppe-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--j--j--------E----j---j--j---o----E-b.";
    blueprint += "beppp^-pr----lppeppppp--lp^-pppppppppepb.";
    blueprint += "b--f---------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b--------j--j---j--------------------E-b.";
    blueprint += "bppppppppp^-pppppppppppppppppppppppppppb.";



    Bg = new sf::Texture();
    Bg->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/back.png");
    if (!Bg->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/back.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    sbg.setTexture(*Bg);
    sbg.setTextureRect(sf::IntRect(0, 0,384,240));
    sbg.setPosition(0,0);
    sbg.scale(2,2);

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


    Props = new sf::Texture();
    Props->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/props.png");
    if (!Props->loadFromFile("resources/Sunny-land-files/PNG/environment/layers/props.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }



    int mx=0,my=0,i=0;
    for( i=0; i< blueprint.size(); i++)
    {
    map_s.setOrigin(0,0);
        if(blueprint.at(i) == 'p')
        {
            map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(16*3, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'l')
        {
        map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(16, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'r')
        {
        map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(16*5, 16,16,16));
            map_s.setPosition(mx*16,my*16);
            plataformas.push_back(map_s);
        }
        if(blueprint.at(i) == 'e')
        {
        map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(112,160,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);
        }
        if(blueprint.at(i) == 'b')
        {
        map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(16,320,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);
        }
        if(blueprint.at(i) == 'w')
        {
        map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(48,48,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);
        }

        if(blueprint.at(i) == 'f')
        {
        map_s.setTexture(*Items);

            map_s.setTextureRect(sf::IntRect(0,3,17,15));
            map_s.setPosition(mx*16,my*16);
            items.push_back(map_s);
            cout<<items.size()<<endl;
        }
        if(blueprint.at(i) == '^')
        {
         map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(256,191,32,16));
            map_s.setPosition(mx*16,my*16);
            trampolines.push_back(map_s);
            cout<<trampolines.size()<<endl;
        }
        if(blueprint.at(i) == 'd')
        {
         map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(14,63,22,33));
            map_s.setPosition(mx*16,my*16-16);
            puertas.push_back(map_s);
            cout<<puertas.size()<<endl;
        }
        if(blueprint.at(i) == 'o')
        {
         map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(219,26,80,16));
            map_s.setOrigin(40,8);
            map_s.setPosition(mx*16,my*16-8);
            balancines.push_back(map_s);
            b_toggles.push_back(false);


            cout<<balancines.size()<<endl;
        }
         if(blueprint.at(i) == 'j')
        {

            a_salto.push_back(sf::FloatRect(mx*16,my*16+16,16,8));
            cout<<"a saltoo:"<<a_salto.size()<<endl;

        }
        if(blueprint.at(i) == 'E')
        {

            map_s.setTexture(*Base);
            map_s.setTextureRect(sf::IntRect(112,160,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);

            a_escalera.push_back(sf::FloatRect(mx*16,my*16,16,16));
            cout<<"a escalera:"<<a_escalera.size()<<endl;

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
        return puertas;

    if(tipo==4)
        return items;

    if(tipo==5)
        return balancines;




}
vector< sf::Rect<float> > Mapa::getAccion(int tipo)
{

        if(tipo==6)
        return a_salto;

        if(tipo==7)
        return a_escalera;
        }

void Mapa::drawMapa(sf::RenderWindow& w, double i)
{

 w.draw(sbg);

    for(int i=0; i<plataformas.size(); i++)
    {
        w.draw(plataformas[i]);

    }
    for(int i=0; i<escaleras.size(); i++)
    {
        w.draw(escaleras[i]);


    }
    for(int i=0; i<trampolines.size(); i++)
    {
        w.draw(trampolines[i]);


    }
    for(int i=0; i<puertas.size(); i++)
    {
        w.draw(puertas[i]);


    }
    for(int i=0; i<items.size(); i++)
    {
        w.draw(items[i]);


    }
    for(int i=0; i<balancines.size(); i++)
    {
        w.draw(balancines[i]);


    }
    for(int i=0; i<a_salto.size(); i++)
    {
        sf::RectangleShape action;
        action.setSize(sf::Vector2f(a_salto[i].width,a_salto[i].height));
    action.setFillColor(sf::Color(100, 250, 50));
    action.setPosition(a_salto[i].left,a_salto[i].top);
        w.draw(action);


    }
    for(int i=0; i<a_escalera.size(); i++)
    {
        sf::RectangleShape action;
        action.setSize(sf::Vector2f(a_escalera[i].width,a_escalera[i].height));
    action.setFillColor(sf::Color(100, 250, 50));
    action.setPosition(a_escalera[i].left,a_escalera[i].top);
        w.draw(action);


    }


}

Mapa::~Mapa()
{
    //dtor
}
