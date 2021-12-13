#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include "System.h"
#include "GameSession.h"

using namespace std;
using namespace grupp20;

//string resPath = "C:/Users/46768/Documents/GitHub/SpelCprog/grupp20/resources";
//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );

GameSession ses;

int main(int argc, char* argv[]){
    ses.run();

    return 0;
}