/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: EmptyCell.h
 * Date: 4/26/2016
 * Objective:   Placeholder object for grid.
 * 
 */
#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Entity.h"
class EmptyCell: public Entity{
    public:
        EmptyCell(int xVal, int yVal);

        EmptyCell();

        int getType();

        void draw();
    private:

};

#endif /** EMPTYCELL_H */