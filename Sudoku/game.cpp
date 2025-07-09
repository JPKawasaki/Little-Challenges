//I have to change the grid, so that its possible to fill the grid with numbers (Interactive)

#include "game.h"
#include "sudoku.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <optional>
#include <iostream>

Game::Game()
: window(sf::VideoMode({800, 600}), "Sudoku") {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            grid[i][j] = 0;
        }
    }

    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Fehler beim Laden der Schriftart!\n";
    }

    fillGrid();
}

void Game::fillGrid() {
    if (!removeNumbers(grid)) {
        std::cerr << "Couldn't generate Sudoku!\n";
    }
}


void Game::drawGrid() {
    float cellSize = 30.f;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(sf::Vector2f(col * cellSize, row * cellSize));
            cell.setFillColor(sf::Color(245, 245, 245));
            cell.setOutlineThickness(1.f);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);

            int value = grid[row][col];
            if (value != 0) {
                sf::Text number(font, sf::String(std::to_string(value)), 20);
                number.setFillColor(sf::Color::Black);
                number.setPosition(sf::Vector2f(col * cellSize + 8.f, row * cellSize + 2.f));
                window.draw(number);
            }
        }
    }
}

void Game::newSudoku() {
    sf::RectangleShape square(sf::Vector2f(130.f, 70.f));
    square.setOutlineColor(sf::Color::Black);
    window.draw(square);
    
    sf::Text btnText(font);
    btnText.setFont(font);
    btnText.setString("New Sudoku");
    btnText.setCharacterSize(18);
    btnText.setPosition(sf::Vector2f());
    btnText.setFillColor(sf::Color::Black);
    window.draw(btnText);
}

void Game::run() {
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        drawGrid();
        newSudoku();
        window.display();
    }
}