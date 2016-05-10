/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Entity.h
 * Date: 4/26/2016
 * Objective:   Base class for objects within TronSnake game.
 */

#ifndef TRONSNAKE_ENTITY_H
#define TRONSNAKE_ENTITY_H
 
class Entity{
public:
    Entity(int xVal = 0, int yVal = 0);
    int getX();
    void setX(int xVal = 0);
    int getY();
    void setY(int yVal = 0);
    virtual int getType() = 0;
private:
    int x;
    int y;

};

#endif /** TRONSNAKE_ENTITY_H */