#include "Ball.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"

#include <iostream>
#include <string>
#include <vector>
#include <tgmath.h>

namespace grupp20{

    std::vector<Ball*> Ball::balls;
    std::vector<Ball*> const Ball::getBalls(){ return balls; }
    int const Ball::getBallsSize() { return balls.size(); }

    SDL_Point Ball::CalculateVelocity(SDL_Point direction){
        int x = direction.x - rect.x;
        int y = direction.y - rect.y;

        double magnitude = sqrt(x * x + y * y);

        double tempX = x / magnitude;
        double tempY = y / magnitude;

        x = (int)(tempX * 10); //eftersom att point sätts i intar måste vi tiodubbla normaliseringen
        y = (int)(tempY * 10);

        std::cout << "X: " << x << "    " << "Y: " << y << std::endl;

        SDL_Point result = { x, y };
        return result;
    }

    Ball::Ball(SDL_Point direction, int x = 0, int y = 0, int spd = 1) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg"){
        speed = spd;
        velocity = CalculateVelocity(direction);
    }

    Ball* Ball::Instantiate(SDL_Point direction, int x = 0, int y = 0, int spd = 1) {
        Ball* b = new Ball(direction, x, y, spd);
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
        /*
		counter++;
		if (rect.y <= 0)
			reset();
		else if (counter % 1 == 0)
			rect.y--;
            rect.x++;*/
        
        counter++;
        //rect.x > WINDOW_X || rect.x < 0 || rect.y < 0 || rect.y > WINDOW_Y
        if(rect.y <= 0 || rect.y >= WINDOW_Y - rect.h || rect.x >= WINDOW_X - rect.w || rect.x <= 0){
            reset();
        }
        else if(counter % speed == 0){
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