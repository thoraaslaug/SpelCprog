//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#include "Wall.h"
#include "DangerousWall.h"
#include "Ball.h"

namespace grupp20{

    void Wall::tick(){
        const GameObject* other = check_collision();
        if(other != nullptr && !dynamic_cast<const Wall*>(other) && !dynamic_cast<const DangerousWall*>(other)){
            collision(other);
        }
    }

    void Wall::collision(const GameObject* other){
       // printf("Wall was hit\n");
    }
}