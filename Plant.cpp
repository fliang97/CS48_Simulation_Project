#include "Plant.h"
class Tile;

using namespace std;


//PUBLIC FUNCTIONS

Plant::Plant(Tile* parentTile): Entity(parentTile) {
	id = 2;
}
void Plant::checkReproduce() {}
void Plant::checkDeath() {}
