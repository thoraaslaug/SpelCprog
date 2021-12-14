#include "Player.h"

#include <iostream>
#include <string>

namespace grupp20{

    void Player::mouseDown(int x, int y){

        SDL_Point mousePos = { x, y };

        std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;
    }
}