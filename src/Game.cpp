#include "Game.h"
using namespace std;

/** GLOBAL **/
const sf::Time Game::timePerFrame = sf::milliseconds(1000.0/25.0);
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

}



void Game::updateGameState(sf::Time t)
{

    double x=0,y=0,potencia=100;
    int frame=0;

    if(eRight)
    {
        x=potencia;
        y=0.0;
        player->setDir(2,frame);
    }
    if(eLeft)
    {
        x=-potencia;
        y=0.0;
        player->setDir(3,frame);//Decimos a donde esta mirando el sprite
    }
    if(eJump)
    {
        x=0.0;
        y=-potencia*4;
        player->setDir(1,frame);//Decimos a donde esta mirando el sprite
    }
    /* else if(eDown)
     {
         x=0.0;
         y=potencia;;
         player->setDir(0,frame);//Decimos a donde esta mirando el sprite

     }*/

    player->updatePlayer(x,y,t,handleCollision()); //Handle collision devuelve el offset de interseccion


}

float Game::handleCollision()
{

    float offsety=0;
    player->setTouchingFloor(false);
    for(int i=0; i<mapa->getElementos(0).size(); i++)
    {

        if(player->getColliderDown().intersects(mapa->getElementos(0)[i].getGlobalBounds()))
        {
         player->setTouchingFloor(true);
            offsety= player->getColliderDown().top-mapa->getElementos(0)[i].getGlobalBounds().top+1;
            //cout<<"Offset de colision "<<offset  << endl;


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
