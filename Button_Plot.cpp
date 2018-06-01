#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

#include "Button.h"
#include "Button_Plot.h"


using namespace std;

Button_Plot::Button_Plot(int x, int y, int w, int h, SDL_Renderer* r, bool & showplot) : Button(x, y, w, h, r), sp(showplot) {
	//TO DO: Set Images
	unclicked_img = IMG_LoadTexture(renderer, "PlotButtonRed.png");
	clicked_img = IMG_LoadTexture(renderer, "PlotButtonOrange.png");
	current_img = unclicked_img;
	//TO DO: Reference to scale
}

void Button_Plot::clicked() {
	sp = !sp;
}
