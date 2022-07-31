#include <iostream>
#include <vector>
using namespace std;

// Method : Depth First Search
// Time Complexity : O(n * m)  Space Complexity : O(1)
bool isSafe(int n, int m, int i, int j){
    
    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;
        
    return true;
}

void dfs(vector< vector<int> > &grid, int row, int col){

    int n = grid.size();
    int m = grid[0].size();

    grid[row][col] = 0;

    int xPos[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int yPos[8] = {0, 0, 1, -1, 1, -1, -1, 1};

    for(int i=0; i<8; i++){

        int x = xPos[i] + row;
        int y = yPos[i] + col;

        if(isSafe(n, m, x, y) && grid[x][y] == 1){

            dfs(grid, x, y);
        }
    }
}
int numberOfIsland(vector< vector<int> > &grid){

    if(grid.size() == 0 || grid[0].size() == 0)  return 0;

    int island = 0;

    // Travel all island using dfs
    for(int i=0; i<grid.size(); i++){

        for(int j=0; j<grid[0].size(); j++){

            if(grid[i][j] == 1){

                dfs(grid, i, j);
                island++;
            }
        }
    }

    return island;
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

    // Number of Islands
    int island = numberOfIsland(grid);

    cout << "Number of Island : " << island;


    cout << endl;
    return 0;
}