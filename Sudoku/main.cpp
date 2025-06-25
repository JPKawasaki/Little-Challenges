//This will be my soduko App with C++
//Need to use Backtracking for checking the 9x9 Arrays

#include <iostream>
#include <string.h>
using namespace std;

bool canPlace(int grid[9][9], int row, int col, int num);
bool solveSudoku(int grid[9][9]);

int main() {
    int grid[9][9] = {{0}}; //Fill the grid with 0

    //Solve Sodoku
    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Couldnt solved!\n";
    }
}

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

//Backtracking
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

    //Heart of the Backtracking-Logic
    for (int i = 1; i <= 9; i++)
        if (canPlace(grid, row, col, i)) { //If the Number is valid
            grid[row][col] = i;
            if (solveSudoku(grid)) 
                return true; //Calls solveSudoku() function recursive!!!

            grid[row][col] = 0; //Reset the Number (i is now i++ 2)
        }

    return false;
}