/*
* File: 	Tail.h
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#include "Entity.h"
#include <vector>

#ifndef TRONSNAKE_TAIL_H
#define TRONSNAKE_TAIL_H

using namespace std;

class Tail: public Entity {
public:

    Tail(int r = 255; int g = 255; int b = 255);

    int getType();

    void setColorRGB(int, int, int);

    vector<int> getColorRGB();

private:

    vector<int> RGB;

};
#endif //TRONSNAKE_TAIL_H
