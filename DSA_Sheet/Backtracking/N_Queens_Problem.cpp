#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Backtracking
// Time Complexity : O(!n)  Space Complexity : O(n^2)
// bool isSafe(vector<string> &board, int row, int col){

//     // Check for same row
//     for(int i=0; i<row; i++){

//         if(board[i][col] == 'Q')
//             return false;
//     }


//     // Check for same col
//     // [this is not needed as col (1-n) will only happen when previous has no Q]


//     // Check for left diagonal
//     int i = row-1;
//     int j = col-1;

//     while(i >= 0 && j >= 0){

//         if(board[i][j] == 'Q')
//             return false;

//         i--;
//         j--;
//     }


//     // Check for right diagonal
//     i = row-1;
//     j = col+1;

//     while(i >= 0 && j < board.size()){

//         if(board[i][j] == 'Q')
//             return false;

//         i--;
//         j++;
//     }

//     return true;
// }

// Method 2 : Backtracking [Optimized Approach]
// Time Complexity : O(!n)  Space Complexity : O(n^2)
unordered_map<int , bool> rowCheck;
unordered_map<int , bool> leftDiagonal;
unordered_map<int , bool> rightDiagonal;

bool isSafe(vector<string> &board, int row, int col){

    int n = board.size();

    if(rowCheck[col] || leftDiagonal[n - 1 + col - row ] || rightDiagonal[row + col])
        return false;

    return true;
}

void nQueenHelper(vector<string> &board, int i, vector< vector<string> > &output){

    int n = board.size();

    if(i == n){

        output.push_back(board);
        return;
    }

    // Check for columns whether it is safe or not
    for(int j=0; j<n; j++){

        if(isSafe(board, i, j)){

            board[i][j] = 'Q';
            rowCheck[j] = true;
            leftDiagonal[n - 1 + j - i] = true;
            rightDiagonal[i + j] = true;

            nQueenHelper(board, i+1, output);

            board[i][j] = '.';
            rowCheck[j] = false;
            leftDiagonal[n - 1 + j - i] = false;
            rightDiagonal[i + j] = false;
        }
    }
}

vector< vector<string> > solveNQueens(int n){

    vector< vector<string> > output;
    if(n == 0) return output;

    // Create the board
    string str = "";

    for(int i=0; i<n; i++){

        str += '.';
    }

    vector <string> board(n, str);

    nQueenHelper(board, 0, output);

    return output;
}

int main()
{
    cout << "Enter the value of n : ";
    int n;
    cin >> n;

    // N Queen Solution
    vector< vector<string> > output = solveNQueens(n);

    cout << "NQueen Solutions : " << endl;
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}