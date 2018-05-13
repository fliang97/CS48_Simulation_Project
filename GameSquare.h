#ifndef GAMESQUARE_H_DEFINED
#define GAMESQUARE_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "WorldScreen.h"
#include "Entity.h"
//#include "Component.h"

class GameState;
using namespace std;

class GameSquare { //will extend components
public:
  GameSquare(int x, int y, GameState* g) {
    this->x = x;
    this->y = y;
    this->g = g;
    this->e = NULL;
  }

  void update(vector< vector<GameSquare*> >* nextIterboard) {
    if (e) e->update(nextIterboard);
  }
  void render(int screenX, int screenY, int scaleX, int scaleY) {
    //render self
    if (e) e->render(screenX + x * scaleX, screenY + y * scaleY, scaleX, scaleY); //change for zoom/scale
  }

  Entity* e; //change to multiple layers
  int x;
  int y;
  GameState* g;
};

#endif /* GAMESQUARE_H_DEFINED */
