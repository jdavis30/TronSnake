/*
* File: 	Tail.cpp
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#include "Tail.h"
using namespace std;

Tail::Tail(int xVal, int yVal, int r, int g, int b):Entity(xVal, yVal){
	RGB.push_back(r);
	RGB.push_back(g);
	RGB.push_back(b);
}

int Tail::getType(){
    return 2;
}

void Tail::setColorRGB(int r, int g, int b){
    RGB[0] = r;
    RGB[1] = g;
    RGB[2] = b;
}

vector<int> Tail::getColorRGB(){
    return RGB;
}