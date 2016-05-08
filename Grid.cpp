//
// Created by Collin on 4/26/2016.
//

#include "Grid.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <random>
>>>>>>> ba54fc091809766e1f1aac1154c6e2d28aac9978
=======
#include "EmptyCell.cpp"
#include "Head.cpp"
#include <random>
#include <time.h>
>>>>>>> e32ceeb22c039cb11e1d817806a9e9ea861b820a


Grid::Grid(int x, int y){
    srand (time(NULL)); //seeds random
    SIZE_X = x;
    SIZE_Y = y;
    grid = new Entity*[SIZE_X*SIZE_Y];
    EmptyCell* empty = new EmptyCell();
    Head* head = new Head();
    Food* food = new Food();
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