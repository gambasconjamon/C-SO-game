#include "Game.h"
using namespace std;



Game::Game(int resol_x, int resol_y, string gamename)
{


    //ctor
    window= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    window->setVerticalSyncEnabled(true);

    font.loadFromFile("resources/Mario-Kart-DS.ttf");
    if (!font.loadFromFile("resources/Mario-Kart-DS.ttf"))
    {
        std::cerr << "Error cargando fuente ";
        exit(0);
    }


}

void Game::newLevel(string blueprint, string bg, int round){

delete player;
delete mapa;

/** GLOBAL **/
timePerFrame = sf::milliseconds(1000.0/25.0);
Gscale = 1.5;
time_limit = 100;
/** GLOBAL **/
player= new Player();
mapa= new Mapa(0,blueprint,bg);
i_score=0,i_hiscore=300,i_round=round,i_time=100,i_en=5,i_bal=5,i_lives=2;
//Para los eventos
    eJump=false;
    eDown=false;
    eLeft=false;
    eRight=false;

    gravity=0;



}

int Game::Gloop()
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
            if(i_lives>=0&&i_time>=0&&i_en>0)
            {
                if(Death.getElapsedTime().asSeconds()>2)
                {

                    updateGameState(elapsedTime);
                }
                else
                {
                    player->setPos(sf::Vector2f(240,420));
                    Spawn.restart();
                    enemigos.clear();
                }
            }
            else
            {

                return i_en;
            }
        }

        //Se calcula el porcentaje de interpolacion
        interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        //Renderizamos con interpolacion
        render(interpolation);

    }

    return 0;

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
void Game::generateEnemigos()
{

    int i= rand() % mapa->getNumSpawns();

    if(enemigos.size()<3)
    {
     if(enemigos.size()<=i_en)
    {
        Enemigo* auxen= new Enemigo();
        cout<<"Spawnea en"<< mapa->getSpawn(i).x <<" , "<<mapa->getSpawn(i).y<<endl;
        auxen->setPos(mapa->getSpawn(i));
        enemigos.push_back(auxen);
        }
    }

}
void Game::updateGameState(sf::Time t)
{


    double x=0,y=0,potencia=100;
    int frame=0;

    this->i_time=time_limit-Timer.getElapsedTime().asSeconds();
    if(this->i_time==0)
    {
        exit(0);
    }
    if(eRight)
    {
        x=potencia;

    }
    if(eLeft)
    {
        x=-potencia;

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
    if(enemigos.size()!=0)
    {
        for(unsigned i=0; i< enemigos.size(); i++)
        {
            enemigos[i]->updateEnemigo(player->getPos()[0],player->getPos()[1],t,handleECollision(i));
        }
    }
    if(Spawn.getElapsedTime().asSeconds()>5)
    {
        generateEnemigos();
        Spawn.restart();
    }
    handleBalancin();


}

sf::Vector2f Game::handleCollision()
{
    int last=0;

    float offsety=0,offsetx=0;
    player->setTouchingFloor(false);
    player->setTouchingEscalera(false);
    player->setTouchingTrampolin(false);
    player->setTouchingPuerta(false);
    for(int t=0 ; t<7; t++)
    {
        for(int i=0; i<mapa->getElementos(t).size(); i++)
        {

            if(t<6&&player->getColliderDown().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
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

                    offsetx= player->getColliderDown().left-mapa->getElementos(t)[i].getGlobalBounds().left+1;
                    cout<<"Offset de x es: "<<offsetx<<endl;
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
                if (t==5)
                {

                    offsetx= player->getSprite().getGlobalBounds().left-mapa->getElementos(t)[i].getGlobalBounds().left+1;
                    cout<<"Offset de x es: "<<offsetx<<endl;

                }

            }
            else if(player->getSprite().getGlobalBounds().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
            {
                if (t==6)
                {

                    mapa->deleteElemento(6,i);
                    i_score+=40;
                    time_limit+=10;
                }
            }

        }
    }
    for(unsigned en=0; en< enemigos.size(); en++)
    {

        if(enemigos[en]->getColliderDown().intersects(player->getSprite().getGlobalBounds()))
        {
            cout<<"Player muere por colision"<<endl;
            Death.restart();
            time_limit+=5;
            i_lives--;
        }

    }

    return sf::Vector2f(offsetx,offsety);
}

sf::Vector2f Game::handleECollision(int en)
{
    int last=0;
    float offsetx=0,offsety=0;

    enemigos[en]->setTouchingFloor(false);
    enemigos[en]->setTouchingEscalera(false);
    enemigos[en]->setTouchingTrampolin(false);
    enemigos[en]->setTouchingPuerta(false);
    for(int t=0 ; t<11; t++)
    {
        if(t<7)
        {
            for(int i=0; i<mapa->getElementos(t).size(); i++)
            {

                if(t<6&&enemigos[en]->getColliderDown().intersects(mapa->getElementos(t)[i].getGlobalBounds()))
                {

                    if (t==0)
                    {
                        enemigos[en]->setTouchingFloor(true);
                        offsety= enemigos[en]->getColliderDown().top-mapa->getElementos(t)[i].getGlobalBounds().top+1;
                        //cout<<"Offset de colision "<<offset  << endl;
                    }
                    if (t==1)
                    {
                        enemigos[en]->setTouchingEscalera(true);

                    }
                    if (t==2)
                    {
                        offsety= enemigos[en]->getColliderDown().top-mapa->getElementos(t)[i].getGlobalBounds().top+1;
                        enemigos[en]->setTouchingTrampolin(true);

                    }
                    if (t==3)
                    {

                         offsetx= enemigos[en]->getColliderDown().left-mapa->getElementos(t)[i].getGlobalBounds().left+1;
                    cout<<"Offset de x es: "<<offsetx<<endl;
                        if(i==0 && (i+1)<mapa->getElementos(t).size())
                        {
                            last=i+1;
                        }
                        else
                        {
                            last=i-1;
                        }
                        enemigos[en]->setUltPuerta(i,mapa->getElementos(t)[last].getPosition());
                        enemigos[en]->setTouchingPuerta(true);


                    }

                    if (t==5)
                    {

                        offsetx= enemigos[en]->getSprite().getGlobalBounds().left-mapa->getElementos(t)[i].getGlobalBounds().left+1;
                        cout<<"Offset de x es: "<<offsetx<<endl;

                    }
                }
            }
        }

        if (t>=7)
        {
            for(int i=0; i<mapa->getAccion(t).size(); i++)
            {
                if(enemigos[en]->getColliderDown().intersects(mapa->getAccion(t)[i]))
                {


                    offsety= enemigos[en]->getColliderDown().top-mapa->getAccion(t)[i].top+1;

                    if(t==9)
                        enemigos[en]->setDecidingJump(true);

                    if(t==10)
                        enemigos[en]->setDecidingStairs(true);
                }
            }

        }
    }

    return sf::Vector2f(offsetx,offsety);
}

float Game::handleBalancin()
{

    bool endol=false,endor=false,enupl=false,enupr=false,pldol=false,pldor=false,plupl=false,plupr=false;
    int id=0,ene=0;


    for(int i=0; i<mapa->getAccion(7).size(); i++)
    {

        if(player->getColliderDown().intersects(mapa->getAccion(7)[i]))
        {

            pldor=true;


        }
        else if(player->getColliderDown().intersects(mapa->getAccion(8)[i]))
        {
            pldol=true;
        }




        else if(player->getColliderTop().intersects(mapa->getAccion(7)[i]))
        {

            plupr=true;



        }
        else if(player->getColliderTop().intersects(mapa->getAccion(8)[i]))
        {
            plupl=true;

        }

        for(unsigned en=0; en< enemigos.size(); en++)
        {

            if(enemigos[en]->getColliderDown().intersects(mapa->getAccion(7)[i]))
            {

                endor=true;
                ene=en;
                en=enemigos.size();


            }
            else if(enemigos[en]->getColliderDown().intersects(mapa->getAccion(8)[i]))
            {
                endol=true;
                ene=en;
                en=enemigos.size();
            }




            else if(enemigos[en]->getColliderTop().intersects(mapa->getAccion(7)[i]))
            {

                enupr=true;
                ene=en;
                en=enemigos.size();



            }
            else if(enemigos[en]->getColliderTop().intersects(mapa->getAccion(8)[i]))
            {
                enupl=true;
                ene=en;
                en=enemigos.size();

            }




        }
        id=i;
        if(endol||endor||enupl||enupr||pldol||pldor||plupl||plupr)
            i=mapa->getAccion(7).size();


    }

    if(mapa->getBalancinTog(id)==false)
    {

        if(pldol)
        {
            if(endor||enupl)
            {
                cout<<"Enemigo muere estampado \ "<<endl;
                    cout<<ene<<" de "<<enemigos.size()<<endl;

                    if(enemigos.size()!=0)
                    enemigos.erase(enemigos.begin()+ene);
                    i_en--;
                    i_score+=100;

                }
                    mapa->updateBalancin(id);
                }
                    if(endol)
                {
                    if(pldor||plupl)
                {
                    cout<<"Player muere \ "<<endl;
                    Death.restart();
                    i_lives--;
                     time_limit+=2;
                }
                    mapa->updateBalancin(id);
                }
                }
                    else if(mapa->getBalancinTog(id)==true)
                {

                    if(pldor)
                {
                    if(endol||enupr)
                {
                    cout<<"Enemigo muere estampado / "<<endl;
                    cout<<ene<<" de "<<enemigos.size()<<endl;
                    if(enemigos.size()!=0)
                    enemigos.erase(enemigos.begin()+ene);
                    i_en--;
                    i_score+=100;

                }
                    mapa->updateBalancin(id);
                }
                    if(endor)
                {
                    if(pldol||plupr)
                {
                    cout<<"Player muere / "<<endl;
                    Death.restart();
                    i_lives--;
                     time_limit+=2;
                }
                    mapa->updateBalancin(id);
                }
                }

                    return 0.0;
                }
                    void Game::render(double i)
                {
                    window->clear();

                    //lvl.drawLevel(*ventana,i);

                    mapa->drawMapa(*window,i);
                    if(enemigos.size()!=0)//Cuidado con esto, si no hay enemigos no te deja updatear el balancin
                {
                    for(unsigned en=0; en< enemigos.size(); en++)
                {
                    enemigos[en]->drawEnemigo(*window,i);
                }
                }
                    player->drawPlayer(*window,i);

                    this->drawDataScore();
                    window->display();
                }

                    Game::~Game()
                {
                    //dtor
                }
