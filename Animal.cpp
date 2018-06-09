#include "Animal.h"
class Tile;

using namespace std;

int Animal::populationCount;

//PUBLIC FUNCTIONS

Animal::Animal(Tile* parentTile): Entity(parentTile) {
	id = 1;
	ageMax = 300;
	Animal::populationCount++;
	cout << "Animal population: " << Animal::populationCount << endl;
}

Animal::~Animal() {
	Animal::populationCount--;
	cout << "Animal population: " << Animal::populationCount << endl;
}

void Animal::checkMove() {}
void Animal::checkAction() {} //Eat
void Animal::checkDeath() {}
void Animal::checkReproduce() {}

int Animal::getPopulationCount() {
	return Animal::populationCount;
}