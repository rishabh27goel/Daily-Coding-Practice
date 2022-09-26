#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3 ^ (m * n))   Space Complexity : O(m * n) 
// int findMaxSquare(vector< vector<int> > &grid, int i, int j, int &maxSquare){

//     int n = grid.size();
//     int m = grid[0].size();

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;


//     // Checking Neighbours
//     int right = findMaxSquare(grid, i, j+1, maxSquare);
//     int diag = findMaxSquare(grid, i+1, j+1, maxSquare);
//     int down = findMaxSquare(grid, i+1, j, maxSquare);

//     // Current Index
//     if(grid[i][j] == 1){

//         int square = 1 + min(diag, min(right, down));

//         maxSquare = max(square, maxSquare);

//         return square;
//     }
//     else{

//         return 0;
//     }
// }

// int maximalSquare(vector< vector<int> > &grid){

//     int n = grid.size();
//     int m = grid[0].size();

//     int maxSquare = 0;
//     int sq = findMaxSquare(grid, 0, 0, maxSquare);

//     return maxSquare * maxSquare;
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(m * n)   Space Complexity : O(m * n) 
// int findMaxSquare(vector< vector<int> > &grid, int i, int j, int &maxSquare, vector< vector<int> > &dp){

//     int n = grid.size();
//     int m = grid[0].size();

//     // Base Case
//     if(i >= n || j >= m)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];


//     // Checking Neighbours
//     int right = findMaxSquare(grid, i, j+1, maxSquare, dp);
//     int diag = findMaxSquare(grid, i+1, j+1, maxSquare, dp);
//     int down = findMaxSquare(grid, i+1, j, maxSquare, dp);

//     // Current Index
//     if(grid[i][j] == 1){

//         // Step 2 : Storing in dp array
//         dp[i][j] = 1 + min(diag, min(right, down));

//         maxSquare = max(dp[i][j], maxSquare);

//         return dp[i][j];
//     }
//     else{

//         return 0;
//     }
// }

// int maximalSquare(vector< vector<int> > &grid){

//     int n = grid.size();
//     int m = grid[0].size();

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, -1));

//     int maxSquare = 0;
//     int sq = findMaxSquare(grid, 0, 0, maxSquare, dp);

//     return maxSquare * maxSquare;
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(m * n)   Space Complexity : O(m * n) 
// int maximalSquare(vector< vector<int> > &grid){

//     int n = grid.size();
//     int m = grid[0].size();

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, 0));
//     int maxSquare = 0;


//     // Step 2 : Tabulation
//     for(int i=0; i<n; i++){

//         for(int j=0; j<m; j++){

//             // Checking Neighbours
//             int left = 0, diag = 0, up = 0;
        
//             if(j-1 >= 0)
//                 left = dp[i][j-1];
            
//             if(i-1 >= 0 && j-1 >= 0)
//                 diag = dp[i-1][j-1];
            
//             if(i-1 >= 0)
//                 up = dp[i-1][j];

//             // Current Index
//             if(grid[i][j] == 1){

//                 dp[i][j] = 1 + min(diag, min(left, up));

//                 maxSquare = max(dp[i][j], maxSquare);
//             }
//             else{

//                 dp[i][j] = 0;
//             }
//         }
//     }

//     return maxSquare * maxSquare;
// }

// Method 4 : Space Optimisation
// Time Complexity : O(m * n)   Space Complexity : O(2 * m) 
int maximalSquare(vector< vector<int> > &grid){

    int n = grid.size();
    int m = grid[0].size();

    // Step 1 : Create dp array [Prev and Current]
    vector <int> prev(m, 0);
    vector <int> curr(m, 0);

    int maxSquare = 0;


    // Step 2 : Tabulation []
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            // Checking Neighbours
            int left = 0, diag = 0, up = 0;
        
            if(j-1 >= 0)        // Same Row
                left = curr[j-1];
            
            if(i-1 >= 0 && j-1 >= 0)    // Previous Row
                diag = prev[j-1];
            
            if(i-1 >= 0)        // Previous Row
                up = prev[j];

            // Current Index
            if(grid[i][j] == 1){

                curr[j] = 1 + min(diag, min(left, up));

                maxSquare = max(curr[j], maxSquare);
            }
            else{

                curr[j] = 0;
            }
        }

        // Update the previous
        prev = curr;
    }


    return maxSquare * maxSquare;
}

int main()
{
    cout << "Enter grid size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }

    // Maximal Square 
    int area = maximalSquare(grid);

    cout << "Maximum Area : " << area;

    cout << endl;
    return 0;
}