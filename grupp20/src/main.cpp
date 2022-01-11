//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include "System.h"
#include "GameSession.h"
#include "Player.h"
#include "Ball.h"
#include "Goal.h"
#include "Wall.h"
#include "DangerousWall.h"

//grupp20::System sys;
std::string grupp20::resPath = "./resources/";
using namespace grupp20;
using namespace std;
const int grupp20::WINDOW_X = 700;
const int grupp20::WINDOW_Y = 500;
const int grupp20::MAX_BALLS = 3;
GameSession grupp20::ses;
//resPath hittar inte sounds

//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );


int main(int argc, char* argv[]){
    Player player(0, 450, 50, 50, "Spelare.png");
    Wall wall1(200, 350, 100, 100);
    Wall wall2(0, 0, 24, 450);
    DangerousWall dwall1(24, 0, 676, 24);
    DangerousWall dwall2(50, 476, 650, 24);
    DangerousWall dwall3(676, 24, 24, 100);
    DangerousWall dwall4(676, 428, 24, 48);
    Wall wall3(500, 190, 60, 120);
    Wall wall4(100, 24, 100, 100);
    Wall wall6(340, 24, 100, 50);
    Wall wall7(606, 24, 70, 50);
    Wall wall5(495, 350, 80, 126);
    //Wall wall3(0, 200, 100, 100);
    //DangerousWall dwall1(400, 200, 50, 50);
    Goal* goal = Goal::Instantiate(700 - 50, 250);
    goal->move_between(0, 75);
    ses.add(&player);
    ses.add(&wall1);
    ses.add(&wall2);
    ses.add(&wall3);
    ses.add(&dwall1);
    ses.add(&wall4);
    ses.add(&wall6);
    ses.add(&wall5);
    ses.add(&wall7);
    ses.add(&dwall2);
    ses.add(&dwall3);
    ses.add(&dwall4);
    ses.run();
    
    return 0;
}