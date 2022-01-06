#ifndef DANGEROUSWALL_H
#define DANGEROUSWALL_H

#include "Wall.h"

namespace grupp20{

    class DangerousWall : public Wall{
    public:
        DangerousWall(int x, int y, int w, int h) : Wall(x, y, w, h) {}
        ~DangerousWall(){ Wall::~Wall(); }
    private:
        void collision(const GameObject*);
    };
}
#endif