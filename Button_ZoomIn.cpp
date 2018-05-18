#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

#include "Button.h"
#include "Button_ZoomIn.h"

using namespace std;

Button_ZoomIn::Button_ZoomIn(int x, int y, int w, int h, SDL_Renderer* r) : Button(x, y, w, h, r) {
}

void Button_ZoomIn::clicked() {
}

void Button_ZoomIn::render() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = width;
	rect.h = height;
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	SDL_SetRenderDrawColor(renderer, 100, 50, 120, 255);
	SDL_RenderFillRect(renderer, &rect);
}
