#include "Ball.h"
#include "GameSession.h"
#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "System.h"
#include <vector>

namespace grupp20{
     std::vector<Ball*> Ball::balls;

    Ball::Ball(int x, int y) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg"){}

     Ball* Ball::Instantiate(int x, int y) {
        Ball* b = new Ball(x, y);
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
		if (rect.y <= 0)
			reset();
		else if (counter % 1 == 0)
			rect.y--;
            rect.x++;
	}

     void Ball::reset(){
        //laugh at ball
        //wacky sound effects
        for(std::vector<Ball*>::iterator i = balls.begin(); i != balls.end();){
            if(*i == this){
        
                i = balls.erase(i);
                break;
            }
            else{
                i++;
        //Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	    //musik = Mix_LoadWAV( (resPath + "sounds/bomba.mp3").c_str());
		//Mix_PlayChannel(-1, musik, -1);
            }
        }
        ses.remove(this);
    }
}