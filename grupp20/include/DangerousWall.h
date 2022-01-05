#ifndef DANGEROUSWALL_H
#define DANGEROUSWALL_H

#include "Sprite.h"

namespace grupp20{

    class DangerousWall : public Sprite{
    public:
        DangerousWall(int x, int y, int w, int h) : Sprite(x, y, w, h, "wall.jpg") {}
        ~DangerousWall(){ Sprite::~Sprite(); }
        void tick();
        void collision(const GameObject*);
    private:
    };
}
#endif