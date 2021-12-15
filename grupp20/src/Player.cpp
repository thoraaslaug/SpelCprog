#include "Player.h"
#include "Ball.h"
#include "GameSession.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Ball.h"
#include "System.h"


#define MAX_BALLS 1

namespace grupp20{

    void Player::mouseDown(int x, int y){
        //SDL_Point mousePos = { x, y };
        //std::cout << SDL_PointInRect(&mousePos, &rect) << std::endl;

        ThrowBall(x, y);
    }

        void Player::ThrowBall(int x, int y){
        if(Ball::balls.size() >= MAX_BALLS) return;
        Ball* ball = Ball::Instantiate(x, y);
        Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	    musik = Mix_LoadWAV( (resPath + "sounds/throw.wav").c_str());
		Mix_PlayChannel(-1, musik, 1);
        ses.add(ball);
    }
}