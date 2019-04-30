#include "SprAnimado.h"

SprAnimado::SprAnimado(string ruta, int numanim, double escala, bool isanimado)
{
    //ctor
    s_sprite=new sf::Sprite();
    textura =new sf::Texture();
    //La carga de texturas podria ser otra clase
    frames.resize(numanim);
    /*for (int i = 0 ; i < 4 ; i++)
    	frames[i].resize(2);*/

    textura->loadFromFile(ruta);
    if (!textura->loadFromFile(ruta))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    speed=0.2;
    s_sprite->setTexture(*textura);
    s_sprite->scale(escala,escala);

    animacion=0;
    frame=0;
    animado=isanimado;
    renderPos.push_back(0.0);
    renderPos.push_back(0.0);

}

void SprAnimado::addFrame(sf::IntRect frame,int animation)
{
    if(animation<frames.size())
    {
        frames[animation].push_back(frame);
    }
}

void SprAnimado::setSpeed(double s)
{
    speed=s;
}

void SprAnimado::setAnimation(int a)
{
    animacion=a;

}

sf::Sprite* SprAnimado::getActualSprite()
{
    return s_sprite;
}
vector<double> SprAnimado::getRenderPos(){

    return renderPos;
}
void SprAnimado::calcInter(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i){


/** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    renderPos[0]=(actual[0]-past[0])*i+past[0];
    renderPos[1]=(actual[1]-past[1])*i+past[1];

}
void SprAnimado:: setPosition(sf::Vector2f posi){
renderPos[0]=posi.x;
renderPos[1]=posi.y;
}
void SprAnimado::drawSprAnimado(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i)
{
//cout<<"Animacion actual "<<animacion<<endl;
if(frame>frames[animacion].size()){
frame=frames[animacion].size()-1;
}
    s_sprite->setOrigin(frames[animacion][frame].width/2,frames[animacion][frame].height/2);
    s_sprite->setTextureRect(frames[animacion][frame]);
    calcInter(past,actual,w,i);
    s_sprite->setPosition(renderPos[0], renderPos[1]);
    w->draw(*s_sprite);
    if(changer.getElapsedTime().asSeconds()>speed&&animado)
    {
        if(animacion<frames.size())
        {


            if(frame<frames[animacion].size()-1){

            frame++;
            }else{
            frame=0;
            }
        }
    changer.restart();
    }


}

SprAnimado::~SprAnimado()
{
    //dtor
}
