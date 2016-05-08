/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Head.cpp
 * Date: 4/26/2016
 * Objective:   Head of the tron snake, defines where the body will go next.
 */

#include "head.h"

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

void draw() {
	;
}