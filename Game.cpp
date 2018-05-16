#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>

#include "Game.h"
#include "ScreenManager.h"
#include "EventHandler.h"

using namespace std;

// Is it good practice to initialize these pointers to null here?
SDL_Renderer* Game::renderer = nullptr;
EventHandler* Game::eventHandler = nullptr;
ScreenManager* Game::screenManager = nullptr;
SDL_Event Game::event;

Game::Game(){
}

Game::~Game() {
	delete eventHandler;
	eventHandler = nullptr;

	//combine destructor and close method?
}

void Game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	eventHandler = new EventHandler;
	screenManager = new ScreenManager(eventHandler, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); //why is this here?

    //SDL_RenderClear(renderer); // Seems unnecessary
}

void Game::close(){
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
    SDL_Quit();

	delete this; 

	//combine destructor and close method?
}


void Game::handleEvents() {
	
	Uint8 mousestate = SDL_GetMouseState(&eventHandler->xMouse, &eventHandler->yMouse);
	eventHandler->setMouseLeftDown(mousestate & SDL_BUTTON(SDL_BUTTON_LEFT));
	if (eventHandler->getMouseLeftDown()) {
		screenManager->mouseDown();
	}

	while (SDL_PollEvent(&event) != 0) //To exit loop, call exit(-1)
	{
		if (event.type == SDL_QUIT) {
			eventHandler->setRunning(false);
		}
		//if (event.type == SDL_MOUSEMOTION) {
		//	SDL_GetMouseState(&eventHandler->xMouse, &eventHandler->yMouse);
		//}

		//if (event.type == SDL_MOUSEBUTTONDOWN) {
		//	screenManager->mousePressed();
		//	//cout << "Clicked0" << endl;
		//}
		if (event.type == SDL_MOUSEBUTTONUP) {
			screenManager->mousePressedUp();
			//cout << "Clicked0" << endl;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			screenManager->mousePressedDown();
			//cout << "Clicked0" << endl;
		}

	}
}

bool Game::eventHandlerIsRunning() {
	return eventHandler->isRunning();
}

void Game::update() {
	screenManager->update();
}

void Game::render() {
	screenManager->render();
}

