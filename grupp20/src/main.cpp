#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include "System.h"
#include "GameSession.h"
#include "GameObject.h"
//#include "Sprite.h"
#include "Player.h"
#include "Ball.h"

using namespace std;
using namespace grupp20;

//resPath måste ändras i System header-filen då vi antar att den måste finnas inom grupp20-namespacet

//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );

//nuvarande storlek 700x500

int main(int argc, char* argv[]){
    Player player(0, 400, 100, 100, "test.jpg");
    ses.add(&player);
    ses.run();
    
    return 0;
}