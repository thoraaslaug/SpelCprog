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
        Ball (int x, int y);
        ~Ball() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Ball* Instatiate(int x, int y) { return new Ball(x, y); }
        void reset();
    private:
        int counter;
    };
    
}
#endif
