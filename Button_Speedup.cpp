#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Button.h"
#include "Button_Speedup.h"


using namespace std;

Button_Speedup::Button_Speedup(int x, int y, int w, int h, SDL_Renderer* r, int & c) : Button(x, y, w, h, r), counter(c) {
	//TO DO: Set Images
	unclicked_img = IMG_LoadTexture(renderer, "speedupyellow.png");
	clicked_img = IMG_LoadTexture(renderer, "speedupgreen.png");
	current_img = unclicked_img;
	//TO DO: Reference to scale
}

void Button_Speedup::clicked() {
	counter = max(5, counter - 5);
}
