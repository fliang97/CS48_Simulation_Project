#ifndef MAP_H_DEFINED
#define MAP_H_DEFINED

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Tile.h"

class Map {
public:
	Map(int width, int height): width(width), height(height) {
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

	Map(): width(0), height(0) {
		//cout << "BuildMap2" << endl;
	}

    vector< vector<Tile*> >* mapGrid;
    vector< vector<Tile*> >* bufferboard;
    //Possibly add list of Entities, Plants/ Animals for added effieciency in search.
    int width;
    int height;
};


#endif /* MAP_H_DEFINED */
