/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Head.h
 * Date: 4/26/2016
 * Objective:   Head of the tron snake, defines where the body will go next.
 */

#ifndef HEAD_H
#define HEAD_H
#include "Entity.h"

class Head: public Entity {
	public:
		Head(int dir = 1);
		int getDirection();
		void setDirection(int dir = 0);
	private:
		int direction;

};

#endif /** Head_H */