#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sf::Vector2f newPosition;
    int velx = 1;
    int vely = 2;
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        newPosition = sprite.getPosition();
        newPosition.x += velx;
        newPosition.y += vely;
        if(newPosition.x + 200 >= 800) {
            velx = -3;
        }
        if(newPosition.x <= 0) {
            velx = 3;
        }
        if(newPosition.y + 200 >= 600) {
            vely = -3;
        }
        if(newPosition.y <= 0) {
            vely = 3;
        }
        sprite.setPosition(newPosition);
        // Clear screen
        window.clear();
        // Draw the string
        window.draw(text);
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}