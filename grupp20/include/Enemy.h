#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Sprite.h"
#include "Ball.h"
#include <string>
#include <vector>

namespace grupp20{

    class Enemy : public Sprite{
    public:
        Enemy(int x, int y, int w, int h, std::string fileName);
        ~Enemy() { Sprite::~Sprite(); }
	    //void draw() const;
	    void tick() {}
        void collision(const GameObject*) {}
	    void mouseDown(int x, int y);
        
        static const std::vector<Player*> getEnemy();
    private:
        static std::vector<Enemy*> enemies;
    };
}

#endif