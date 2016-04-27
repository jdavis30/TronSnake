//
// Created by Collin on 4/26/2016.
//

#include "Entity.h"

void Game::update(){
    int dir = head.getDirection();
    int head_x = head.getX();
    int head_y = head.getY();
    Entity moveInTo;
    if(dir == 0){
        if(head_x == 0){
            head.setX(SIZE_X);
        }else{
            head.setX(head_x-1);
        }
        moveInTo = grid[head.getX()*SIZE_Y];
    }else if(dir == 1){
        if(head_y == 0){
            head.setY(SIZE_Y);
        }else{
            head.setY(head_y-1);
        }
        moveInTo = grid[head.getY()*SIZE_X];
    }else if(dir == 2){
        if(head_y == SIZE_X){
            head.setX(0);
        }else{
            head.setX(head_x+1);
        }
        moveInTo = grid[head.getX()*SIZE_Y];
    }else{
        if(head_y == SIZE_Y){
            head.setY(0);
        }else{
            head.setY(head_y+1);
        }
        moveInTo = grid[head.getY()*SIZE_X];
    }
    if (moveInTo.getType() == 0){
        moveInTo = head;
    }
}