#include "Ball.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"

#include <iostream>
#include <string>
#include <vector>
#include <tgmath.h>

#define PRECISION 100

namespace grupp20{

    std::vector<Ball*> Ball::balls;
    std::vector<Ball*> const Ball::getBalls(){ return balls; }
    int const Ball::getBallsSize() { return balls.size(); }

    SDL_Point Ball::CalculateVelocity(SDL_Point direction){
        //precisionen är ganska dålig

        //nu normaliserar jag. man kan köra utan normalisering för att få högre precision men
        //då ändras hasigheten i förhållande till hur långt bort man klickar
        
        int x = direction.x - rect.x;
        int y = direction.y - rect.y;

        
        double magnitude = sqrt(x * x + y * y);

        double tempX = (x * PRECISION) / magnitude;
        double tempY = (y * PRECISION) / magnitude;

        x = (int)round(tempX / (PRECISION / 10));
        y = (int)round(tempY / (PRECISION / 10));

        std::cout << "X: " << x << "    " << "Y: " << y << std::endl;

        SDL_Point result = { x, y };
        return result;
    }

    Ball::Ball(SDL_Point direction, int x = 0, int y = 0, int spd = 1) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg"){
        speed = spd;
        velocity = CalculateVelocity(direction);
    }

    Ball* Ball::Instantiate(SDL_Point direction, int x = 0, int y = 0, int spd = 1) {
        int offsetX = x - BALL_SIZE / 2; //account for center pivot
        int offsetY = y - BALL_SIZE / 2;
        Ball* b = new Ball(direction, offsetX, offsetY, spd);
        balls.push_back(b);
		return b;
	}

    void Ball::collision(const GameObject* other){
        std::cout << "Collision!" << std::endl;
        reset();
    }

    void Ball::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);
        
        //object speed
        counter++;
        if(rect.y <= 0 || rect.y >= WINDOW_Y - rect.h || rect.x >= WINDOW_X - rect.w || rect.x <= 0){
            reset();
        }
        else if(counter % speed == 0){
            //rect.x += velocity.x / (PRECISION / 10);
            //rect.y += velocity.y / (PRECISION / 10);
            rect.x += velocity.x;
            rect.y += velocity.y;
        }
	}

    void Ball::reset(){
        //laugh at ball
        //wacky sound effects
        std::cout << "Ball destroyed" << std::endl;

        for(std::vector<Ball*>::iterator i = balls.begin(); i != balls.end();){
            if(*i == this){
                i = balls.erase(i);
                break;
            }
            else{
                i++;
            }
        }

        ses.remove(this);
    }
}