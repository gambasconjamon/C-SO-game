#include "Mapa.h"

Mapa::Mapa(int id,string blueprint, string backgr)
{
    //Aqui ira un loop que genera el mapa, mientras voy a hacer solo una plataforma

    Bg = new sf::Texture();
    Bg->loadFromFile(backgr);
    if (!Bg->loadFromFile(backgr))
    {
        std::cerr << "Error cargando la imagen "<<backgr ;
        exit(0);
    }

    sbg.setTexture(*Bg);
    sbg.setTextureRect(sf::IntRect(0, 0,384,240));
    sbg.setPosition(0,0);
    sbg.scale(1.7,2);

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
            paredes.push_back(map_s);
        }
        if(blueprint.at(i) == 'w')
        {
            map_s.setTexture(*Base);

            map_s.setTextureRect(sf::IntRect(48,48,16,16));
            map_s.setPosition(mx*16,my*16);
            paredes.push_back(map_s);
        }

        if(blueprint.at(i) == 'f')
        {
            iteme=new SprAnimado("resources/Sunny-land-files/PNG/spritesheets/gem.png",1,1.5,true);
            iteme->addFrame(sf::IntRect(1, 1,13,11),0);//dcha
            iteme->addFrame(sf::IntRect(16, 1,13,11),0);//dcha
            iteme->addFrame(sf::IntRect(31, 1,13,11),0);//dcha
            iteme->addFrame(sf::IntRect(46, 1,13,11),0);//dcha
            iteme->addFrame(sf::IntRect(61, 1,13,11),0);//dcha
            iteme->setSpeed(0.1);

           iteme->setPosition(sf::Vector2f(mx*16,my*16+8));


            items.push_back(iteme);

        }
        if(blueprint.at(i) == '^')
        {
            map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(256,191,32,16));
            map_s.setPosition(mx*16,my*16);
            trampolines.push_back(map_s);

        }
        if(blueprint.at(i) == 'd')
        {
            map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(14,63,22,33));
            map_s.setPosition(mx*16,my*16-16);
            puertas.push_back(map_s);

        }
        if(blueprint.at(i) == 'o')
        {
            map_s.setTexture(*Props);

            map_s.setTextureRect(sf::IntRect(230,27,60,16));
            map_s.setOrigin(30,8);
            map_s.setPosition(mx*16+8,my*16);
            map_s.rotate(30);
            balancines.push_back(map_s);
            b_rights.push_back(sf::FloatRect(mx*16+16,my*16+16,16,8));
            b_lefts.push_back(sf::FloatRect(mx*16-16,my*16-16,16,8));
            b_toggles.push_back(false);
            map_s.rotate(-30);




        }
        if(blueprint.at(i) == 'j')
        {

            a_salto.push_back(sf::FloatRect(mx*16,my*16+16,16,8));


        }
        if(blueprint.at(i) == 'E')
        {

            map_s.setTexture(*Base);
            map_s.setTextureRect(sf::IntRect(112,160,16,16));
            map_s.setPosition(mx*16,my*16);
            escaleras.push_back(map_s);

            a_escalera.push_back(sf::FloatRect(mx*16+4,my*16,8,16));


        }
        if(blueprint.at(i) == 's')
        {

            spawn.push_back(sf::Vector2f(mx*16+4,my*16));


        }



        mx++;
        if(blueprint.at(i) == '.')
        {
            my++;
            mx=0;
        }
    }

}

void Mapa::deleteElemento(int tipo,int i )
{


    if( tipo==6 && items.size()!=0)
    {

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
        return balancines;

    if(tipo==5)
        return paredes;
    if(tipo==6){
        vector<sf::Sprite> itemes;
        for(unsigned i=0; i< items.size(); i++){
        itemes.push_back(*(items[i]->getActualSprite()));
        }
        return itemes;
        }





}

void Mapa::updateBalancin(int id)
{
    if(b_toggles[id]==true)
    {
        b_toggles[id]=false;
        balancines[id].rotate(60);
        b_rights[id].top+=32;
        b_lefts[id].top-=32;
    }
    else
    {
        b_toggles[id]=true;
        balancines[id].rotate(-60);
        b_rights[id].top-=32;
        b_lefts[id].top+=32;
    }
}
bool Mapa::getBalancinTog(int id)
{

    if(!b_toggles.empty()){
    return b_toggles[id];
    }
}
vector< sf::Rect<float> > Mapa::getAccion(int tipo)
{

    if(tipo==7)
        return b_rights;
    if(tipo==8)
        return b_lefts;

    if(tipo==9)
        return a_salto;

    if(tipo==10)
        return a_escalera;
}

sf::Vector2f Mapa::getSpawn(int id)
{
    if(!spawn.empty())
    return spawn[id];
    else
    return sf::Vector2f(-1,-1);
}

void Mapa::drawMapa(sf::RenderWindow* w, double i)
{

    w->draw(sbg);

    for(int i=0; i<plataformas.size(); i++)
    {
        w->draw(plataformas[i]);

    }
    for(int i=0; i<escaleras.size(); i++)
    {
        w->draw(escaleras[i]);


    }
    for(int i=0; i<trampolines.size(); i++)
    {
        w->draw(trampolines[i]);


    }
    for(int i=0; i<puertas.size(); i++)
    {
        w->draw(puertas[i]);


    }
    for(int i=0; i<items.size(); i++)
    {
        items[i]->drawSprAnimado(items[i]->getPosition(),items[i]->getPosition(),w,i);


    }
    for(int i=0; i<balancines.size(); i++)
    {
        w->draw(balancines[i]);


    }
    for(int i=0; i<paredes.size(); i++)
    {
        w->draw(paredes[i]);


    }
    /* for(int i=0; i<a_salto.size(); i++)
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
     for(int i=0; i<b_rights.size(); i++)
     {
         sf::RectangleShape trampolindcha;
         trampolindcha.setSize(sf::Vector2f(b_rights[i].width,b_rights[i].height));
         trampolindcha.setFillColor(sf::Color(200, 150, 50));
         trampolindcha.setPosition(b_rights[i].left,b_rights[i].top);
         w.draw(trampolindcha);


     }
     for(int i=0; i<b_lefts.size(); i++)
     {
         sf::RectangleShape trampolinizqda;
         trampolinizqda.setSize(sf::Vector2f(b_lefts[i].width,b_lefts[i].height));
         trampolinizqda.setFillColor(sf::Color(200, 150, 50));
         trampolinizqda.setPosition(b_lefts[i].left,b_lefts[i].top);
         w.draw(trampolinizqda);


     }*/


}

Mapa::~Mapa()
{
    //dtor
}
