#include "Player.h"
#include "Ball.h"
#include "GameSession.h"

#include <iostream>
#include <string>

namespace grupp20{

    void Player::mouseDown(int x, int y){
        //SDL_Point mousePos = { x, y };
        //std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;

        ThrowBall(x, y);
    }

    void Player::ThrowBall(int x, int y){
        Ball* ball = Ball::Instatiate(x, y);
        ses.add(ball);
    }
}