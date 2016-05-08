//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    Game game = Game(10, 10);
    char c;
    int x = 0;
    cout << "WASD directions. After each direction choice you go 1 step." << endl;
    while(x<10) {// YOU ONLY GET 10 STEPS FOR THIS DEMO. CHANGE PARAMETER FOR MORE STEPS.
        cin >> c;
        game.setDirection(c);
        game.update();
        cout << endl;
        x++;
    }

    return 0;
}