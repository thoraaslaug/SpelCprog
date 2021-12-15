#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include <string>
#include <vector>
#include <SDL2/SDL_mixer.h>

#define BALL_SIZE 50 //bollstorlek i pixlar

namespace grupp20{

    class Ball : public Sprite{

    public:
        Mix_Chunk* musik;
        Ball (int x, int y);
        ~Ball() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Ball* Instatiate(int x, int y) { return new Ball(x, y); }
        void reset();
        void musicPlay();

    private:
        int counter;
    };
    
}
#endif
