//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841

#include "Ball.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>

namespace grupp20{

    std::vector<Ball*> Ball::balls;
    std::vector<Ball*> const Ball::getBalls(){ return balls; }
    int const Ball::getBallsSize() { return balls.size(); }

    void Ball::bounce(const GameObject* other){
        if(latestCollision == other) return;
        latestCollision = other;

        //printf("Bounce!");
        
        int otherCenterX = (other->getRect().w / 2);
        int otherCenterY = other->getRect().h / 2;
        int ballCenterX = rect.w / 2;
        int ballCenterY = rect.h / 2;

        int distanceX = (other->getRect().x + otherCenterX) - (rect.x + ballCenterX);
        int distanceY = (other->getRect().y + otherCenterY) - (rect.y + ballCenterY);

        
        if(distanceX < -otherCenterX || distanceX > otherCenterX){
            velocity.x = -velocity.x;
        }
        //upper under
        if(distanceY < -otherCenterY || distanceY > otherCenterY){
            velocity.y = -velocity.y;
        }
    }

    void Ball::CalculateVelocity(Velocity direction){
        double x = direction.x - rect.x;
        double y = direction.y - rect.y;
        
        double magnitude = sqrt(x * x + y * y);

        x /= magnitude;
        y /= magnitude;

        Velocity result = { x, y };
        //std::cout << "X: " << result.x << "    " << "Y: " << result.y << std::endl;
        
        velocity = result;
    }

    Ball::Ball(Velocity direction, int x = 0, int y = 0, int ballSpeed = 1, int tick = 1) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "Ball.png"){
        speed = ballSpeed;
        tickSpeed = tick;
        CalculateVelocity(direction);
    }

    Ball* Ball::Instantiate(Velocity direction, int x = 0, int y = 0, int ballSpeed = 1, int tick = 1) {
        int offsetX = x - BALL_SIZE / 2; //account for center pivot
        int offsetY = y - BALL_SIZE / 2;
        Ball* b = new Ball(direction, offsetX, offsetY, ballSpeed, tick);
        balls.push_back(b);
		return b;
	}

    void Ball::collision(const GameObject* other){
        //std::cout << "Collision!" << std::endl;

        const Ball* b = dynamic_cast<const Ball*>(other);

        if(b != nullptr){
            reset();
        }
        else{
            bounce(other);
        }
    }

    void Ball::tick() {
        //latestCollision = nullptr;
       // std::cout << "X: " << velocity.x << "    " << "Y: " << velocity.y << std::endl;

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