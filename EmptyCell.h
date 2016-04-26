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
        virtual int getType();
        virtual void draw() = 0;
    private:

};

#endif /** EMPTYCELL_H */