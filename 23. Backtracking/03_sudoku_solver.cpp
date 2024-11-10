/*
How can you just come up with a solution of isSafe for a 3*3 cell, its so difficult to come up with that formula
board [ 3*(row/3) + i/3 ] [ 3*(col/3) + i%3 ]   ???

Ans -> The intuition behind this is, 3*(X)/3 will bring you to the starting index of the row/col 
of the sudoku box you are checking. Now with iteration we want to keep the row value constant 
for the next three iteration hence adding i/3(same values for (0-1-2, 3-4-5, 6-7-8)) and want to 
change column constantly hence adding i%3 (which would give either 0,1,2 as output).

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    
    for(int i=0; i<board.size(); i++) {
        //row check
        if(board[row][i] == val) {
            return false;
        }
        //col check
        if(board[i][col] == val) {
            return false;
        }
        //3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board) {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {

            //cell empty
            if(board[i][j] == 0) {
                for(int val=1; val<=9; val++) {
                    if(isSafe(i, j, board, val) ) {
                        //If it's safe to place the value, place it
                        board[i][j] = val;

                        //Recursive call
                        bool aageSolutionPossible = solve(board);
                        if(aageSolutionPossible) 
                            return true;
                        else 
                            //backtrack if the solution is not valid
                            board[i][j] = 0;
                    }
                }
                //Return false if no valid number can be placed in this cell
                return false;
            }
            
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
	solve(sudoku);
}

int main() {

    vector<vector<int>> sudoku = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(sudoku);

    // Print the Sudoku board
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

}