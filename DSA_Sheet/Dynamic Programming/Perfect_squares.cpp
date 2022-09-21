#include <iostream>
#include <vector>
using namespace std;

#include <math.h>

// Method 1 : Recursion Method
// Time Complexity : O(sqrt(n) ^ n)  Space Complexity : O(n)
// int findSquares(int n){

//     // Base Case
//     if(n <= 1)  
//         return n;

//     int minSq = n;

//     for(int i=1; i*i <= n; i++){

//         int count = findSquares(n-i*i);

//         minSq = min(minSq, count + 1);
//     }

//     return minSq;
// }

// int perfectSquares(int n){

//     return findSquares(n);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int findSquares(int n, vector<int> &dp){

//     // Base Case
//     if(n <= 1)  
//         return n;

//     // Step 3 : Already Exists
//     if(dp[n] != -1)
//         return dp[n];


//     int minSq = n;

//     for(int i=1; i*i <= n; i++){

//         int count = findSquares(n-i*i, dp);

//         minSq = min(minSq, count + 1);
//     }

//     // Step 2 : Store in dp array
//     dp[n] = minSq;

//     return dp[n];
// }

// int perfectSquares(int n){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, -1);

//     return findSquares(n, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int perfectSquares(int n){

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, INT_MAX);

//     // Base Case
//     dp[0] = 0;

//     // Step 2 : Tabulation
//     for(int i=1; i<=n; i++){

//         for(int j=1; j*j <= i; j++){

//             dp[i] = min(dp[i], dp[i - j*j] + 1);
//         }
//     }

//     return dp[n];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(sqrt(n))  Space Complexity : O(1)
int perfectSquares(int n){

    // Every number can be expressed in perfect squares 
    // [Max Value of 4 is possible]

    int rt = sqrt(n);
        
    if((int) (rt * rt) == n) return 1;
    
    for(int i=1; i*i<=n; i++){
        
        int sq = (sqrt(n - i*i));
        
        if((int) (sq * sq)  == n - i*i)
            return 2;
            
    }
    
    while(n % 4 == 0){
        
        n = n >> 2;
    } 
        
    if(n % 8 == 7) 
        return 4;
        
        
    return 3;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Minimum Perfect Squares
    int minimum = perfectSquares(n);

    cout << "Minimum Perfect Squares : " << minimum;

    cout << endl;
    return 0;
}