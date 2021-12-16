#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include <string>
#include <vector>

#define BALL_SIZE 50 //bollstorlek i pixlar

namespace grupp20{

    class Ball : public Sprite{

    public:
        Ball (SDL_Point, int, int, int);
        ~Ball() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Ball* Instantiate(SDL_Point, int, int, int);
        void reset();
        static const std::vector<Ball*> getBalls();
        static const int getBallsSize();
        SDL_Point CalculateVelocity(SDL_Point);
        int speed; //1 = fastest
    private:
        SDL_Point velocity;
        static std::vector<Ball*> balls;
        int counter;
    };

    extern const int MAX_BALLS;
    
}
#endif
