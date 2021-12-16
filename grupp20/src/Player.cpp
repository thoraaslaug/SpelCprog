#include "Player.h"
#include "Ball.h"
#include "GameSession.h"

#include <iostream>
#include <string>

namespace grupp20{

    std::vector<Player*> players;
    const std::vector<Player*> getPlayers() { return players; }

    Player::Player(int x, int y, int w, int h, std::string fileName) : Sprite(x, y, w, h, fileName){}

    void Player::mouseDown(int x, int y){
        //SDL_Point mousePos = { x, y };
        //std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;

        ThrowBall();
    }

    SDL_Point CalculateDirection(){
        SDL_Point p; //punkt att röra sig till
        SDL_GetMouseState(&p.x, &p.y);

        return p;
    }

    void Player::ThrowBall(){
        if(Ball::getBallsSize() >= MAX_BALLS) return;

        Ball* ball = Ball::Instantiate(CalculateDirection(), rect.x + 200, rect.y - 200, 1);
        ses.add(ball);
    }

}