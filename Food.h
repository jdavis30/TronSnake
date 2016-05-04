/*
* File: 	Food.h
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#include "Entity.h"
#include <vector>

#ifndef TRONSNAKE_FOOD_H
#define TRONSNAKE_FOOD_H

using namespace std;

class Food: public Entity {
public:

    Food(int xVal = 0, int yVal = 0);

    int getType();

    void setColorRGB(int, int, int);

    vector<int> getColorRGB();

    void draw();

private:

    vector<int> RGB;

};

#endif //TRONSNAKE_FOOD_H


