#include "Enemy.h"
#include "Ball.h"
#include "GameSession.h"

#include <iostream>
#include <string>

namespace grupp20{

    std::vector<Enemy*> enemies;
    const std::vector<Player*> getPlayers() { return enemies; }

    Enemy::Enemy(int x, int y, int w, int h, std::string fileName) : Sprite(x, y, w, h, fileName){}

    void Enemy::mouseDown(int x, int y){
        //SDL_Point mousePos = { x, y };
        //std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;

        //ThrowBall();
    }

    /*Velocity CalculateDirection(){
        SDL_Point p; //punkt att röra sig till
        SDL_GetMouseState(&p.x, &p.y);

        Velocity vel = { (double)(p.x - (BALL_SIZE / 2)), (double)(p.y - (BALL_SIZE / 2)) }; //account for center pivot
        return vel;
    }*/

   /* void Enemy::ThrowBall(){
        if(Ball::getBallsSize() >= MAX_BALLS) return;

        Ball* ball = Ball::Instantiate(CalculateDirection(), rect.x + 200, rect.y - 200, 1, 1);
        ses.add(ball);
    }*/

}