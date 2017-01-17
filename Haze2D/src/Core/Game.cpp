#include "Haze2D/Core/Game.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int Game::run() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
