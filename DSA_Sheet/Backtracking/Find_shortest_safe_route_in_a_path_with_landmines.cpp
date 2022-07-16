#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(4 ^ (n * m)) or O(3 ^ (n * m)) [Optimised]  
// Space Complexity : O(n * m)
bool isSafe(vector< vector<int> > &field, int i, int j){

    if(i < 0 || j < 0 || i >= field.size() || j >= field[0].size())
        return false;

    return true;
}

void makeUnsafe(vector< vector<int> > &field){

    // Make the indexes which we cannot travel
    for(int i=0; i<field.size(); i++){

        for(int j=0; j<field[i].size(); j++){

            if(field[i][j] == 0){

                int xPos[4] = {1, -1, 0, 0};
                int yPos[4] = {0, 0, 1, -1};

                for(int k=0; k<4; k++){

                    int a = i + xPos[k];
                    int b = j + yPos[k];

                    // If adjacent are only one   [On my understanding]
                    // if(isSafe(field, a, b) && field[a][b] == 1){

                    //     field[a][b] = -1;
                    // }

                    // From geeks for geeks
                    if(isSafe(field, a, b)){

                        field[a][b] = -1;
                    }
                }
            }
        }
    }

    // Make -1's unavailable
    for(int i=0; i<field.size(); i++){

        for(int j=0; j<field[i].size(); j++){

            if(field[i][j] == -1){

                field[i][j] = 0;
            }
        }
    }
}

void shortestSafeRouteHelper(vector< vector<int> > &field, vector< vector<bool> > &visited, int row, int col, int count, int &output){

    if(col == field[0].size()-1){

        output = min(output , count);
        return;
    }

    if(count > output)
        return;

    visited[row][col] = true;

    // Forward Move
    if(isSafe(field, row, col+1) && visited[row][col+1] == false && field[row][col+1] == 1){

        shortestSafeRouteHelper(field, visited, row, col+1, count+1, output);
    }

    // Down Move
    if(isSafe(field, row+1, col) && visited[row+1][col] == false && field[row+1][col] == 1){

        shortestSafeRouteHelper(field, visited, row+1, col, count+1, output);
    }

    // Up Move
    if(isSafe(field, row-1, col) && visited[row-1][col] == false && field[row-1][col] == 1){

        shortestSafeRouteHelper(field, visited, row-1, col, count+1, output);
    }

    // Back Move
    if(isSafe(field, row, col-1) && visited[row][col-1] == false && field[row][col-1] == 1){

        shortestSafeRouteHelper(field, visited, row, col-1, count+1, output);
    }

    visited[row][col] = false;
}

int shortestSafeRoute(vector< vector<int> > &field){

    if(field.size() == 0) return 0; 

    int n = field.size();
    int m = field[0].size();

    int output = INT_MAX;

    // Make adjacent 1's as unsafe
    makeUnsafe(field);

    // Start travelling from each row
    for(int i=0; i<field.size(); i++){

        vector< vector<bool> > visited(n, vector<bool>(m, false));

        if(field[i][0] == 1){

            shortestSafeRouteHelper(field, visited, i, 0, 0, output);
        }

    }

    if(output == INT_MAX){

        return -1;
    }

    return output;
}

int main()
{
    cout << "Enter n and m : ";
    int n, m;
    cin >> n >> m;

// Input:
// 1 1 1 1 1 1 1 1 1 1
// 1 0 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1
// 1 1 1 1 0 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 0 1 1 1 1
// 1 0 1 1 1 1 1 1 0 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 0 1 1 1 1 0 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1

    cout << "Enter field : \n";
    vector< vector<int> > field(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> field[i][j];
        }
    }

    // Shortest Safe Route
    int minDistance = shortestSafeRoute(field);

    cout << "Minimum Distance : " << minDistance;

    cout << endl;
    return 0;
}