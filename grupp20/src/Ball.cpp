#include "Ball.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

namespace grupp20{

    std::vector<Ball*> Ball::balls;
    std::vector<Ball*> const Ball::getBalls(){ return balls; }
    int const Ball::getBallsSize() { return balls.size(); }

    Velocity Ball::NormalizeVelocity(Velocity direction){
        double x = direction.x - rect.x;
        double y = direction.y - rect.y;
        
        double magnitude = sqrt(x * x + y * y);

        x /= magnitude;
        y /= magnitude;

        Velocity result = { x, y };
        std::cout << "X: " << result.x << "    " << "Y: " << result.y << std::endl;
        return result;
    }

    Ball::Ball(Velocity direction, int x = 0, int y = 0, int ballSpeed = 1, int tick = 1) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg"){
        speed = ballSpeed;
        tickSpeed = tick;
        velocity = NormalizeVelocity(direction);
    }

    Ball* Ball::Instantiate(Velocity direction, int x = 0, int y = 0, int ballSpeed = 1, int tick = 1) {
        int offsetX = x - BALL_SIZE / 2; //account for center pivot
        int offsetY = y - BALL_SIZE / 2;
        Ball* b = new Ball(direction, offsetX, offsetY, ballSpeed, tick);
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
        else if(counter % tickSpeed == 0){
            double velX = 0;
            double velY = 0;
            
            velocity.restX += velocity.x;
            velocity.restY += velocity.y;

            if(velocity.restX >= 1 && velocity.x >= 0){ velX++; velocity.restX--; }
            if(velocity.restY >= 1 && velocity.y >= 0) { velY++; velocity.restY--; }
            if(velocity.restX <= -1 && velocity.x < 0) { velX--; velocity.restX++; }
            if(velocity.restY <= -1 && velocity.y < 0) { velY--; velocity.restY++; }
            
            rect.x += (int)round(velX) * speed;
            rect.y += (int)round(velY) * speed;
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