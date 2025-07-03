#include <iostream>
#include "game.h"
#include "sudoku.h"

int main() {
    int grid[9][9] = {{0}};

    if (removeNumbers(grid)) {
        std::cout << "Sudoku solved:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "Couldn't solve!\n";
    }

    Game game;
    game.run();

    return 0;
}