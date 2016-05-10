#include <SFML/Graphics.hpp>
#include "Tail.h"
int main()
{
    Tail tail = Tail(3, 5, 240, 380, 33);
    sf::RectangleShape shape;
    shape.move(tail.getX() * 800/10, tail.getY() * 800/10);
    shape.setSize(sf::Vector2f(800/10, 800/10));
    shape.setFillColor(sf::Color(255,255,255,255));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tron Test");

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
        window.draw(shape);
        // end the current frame
        window.display();
    }

    return 0;
}