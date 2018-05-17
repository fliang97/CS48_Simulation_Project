#include <vector>

#include "Tile.h"
#include "Map.h"

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
}

Map::Map() : width(0), height(0) {
	//cout << "BuildMap2" << endl;
}
