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
}