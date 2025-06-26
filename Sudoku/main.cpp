//This will be my soduko App with C++
//Need to use Backtracking for checking the 9x9 Arrays
/*First, you must have a sudoku solver. Apply the solver on an empty sudoku. That is to find a solution for a sudoku with no clues.
Filling in numbers from top left to right bottom in order. Otherwise, there is a time issue. I don't know why.
Anyway, it works very fast wait no time to have a completed sudoku puzzle. When you apply backtracking,
shuffle the list of possible numbers for each position. Otherwise, you will get the same puzzle everytime.

Second, randomize a new list of all positions. That is a list of 81 positions in random order. According to this list of order,
try removing numbers from the above puzzle. Everytime, you remove a number, you have to check if it has more than one solution.
If it has more than one solution. The number should put back and try next position in the random list.
This process continues until the end of list or you already has removed 64 numbers from the puzzle successfully.
The number is 64 because somebody has proved that there is no sudoku with less than 17 clues with unique solution.
This process is varies from 15 seconds to 2 minutes. Usually 30 seconds to get a sudoku puzzle.

Third, if you don't want to wait 30 seconds to 2 minutes for each sudoku puzzle, you may apply some mutations to the above sudoku.
This includes switching rows and columns, rotating. You may also remap the numbers. For example, 1->2, 2->3...9->1.
After rotating and remapping, no one will notice this is the original sudoku.
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

bool canPlace(int grid[9][9], int row, int col, int num);
bool solveSudoku(int grid[9][9]);

int main() {
    int grid[9][9] = {{0}}; //Fill the grid with 0

    //Solve Sodoku
    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        for (int i = 0; i < 9; i++) { //To print out the grid
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

//Function to remove Numbers and to check if there is only one Solution per deleted number
bool removeNumbers(int grid[9][9]) {

}