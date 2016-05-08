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

#ifndef GRID_H
#define GRID_H

using namespace std;

class Grid {
public:

    Grid(int x = 10, int y = 10);
    Entity* getCell(int x = 0, int y = 0);
    void draw();

    Entity* getCell(int x);

    void setCell(int x, Entity &e);

private:

    Entity ** grid;
    int SIZE_X;
    int SIZE_Y;
    EmptyCell *empty;
    Head *head;
    Food *food;

};

#endif //GRID_H
