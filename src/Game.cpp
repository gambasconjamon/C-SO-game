#include "Game.h"
using namespace std;

/** GLOBAL **/
const sf::Time Game::timePerFrame = sf::milliseconds(1000.0/25.0);
const float Game::Gscale = 1.5;
const int timelimit = 100;
/** GLOBAL **/

Game::Game(int resol_x, int resol_y, string gamename)
{

    //ctor
    window= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    window->setVerticalSyncEnabled(true);



    player= new Player();
    mapa= new Mapa(0);

    i_score=0,i_hiscore=300,i_round=00,i_time=100,i_en=5,i_bal=5,i_lives=2;

    font.loadFromFile("resources/Mario-Kart-DS.ttf");
    if (!font.loadFromFile("resources/Mario-Kart-DS.ttf"))
    {
        std::cerr << "Error cargando fuente ";
        exit(0);
    }

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

void Game::updateDataScore(int i_score,int i_hiscore,int i_round,int i_time,int i_en,int i_bal,int i_lives)
{


}
void Game::drawDataScore()
{


    t_score.setFont(font); // font is a sf::Font
// set the string to display
    std::stringstream ss;  // #include <sstream>
    ss << setw(7) << setfill('0') << i_score;
    t_score.setString("score  "+ss.str()+"");
    t_score.setCharacterSize(23);
    t_score.setColor(sf::Color::White);
    t_score.setStyle(sf::Text::Bold);
    t_score.setOrigin(0,0);
    t_score.setPosition(16.0,-8.0);

    t_hiscore.setFont(font);
   std::stringstream ss1;  // #include <sstream>
    ss1 << setw(5) << setfill('0') << i_hiscore;
    t_hiscore.setString("hi-score  "+ss1.str()+"");
    t_hiscore.setCharacterSize(23);
    t_hiscore.setColor(sf::Color::White);
    t_hiscore.setStyle(sf::Text::Bold);
    t_hiscore.setOrigin(0,0);
    t_hiscore.setPosition(16.0,8.0);

    t_round.setFont(font);
    std::stringstream ss2;  // #include <sstream>
    ss2 << setw(2) << setfill('0') << i_round;
    t_round.setString("round  "+ss2.str()+"");
    t_round.setCharacterSize(23);
    t_round.setColor(sf::Color::White);
    t_round.setStyle(sf::Text::Bold);
    t_round.setOrigin(0,0);
    t_round.setPosition(16.0,24.0);

    t_time.setFont(font);
    std::stringstream ss3;  // #include <sstream>
    ss3 << setw(3) << setfill('0') << i_time;
    t_time.setString("time  "+ss3.str()+"");
    t_time.setCharacterSize(23);
    t_time.setColor(sf::Color::White);
    t_time.setStyle(sf::Text::Bold);
    t_time.setOrigin(0,0);
    t_time.setPosition(32.0,40.0);

    t_en.setFont(font);
    std::stringstream ss4;  // #include <sstream>
    ss4 << setw(2) << setfill('0') << i_en;
    t_en.setString(""+ss4.str()+"");
    t_en.setCharacterSize(23);
    t_en.setColor(sf::Color::White);
    t_en.setStyle(sf::Text::Bold);
    t_en.setOrigin(0,0);
    t_en.setPosition(32.0,56.0);
    t_en.setFont(font);

    t_bal.setFont(font);
    std::stringstream ss5;  // #include <sstream>
    ss5 << setw(2) << setfill('0') << i_bal;
    t_bal.setString(""+ss5.str()+"");
    t_bal.setCharacterSize(23);
    t_bal.setColor(sf::Color::White);
    t_bal.setStyle(sf::Text::Bold);
    t_bal.setOrigin(0,0);
    t_bal.setPosition(96.0,56.0);

    t_lives.setFont(font);
    std::stringstream ss6;  // #include <sstream>
    ss6 << setw(2) << setfill('0') << i_lives;
    t_lives.setString("lives  "+ss6.str()+"");
    t_lives.setCharacterSize(23);
    t_lives.setColor(sf::Color::White);
    t_lives.setStyle(sf::Text::Bold);
    t_lives.setOrigin(0,0);
    t_lives.setPosition(32.0,72.0);



    window->draw(t_score);
    window->draw(t_hiscore);
    window->draw(t_round);
    window->draw(t_time);
    window->draw(t_en);
    window->draw(t_bal);
     window->draw(t_lives);

}

void Game::updateGameState(sf::Time t)
{

    double x=0,y=0,potencia=100;
    int frame=0;

    this->i_time=timelimit-Timer.getElapsedTime().asSeconds();
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


        if(player->isTouchingFloor())
        {
            y=-potencia*2.5;
        }

    }
    if(eUp)
    {



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
    int last=0;

    float offsety=0;
    player->setTouchingFloor(false);
    player->setTouchingEscalera(false);
    player->setTouchingTrampolin(false);
    player->setTouchingPuerta(false);
    for(int t=0 ; t<5; t++)
        for(int i=0; i<mapa->getElementos(t).size(); i++)
        {

            if(t<4&&player->getColliderDown().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
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
                if (t==2)
                {
                    offsety= player->getColliderDown().top-mapa->getElementos(t)[i].getGlobalBounds().top+1;
                    player->setTouchingTrampolin(true);

                }
                if (t==3)
                {

                    offsety= player->getColliderDown().top-mapa->getElementos(t)[i].getGlobalBounds().top+1;
                    if(i==0 && (i+1)<mapa->getElementos(t).size())
                    {
                        last=i+1;
                    }
                    else
                    {
                        last=i-1;
                    }
                    player->setUltPuerta(i,mapa->getElementos(t)[last].getPosition());
                    player->setTouchingPuerta(true);


                }



            }
            else if(player->getSprite().getGlobalBounds().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
            {
                if (t==4)
                {

                    mapa->deleteElemento(4,i);
                    this->i_score+=40;
                }
            }

        }

    return offsety;
}

void Game::render(double i)
{
    window->clear();

    //lvl.drawLevel(*ventana,i);
    mapa->drawMapa(*window,i);
    player->drawPlayer(*window,i);
    this->drawDataScore();
    window->display();
}

Game::~Game()
{
    //dtor
}
