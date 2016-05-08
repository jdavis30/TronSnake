/*
* File: 	Food.cpp
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#include "Food.h"

Food::Food(int xVal,int yVal): Entity(xVal, yVal){

}

int Food::getType(){
    return 3;
}

void Food::setColorRGB(int r, int g, int b){
    RGB[0] = r;
    RGB[1] = g;
    RGB[2] = b;
}

vector<int> Food::getColorRGB(){
    return RGB;
}
