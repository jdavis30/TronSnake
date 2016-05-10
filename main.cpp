#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	int gridSizeX = 50;
	int gridSizeY = 50;
	int windowSizeX = 600;
	int windowSizeY = 600;
    Game game = Game(gridSizeX, gridSizeY, windowSizeX, windowSizeY);
    //cout << "WASD directions. After each direction choice you go 1 step. Hit Q to quit." << endl;// Terminal UI.
    bool game_on = true;
    game.setDirection('n');/////does not move character until button is pressed.
    sf::Keyboard keyboard;
    while(!keyboard.isKeyPressed(sf::Keyboard::Q)) {
	    if(game_on) {
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
	    } else
	    game.endGame();
	    if(keyboard.isKeyPressed(sf::Keyboard::R)) {
	    	game.reset();
    		game.setDirection('n');/////does not move character until button is pressed.
	    	game_on = true;
	    }
	}

    return 0;
}