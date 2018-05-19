#include <vector>

#include "Tile.h"
#include "Map.h"
#include "Game.h"

Map::Map(int width, int height) : width(width), height(height) {
	//cout << "BuildGameState" << endl;
	mapGrid = new vector< vector<Tile*> >(width, vector<Tile*>(height));
	bufferboard = new vector< vector<Tile*> >(width, vector<Tile*>(height));
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			(*mapGrid)[i][j] = new Tile(i, j, this);
			(*bufferboard)[i][j] = new Tile(i, j, this);
		}
	}
	counter = Game::COUNTER;
}

Map::Map() : width(0), height(0) {
	counter = Game::COUNTER;
}

void Map::updateEachTile() {
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

}
