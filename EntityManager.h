#ifndef ENTITYMANAGER_H_DEFINED
#define ENTITYMANAGER_H_DEFINED


#include "Entity.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Cow.h"
#include "Wolf.h"

//Enum used to identify types the subclasses of Entity
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

	//createEntity - Factory method that creates a dervied class of Entity.
	//Return - A pointer to the newly created derived entity or null if no derived entity could be created.
	//Pre - A valid entity type id and open Tile are passed or else a null pointer is returned.
	//Post - A derived entity of the specified type is created in the specified Tile and a pointer to said derived entity is returned.
	static Entity* createEntity(EntityID id, Tile* parentTile);

};

#endif /* ENTITYMANAGER_H_DEFINED */
