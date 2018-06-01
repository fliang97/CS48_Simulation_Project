
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "Screen_GameMap.h"
#include "Screen_Game.h"


using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

Screen_Game::Screen_Game(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map) : Screen(eventHandler, r, w, h), map(map) {
	screen_world = new Screen_GameMap(eventHandler, r, width / 6, 0, 5 * width / 6, 5 * height / 6, cs, map);

}

void Screen_Game::mousePressedUp() {
	for (Component* c : components) {
		if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
			c->clicked();
		}
	}

	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mousePressedUp();
	}
}

void Screen_Game::mousePressedDown() {
	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mousePressedDown();
	}
}

void Screen_Game::mouseDown() {
	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mouseDown();
	}
}

void Screen_Game::update() {
	screen_world->update();
}

void Screen_Game::render() {
	screen_world->render();
	SDL_Rect rect1 = { 0, 0, screen_world->xpos, height };
	SDL_SetRenderDrawColor(renderer, 0, 200, 50, 255);
	SDL_RenderFillRect(renderer, &rect1);
	SDL_Rect rect2 = { screen_world->xpos, screen_world->height, screen_world->width, height - screen_world->height };
	SDL_SetRenderDrawColor(renderer, 0, 200, 50, 255);
	SDL_RenderFillRect(renderer, &rect2);

}
