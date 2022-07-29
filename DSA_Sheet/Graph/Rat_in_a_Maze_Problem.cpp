#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(3^(n * n))  Space Complexity : O(n^2)
bool isSafe(int n, int x, int y){

    if(x < 0 || y < 0 || x >= n || y >= n)
        return false;

    return true;
}

void pathHelper(vector< vector<int> > &board, vector< vector<bool> > &visited, int row, int col, string str, vector<string> &output){

    int n = board.size();

    if(row == n-1 && col == n-1){

        output.push_back(str);
        return;
    }

    visited[row][col] = true;

    // Down
    if(isSafe(n, row+1, col) && visited[row+1][col] == false && board[row+1][col] == 1){

        pathHelper(board, visited, row+1, col, str + 'D', output);
    }

    // Left
    if(isSafe(n, row, col-1) && visited[row][col-1] == false && board[row][col-1] == 1){

        pathHelper(board, visited, row, col-1, str + 'L', output);
    }

    // Right
    if(isSafe(n, row, col+1) && visited[row][col+1] == false && board[row][col+1] == 1){

        pathHelper(board, visited, row, col+1, str + 'R', output);
    }

    // Up
    if(isSafe(n, row-1, col) && visited[row-1][col] == false && board[row-1][col] == 1){

        pathHelper(board, visited, row-1, col, str + 'U', output);
    }

    // Backtracking
    visited[row][col] = false;
}

vector<string> ratInMaze(vector< vector<int> > &board){

    int n = board.size();

    vector <string> output;

    if(board[0][0] == 0 || board[n-1][n-1] == 0)
        return output;

    // Visited array for tracking path
    vector<vector<bool>> visited(n, vector<bool> (n, false));

    pathHelper(board, visited, 0, 0, "", output);

    return output;
}

int main()
{
    cout << "Enter value of n : ";
    int n;
    cin >> n;

    cout << "Enter Board : \n";
    vector< vector<int> > board(n, vector<int> (n));

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> board[i][j];
        }
    }

    // Rat in a Maze
    vector<string> path = ratInMaze(board);

    cout << "Paths : ";

    for(int i=0; i<path.size(); i++){

        cout << path[i] << " ";
    }

    cout << endl;
    return 0;
}