//
// Created by Collin on 4/26/2016.
//

#include "Grid.h"
#include <random>


Grid::Grid(int x = 10, int y = 10){
    SIZE_X = x;
    SIZE_Y = y;
    grid = new Entity*[SIZE_X*SIZE_Y];
    empty = new EmptyCell;
    head = new Head;
    food = new Food;
    int index;
    while(true){
        index = rand() % (SIZE_X*SIZE_Y-1);
        if(index == (SIZE_X*SIZE_Y - (SIZE_X/2)))
            continue;
        break;
    }
    for(int i = 0; i<SIZE_X*SIZE_Y; i++){
        if(i == (SIZE_X*SIZE_Y - (SIZE_X/2))){
            grid[i] = head;
        }else if(i == index){
            grid[i] = food;
        }else{
            grid[i] = empty;
        }
    }
}

Entity* Grid::getCell(int x){
    return grid[x];
}

void Grid::setCell(int x, Entity &e){
    grid[x] = &e;
}

void Grid::draw(){

}