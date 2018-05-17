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
	void setRunning(bool runningVal);
	bool isRunning();
	int getxMousePtr();
	int getyMousePtr();
	int getMouseLeftDown();
	void setMouseLeftDown(bool leftDown);

};

#endif /* EVENTHANDLER_H_DEFINED */
