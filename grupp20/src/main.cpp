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


using namespace grupp20;
using namespace std;
std::string grupp20::resPath = "./resources/";
const int grupp20::WINDOW_X = 700;
const int grupp20::WINDOW_Y = 500;
const int grupp20::MAX_BALLS = 3;
GameSession grupp20::ses;
//resPath hittar inte sounds

//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );


int main(int argc, char* argv[]){
    Player player(0, 400, 100, 100, "test.jpg");
    Wall wall1(500, 0, 100, 100);
    Wall wall2(0, 0, 20, 350);
    DangerousWall dwall1(500, 300, 50, 50);
    Goal* goal = Goal::Instantiate(200, 200);
    goal->move_between(0, 75);
    ses.add(&player);
    ses.add(&wall1);
    ses.add(&wall2);
    ses.add(&dwall1);
    ses.run();
    
    return 0;
}