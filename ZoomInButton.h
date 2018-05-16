#ifndef BUTTON_ZOOMIN_H_DEFINED
#define BUTTON_ZOOMIN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Button.h"


using namespace std;

class Button_ZoomIn : public Button {
public:
	Button_ZoomIn(int x, int y, int w, int h, SDL_Renderer* r) : Button(x, y, w, h, r) {
	}
	//~Button_Start() {
	//  delete currentScreen;
	//}
	void clicked() override {

	}
	void render() override {
		SDL_Rect rect;
		rect.x = xpos;
		rect.y = ypos;
		rect.w = width;
		rect.h = height;
		//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		SDL_SetRenderDrawColor(renderer, 100, 50, 120, 255);
		SDL_RenderFillRect(renderer, &rect);
	}

};
#endif /* BUTTON_ZOOMIN_H_DEFINED */