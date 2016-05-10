//#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Game.h"
#include <thread>

int main()
{
    Game game = Game(10, 10);
    cout << "WASD directions. After each direction choice you go 1 step. Hit Q to quit." << endl;
    bool game_on = true;

    while(game_on) {
        Sleep(1000);
        if (GetAsyncKeyState(0x41)) {
            game.setDirection('a');
        }else if(GetAsyncKeyState(0x44)){
            game.setDirection('d');
        }else if(GetAsyncKeyState(0x53)){
            game.setDirection('s');
        }else if(GetAsyncKeyState(0x57)){
            game.setDirection('w');
        }else if(GetAsyncKeyState(0x51)){
            game.setDirection('q');
        }else{

        }
        game_on = game.update();
    }
    return 0;
}