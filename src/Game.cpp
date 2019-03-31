#include "Game.h"
using namespace std;

/** GLOBAL **/
const sf::Time Game::timePerFrame = sf::milliseconds(1000.0/20.0);
/** GLOBAL **/

Game::Game(int resol_x, int resol_y, string gamename)
{
    //ctor
    window= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    window->setVerticalSyncEnabled(true);

    player= new Player();
    mapa= new Mapa(0);


    //Para los eventos
    eJump=false;
    eDown=false;
    eLeft=false;
    eRight=false;

    gravity=0;

}

void Game::Gloop()
{

    while (window->isOpen())
    {

        //Proceso mis eventos
        handleEvents();

        if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds())
        {
            //Calculamos el tiempo desde el ultimo update
            elapsedTime=updateClock.restart();

            //updateamos dependiendo del tiempo pasado



            updateGameState(elapsedTime);
        }

        //Se calcula el porcentaje de interpolacion
        interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        //Renderizamos con interpolacion
        render(interpolation);

    }

}

void Game::handleEvents()
{

    sf::Event event;
    if (window->pollEvent(event))
    {

        if(event.type==sf::Event::KeyPressed)
            handleInputs(event.key.code, true);

        if(event.type==sf::Event::KeyReleased)
            handleInputs(event.key.code, false);

        if(event.type==sf::Event::Closed)
            window->close();


    }


}
void Game::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::Space)            //Traslaciones
        eJump = isPressed;
    if (key == sf::Keyboard::Down)
        eDown = isPressed;
    if (key == sf::Keyboard::Left)
        eLeft = isPressed;
    if (key == sf::Keyboard::Right)
        eRight = isPressed;
        if (key == sf::Keyboard::Up)
        eUp = isPressed;

}



void Game::updateGameState(sf::Time t)
{

    double x=0,y=0,potencia=100;
    int frame=0;


    if(eRight)
    {
        x=potencia;

       // player->setDir(2,frame);
    }
    if(eLeft)
    {
        x=-potencia;

        //player->setDir(3,frame);//Decimos a donde esta mirando el sprite
    }
    if(eJump)
    {


            if(player->isTouchingFloor()){
            y=-potencia*2.5;
            }

    }
    if(eUp){



            if(player->isTouchingEscalera())
            y=-potencia;

    }
    else if(eDown)
    {


            y=potencia;


    }
    player->updatePlayer(x,y,t,handleCollision()); //Handle collision devuelve el offset de interseccion


}

float Game::handleCollision()
{

    float offsety=0;
    player->setTouchingFloor(false);
    player->setTouchingEscalera(false);
    for(int t=0 ; t<2; t++)
        for(int i=0; i<mapa->getElementos(t).size(); i++)
        {

            if(player->getColliderDown().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
            {

                if (t==0)
                {
                    player->setTouchingFloor(true);
                    offsety= player->getColliderDown().top-mapa->getElementos(t)[i].getGlobalBounds().top+1;
                    //cout<<"Offset de colision "<<offset  << endl;
                }
                if (t==1)
                {
                    player->setTouchingEscalera(true);
                }


            }

        }

    return offsety;
}

void Game::render(double i)
{
    window->clear();
    player->drawPlayer(*window,i);
    //lvl.drawLevel(*ventana,i);
    mapa->drawMapa(*window,i);
    window->display();
}

Game::~Game()
{
    //dtor
}
