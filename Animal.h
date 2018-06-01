#ifndef ANIMAL_H_DEFINED
#define ANIMAL_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Map.h"
#include "Tile.h"
#include "Entity.h"
using namespace std;

class Animal : public Entity {
public:
	Animal(Tile* parentTile);
	virtual void checkMove();
  virtual void checkAction() ;
  virtual void checkDeath() ;
	virtual void checkReproduce();

  int health;
	int hunger;
  int age;
};







#endif /* ANIMAL_H_DEFINED */
