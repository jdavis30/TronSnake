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

Game::Game(int sizeX, int sizeY, int wSizeX, int wSizeY){
    SIZE_X = sizeX;
    SIZE_Y = sizeY;
    W_SIZE_X = wSizeX;
    W_SIZE_Y = wSizeY;
    emptyCell = EmptyCell();
    grid = Grid(SIZE_X, SIZE_Y);
    firstRun = true;
    head = Head(5,9,1);//sets values in head, doesnt actually set the heads location.
    headShape = new sf::RectangleShape();
    (*headShape).setPosition(5 * W_SIZE_X/SIZE_X,9 * W_SIZE_Y/SIZE_Y);
    (*headShape).setSize(sf::Vector2f(W_SIZE_X/SIZE_X,W_SIZE_Y/SIZE_Y));
    (*headShape).setFillColor(sf::Color(255,255,255,255));
    foodShape = new sf::RectangleShape();
    (*foodShape).setFillColor(sf::Color(240,35,43,255));
    (*foodShape).setSize(sf::Vector2f(W_SIZE_X/SIZE_X,W_SIZE_Y/SIZE_Y));;
    window = new sf::RenderWindow(sf::VideoMode(W_SIZE_X, W_SIZE_Y), "TronSnake");
}

void Game::setDirection(char d) {
    if (d == 'a') {
        if (head.getDirection() != 2)
            head.setDirection(0);
    } else if (d == 'w') {
        if (head.getDirection() != 3)
            head.setDirection(1);
    } else if (d == 'd') {
        if (head.getDirection() != 0)
            head.setDirection(2);
    } else if (d == 's') {
        if (head.getDirection() != 1)
            head.setDirection(3);
    }else if(d == 'q'){
        head.setDirection(-3);
    }else {
        head.setDirection(-1);
    }
}

bool Game::update(){
    ///////////// deal with moving head ///////////////
    int dir = head.getDirection();
    int head_x = head.getX();
    int head_y = head.getY();
    int location;
    bool ateFood = false;
    Entity * moveInTo;
    if(dir == -3) {
        //cout << "quit game" << endl;
        return false;
    }
    if(dir == 0){
        if(head_x == 0){
            //head.setX(SIZE_X-1);
            return false;
        }else{
            head.setX(head_x-1);
        }
    }else if(dir == 1){
        if(head_y == 0){
            //head.setY(SIZE_Y-1);
            return false;
        }else{
            head.setY(head_y-1);
        }
    }else if(dir == 2){
        if(head_x == SIZE_X-1){
            //head.setX(0);
            return false;
        }else{
            head.setX(head_x+1);
        }
    }else if(dir == 3){
        if(head_y == SIZE_Y-1){
            //head.setY(0);
            return false;
        }else{
            head.setY(head_y+1);
        }
    }else {
        ;
    }
    (*headShape).setPosition(head.getX() * W_SIZE_X/SIZE_X, head.getY() * W_SIZE_Y/SIZE_Y);
    location = head.getY()*SIZE_Y + head.getX();
    moveInTo = grid.getCell(location);
    if ((*moveInTo).getType() == 0){
        grid.setCell(location, head);
    } else if((*moveInTo).getType() == 3){
        grid.setCell(location, head);
        ateFood = true;
    }else {
        //cout << "lost" << endl; //TAKE OUT AFTER DONE TESTING
        return false; //YOU HIT THE TAIL AND LOST THE GAME!!!!!
    }
    /////////// Deal with tail ////////////////
    Tail* whereHeadWas = new Tail();
    sf::RectangleShape* tailBlock = new sf::RectangleShape();
    (*whereHeadWas).setX(head_x);
    (*whereHeadWas).setY(head_y);
    (*tailBlock).setPosition(head_x * W_SIZE_X/SIZE_X, head_y * W_SIZE_Y/SIZE_Y);
    (*tailBlock).setFillColor(sf::Color(45,200,24,255));
    (*tailBlock).setSize(sf::Vector2f(W_SIZE_X/SIZE_X,W_SIZE_Y/SIZE_Y));
    tail.insert (tail.begin(), (*whereHeadWas));
    rects.insert (rects.begin(), (*tailBlock));
    grid.setCell((*whereHeadWas).getY()*SIZE_Y + (*whereHeadWas).getX(), (*whereHeadWas));
    if(!(ateFood)) {
        Tail* t = &tail.back();
        tail.pop_back();
        rects.pop_back();
        grid.setCell((*t).getY()*SIZE_Y+(*t).getX(), emptyCell);
    }

    /////////// Deal with eaten food /////////////

    if(ateFood || firstRun){
        firstRun = false;
        Food* newFood = new Food();
        int indexX;
        int indexY;
        int index;
        while(true){
            indexX = rand() % (SIZE_X - 1);
            //cout << indexX << endl;//////////DEBUG
            indexY = rand() % (SIZE_Y - 1);
            //cout << indexY << endl;//////////DEBUG
            index =  (((indexY + 1) * SIZE_X) + indexX + 1);
            //cout << index << endl;///////////DEBUG
            if((*grid.getCell(index)).getType() != 0)
                continue;
            grid.setCell(index,*newFood);
            (*foodShape).setPosition((indexX + 1) * W_SIZE_X/SIZE_X, (indexY + 1) * W_SIZE_Y/SIZE_Y);
            break;
        }
    }


    
    

    return true;
}

void Game::draw() {
    ////////////////////////////FOR MAIN TESTING////////////
    /*for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << (*grid.getCell(i*10 + j)).getType();
        }
        cout << endl;
    }*/
    sf::Font font;
    if(!font.loadFromFile("ThrowMyHandsUpintheAirBold.ttf")){
        return;
    }
    sf::Text text("WASD to move", font, 50);
    text.setPosition(W_SIZE_X/2 - 150, W_SIZE_Y/2 - 150);
    /////Clear Window
    (*window).clear(sf::Color::Black);
    //draw head and food
    if(head.getDirection() == -1){
        (*window).draw(text);
    }
    (*window).draw(*headShape);
    (*window).draw(*foodShape);
    //////draw tail.
    for(sf::RectangleShape i : rects) {
        (*window).draw(i);
    }
    ///////ddisplay screen
    (*window).display();
}
void Game::endGame() {
    sf::Font font;
    if(!font.loadFromFile("ThrowMyHandsUpintheAirBold.ttf")){
        return;
    }
    sf::Text text("Game Over, Q to quit \n R to restart", font, 50);
    text.setPosition(W_SIZE_X/2 - 200, W_SIZE_Y/2 - 200);
    (*window).clear(sf::Color::Black);
    (*window).draw(text);
    (*window).display();
}

void Game::reset() {
    emptyCell = EmptyCell();
    grid = Grid(SIZE_X, SIZE_Y);
    firstRun = true;
    head = Head(5,9,1);//sets values in head, doesnt actually set the heads location.
    (*headShape).setPosition(head.getX() * W_SIZE_X/SIZE_X,head.getY() * W_SIZE_Y/SIZE_Y);
    tail.clear();
    rects.clear();
}