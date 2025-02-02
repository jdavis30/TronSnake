/*
* File: 	Grid.h
* Author: 	Collin Graf and Jasper Davis
* Date:		4/26/2016
 */

#include <vector>
#include "Entity.h"
#include "EmptyCell.h"
#include "Tail.h"
#include "Food.h"
#include "Head.h"

#ifndef TRONSNAKE_GRID_H
#define TRONSNAKE_GRID_H

using namespace std;

class Grid {
public:

    Grid(int x = 10, int y = 10);

    Entity* getCell(int x);

    void setCell(int x, Entity &e);

private:

    Entity ** grid;
    int SIZE_X;
    int SIZE_Y;

};

#endif //TRONSNAKE_GRID_H
