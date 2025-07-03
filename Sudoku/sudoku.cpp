//This will be my soduko App with C++
//Need to use Backtracking for checking the 9x9 Grids
/*First, you must have a sudoku solver. Apply the solver on an empty sudoku. That is to find a solution for a sudoku with no clues.
Filling in numbers from top left to right bottom in order. Otherwise, there is a time issue. I don't know why.
Anyway, it works very fast wait no time to have a completed sudoku puzzle. When you apply backtracking,
shuffle the list of possible numbers for each position. Otherwise, you will get the same puzzle everytime.

Second, randomize a new list of all positions. That is a list of 81 positions in random order. According to this list of order,
try removing numbers from the above puzzle. Everytime, you remove a number, you have to check if it has more than one solution.
If it has more than one solution. The number should put back and try next position in the random list.
This process continues until the end of list or you already has removed 64 numbers from the puzzle successfully.
The number is 64 because somebody has proved that there is no sudoku with less than 17 clues with unique solution.
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

bool canPlace(int grid[9][9], int row, int col, int num);
bool solveSudoku(int grid[9][9]);
bool removeNumbers(int grid[9][9]);

//Function to see if i can use my current number
bool canPlace(int grid[9][9], int row, int col, int num) {

    //Check the rows
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) {
            return false;
        }
    }

    //Check the columns
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    //Check the 3x3 block
    int blockRow = (row / 3) * 3;
    int blockCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[blockRow + i][blockCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

//Backtracking!
bool solveSudoku(int grid[9][9]) {
    int row, col;
    bool emptyFound = false;


    //Looking for a empty row or column
    for (int i = 0; i < 9 && !emptyFound; i++)
        for (int j = 0; j < 9 && !emptyFound; j++)
            if (grid[i][j] == 0) {
                row = i; col = j; emptyFound = true; //emptyFound = true, to stop the searching process
            }

    //If no empty Cell was found, the Sudoku is solved
    if (!emptyFound) return true;

    //Heart of the Backtracking-Logic!
    //Random Number
    std::vector<int> randomNum = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(randomNum.begin(), randomNum.end(), g);

    for (int num : randomNum)
        if (canPlace(grid, row, col, num)) { //If the Number is valid
            grid[row][col] = num;
            if (solveSudoku(grid)) 
                return true; //Calls solveSudoku() function recursive!!!

            grid[row][col] = 0; //Reset the Number (i is now i++ 2)
        }

    return false;
}

int countSolutions(int grid[9][9]) {
    int row, col;
    bool emptyFound = false;


    //Looking for a empty row or column
    for (int i = 0; i < 9 && !emptyFound; i++)
        for (int j = 0; j < 9 && !emptyFound; j++)
            if (grid[i][j] == 0) {
                row = i; col = j; emptyFound = true; //emptyFound = true, to stop the searching process
            }

    if (!emptyFound) return 1;

    int solutions = 1;
    for (int i = 0; i < 9; i++) {
        if (canPlace(grid, row, col, i)) {
            grid[row][col] = i;
            solutions += countSolutions(grid);
            grid[row][col] = 0;
            if (solutions > 1) {
                return solutions; //Abbruch bei zwei Solutions
            }
        }
    }
    return solutions;
}

//Function to remove Numbers and to check if there is only one Solution per deleted number
bool removeNumbers(int grid[9][9]) {
    solveSudoku(grid);

    std::vector<int> cells(81);
    std::iota(cells.begin(), cells.end(), 0); // füllt mit 0..80
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cells.begin(), cells.end(), g);

    int removedCount = 0;

    for (int pos : cells) {
        int row = pos / 9;
        int col = pos % 9;
        int backup = grid[row][col];
        grid[row][col] = 0;
        
        if (countSolutions(grid) != 1) {
            grid[row][col] = backup;
        } else {
            removedCount++;
        }

        if (removedCount >= 47) { //64 ist maximum
            break;
        }
    }
    return true;
}