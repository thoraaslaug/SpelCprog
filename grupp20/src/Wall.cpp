#include "Wall.h"
#include "Ball.h"

namespace grupp20{

    void Wall::tick(){
        const GameObject* other = check_collision();
        if(other != nullptr)
            collision(other);
    }

    void Wall::collision(const GameObject* other){
        printf("Wall was hit\n");
    }
}