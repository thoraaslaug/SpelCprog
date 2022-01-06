#include "DangerousWall.h"
#include "Ball.h"

namespace grupp20{

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