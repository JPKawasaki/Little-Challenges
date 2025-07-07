#include "game.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <optional>

Game::Game()
: window(sf::VideoMode({800, 600}), "Sudoku")
{
}

void Game::run() //not main
{
    //sf::Window window(sf::VideoMode({800, 600}), "Sudoku");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        window.display();
    }
}