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

    Entity* getCell(int x = 0, int y = 0);

    void setCell(int x = 0, int y = 0, Entity &e);

    friend Game;

private:

    Entity ** grid;
    int SIZE_X;
    int SIZE_Y;
    EmptyCell *empty;
    Head *head;
    Food *food;

};

#endif //TRONSNAKE_GRID_H
