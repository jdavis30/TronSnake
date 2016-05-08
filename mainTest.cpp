#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
int main()
{
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    Grid grid(9, 9);
    Head tail(50, 35, 140);

    for(int i = 0;  i < 4; i ++){
        grid.setCell(rand(9), rand(9), &tail);
    }
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "TronGame Test");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}