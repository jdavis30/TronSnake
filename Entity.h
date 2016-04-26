/*
* CS100
* 
*/

#ifndef ENTITY_H
#define ENTITY_H

class Entity{
    public:
        Entity(int x = 0, int y = 0);
        int getX();
        void setX();
        int getY();
        void setY();
        virtual int getType() = 0;
        virtual void draw() = 0;
    private:
        int x;
        int y;


}