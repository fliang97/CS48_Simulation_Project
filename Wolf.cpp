
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>

//#include "Map.h"
//#include "Tile.h"
//#include "Entity.h"
#include "Cow.h"
#include "Wolf.h"
#include "EntityManager.h"
#include "Game.h"

using namespace std;

int Wolf::populationCount = 0;

//PUBLIC FUNCTIONS
SDL_Texture* Wolf::static_img = NULL;
SDL_Texture* Wolf::static_img_sick = NULL;

Wolf::Wolf(Tile* parentTile) : Animal(parentTile) {
	id = 5;
	health = 100;
	hunger = 100;
	age = 0;
	Wolf::populationCount++;
}

Wolf::~Wolf() {
	Wolf::populationCount--;
}

// checkMove moves the Wolf towards nearby food or in a random direction if no food is directly nearby
void Wolf::checkMove() {
	int changeX = 0;
	int changeY = 0;

	int eaterX = parentTile->getPosX();
	int eaterY = parentTile->getPosY();

	// Find the closet adjacent cow square within 2 range.
	Entity* tmpFood = parentTile->map->getClosestEntityInRange(EntityID::cow, 2, parentTile, 1);

	// If food is found within range, calculate the relative change in position necessary to move there
	if (tmpFood) {

		int foodX = tmpFood->getParentTile()->getPosX();
		int foodY = tmpFood->getParentTile()->getPosY();

		if (eaterX < foodX)
			changeX = 1;
		if (eaterX > foodX)
			changeX = -1;

		if (eaterY < foodY)
			changeY = 1;
		if (eaterY > foodY)
			changeY = -1;
	}
	else { // If food is not found nearby, randomly select a direction to move
		changeX = rand() % 3 - 1;
		changeY = rand() % 3 - 1;
	}

	// Calculate the new square position based on the Cow's current square and calculated change in position
	int newX = parentTile->getPosX() + changeX;
	int newY = parentTile->getPosY() + changeY;

	// Move the Wolf to the new tile position if that tile is open
	if (parentTile->map->getTile(newX, newY)) {
		vector< vector<Tile*> >* grid = parentTile->map->mapGrid;
		Tile* s = (*grid)[newX][newY];//getting tentative location in iter
		//Square must know Entity
		if (!s->layer2) {
			s->layer2 = this; //setting iterboard tile entity to this
			parentTile->layer2 = NULL; // old tile parent in old board to null
			parentTile = s; // set parent to new tile
		}
	}
}


void Wolf::checkAction() {
	++age;
	hunger -= 5;


	if (hunger < 80) {
		Entity* prey = parentTile->map->getClosestEntityInRange(EntityID::cow, 2, parentTile, 1);

		if (prey) {
			prey->modifyHealth(-25);
			hunger = min(100, hunger + 20);
			health = min(100, health + 2);
		}
	}
}

void Wolf::checkDeath() {
	if (hunger <= 0) {
		health += hunger;
	}
	if (health <= 0 || age > 300) {
		parentTile->layer2 = NULL;
		//cout << "TestDestroy: " << health << " " << age << endl;
		parentTile->map->toDestroyAnimals.insert(this);
		//delete this;
	}
	//if (s->layer1.id = 1)
}

void Wolf::checkReproduce() {
	if (age > 10 && hunger > 80 && rand() % 12 == 0) {
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < parentTile->map->width
			&& parentTile->y + y >= 0 && parentTile->y + y < parentTile->map->height) {
			Tile* s = (*parentTile->map->mapGrid)[parentTile->x + x][parentTile->y + y];
			//Square must know Entity
			EntityManager::createEntity(EntityID::wolf, s);
		}
	}
}

void Wolf::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//cout << "GrassRender" << endl;
	//SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	int le = min(w, w/2 + age);
	int he = min(h, h/2 + age);

	SDL_Rect rect = {x + (w - le)/2, y + (h - he)/2, le, he };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));

	//SDL_SetRenderDrawColor(r, 100, 50, 0, 255);
	//SDL_SetRenderDrawColor(r, max(0, hunger), health, min(age, 255), 255);
	//SDL_RenderFillRect(r, &rect);
	//SDL_RenderPresent( renderer);


	if (health < 75 || age > ageMax - 25) {
		SDL_RenderCopy(r, static_img_sick, NULL, &rect);
	}
	else {
		SDL_RenderCopy(r, static_img, NULL, &rect);
	}
}

int Wolf::getPopulationCount() {
	return Wolf::populationCount;
}


//This function not currently used?
void Wolf::modifyHealth(int healthChange) {
	health += healthChange;
	return;
}


void Wolf::setTextureImg() {
		//cout << "wolf.png" << endl;
		Wolf::static_img = IMG_LoadTexture(Game::renderer, "wolf.png");
}

void Wolf::setTextureImgSick() {
		//cout << "wolf_sick" << endl;
		Wolf::static_img_sick = IMG_LoadTexture(Game::renderer, "wolf_sick.png");
}
