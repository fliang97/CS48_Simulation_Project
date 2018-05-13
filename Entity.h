#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
//#include "GameSquare.h"
class GameSquare;
using namespace std;

class Entity {
public:
  Entity(GameSquare* parentSquare) {
    this->parentSquare = parentSquare;
  }
//don't move
  virtual void update() {
    //(*nextIterboard)[parentSquare->x][parentSquare->y]->e = new Entity((*nextIterboard)[parentSquare->x][parentSquare->y]);
  }
  virtual void render(int x, int y, int w, int h) {
    //cout << "Entity" << endl;
  }
  GameSquare* parentSquare;
};
#endif /* ENTITY_H_DEFINED */
