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


	void setRunning(bool runningVal) {
		this->running = runningVal;
	}

	bool isRunning() {
		return this->running;
	}

	int getxMousePtr() {
		return this->xMouse;
	}

	int getyMousePtr() {
		return this->yMouse;
	}

	int getMouseLeftDown() {
		return this->mouseLeftDown;
	}

	void setMouseLeftDown(bool leftDown) {
		this->mouseLeftDown = leftDown;
	}



	EventHandler() {
		running = true;
		xMouse = 0;
		yMouse = 0;
		mouseLeftDown = false;
	}

};

#endif /* EVENTHANDLER_H_DEFINED */
