#include <string>
#include <iostream>

using namespace std;

std::string resPath = "../resources/";
//exempel: SDL_LoadBMP( (resPath + "images/bg.bmp").c_str() );

int main(int argc, char* argv[]){
    std::string greetings = "Hello World!";
    std::cout << greetings << std::endl;

    return 0;
}