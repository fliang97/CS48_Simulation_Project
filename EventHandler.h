#ifndef EVENTHANDLER_H_DEFINED
#define EVENTHANDLER_H_DEFINED

class EventHandler {
public:
	bool running;
	int xMouse;
	int yMouse;

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

	EventHandler() {
		running = true;
		xMouse = 0;
		yMouse = 0;
	}

};

#endif /* EVENTHANDLER_H_DEFINED */
