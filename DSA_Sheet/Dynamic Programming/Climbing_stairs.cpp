#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Ways from 0 to n  AND  Ways from n to 0
// Time Complexity : O(2^n)  Space Complexity : O(n)
// Approach 1: Ways from 0 to n
// int climbingStairsHelper(int n, int s){

//     // Base Case
//     if(s > n)  return 0;
//     if(s == n)  return 1;


//     return climbingStairsHelper(n, s+1) + climbingStairsHelper(n, s+2);
// }

// int climbingStairs(int n){

//     return climbingStairsHelper(n, 0);
// }

// Approach 2: Ways from n to 0
// int climbingStairs(int n){

//     // Base Case
//     if(n == 0)  return 1;
//     if(n == 1)  return 1;

//     return climbingStairs(n-1) + climbingStairs(n-2);
// }

// Method 2 : Using Dynamic Programming & Memoization
// Time Complexity : O(n)  Space Complexity : O(n)
// Approach 1:
// int climbingStairsHelper(int n, int s, vector<int> &dp){

//     // Base Case
//     if(s > n)  return 0;
//     if(s == n)  return 1;

//     // Step 3 : If dp[n] exits
//     if(dp[s] != -1)
//         return dp[s];

//     // Step 2 : Store value in dp array
//     dp[s] = climbingStairsHelper(n, s+1, dp) + climbingStairsHelper(n, s+2, dp);

//     return dp[s];
// }

// int climbingStairs(int n){

//     // Step 1 : Create DP Array
//     vector<int> dp(n, -1);

//     return climbingStairsHelper(n, 0, dp);
// }

// Approach 2:
// int climbingStairsHelper(int n, vector<int> &dp){

//     // Base Case
//     if(n == 0)  return 1;
//     if(n == 1)  return 1;

//     // Step 3 : If dp[n] exits
//     if(dp[n] != -1)
//         return dp[n];

//     // Step 2 : Store value in dp array
//     dp[n] = climbingStairsHelper(n-1, dp) + climbingStairsHelper(n-2, dp);

//     return dp[n];
// }

// int climbingStairs(int n){

//     // Step 1 : Create dp array
//     vector<int> dp(n+1, -1);

//     return climbingStairsHelper(n, dp);
// }

// Method 3 : Using Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int climbingStairs(int n){

//     // Step 1 : Create DP Array
//     vector<int> dp(n+1, -1);

//     // Base Case
//     dp[0] = 1;
//     dp[1] = 1;

//     // Step 2 : Tabulation
//     for(int i=2; i<=n; i++){

//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int climbingStairs(int n){

    if(n <= 1)  return 1;

    int x = 1;
    int y = 1;

    for(int i=2; i<=n; i++){

        y = x + y;
        x = y - x;
    }

    return y;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Climbing Stairs
    int ways = climbingStairs(n);

    cout << "Ways : " << ways;

    cout << endl;
    return 0;
}