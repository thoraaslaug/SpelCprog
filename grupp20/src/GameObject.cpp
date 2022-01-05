#include "GameObject.h"
#include "GameSession.h"

namespace grupp20{

    const GameObject* GameObject::check_collision(){

        for(GameObject* go : ses.gameObjects){
            if(SDL_HasIntersection(&rect, &go->rect) && go != this){
                return go;
            }
        }

        return nullptr;
    }

    void GameObject::move(){
        counter++;
        if(counter % tickSpeed == 0){
            if(moveX > 0){
                if(moveRight){
                    rect.x++; //utbyt till lerp???

                    if(rect.x == moveX) moveRight = false;
                }//right
                else{
                    rect.x--;//utbyt till lerp???
                    if(rect.x == (XOrigin - rect.x)) moveRight = true;
                }//left
            }
            if(moveY > 0){
                if(moveUp){
                    rect.y++; //utbyt till lerp???

                    if(rect.y == moveY) moveUp = false;
                }//up
                else{
                    rect.y--;//utbyt till lerp???
                    if(rect.y == (YOrigin - rect.y)) moveUp = true;
                }//down
            }
        }
    }

    void GameObject::move_between(int x, int y){
        if(x > 0){
            moveRight = true;
            moveX = rect.x + x;
        }
        if(y > 0){
            moveUp = true;
            moveY = rect.y + y;
        }
    }
}