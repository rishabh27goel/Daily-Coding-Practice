#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int findCount(int n){

//     // Base Case
//     if(n == 1)  return 0;
//     if(n == 2)  return 1;


//     return (n-1) * (findCount(n-1) + findCount(n-2));
// }

// int countDerangements(int n){

//     return findCount(n);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int findCount(int n, vector<int> &dp){

//     // Base Case
//     if(n == 1)  return 0;
//     if(n == 2)  return 1;

//     // Step 3 : Already Exists
//     if(dp[n] != -1)
//         return dp[n];


//     // Step 2 : Store in dp array
//     dp[n] = (n-1) * (findCount(n-1, dp) + findCount(n-2, dp));


//     return dp[n];
// }

// int countDerangements(int n){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, -1);

//     return findCount(n, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int countDerangements(int n){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, -1);

//     // Base Case
//     dp[0] = 0;
//     dp[1] = 0;
//     dp[2] = 1;

//     // Step 2 : Tabulation
//     for(int i=3; i<=n; i++){

//         dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
//     }


//     return dp[n];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int countDerangements(int n){

    // Base Case
    int x = 0;
    int y = 1;

    // Step 2 : Tabulation
    for(int i=3; i<=n; i++){

        int store = y;

        y = (i-1) * (x + y);
        x = store;
    }

    return y;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Count Derangements
    int count = countDerangements(n);

    cout << "Derangements Count : " << count;


    cout << endl;
    return 0;
}