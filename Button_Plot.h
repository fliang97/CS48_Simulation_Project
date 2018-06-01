#ifndef BUTTON_PLOT_H_DEFINED
#define BUTTON_PLOT_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>
#include "Button.h"
#include "plotsdl/plot.h"
#include "plotsdl/llist.h"

using namespace std;

class Button_Plot : public Button {
public:
	Button_Plot(int x, int y, int w, int h, SDL_Renderer* r, bool & showplot);

	//Parameters:
	//Return Values:
	//Precondition: Mouse is over button border and is released.
	//Postcondition: Increase values of map scales.
	void clicked() override;

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Renders images of zoom out button.
	//void render() override;

	bool &sp;
};

#endif /* BUTTON_PLOT_H_DEFINED */
