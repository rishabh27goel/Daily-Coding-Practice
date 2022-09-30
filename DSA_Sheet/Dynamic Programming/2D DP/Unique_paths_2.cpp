#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int n, int m, int i, int j){

    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;

    return true;    
}

// Method 1 : Recursion Method 
// Time Complexity : O(2 ^ (n * m))  Space Complexity : O(n * m)
// int allPaths(int n, int m, vector< vector<int> > &grid, int row, int col){

//     // Base Case
//     if(row == n-1 && col == m-1)
//         return 1;


//     // Recursive Calls
//     int count = 0;

//     // Right Calls
//     if(isSafe(n, m, row, col+1) && grid[row][col+1] == 0)
//         count += allPaths(n, m, grid, row, col+1);

//     // Down Calls
//     if(isSafe(n, m, row+1, col) && grid[row+1][col] == 0)
//         count += allPaths(n, m, grid, row+1, col);
        

//     return count;
// }

// int findUniquePaths(int n, int m, vector< vector<int> > &grid){


//     return allPaths(n, m, grid, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int allPaths(int n, int m, vector< vector<int> > &grid, int row, int col, vector< vector<int> > &dp){

//     // Base Case
//     if(row == n-1 && col == m-1)
//         return 1;


//     // Step 3 : Already Exists 
//     if(dp[row][col] != -1)
//         return dp[row][col];


//     // Recursive Calls
//     int count = 0;

//     // Right Calls
//     if(isSafe(n, m, row, col+1) && grid[row][col+1] == 0)
//         count += allPaths(n, m, grid, row, col+1, dp);

//     // Down Calls
//     if(isSafe(n, m, row+1, col) && grid[row+1][col] == 0)
//         count += allPaths(n, m, grid, row+1, col, dp);
        

//     // Step 2 : Store in dp array
//     dp[row][col] = count;

//     return dp[row][col];
// }

// int findUniquePaths(int n, int m, vector< vector<int> > &grid){

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, -1));

//     return allPaths(n, m, grid, 0, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int findUniquePaths(int n, int m, vector< vector<int> > &grid){

//     // Base Case
//     if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
//             return 0;

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, 0));


//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i--){

//         for(int j=m-1; j>=0; j--){

//             if(grid[i][j] == 1){

//                 dp[i][j] = 0;
//             }
//             else if(i == n-1 && j == m-1){

//                 dp[i][j] = 1;
//             }
//             else{

//                 long right = i+1 < n ? dp[i+1][j] : 0;
//                 long down = j+1 < m ? dp[i][j+1] : 0;

//                 dp[i][j] = right + down;
//             }
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation [Using grid only for memoisation]
// Time Complexity : O(n * m)  Space Complexity : O(1)
int findUniquePaths(int n, int m, vector< vector<int> > &grid){

    // Base Case
    if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return 0;


    // Step 1 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=m-1; j>=0; j--){

            if(grid[i][j] == 1){

                grid[i][j] = 0;
            }
            else if(i == n-1 && j == m-1){

                grid[i][j] = 1;
            }
            else{

                long right = i+1 < n ? grid[i+1][j] : 0;
                long down = j+1 < m ? grid[i][j+1] : 0;

                grid[i][j] = right + down;
            }
        }
    }

    return grid[0][0];
}

int main()
{
    cout << "Enter size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }


    // Unique Paths 
    int paths = findUniquePaths(n, m, grid);

    cout << "Unique Paths : " << paths;


    cout << endl;
    return 0;
}