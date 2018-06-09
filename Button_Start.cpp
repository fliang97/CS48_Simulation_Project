#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Button_Start.h"
#include "Button.h"
#include "Entity.h"
#include "Grass.h"
#include "Cow.h"
#include "Map.h"


using namespace std;
class ScreenManager;

Button_Start::Button_Start(int x, int y, int w, int h, SDL_Renderer* r, int& currentScreen, Map& map) : Button(x, y, w, h, r), currentScreen(currentScreen), map(map) {
	unclicked_img = IMG_LoadTexture(renderer, "StartButtonRed.png");
	clicked_img = IMG_LoadTexture(renderer, "StartButtonBlue.png");
	current_img = unclicked_img;
}

void Button_Start::clicked() {
	map.buildMap(100, 100);
	Tile* tile = (*map.mapGrid)[5][5];

	//Square must know Entity
	Grass* g = new Grass(tile);
	map.plants.insert(g);
	tile->layer1 = g;
	tile = (*map.mapGrid)[8][5];
	//Square must know Entity
	g = new Grass(tile);
	map.plants.insert(g);
	tile->layer1 = g;
	tile = (*map.mapGrid)[7][5];
	//Square must know Entity
	g = new Grass(tile);
	map.plants.insert(g);
	tile->layer1 = g;
	tile = (*map.mapGrid)[6][5];
	//Square must know Entity
	g = new Grass(tile);
	map.plants.insert(g);
	tile->layer1 = g;
	tile = (*map.mapGrid)[4][5];
	//Square must know Entity
	g = new Grass(tile);
	map.plants.insert(g);
	tile->layer1 = g;

	tile = (*map.mapGrid)[3][5];
	Cow* c = new Cow(tile);
	map.animals.insert(c);
	tile->layer2 = c;

	tile = (*map.mapGrid)[9][8];
	c = new Cow(tile);
	map.animals.insert(c);
	tile->layer2 = c;
	currentScreen = 1;
}
