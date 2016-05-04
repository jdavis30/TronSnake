/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: EmptyCell.cpp
 * Date: 4/26/2016
 * Objective:   Placeholder object for grid.
 * 
 */
#include "EmptyCell.h"

EmptyCell::EmptyCell(int xVal, int yVal): Entity(xVal, yVal) {

}
int EmptyCell::getType() {
	return 0;
}

void EmptyCell::draw(){

}