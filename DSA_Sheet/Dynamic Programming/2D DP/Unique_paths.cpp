#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (n * m))  Space Complexity : O(n * m)
// int allPaths(int n, int m, int row, int col){

//     // Base Case
//     if(row < 0 || col < 0 || row >= n || col >= m)  
//         return 0;
    
//     if(row == n-1 && col == m-1)
//         return 1;


//     // Try all paths
//     int count = 0;

//     // Right Call
//     count += allPaths(n, m, row, col+1);

//     // Down Call
//     count += allPaths(n, m, row+1, col);


//     return count;
// }

// int uniquePaths(int n, int m){

//     return allPaths(n, m, 0, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int allPaths(int n, int m, int row, int col, vector< vector<int> > &dp){

//     // Base Case
//     if(row < 0 || col < 0 || row >= n || col >= m)  
//         return 0;
    
//     if(row == n-1 && col == m-1)
//         return 1;

//     // Step 3 : Already Exists
//     if(dp[row][col] != -1)
//         return dp[row][col];

//     // Try all paths
//     int count = 0;

//     // Right Call
//     count += allPaths(n, m, row, col+1, dp);

//     // Down Call
//     count += allPaths(n, m, row+1, col, dp);


//     // Step 2 : Store in dp array
//     dp[row][col] = count;

//     return dp[row][col];
// }

// int uniquePaths(int n, int m){

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, -1));

//     return allPaths(n, m, 0, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
// int uniquePaths(int n, int m){

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (m, 0));

//     // Step 2 : Tabulation
//     for(int i=n-1; i>=0; i--){

//         for(int j=m-1; j>=0; j--){

//             if(i == n-1 || j == m-1){

//                 dp[i][j] = 1;
//             }
//             else{

//                 dp[i][j] = dp[i+1][j] + dp[i][j+1];
//             }
//         }
//     }

//     return dp[0][0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * m)  Space Complexity : O(m)
int uniquePaths(int n, int m){

    // Step 1 : Create dp array
    vector <int> dp(m, 1);

    // Step 2 : Tabulation
    for(int i=n-2; i>=0; i--){

        for(int j=m-2; j>=0; j--){

            dp[j] += dp[j+1];
        }
    }

    return dp[0];
}

int main()
{
    cout << "Enter size : ";
    int n, m;
    cin >> n >> m;

    // Unique Paths
    int paths = uniquePaths(n, m);

    cout << "Unique Paths : " << paths;


    cout << endl;
    return 0;
}