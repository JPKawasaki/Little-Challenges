#pragma once
#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();

    private:
        sf::RenderWindow window;
        int grid[9][9];
        sf::Font font;
        void drawGrid();
        void fillGrid();
};