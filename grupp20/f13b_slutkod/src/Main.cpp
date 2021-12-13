#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

// Paths to resource folders. Change to your own path!
//std::string resPath = "/Users/kjellna/dev/cpp21/f13b_v2/resources/";
std::string resPath = "../../resources/";

Session ses;


class Bullet : public Component {
public:
	static Bullet* getInstance(int x) {
		return new Bullet(x);
	}
	Bullet(int x) : Component(x, 500, 40,40){
		// Path to your own 'images' folder.
		//texture = IMG_LoadTexture(sys.ren, "/Users/kjellna/dev/cpp21/f13b/images/dot40x40.bmp");
		texture = IMG_LoadTexture(sys.ren, (resPath + "images/dot40x40.bmp").c_str() );
	}
	~Bullet() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		// Code adjustment to handle the address to temporary object. 
		const SDL_Rect &rect = getRect();
		//SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick() {
		counter++;
		if (rect.y <= 0)
			ses.remove(this);
		else if (counter % 10 == 0)
			rect.y--;
	}
private:
	SDL_Texture* texture;
	int counter = 0;
};

class Pistol : public Component {
public:
	Pistol() :Component(0, 0, 0, 0) {}
	void draw() const {}
	void tick() {}
	void mouseDown(int x, int y) {
		Bullet* b = Bullet::getInstance(x);
		ses.add(b);
	}
};

int main(int argc, char** argv) {
	Pistol* pistol = new Pistol();
	ses.add(pistol);
	ses.run();
	
	return 0;
}
