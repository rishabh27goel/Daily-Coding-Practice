#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Depth First Search
// Time Complexity : O(n * m)  Space Complexity : O(1)
bool isSafe(int n, int m, int x, int y){

    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;

    return true;
}

// void dfs(vector< vector<int> > &grid, int row, int col, int value, int color){

//     int n = grid.size();
//     int m = grid[0].size();

//     grid[row][col] = color;

//     // Check for neighbour pixels
//     int xPos[4] = {0, 0, 1, -1};
//     int yPos[4] = {1, -1, 0, 0};

//     for(int i=0; i<4; i++){

//         int x = xPos[i] + row;
//         int y = yPos[i] + col;

//         if(isSafe(n, m, x, y) && grid[x][y] == value){

//             dfs(grid, x, y, value, color);
//         }
//     }
// }

// vector< vector<int> > floodFill(vector< vector<int> > &grid, int px, int py, int color){

//     if(grid[px][py] == color)  return grid;

//     int value = grid[px][py];

//     // Function to fill color [Neighbour Pixels]
//     dfs(grid, px, py, value, color);

//     return grid;
// }


// Method 2 : Breadth First Search
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
vector< vector<int> > floodFill(vector< vector<int> > &grid, int px, int py, int color){

    if(grid[px][py] == color)  return grid;

    // Store the current color of pixel
    int value = grid[px][py];

    // Store the starting pixel in queue
    queue< pair<int, int> > q;

    q.push(make_pair(px, py));


    while(!q.empty()){

        pair<int, int> frontPair = q.front();
        q.pop();

        grid[frontPair.first][frontPair.second] = color;


        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};
        
        for(int i=0; i<4; i++){

            int x = xPos[i] + frontPair.first;
            int y = yPos[i] + frontPair.second;

            if(isSafe(grid.size(), grid[0].size(), x, y) && grid[x][y] == value){

                q.push(make_pair(x, y));
            }
        }
    }

    return grid;
}


int main()
{
    cout << "Enter size of grid : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    cout << "Enter grid : ";
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }

    cout << "Enter Pixel : ";
    int px, py;
    cin >> px >> py;

    cout << "Enter New Color : ";
    int color;
    cin >> color;

    // Flood Fill
    vector< vector<int> > output = floodFill(grid, px, py, color);

    cout << "\nNew Grid : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[0].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}