#include "Ball.h"
#include "GameSession.h"
#include "Player.h"

#include <iostream>
#include <string>

namespace grupp20{

    Ball::Ball(int x, int y) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg"){}

    static Ball* Instantiate(int x, int y) {
		return new Ball(x, y);
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
		if (rect.y <= 0)
			reset();
		else if (counter % 1 == 0)
			rect.y--;
            rect.x++;
	}

    void Ball::reset(){
        //laugh at ball
        //wacky sound effects
        ses.remove(this);
    }
}