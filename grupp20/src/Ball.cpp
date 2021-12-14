#include "Ball.h"

#include <iostream>
#include <string>

namespace grupp20{

    void Ball::mouseDown(int x, int y){

        SDL_Point mousePos = { x, y };

        std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;
    }

    static Ball* getInstance(int x, int y, int w, int h, std::string fileName) {
		return new Ball(x, y, w, h, "ball.jpg");
	}
}