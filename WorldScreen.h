#ifndef WORLDSCREEN_H_DEFINED
#define WORLDSCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "GameState.h"

const int COUNTER = 30;

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class WorldScreen : public Screen {
 public:
	WorldScreen(EventHandler* eh, SDL_Renderer* r, int x, int y, int w, int h, int& cs, GameState& gs) : Screen(eh, r, w, h), gamestate(gs), xpos(x), ypos(y), width(w),
		height(h), counter(COUNTER), worldposX(0), worldposY(0) {
		scaleX = width / gamestate.width;
		scaleY = height / gamestate.height;

	}

	void mousePressedUp() override {  
	}

	void mousePressedDown() override {
		cout << "mousePressedDown" << endl;

		mouseInitX = eh->xMouse;
		mouseInitY = eh->yMouse;
		worldInitX = worldposX;
		worldInitY = worldposY;
	}

	void mouseDown() override {
		worldposX = worldInitX - (eh->xMouse - mouseInitX);
		worldposY = worldInitY - (eh->yMouse - mouseInitY);
		cout << worldposX << " " << worldposY << endl;
	}

	void update() override {
		//cout << "WorldScreenUpdate" << endl;
		if (counter == 0) {
			//cout << "SuccessfulUpdate" << endl;
			for (int i = 0; i < gamestate.width; ++i) {
				for (int j = 0; j < gamestate.height; ++j) {
					(*gamestate.board)[i][j]->update(gamestate.bufferboard);
				}
			}
			vector< vector<Tile*> >* temp = gamestate.board;
			gamestate.board = gamestate.bufferboard;
			gamestate.bufferboard = temp;
			counter = COUNTER;
		}
		--counter;
		//cout << counter << endl;
	}

	void render() override {
		//cout << "WorldScreenRender" << endl;
		SDL_Rect rect = { xpos, ypos, width, height };
		//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		SDL_SetRenderDrawColor(renderer, 0, 240, 220, 205);
		SDL_RenderFillRect(renderer, &rect);
		
		for (int i = 0; i < gamestate.width; ++i) {
			for (int j = 0; j < gamestate.height; ++j) {
				//cout << i << " " << j << endl;
				(*gamestate.board)[i][j]->render(xpos, ypos, worldposX, worldposY, scaleX, scaleY, renderer); //change to include zoom value and whatnot
			}
		}
	}

	int mouseInitX;
	int mouseInitY;
	int worldInitX;
	int worldInitY;

	int counter;
	int xpos;
	int ypos;
	int worldposX;
	int worldposY;
	int scaleX;
	int scaleY;
	int width;
	int height;
	GameState& gamestate;
};

#endif /* WORLDSCREEN_H_DEFINED */
