#ifndef MAP_H_DEFINED
#define MAP_H_DEFINED

#include <vector>
#include <unordered_set>
#include <cstdlib>


#include "Tile.h"
class Animal;
class Plant;

class Map {
public:
	Map(int width, int height);
	Map();

	//Parameters:
  //Return Values:
  //Precondition:
  //Postcondition:  Calls the update function for each Tile. Then switches between mapGrid and bufferboard.
	void updateEntities();
	void buildMap(int width, int height);
	Tile *getTile(int posX, int posY);
	Tile* getRandomTile();
	Entity* getEntityOfTypeFromTile(int entityType, int layerNum, Tile* tile);
	Entity* getClosestEntityInRange(int entityType, int getLayerToCheck, Tile* centerTile, int radius);

	vector< vector<Tile*> >* mapGrid;
	//vector< vector<Tile*> >* bufferboard;
	int width;
	int height;

	//Possibly add list (unordered set) of Entities, Plants/ Animals for added effieciency in search.
	unordered_set<Entity*> entities; //currently unused
	unordered_set<Animal*> animals; //for 	//move  //Eat / Action //Death //Reproduce  update gamestate
	unordered_set<Plant*> plants; //for Reproduce
	unordered_set<Animal*> toDestroyAnimals;
	unordered_set<Plant*> toDestroyPlants;
};

#endif /* MAP_H_DEFINED */
