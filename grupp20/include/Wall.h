#ifndef WALL_H
#define WALL_H

#include "Sprite.h"

namespace grupp20{

    class Wall : public Sprite{
    public:
        Wall(int x, int y, int w, int h) : Sprite(x, y, w, h, "wall.jpg") {}
        ~Wall(){ Sprite::~Sprite(); }
        virtual void collision(const GameObject*);
    private:
        void tick();
    };
}

#endif