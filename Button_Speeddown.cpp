#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Button.h"
#include "Button_Speeddown.h"


using namespace std;

Button_Speeddown::Button_Speeddown(int x, int y, int w, int h, SDL_Renderer* r, int & c) : Button(x, y, w, h, r), counter(c) {
	//TO DO: Set Images
	unclicked_img = IMG_LoadTexture(renderer, "speeddownred.png");
	clicked_img = IMG_LoadTexture(renderer, "speeddownorange.png");
	current_img = unclicked_img;
	//TO DO: Reference to scale
}

void Button_Speeddown::clicked() {
	counter = min(120, counter + 5);
}
