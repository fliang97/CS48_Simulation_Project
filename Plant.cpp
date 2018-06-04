#include "Plant.h"
class Tile;

using namespace std;

int Plant::populationCount = 0;

//PUBLIC FUNCTIONS

Plant::Plant(Tile* parentTile): Entity(parentTile) {
	id = 2;
	Plant::populationCount++;
}

Plant::~Plant() {
	Plant::populationCount--;
}
void Plant::checkReproduce() {}
void Plant::checkDeath() {}

int Plant::getPopulationCount() {
	return Plant::populationCount;
}