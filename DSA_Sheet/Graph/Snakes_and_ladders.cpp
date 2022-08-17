#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Method : Breadth First Search [As we need less moves as possible]
// Time Complexity : O(n^2)  Space Complexity : O(n^2)
// As we only reaching each cell once
int snakesAndLadders(int n, vector< vector<int> > &board){

    // For visiting each node once
    vector <bool> visited(n * n, false);

    // For storing each cell
    queue< pair<int, int> > q;

    q.push(make_pair(0, 0));   // Pair : {Start, Steps}
    visited[0] = true;

    while(!q.empty()){

        pair<int, int> frontPair = q.front();
        q.pop();

        int start = frontPair.first;
        int steps = frontPair.second;

        // If we reach the last cell
        if(start == (n * n)-1)
            return steps;

        // Now move next 6 positions
        for(int i=1; i<=6; i++){

            if(start + i >= n * n)
                continue;

            int orgPos = (start + i) / n;

            int row = (n-1) - orgPos;
            int col = (start + i) % n;

            // For alternate rows change columns
            if(orgPos % 2 == 1){

                col = (n-1) - col;
            }

            int value = board[row][col] == -1 ? start + i : board[row][col]-1;

            // Check if the position is visited
            if(visited[value] == false){

                q.push(make_pair(value, steps + 1));
                visited[value] = true;
            }
        }
    }

    return -1;
}


int main()
{
    cout << "Enter value of n : ";
    int n;
    cin >> n;

    vector< vector<int> > board(n, vector<int> (n));

// Input :
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// -1 35 -1 -1 13 -1 
// -1 -1 -1 -1 -1 -1 
// -1 15 -1 -1 -1 -1


    cout << "Enter Board : \n";

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> board[i][j];
        }
    }

    // Snakes and Ladders
    int moves = snakesAndLadders(n, board);

    if(moves == -1){

        cout << "Not Possible !!";
    }
    else{

        cout << "Steps Required : " << moves;
    }

    cout << endl;
    return 0;
}