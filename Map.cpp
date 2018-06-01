#include <vector>

#include "Tile.h"
#include "Map.h"
#include "Game.h"

Map::Map(int width, int height){
	buildMap(width, height);
}

Map::Map(){
	buildMap(0, 0);
}

void Map::buildMap(int width, int height) {

	this->width = width;
	this->height = height;
	animals.clear(); //for 	//move  //Eat / Action //Death //Reproduce  update gamestate
	plants.clear(); //for Reproduce
	toDestroyAnimals.clear();
	toDestroyPlants.clear();

	mapGrid = new vector< vector<Tile*> >(width, vector<Tile*>(height));
	//bufferboard = new vector< vector<Tile*> >(width, vector<Tile*>(height));
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			(*mapGrid)[i][j] = new Tile(i, j, this);
			//(*bufferboard)[i][j] = new Tile(i, j, this);
		}
	}
}

void Map::updateEachTile() {
		for (Animal* a : animals) {
			a->checkMove();
		}
		for (Animal* a : animals) {
			a->checkAction();
		}
		for (Animal* a : animals) {
			a->checkReproduce();
		}
		for (Plant* p : plants) {
			p->checkReproduce();
		}
		for (Animal* a : animals) {
			a->checkDeath();
		}
		for (Plant* p : plants) {
			p->checkDeath();
		}
		for (Plant* p : plants) {
			p->checkDeath();
		}
		for (Animal* a : toDestroyAnimals) {
			animals.erase(a);
		}
		for (Plant* p : toDestroyPlants) {
			plants.erase(p);
		}
		toDestroyAnimals.clear();
		toDestroyPlants.clear();

/*
	if (counter == 0) {
		for (int i = 0; i < this->width; ++i) {
			for (int j = 0; j < this->height; ++j) {
				(*this->mapGrid)[i][j]->update(this->bufferboard);
			}
		}
		vector< vector<Tile*> >* temp = this->mapGrid;
		this->mapGrid = this->bufferboard;
		this->bufferboard = temp;
		counter = Game::COUNTER;
	}
	--counter;
	//cout << counter << endl;
*/
}
