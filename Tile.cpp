
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Game.h"
#include "Entity.h"
#include "Tile.h"
#include "EntityManager.h"


class Map;
using namespace std;

Tile::Tile(int x, int y, Map* map) {
	this->x = x;
	this->y = y;
	this->map = map;
	this->layer1 = NULL;
	this->layer2 = NULL;
	static_img = IMG_LoadTexture(Game::renderer, "grass_3.jpg");
}
/*
	void Tile::update(vector< vector<Tile*> >* nextIterboard) {
		//cout << "TileUpdate" << endl;
		//if (layer1) layer1->update(nextIterboard);
		//if (layer2) layer2->update(nextIterboard);
	}
*/
void Tile::render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r) {
	//render self
	SDL_Rect rect = { (screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY };
	SDL_RenderCopy(r, static_img, NULL, &rect);

	if (layer1) layer1->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r);
	if (layer2) layer2->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r);
}


Entity* Tile::getEntityFromLayer(int layerNum) {
	switch (layerNum) {
	case(1): return this->layer1;
	case(2): return this->layer2;
	}

	return nullptr;
}

Entity* Tile::getEntityOfType(int entityType, int layerNum) {

				Entity* tmpEntity = nullptr;

				switch (layerNum) {
				case 1: tmpEntity = this->getEntityFromLayer(1);
					break;
				case 2: tmpEntity = this->getEntityFromLayer(2);
					break;
				}

				if (tmpEntity && entityType == tmpEntity->getID())
					return tmpEntity;

	return nullptr;
}


int Tile::getPosX() {
	return this->x;
}

int Tile::getPosY() {
	return this->y;
}