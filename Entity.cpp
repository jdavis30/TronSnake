/**
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * Date: 4/26/2016
 * File: Entity.cpp
 * Objective: Base class for objects within TronSnake game.
 */
#include "Entity.h"

Entity::Entity(int xVal, int yVal) {
	x = xVal;
	y = yVal;
}

int Entity::getX() {
	return x;
}

void Entity::setX(int xVal) {
	x = xVal;
}

int Entity::getY() {
	return y;
}

void Entity::setY(int yVal) {
	y = yVal;
}