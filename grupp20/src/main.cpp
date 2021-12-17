#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include "System.h"
#include "GameSession.h"
#include "Player.h"
#include "Ball.h"
#include "Goal.h"
#include "ObjSpawner.h"


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
    ObjSpawner objspawner;
    Player player(0, 400, 100, 100, "test.jpg");
    ses.add(&objspawner);
    ses.add(&player);
    ses.run();
    
    return 0;
}