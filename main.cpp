#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    Game game = Game(10, 10, 400, 400);
    cout << "WASD directions. After each direction choice you go 1 step. Hit Q to quit." << endl;
    bool game_on = true;
    game.draw();
    sf::Keyboard keyboard;

    while(game_on) {
        sf::sleep(sf::milliseconds(50));
        game.draw();
        if(keyboard.isKeyPressed(sf::Keyboard::W)) {
            game.setDirection('w');
        }
        else if(keyboard.isKeyPressed(sf::Keyboard::S)) {
            game.setDirection('s');
        }
        else if(keyboard.isKeyPressed(sf::Keyboard::A)) {
            game.setDirection('a');
        }
        else if(keyboard.isKeyPressed(sf::Keyboard::D)) {
            game.setDirection('d');
<<<<<<< HEAD
        }else if(GetAsyncKeyState(0x53)){
            game.setDirection('s');
        }else if(GetAsyncKeyState(0x57)){
            game.setDirection('w');
        }else if(GetAsyncKeyState(0x51)){
            game.setDirection('q');
        }else{

=======
        }
        else if(keyboard.isKeyPressed(sf::Keyboard::Q)) {
            game.setDirection('q');
>>>>>>> 3499963cb4925defc53a6bea6a6217c792176694
        }
        game_on = game.update();
    }
    return 0;
}