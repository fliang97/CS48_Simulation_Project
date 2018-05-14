#ifndef GAMESTATE_H_DEFINED
#define GAMESTATE_H_DEFINED

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Tile.h"

class GameState {
public:
	GameState(int wi, int he): width(wi), height(he) {
	    //cout << "BuildGameState" << endl;
	    board = new vector< vector<Tile*> >(wi, vector<Tile*>(he));
	    bufferboard = new vector< vector<Tile*> >(wi, vector<Tile*>(he));
	    for (int i = 0; i < wi; ++i) {
			for (int j = 0; j < he; ++j) {
				(*board)[i][j] = new Tile(i, j, this);
				(*bufferboard)[i][j] = new Tile(i, j, this);
			}
		}
	}

	GameState(): width(0), height(0) {
		//cout << "BuildGameState2" << endl;
	}

    vector< vector<Tile*> >* board;
    vector< vector<Tile*> >* bufferboard;
    //Possibly add list of Entities, Plants/ Animals for added effieciency in search.
    int width;
    int height;
};


#endif /* GAMESTATE_H_DEFINED */
