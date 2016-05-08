//
// Created by Collin on 4/26/2016.
//

#include <stdlib.h>
#include <ostream>
#include <iostream>
#include "Entity.h"
#include "Tail.h"
#include "Food.h"
#include "Game.h"

Game::Game(int sizeX, int sizeY){
    SIZE_X = sizeX;
    SIZE_Y = sizeY;
    emptyCell = EmptyCell();
    grid = Grid();
    head = Head(5,9,1);//sets values in head, doesnt actually set the heads location.
}

void Game::setDirection(char d) {
    if (d == 'a') {
        if (head.getDirection() != 2)
            head.setDirection(0);
    } else if (d == 'w'){
        if (head.getDirection() != 3)
            head.setDirection(1);
    }else if(d == 'd'){
        if(head.getDirection() != 0)
            head.setDirection(2);
    }else if(d == 's'){
        if(head.getDirection() != 1)
            head.setDirection(3);
    }else
        return;
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
            head.setX(SIZE_X-1);
        }else{
            head.setX(head_x-1);
        }
    }else if(dir == 1){
        if(head_y == 0){
            head.setY(SIZE_Y-1);
        }else{
            head.setY(head_y-1);
        }
    }else if(dir == 2){
        if(head_y == SIZE_X-1){
            head.setX(0);
        }else{
            head.setX(head_x+1);
        }
    }else{
        if(head_y == SIZE_Y-1){
            head.setY(0);
        }else{
            head.setY(head_y+1);
        }
    }
    location = head.getY()*SIZE_Y + head.getX();
    moveInTo = grid.getCell(location);
    if ((*moveInTo).getType() == 0){
        grid.setCell(location, head);
    }
    else if((*moveInTo).getType() == 3){
        grid.setCell(location, head);
        ateFood = true;
    }
    else{
        cout << "lost"; //TAKE OUT AFTER DONE TESTING
        return false;//YOU HIT THE TAIL AND LOST THE GAME!!!!!
    }

    /////////// Deal with tail ////////////////
    Tail whereHeadWas = Tail();
    whereHeadWas.setX(head_x);
    whereHeadWas.setY(head_y);
    tail.insert (tail.begin(), whereHeadWas);
    grid.setCell(whereHeadWas.getY()*SIZE_Y + whereHeadWas.getX(), whereHeadWas);
    if(!(ateFood)) {
        Tail t = tail.back();
        tail.pop_back();
        grid.setCell(t.getY()*SIZE_Y+t.getX(), emptyCell);
    }

    /////////// Deal with eaten food /////////////

    if(ateFood){
        Food* newFood = new Food();
        int index;
        while(true){
            index = rand() % (SIZE_X*SIZE_Y-1);
           if((*grid.getCell(index)).getType() != 0)
                continue;
            grid.setCell(index,*newFood);
            break;
        }
    }


    ////////////////////////////FOR MAIN TESTING////////////
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << (*grid.getCell(i*10 + j)).getType();
        }
        cout << endl;
    }

    return true;
}