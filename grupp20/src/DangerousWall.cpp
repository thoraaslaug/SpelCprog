#include "DangerousWall.h"
#include "Ball.h"

namespace grupp20{

    void DangerousWall::tick(){
        const GameObject* other = check_collision();
        if(other != nullptr)
            collision(other);
    }

    void DangerousWall::collision(const GameObject* other){
        /*
        const Ball* b = dynamic_cast<const Ball*>(other);

        if(b != nullptr){
            Ball* ball = const_cast<Ball*>(b);
            ball->bounce();
        }*/

        const Ball* b = dynamic_cast<const Ball*>(other);

        if(b != nullptr){
            Ball* ball = const_cast<Ball*>(b);
            ball->reset();
        }
    }
}