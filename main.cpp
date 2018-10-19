#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "menu.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow app(sf::VideoMode(1280, 720), "Menu POC");

    Menu main_menu;

    main_menu.add_item("START");
    main_menu.add_item("SETTINGS");
    main_menu.add_item("EXIT");

    while(app.isOpen()) {

        sf::Event event { };
        while(app.pollEvent(event)) {
            switch(event.type)
            {
                case sf::Event::Closed: app.close(); break;
                case sf::Event::KeyPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape: app.close(); break;
                        default: break;
                    }
                }
                default: break;
            }
        }

        app.clear();
        app.draw(main_menu);
        app.display();
    }

    return 0;
}
