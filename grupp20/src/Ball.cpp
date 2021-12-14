#include "Ball.h"
#include "GameSession.h"

#include <iostream>
#include <string>

namespace grupp20{

    static Ball* Instantiate(int x, int y) {
		return new Ball(x, y);
	}

    void Ball::collision(const GameObject* other){
        std::cout << "Collision!" << std::endl;
        ses.remove(this);
    }

    void Ball::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);

        //object speed
		counter++;
		if (rect.y <= 0)
			ses.remove(this);
		else if (counter % 1 == 0)
			rect.y--;
            rect.x++;
	}
}