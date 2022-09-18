#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int findWays(int n, int k){

//     // Base Case
//     if(n == 1)  return k;
//     if(n == 2)  return k * k;

//     // Previous Calls
//     int oneBack = findWays(n-1, k);
//     int twoBack = findWays(n-2, k);

//     return (oneBack + twoBack) * (k-1);
// }

// int paintingFence(int n, int k){

//     return findWays(n, k);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int findWays(int n, int k, vector<int> &dp){

//     // Base Case
//     if(n == 1)  return k;
//     if(n == 2)  return k * k;

//     // Step 3 : Already Exists
//     if(dp[n] != -1)
//         return dp[n];

//     // Previous Calls
//     int oneBack = findWays(n-1, k, dp);
//     int twoBack = findWays(n-2, k, dp);

//     // Step 2 : Store in dp array8
//     dp[n] = (oneBack + twoBack) * (k-1);

//     return dp[n];
// }

// int paintingFence(int n, int k){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, -1); 

//     return findWays(n, k, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int paintingFence(int n, int k){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, -1);

//     // Base Case
//     dp[0] = 0;
//     dp[1] = k;
//     dp[2] = k * k;

//     // Step 2 : Tabulation
//     for(int i=3; i<=n; i++){

//         dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
//     }

//     return dp[n];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int paintingFence(int n, int k){

    // Base Case
    int x = k;
    int y = k * k;

    // Step 2 : Tabulation
    for(int i=3; i<=n; i++){

        int store = y;

        y = (x + y) * (k-1);
        x = store;
    }

    return y;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Painting the fence
    int ways = paintingFence(n, k);

    cout << "Total Ways : " << ways;


    cout << endl;
    return 0;
}