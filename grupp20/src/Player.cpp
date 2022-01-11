//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#include "Player.h"
#include "Ball.h"
#include "GameSession.h"
#include "Goal.h"

#include <iostream>
#include <string>

namespace grupp20{

    std::vector<Player*> Player::players;
    const std::vector<Player*> Player::getPlayers() { return players; }
    

    Player::Player(int x, int y, int w, int h, std::string fileName) : Sprite(x, y, w, h, fileName){
        players.push_back(this);
    }
    
    Player::~Player(){
        
        for(std::vector<Player*>::iterator i = players.begin(); i != players.end();){
            if(*i == this){
                i = players.erase(i);
                break;
            }
            else{
                i++;
            }
        }

        Sprite::~Sprite();
    }

    void Player::mouseDown(int x, int y){
        //SDL_Point mousePos = { x, y };
        //std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;

        ThrowBall();
    }

    Velocity CalculateDirection(){
        SDL_Point p; //punkt att röra sig till
        SDL_GetMouseState(&p.x, &p.y);

        Velocity vel = { (double)(p.x - (BALL_SIZE / 2)), (double)(p.y - (BALL_SIZE / 2)) }; //account for center pivot
        return vel;
    }

    void Player::ThrowBall(){
        if(Ball::getBallsSize() >= MAX_BALLS) return;

        Ball* ball = Ball::Instantiate(CalculateDirection(), getCenterX() + rect.w + 10 , getCenterY() - rect.h - 10, 3, 1);
        //std::cout << getCenterX() <<  " " << getCenterY() << std::endl;
        ses.add(ball);
    }
}