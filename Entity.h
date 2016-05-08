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
<<<<<<< HEAD
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
=======
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
>>>>>>> e32ceeb22c039cb11e1d817806a9e9ea861b820a

};

#endif /** TRONSNAKE_ENTITY_H */
