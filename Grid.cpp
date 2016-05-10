//
// Created by Collin on 4/26/2016.
//

#include "Grid.h"
#include "EmptyCell.cpp"
#include "Head.cpp"
#include <stdlib.h>
#include <time.h>


Grid::Grid(int x, int y){
    srand (time(NULL)); //seeds random
    SIZE_X = x;
    SIZE_Y = y;
    grid = new Entity*[SIZE_X*SIZE_Y];
    EmptyCell* empty = new EmptyCell();
    for(int i = 0; i<SIZE_X*SIZE_Y; i++){
        grid[i] = empty;
    }
}

Entity* Grid::getCell(int x){
    return grid[x];
}

void Grid::setCell(int x, Entity &e){
    grid[x] = &e;
}