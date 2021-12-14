#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include "System.h"
#include "GameSession.h"

using namespace std;
using namespace grupp20;

//resPath måste ändras i System header-filen då vi antar att den måste finnas inom grupp20-namespacet

//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );

GameSession ses;

int main(int argc, char* argv[]){
    ses.run();

    return 0;
}