//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include <string>
#include <vector>

#define BALL_SIZE 24 //bollstorlek i pixlar

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
        static Ball* Instantiate(Velocity, int, int, int, int);
        void reset();
        static const std::vector<Ball*> getBalls();
        static const int getBallsSize();
        Velocity getVelocity(){ return velocity; }
    private:
        void CalculateVelocity(Velocity);
	    void tick();
        void collision(const GameObject*);
        int tickSpeed; //1 = fastest
        int speed;
        void bounce(const GameObject*);
        Velocity velocity;
        static std::vector<Ball*> balls;
        const GameObject* latestCollision; //check for latest collided object
        int counter;
    };

    extern const int MAX_BALLS;
    
}
#endif
