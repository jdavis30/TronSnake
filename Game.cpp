//
// Created by Collin on 4/26/2016.
//

#include <stdlib.h>
#include "Entity.h"
#include "Tail.h"
#include "Food.h"
#include "Game.h"

Game::Game(int sizeX, int sizeY){
    SIZE_X = sizeX-1;
    SIZE_Y = sizeY-1;
    emptyCell = EmptyCell();
    grid = Grid();
    head = Head();
}

bool Game::update(){
    ///////////// deal with moving head ///////////////
    int dir = head.getDirection();
    int head_x = head.getX();
    int head_y = head.getY();
    int location;
    bool ateFood = false;
    Entity * moveInTo;
    if(dir == 0){
        if(head_x == 0){
            head.setX(SIZE_X);
        }else{
            head.setX(head_x-1);
        }
        moveInTo = grid.getCell(head.getX()*SIZE_Y);
        location = head.getX()*SIZE_Y;
    }else if(dir == 1){
        if(head_y == 0){
            head.setY(SIZE_Y);
        }else{
            head.setY(head_y-1);
        }
        moveInTo = grid.getCell(head.getY()*SIZE_X);
        location = head.getY()*SIZE_X;
    }else if(dir == 2){
        if(head_y == SIZE_X){
            head.setX(0);
        }else{
            head.setX(head_x+1);
        }
        moveInTo = grid.getCell(head.getX()*SIZE_Y);
        location = head.getX()*SIZE_Y;
    }else{
        if(head_y == SIZE_Y){
            head.setY(0);
        }else{
            head.setY(head_y+1);
        }
        moveInTo = grid.getCell(head.getY()*SIZE_X);
        location = head.getY()*SIZE_X;
    }
    if ((*moveInTo).getType() == 0){
        grid.setCell(location, head);
    }
    else if((*moveInTo).getType() == 3){
        grid.setCell(location, head);
        ateFood = true;
    }
    else{
        return false;//YOU HIT THE TAIL AND LOST THE GAME!!!!!
    }

    /////////// Deal with tail ////////////////
    Tail whereHeadWas = Tail();
    whereHeadWas.setX(head_x);
    whereHeadWas.setY(head_y);
    tail.insert (tail.begin(), whereHeadWas);
    if(!(ateFood)) {
        tail.pop_back();
        grid.setCell(head_y*SIZE_X+head_x, emptyCell);
    }

    /////////// Deal with eatten food /////////////

    if(ateFood){
        Food newFood = Food();
        while(true){
            int index = rand() % (SIZE_X*SIZE_Y-1);
            if((*grid.getCell(index)).getType() != 0)
                continue;
            grid.setCell(index,newFood);
            break;
        }
    }
    return true;
}