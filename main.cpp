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
        }
        else if(keyboard.isKeyPressed(sf::Keyboard::Q)) {
            game.setDirection('q');
        }
        game_on = game.update();
    }
    return 0;
}