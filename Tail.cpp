/*
* File: 	Tail.cpp
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#import "Tail.h"

Tail::Tail(int r, int g, int b){
	RGB[0] = r;
	RGB[1] = g;
	RGB[2] = b;
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

void Tail::draw(){

}