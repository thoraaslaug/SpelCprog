#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <vector>
#include "GameObject.h"

namespace grupp20
{
    class GameSession
    {
    public:
        void run();
        void add(GameObject*);
        void remove(GameObject*);
    private:
        std::vector<GameObject*> gameObjects;
        std::vector<GameObject*> added, removed;

        friend const GameObject* GameObject::check_collision();
    };

    extern GameSession ses;

    //gör mer generisk?
    //template<typename T>
    //GameObject* find_first(T obj)
    //{
        //for(GameObject* go : ses.gameObjects){
            //if(std::is_same<obj, go>) return go;
        //}

        //return nullptr;
    //}

    /*
    template<typename T>
    bool contains(this std::vector<T>, T obj){
        for(T go : this)
        {
            if(std::is_same<obj, go>) return true;
        }

        return false;
    }*/
}

#endif