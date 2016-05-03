//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"

int main()
{
    Grid grid = Grid();
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << grid.getCell(i*10 + j);
        }
    }

    return 0;
}