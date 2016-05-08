/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: EmptyCell.h
 * Date: 4/26/2016
 * Objective:   Placeholder object for grid.
 * 
 */
#ifndef TRONSNAKE_EMPTYCELL_H
#define TRONSNAKE_EMPTYCELL_H
#include "Entity.h"
class EmptyCell: public Entity{
    public:
        EmptyCell(int xVal, int yVal);

        EmptyCell();

        int getType();

        void draw();
    private:

};

#endif /** TRONSNAKE_EMPTYCELL_H */