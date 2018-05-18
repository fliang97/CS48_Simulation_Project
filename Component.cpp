#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Component.h"
using namespace std;

Component::Component(int x, int y, int w, int h, SDL_Renderer* r) : xpos(x), ypos(y), width(w), height(h), renderer(r) {
}


 bool Component::isOver(int mousex, int mousey) {
	bool over = (mousex >= xpos && mousex < (xpos + width) && mousey >= ypos && mousey < (ypos + height));
	return over;
}

void Component::clicked() {
}

void Component::pressed() {
}

void Component::released() {
}

void Component::render() {
}
