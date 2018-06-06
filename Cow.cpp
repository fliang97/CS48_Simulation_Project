
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>

//#include "Map.h"
//#include "Tile.h"
//#include "Entity.h"
#include "Game.h"
#include "Cow.h"
#include "Plant.h"
#include "EntityManager.h"

using namespace std;

int Cow::populationCount = 0;

//PUBLIC FUNCTIONS

Cow::Cow(Tile* parentTile) : Animal(parentTile) {
	id = 3;
	health = 100;
	hunger = 100;
	age = 0;
	Cow::populationCount++;
	cout << "Cow population: " << Cow::populationCount << endl;
	static_img = IMG_LoadTexture(Game::renderer, "cow.png");
	static_img_sick = IMG_LoadTexture(Game::renderer, "cow_sick.png");
}

Cow::~Cow() {
	Cow::populationCount--;
	cout << "Cow population: " << Cow::populationCount << endl;
}


/*
void Cow::update(vector< vector<Tile*> >* nextIterboard) {
	checkEat();
	Tile* s = (*nextIterboard)[parentTile->x][parentTile->y];
	int x = rand() % 3 - 1;
	int y = rand() % 3 - 1;
	if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(nextIterboard->size())
		&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>((*nextIterboard)[0].size())) {
		s = (*nextIterboard)[parentTile->x + x][parentTile->y + y];//getting tentative location in iter
		//Square must know Entity
		if (!s->layer2) {
			s->layer2 = this; //setting iterboard tile entity to this
			//parentTile->layer2 = NULL; // old tile parent in old board to null
			parentTile = s; // set parent to new tile
		}
	}
	else {
		Tile* tile = (*nextIterboard)[parentTile->x][parentTile->y];  //if it cant move then just update new board with old lcoation
		//Square must know Entity
		//if (!tile->entity) //gets overriden if something moves into it. This now overrides anything on it.
		if (!s->layer2) {
			tile->layer2 = this;
			//parentTile->layer2 = NULL;
			parentTile = tile;
		}
	}
}
*/
void Cow::checkMove() {
	int changeX = rand() % 3 - 1;
	int changeY = rand() % 3 - 1;

	int newX = parentTile->getPosX() + changeX;
	int newY = parentTile->getPosY() + changeY;

	if (parentTile->map->getTile(newX,newY)) {
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

void Cow::checkAction() {
	++age;
	hunger -= 9;
	Entity* e = parentTile->layer1;
	if (hunger < 75 && e && e->id == 4) {
		((Plant*) parentTile->layer1)->health -= 50;
		hunger = min(100, hunger + 75);
		health = min(100, health + 25);
	}
}

void Cow::checkDeath() {
	if (hunger <= 0) {
		health += hunger;
		//health += hunger/2 - 5;
	}
	if (health <= 0 || age > ageMax) {
		parentTile->layer2 = NULL;
		cout << "TestDestroy: " << health << " " << age << endl;
		parentTile->map->toDestroyAnimals.insert(this);
		//delete this;
	}
	//if (s->layer1.id = 1)
}

void Cow::checkReproduce() {
	if (age > 10 && hunger > 90 && rand() % 7 == 0) {
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < parentTile->map->width
			&& parentTile->y + y >= 0 && parentTile->y + y < parentTile->map->height) {
			Tile* s = (*parentTile->map->mapGrid)[parentTile->x + x][parentTile->y + y];
			//Square must know Entity
			EntityManager::createEntity(EntityID::cow, s);
		}
	}
}

void Cow::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//cout << "GrassRender" << endl;
	//SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	int le = min(w, w/2 + age);
	int he = min(h, h/2 + age);

	SDL_Rect rect = {x + (w - le)/2, y + (h - he)/2, le, he };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));

	//SDL_SetRenderDrawColor(r, 100, 50, 0, 255);
	//SDL_SetRenderDrawColor(r, health, max(0, hunger), min(age, 255), 255);
	//SDL_RenderFillRect(r, &rect);
	//SDL_RenderPresent( renderer);
	//SDL_Rect rect = { x, y, w, h };

	if (health < 95 || age > ageMax - 25) {
		SDL_RenderCopy(r, static_img_sick, NULL, &rect);
	}
	else {
		SDL_RenderCopy(r, static_img, NULL, &rect);
	}

}

int Cow::getPopulationCount() {
	return Cow::populationCount;
}


void Cow::modifyHealth(int healthChange) {
	health += healthChange;
	return;
}