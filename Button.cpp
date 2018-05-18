#include "Component.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cstdlib>
#include "Button.h"

using namespace std;

Button::Button(int x, int y, int w, int h, SDL_Renderer* r) : Component(x, y, w, h, r) {
  clicked_img = NULL;
  unclicked_img = NULL;
  current_img = unclicked_img;
}

void Button::clicked() {
}

void Button::pressed() {
	current_img = clicked_img;
}

void Button::released() {
	current_img = unclicked_img;
}

void Button::render() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(renderer, current_img, NULL, &rect);
}
