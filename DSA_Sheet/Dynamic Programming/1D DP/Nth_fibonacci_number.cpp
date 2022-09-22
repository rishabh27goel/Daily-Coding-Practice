#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Using Recursion 
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int nthFibonacci(int n){

//     if(n == 0 || n == 1)
//         return n;

//     return nthFibonacci(n-1) + nthFibonacci(n-2);
// }

// Method 2 : Using Dynamic Programming + Memoization 
// Time Complexity : O(n)  Space Complexity : O(n)
// int nthFibonacciHelper(int n, vector<int> &dp){

//     // Base Case
//     if(n == 0 || n == 1)
//         return n;

//     // Step 3 : If dp[n] is already present
//     if(dp[n] != -1)
//         return dp[n];

//     // Step 2 : Store values from recursion calls
//     dp[n] = nthFibonacciHelper(n-1, dp) + nthFibonacciHelper(n-2, dp);

//     return dp[n];
// }

// int nthFibonacci(int n){

//     // Step 1 : Create DP
//     vector<int> dp(n + 1, -1);

//     return nthFibonacciHelper(n, dp);
// }

// Method 3 : Using Dynamic Programming + Tabulation 
// Time Complexity : O(n)  Space Complexity : O(n)
// int nthFibonacci(int n){

//     // Step 1 : Create DP
//     vector<int> dp(n + 1, -1);

//     // Step 2 : Base Case
//     dp[0] = 0;
//     dp[1] = 1;

//     // Step 3 : Tabulation 
//     for(int i=2; i<=n; i++){

//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int nthFibonacci(int n){

    if(n <= 1)  return n;

    int x = 0;
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

    // Nth Fibonacci Number
    int number = nthFibonacci(n);

    cout << "Nth Fibonacci Number is : " << number;

    cout << endl;
    return 0;
}