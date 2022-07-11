#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

// Method : Backtracking
// Time Complexity : O(9 ^ (n * n))  Space Complexity : O(n * n)
void printBoard(vector< vector<int> > &board){

    cout << "\nPrinting the board : \n";
    for(int i=0; i<N; i++){

        for(int j=0; j<N; j++){

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool isSafe(vector< vector<int> > &board, int row, int col, int val){

    // Check for same row
    for(int i=0; i<N; i++){

        if(board[row][i] == val)
            return false;
    }

    // Check for same column
    for(int i=0; i<N; i++){

        if(board[i][col] == val)
            return false;
    }

    // Check 3 X 3 Grid
    int a = (row / 3) * 3;
    int b = (col / 3) * 3;

    for(int i=a; i<a+3; i++){

        for(int j=b; j<b+3; j++){

            if(board[i][j] == val)
                return false;
        }
    }

    return true;
}

bool sudokuSolverHelper(vector< vector<int> > &board, int i, int j){

    // When solution is found
    if(i == N-1 && j == N){

        printBoard(board);
        return true;
    }

    // Move to next row
    if(j == N){

        i = i + 1;
        j = 0;
    }

    // If the board[i][j] already has a value [Check for next index]
    if(board[i][j] != 0)
        return sudokuSolverHelper(board, i, j + 1);

    if(board[i][j] == 0){

        // Try values from 1-9
        for(int val=1; val<=9; val++){

            if(isSafe(board, i, j, val)){

                board[i][j] = val;

                // If we get a solution
                if(sudokuSolverHelper(board, i, j + 1)){

                    return true;
                }

                // Backtracking 
                board[i][j] = 0;
            }
        }

        // After trying all values 
        return false;
    }

    return true;
}

bool sudokuSolver(vector< vector<int> > &board){

    return sudokuSolverHelper(board, 0, 0);
}

int main()
{
//     Input : 
// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0

    cout << "Enter board : ";
    vector< vector<int> > board(9, vector<int> (9));

    for(int i=0; i<9; i++){

        for(int j=0; j<9; j++){

            cin >> board[i][j];
        }
    }

    // Sudoku Solver
    if(sudokuSolver(board)){

        printBoard(board);
    }


    cout << endl;
    return 0;
}
