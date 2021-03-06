
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "Screen_GameMap.h"
#include "Screen_Game.h"
#include "Game.h"
#include "Wolf.h"


using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

SDL_Texture* Screen_Game::static_img = NULL;

Screen_Game::Screen_Game(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map) : Screen(eventHandler, r, w, h), map(map) {
	screen_world = new Screen_GameMap(eventHandler, r, width / 6, 0, 5 * width / 6, 5 * height / 6, cs, map);
	speedup = new Button_Speedup(4 * width / 20, 17 * height / 20, width / 10, height / 10, r, COUNTER);
	components.push_back(speedup);
	speeddown = new Button_Speeddown(width / 20, 17 *height / 20, width / 10, height / 10, r, COUNTER);
	components.push_back(speeddown);
	entity3 = new Button_Entity(8 *width / 20, 17 *height / 20, width / 10, height / 10, r, 3);
	components.push_back(entity3);
	entity4 = new Button_Entity(12 *width / 20, 17 *height / 20, width / 10, height / 10, r, 4);
	components.push_back(entity4);
	entity5 = new Button_Entity(16 *width / 20, 17 *height / 20, width / 10, height / 10, r, 5);
	components.push_back(entity5);
	COUNTER = 30;
	counter = COUNTER;
	mouse_img = NULL;

}

void Screen_Game::mousePressedUp() {
	//possibly Screen::mousePressedUp()
	for (Component* c : components) {
		c->released();
		if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
			c->clicked();
		}
	}

	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mousePressedUp();
	}
	if (eventHandler->mouseID == -1) {
		mouse_img = NULL;
	} else if(eventHandler->mouseID == 3) {
		mouse_img = Cow::static_img;
	} else if (eventHandler->mouseID == 4) {
		mouse_img = Grass::static_img;
	} else if (eventHandler->mouseID == 5) {
		mouse_img = Wolf::static_img;
	}
}

void Screen_Game::mousePressedDown() {
	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mousePressedDown();
	}
}

void Screen_Game::mouseDown() {
	for (Component* c : components) {
		if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
			c->pressed();
		}
	}

	if (eventHandler->xMouse >= screen_world->xpos && eventHandler->yMouse >= screen_world->ypos && eventHandler->xMouse <= screen_world->xpos + screen_world->width && eventHandler->yMouse <= screen_world->ypos + screen_world->height) {
		screen_world->mouseDown();
	}
}

void Screen_Game::update() {
	if (counter == 0) {
		screen_world->update();
		counter = COUNTER;
	}
	--counter;
}

void Screen_Game::render() {
	screen_world->render();

	SDL_Rect rect1 = { 0, 0, screen_world->xpos, height };
	//SDL_SetRenderDrawColor(renderer, 61, 40, 1, 255);
	//SDL_RenderFillRect(renderer, &rect1);
	SDL_RenderCopy(Game::renderer, static_img, NULL, &rect1);


	SDL_Rect rect2 = { screen_world->xpos, screen_world->height, screen_world->width, height - screen_world->height };
	//SDL_SetRenderDrawColor(renderer, 61, 40, 1, 255);
	//SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderCopy(Game::renderer, static_img, NULL, &rect2);

	speedup->render();
	speeddown->render();
	entity3->render();
	entity4->render();
	entity5->render();
	SDL_Rect mouserect = { eventHandler->xMouse - width/30, eventHandler->yMouse - height/30, width/15, height/15};
	SDL_RenderCopy(renderer, mouse_img, NULL, &mouserect);
}


void Screen_Game::setTextureImg() {
	//cout << "game_wood_background.jpg" << endl;
	Screen_Game::static_img = IMG_LoadTexture(Game::renderer, "game_wood_background.jpg");
}
