#ifndef TILE_H_DEFINED
#define TILE_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>

#include "Entity.h"

class Map;
using namespace std;

class Tile{ //will extend components
public:
    //Tile
    //parameter x is phorizontal ordinate， patameter y is vertical coordinates
    //pre- images
    //post- load the image on the map
	Tile(int x, int y, Map* map);
    
	//void update(vector< vector<Tile*> >* nextIterboard);
	void render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r);
	Entity* layer1; //Terrain
	Entity* layer2; //Object
	int x;//phorizontal ordinate
	int y;//vertical coordinates
	Map* map;
	SDL_Texture *static_img;

    
	//getEntityFromLayer
	//Param layerNum is used to specify the layer
	//Return - layer1 or layer2
	Entity* getEntityFromLayer(int layerNum);

    //entityType: animals or plants, layerNum is used to specify the layer 
	Entity* getEntityOfType(int entityType, int layerNum);
    
    //isOver
    //parameters: the phorizontal ordinates and vertical coordinates of screen, world, scale and mouse
    //precondition: all the parameters are defined and no negative nums
    //return: true or flase
	bool isOver(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, int mousex, int mousey);
	
    //clicked
    //pre- when you click on grass, cow or wolf
    //post- there will be a new entity of which you clicked
    void clicked();

    //get the (x,y) of the map
	int getPosX();
	int getPosY();


};

#endif /* TILE_H_DEFINED */
