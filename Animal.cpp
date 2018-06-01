#include "Animal.h"
class Tile;

using namespace std;


//PUBLIC FUNCTIONS

Animal::Animal(Tile* parentTile): Entity(parentTile) {
	id = 1;
}

void Animal::checkMove() {}
void Animal::checkAction() {} //Eat
void Animal::checkDeath() {}
void Animal::checkReproduce() {}
