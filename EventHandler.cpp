#include "EventHandler.h"

// TO DO:
// Fully implement getters and setters in other classes.  Some classes still access this data directly.
// Make these inline functions?

EventHandler::EventHandler() {
	running = true;
	xMouse = 0;
	yMouse = 0;
	mouseLeftDown = false;
}

void EventHandler::setRunning(bool runningVal) {
	this->running = runningVal;
}

bool EventHandler::isRunning() {
	return this->running;
}

int EventHandler::getxMousePtr() {
	return this->xMouse;
}

int EventHandler::getyMousePtr() {
	return this->yMouse;
}

int EventHandler::getMouseLeftDown() {
	return this->mouseLeftDown;
}

void EventHandler::setMouseLeftDown(bool leftDown) {
	this->mouseLeftDown = leftDown;
}
