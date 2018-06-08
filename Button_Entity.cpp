#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Wolf.h"
#include "Button.h"
#include "Entity.h"
#include "Button_Entity.h"


using namespace std;

Button_Entity::Button_Entity(int x, int y, int w, int h, SDL_Renderer* r, int id) : Button(x, y, w, h, r), EntityID(id) {
	//TO DO: Set Images
	//unclicked_img = IMG_LoadTexture(renderer, "grass3.png");
	//clicked_img = IMG_LoadTexture(renderer, "grass3.png");
	current_img = unclicked_img;
	//TO DO: Reference to scale
}

void Button_Entity::clicked() {
	if(EventHandler::mouseID == EntityID) {
		EventHandler::mouseID = -1;
	} else {
		EventHandler::mouseID = EntityID;
	}
}

void Button_Entity::render() {

	//MOVE TO CONSTRUCTOR
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = width;
	rect.h = height;
	if(EntityID == 3) {
		unclicked_img = Cow::static_img;
		clicked_img = Cow::static_img_sick;
	} else if (EntityID == 4) {
		unclicked_img = Grass::static_img;
		clicked_img = Grass::static_img;
	} else if (EntityID == 5) {
		unclicked_img = Wolf::static_img;
		clicked_img = Wolf::static_img_sick;
	}

	SDL_RenderCopy(renderer, current_img, NULL, &rect);
}
