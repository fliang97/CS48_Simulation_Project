#ifndef SCREEN_GAME_H_DEFINED
#define SCREEN_GAME_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "Screen_World.h"
#include "ZoomInButton.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class Screen_Game : public Screen {
	public:
	Screen_Game(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map): Screen(eventHandler, r, w, h), map(map) {
		screen_world = new Screen_World(eventHandler, r, width/4, 0, 3*width/4, 3*height/4, cs, map);
		button_zoomIn = new Button_ZoomIn(width / 20, height / 20, width / 10, height / 10, r);
		components.push_back(button_zoomIn);
	}

	void mousePressedUp() override{
		//cout << "somewhere clicked" << end;
		//cout << "Clicked02" << endl;
		for (Component* c : components) {
			if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
				c->clicked();
			}
		}
    
		if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
			screen_world->mousePressedUp();
		}
	    //if ()
	}

	void mousePressedDown() override {
		if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
			screen_world->mousePressedDown();
		}
	}

	void mouseDown() override {
		if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
			screen_world->mouseDown();
		}
	}

	void update() override {
		//cout << "GameScreenUpdate" << endl;
		screen_world->update();
	}

	void render() override {
		//cout << "GameScreenRender" << endl;
		//SDL_Rect rect = {0, 0, width, height};
		//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		//SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
		//SDL_RenderFillRect( renderer, &rect);
		screen_world->render();
        SDL_Rect rect1 = {0, 0, screen_world->xpos, height};
        SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
        SDL_RenderFillRect( renderer, &rect1);
        SDL_Rect rect2 = {screen_world->xpos, screen_world->height, screen_world->width, height - screen_world->height};
        SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
        SDL_RenderFillRect( renderer, &rect2);
		button_zoomIn->render();
	}
	Screen_World* screen_world;
	Map& map;
	Button_ZoomIn* button_zoomIn;
};
#endif /* SCREEN_GAME_H_DEFINED */
