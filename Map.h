#ifndef MAP_H_DEFINED
#define MAP_H_DEFINED

#include <vector>
#include <cstdlib>

#include "Tile.h"

class Map {
public:
	Map(int width, int height);
	Map();

	vector< vector<Tile*> >* mapGrid;
	vector< vector<Tile*> >* bufferboard;
	int width;
	int height;

	//Possibly add list of Entities, Plants/ Animals for added effieciency in search.
};

#endif /* MAP_H_DEFINED */
