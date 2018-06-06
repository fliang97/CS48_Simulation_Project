using namespace std;

#include "EntityManager.h"
#include "Entity.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Cow.h"
#include "Wolf.h"


//PUBLIC FUNCTIONS

Entity* EntityManager::createEntity(EntityID id, Tile* parentTile) {
	if (id == EntityID::grass && parentTile->getEntityFromLayer(1)==nullptr) {
		Grass* grass = new Grass(parentTile);
		parentTile->map->plants.insert(grass);
		parentTile->layer1 = grass;
		return grass;
	}
	else if (id == EntityID::cow && parentTile->getEntityFromLayer(2) == nullptr) {
		Cow* cow = new Cow(parentTile);
		parentTile->map->animals.insert(cow);
		parentTile->layer2 = cow;
		return cow;
	}
	else if (id == EntityID::wolf && parentTile->getEntityFromLayer(2) == nullptr) {
		Wolf* wolf = new Wolf(parentTile);
		parentTile->map->animals.insert(wolf);
		parentTile->layer2 = wolf;
		return wolf;
	}

	return nullptr;
}
