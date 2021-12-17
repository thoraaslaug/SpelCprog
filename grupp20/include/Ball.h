#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include <string>
#include <vector>

#define BALL_SIZE 50 //bollstorlek i pixlar

namespace grupp20{

    struct Velocity{
        double x;
        double y;

        double restX;
        double restY;
    };

    class Ball : public Sprite{
    public:
        Ball (Velocity, int, int, int, int);
        ~Ball() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Ball* Instantiate(Velocity, int, int, int, int);
        void reset();
        static const std::vector<Ball*> getBalls();
        static const int getBallsSize();
        Velocity NormalizeVelocity(Velocity);
        int tickSpeed; //1 = fastest
        int speed;
    private:
        Velocity velocity;
        static std::vector<Ball*> balls;
        int counter;
    };

    extern const int MAX_BALLS;
    
}
#endif
