#ifndef EVENTHANDLER_H_DEFINED
#define EVENTHANDLER_H_DEFINED

class EventHandler {
public:
	bool running;
	int xMouse;
	int yMouse;
	bool mouseLeftDown;

	// TO DO:
	// Fully implement getters and setters in other classes.  Some classes still access this data directly.
	// Make these inline functions?

	EventHandler();
	//Parameters:
	//runningVal: Setter input for running
	//Return Values:
	//Precondition: There is an event.type == SDL_QUIT
	//Postcondition: Setter for running, which controls whether the game will continue to loop.
	void setRunning(bool runningVal);

	//Parameters:
	//Return Values: gets value of  Runningval
	//Precondition:
	//Postcondition: Getter for running, which controls whether the game will continue to loop.
	bool isRunning();

	//Parameters:
	//Return Values: gets value of  xMouse
	//Precondition: Always updated when handling events.
	//Postcondition: Getter for xMouse, which controls the x location of the mouse on the screen.
	int getxMousePtr();

	//Parameters:
	//Return Values: gets value of yMouse
	//Precondition: Always updated when handling events.
	//Postcondition: Getter for yMouse, which controls the y location of the mouse on the screen.
	int getyMousePtr();

	//Parameters:
	//Return Values: gets value mouseLeftDown
	//Precondition:
	//Postcondition: Getter for mouseLeftDown, which controls the state of the mouses left button
	bool getMouseLeftDown();
	//mousestate & SDL_BUTTON(SDL_BUTTON_LEFT)

	//Parameters: bool leftDown: Setter input for mouseLeftDown
	//Return Values:
	//Precondition: (mousestate & SDL_BUTTON(SDL_BUTTON_LEFT))
	//Postcondition: Setter for mouseLeftDown, which controls the state of the mouses left button
	void setMouseLeftDown(bool leftDown);

};

#endif /* EVENTHANDLER_H_DEFINED */
