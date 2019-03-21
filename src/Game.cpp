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
    //Para los eventos
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;
}

void Game::Gloop(){

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

        switch (event.type)
        {
        case sf::Event::KeyPressed:

            handleInputs(event.key.code, true);
            break;

        case sf::Event::KeyReleased:

            handleInputs(event.key.code, false);
            break;

        case sf::Event::Closed:
            window->close();
            break;
        }
    }

}
void Game::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::Up)            //Traslaciones
        eUp = isPressed;
    else if (key == sf::Keyboard::Down)
        eDown = isPressed;
    else if (key == sf::Keyboard::Left)
        eLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        eRight = isPressed;

}

void Game::updateGameState(sf::Time t)
{

    double x=0,y=0,potencia=50;
    int frame=0;

    /*if(t.asSeconds()>timePerFrame.asSeconds())
    {
        frame+=1;
        if(frame>1)
        {
            frame=-1;
        }
    }*/

    if(eRight)
    {
        x=potencia;
        y=0.0;
        player->setDir(2,frame);
    }
    else if(eLeft)
    {
        x=-potencia;
        y=0.0;
        player->setDir(3,frame);//Decimos a donde esta mirando el sprite
    }
    else if(eUp)
    {
        x=0.0;
        y=-potencia;
        player->setDir(1,frame);//Decimos a donde esta mirando el sprite
    }
    else if(eDown)
    {
        x=0.0;
        y=potencia;;
        player->setDir(0,frame);//Decimos a donde esta mirando el sprite

    }


    player->updatePlayer(x,y,t);


}

void Game::render(double i)
{
    window->clear();
    player->drawPlayer(*window,i);
    //lvl.drawLevel(*ventana,i);
    window->display();
}


Game::~Game()
{
    //dtor
}
