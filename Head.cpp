/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Head.cpp
 * Date: 4/26/2016
 * Objective:   Head of the tron snake, defines where the body will go next.
 */
<<<<<<< HEAD

#include "head.h"

=======
#include "Head.h"
>>>>>>> 5c82183ace0dd5b199b76783bb6c319621307521
Head::Head(int xVal, int yVal, int dir): Entity(xVal, yVal) {
	direction = dir;
}

int Head::getDirection() {
	return direction;
}

void Head::setDirection(int dir) {
	direction = dir;
}

int Head::getType() {
	return 1;
}