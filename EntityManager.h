#ifndef ENTITYMANAGER_H_DEFINED
#define ENTITYMANAGER_H_DEFINED


#include "Entity.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Cow.h"
#include "Wolf.h"


enum EntityID : int {
	entity = 0,
	animal = 1,
	plant = 2,
	cow = 3,
	grass = 4,
	wolf = 5
};

class EntityManager {
public:
	static Entity* createEntity(EntityID id, Tile* parentTile);

};



#endif /* ENTITYMANAGER_H_DEFINED */
