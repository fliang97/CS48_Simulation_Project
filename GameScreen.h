#ifndef GAMESCREEN_H_DEFINED
#define GAMESCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "WorldScreen.h"
#include "ZoomInButton.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class GameScreen : public Screen {
	public:
	GameScreen(EventHandler* eh, SDL_Renderer* r, int w, int h, int& cs, GameState& gs): Screen(eh, r, w, h), gamestate(gs) {
		ws = new WorldScreen(eh, r, width/4, 0, 3*width/4, 3*height/4, cs, gs);
		zib = new ZoomInButton(width / 20, height / 20, width / 10, height / 10, r);
		components.push_back(zib);
	}

	void mousePressedUp() override{
		//cout << "somewhere clicked" << end;
		//cout << "Clicked02" << endl;
		for (Component* c : components) {
			if (c->isOver(eh->xMouse, eh->yMouse)) {
				c->clicked();
			}
		}
    
		if (eh->xMouse >= ws->xpos && eh->yMouse >= ws->ypos && eh->xMouse <= ws->xpos + ws->width && eh->yMouse <= ws->ypos + ws->height) {
			ws->mousePressedUp();
		}
	    //if ()
	}

	void mousePressedDown() override {
		if (eh->xMouse >= ws->xpos && eh->yMouse >= ws->ypos && eh->xMouse <= ws->xpos + ws->width && eh->yMouse <= ws->ypos + ws->height) {
			ws->mousePressedDown();
		}
	}

	void mouseDown() override {
		if (eh->xMouse >= ws->xpos && eh->yMouse >= ws->ypos && eh->xMouse <= ws->xpos + ws->width && eh->yMouse <= ws->ypos + ws->height) {
			ws->mouseDown();
		}
	}

	void update() override {
		//cout << "GameScreenUpdate" << endl;
		ws->update();
	}

	void render() override {
		//cout << "GameScreenRender" << endl;
		SDL_Rect rect = {0, 0, width, height};
		//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
		SDL_RenderFillRect( renderer, &rect);
		ws->render();
		zib->render();
	}
	WorldScreen* ws;
	GameState& gamestate;
	ZoomInButton* zib;
};
#endif /* GAMESCREEN_H_DEFINED */
