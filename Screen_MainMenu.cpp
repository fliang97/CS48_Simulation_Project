#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen_MainMenu.h"
#include "Button_Start.h"
#include "Screen.h"
#include "EventHandler.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

Screen_MainMenu::Screen_MainMenu(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map) : Screen(eventHandler, r, w, h) {
	button_start = new Button_Start(width / 3, height / 3, width / 3, height / 3, r, cs, map);
	components.push_back(button_start);
}

//~Screen_MainMenu() {
//  delete button_start;
//}

void Screen_MainMenu::mousePressedUp() {
 for (Component* c : components) {
	 if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
		 c->clicked();
	 }
 }
 button_start->released();
}

void Screen_MainMenu::mousePressedDown() {
	if (button_start->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
		button_start->pressed();
	}
}

void Screen_MainMenu::update() {
}

void Screen_MainMenu::render() {
	SDL_Rect rect = { 0, 0, width, height };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	SDL_SetRenderDrawColor(renderer, 100, 0, 100, 255);
	SDL_RenderFillRect(renderer, &rect);
	//cout <<  rect.w << endl;
	button_start->render();
}
