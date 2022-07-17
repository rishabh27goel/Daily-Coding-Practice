#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(8 ^ (n * m))  Space Complexity : O(n * m)
bool isSafe(vector< vector <int> > &board, int i, int j){

    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){

        return false;
    }

    return true;
}

void printBoard(vector< vector <int> > &board){

    int n = board.size();
    int m = board[0].size();

    cout << "Knight's Tour Solution : \n\n";

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

void knightTourHelper(vector< vector <int> > &board, int row, int col, int move, bool &found){

    int n = board.size();
    int m = board[0].size();

    if(move == (n * m)-1){

        board[row][col] = move;

        // printBoard(board);

        found = true;
        // board[row][col] = -1;

        return;
    }

    // Fill the move number
    board[row][col] = move;

    int xPos[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yPos[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for(int i=0; i<8; i++){

        int a = xPos[i] + row;
        int b = yPos[i] + col;

        // If the next position is safe and -1 is still there
        if(isSafe(board, a, b) && board[a][b] == -1){

            knightTourHelper(board, a, b, move + 1, found);

            // If a soultion is found
            if(found == true)
                return;
        }
    }

    // Backtracking
    board[row][col] = -1;
}

void knightTour(int n, int m){

    vector< vector <int> > board(n, vector<int> (m, -1));
    if(n == 0 || m == 0)  return;

    // Start the knight tour from 0,0 
    bool found = false;
    knightTourHelper(board, 0, 0, 0, found);

    printBoard(board);
} 


int main()
{
    cout << "Enter n and m : ";
    int n, m;
    cin >> n >> m;

    // The Knight’s tour problem
    knightTour(n, m);


    cout << endl;
    return 0;
}