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

class Kasta : public GameObject {
public:
	Kasta() :GameObject(0, 0, 0, 0) {}
	void draw() const {}
	void tick() {}
	void mouseDown(int x, int y) {
		//Ball* b = Ball::getInstance(x, y, 70, 70, "ball.jpg");
		ses.add(b);
	}
};
int main(int argc, char* argv[]){
    Player player(0, 0, 100, 100, "test.jpg");
    Kasta* kast = new Kasta();
    ses.add(kast);
    ses.add(&player);
    
    ses.run();
    
    return 0;
}