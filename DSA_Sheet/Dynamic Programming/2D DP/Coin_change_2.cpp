#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (n * target))  Space Complexity : O(n * target)
// int totalWays(vector<int> &coins, int target, int ind){

//     // Base Case
//     if(ind == 0){

//         return target % coins[ind] == 0;
//     }

//     int include = 0;

//     if(target >= coins[ind]) 
//         include = totalWays(coins, target-coins[ind], ind);


//     int exclude = totalWays(coins, target, ind-1);
    

//     return include + exclude;
// }

// int coinsChange(vector<int> &coins, int target){

//     int n = coins.size();

//     return totalWays(coins, target, n-1, dp);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// int totalWays(vector<int> &coins, int target, int ind, vector< vector<int> > &dp){

//     // Base Case
//     if(ind == 0){

//         return target % coins[ind] == 0;
//     }

//     // Step 3 : Already Exists
//     if(dp[ind][target] != -1)
//         return dp[ind][target];

//     int include = 0;

//     if(target >= coins[ind]) 
//         include = totalWays(coins, target-coins[ind], ind, dp);


//     int exclude = totalWays(coins, target, ind-1, dp);
    

//     // Step 2 : Store in dp array
//     dp[ind][target] = include + exclude;


//     return dp[ind][target];
// }

// int coinsChange(vector<int> &coins, int target){

//     int n = coins.size();
        
//     // Sort the coins
//     sort(coins.begin(), coins.end());

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (target+1, -1));

//     return totalWays(coins, target, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * target)  Space Complexity : O(n * target)
// int coinsChange(vector<int> &coins, int target){

//     int n = coins.size();
    
//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (target+1, 0));
    
//     // Base Case
//     for(int i=0; i<=target; i++){

//         if((i % coins[0]) == 0){

//             dp[0][i] = 1;
//         }
//     }
    
//     // Step 2 : Tabulation
//     for(int i=1; i<n; i++){

//         for(int j=0; j<=target; j++){

//             if(j == 0){

//                 dp[i][j] = 1;
//             }
//             else{

//                 if(j - coins[i] >= 0){

//                     dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
//                 }
//                 else{

//                     dp[i][j] += dp[i-1][j];
//                 }
//             }
//         }
//     }

//     return dp[n-1][target];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n * target)  Space Complexity : O(target)
int coinsChange(vector<int> &coins, int target){

    int n = coins.size();
    
    // Sort the coins
    sort(coins.begin(), coins.end());

    // Step 1 : Create dp array
    vector <int> dp(target + 1, 0); 
    
    // Base Case
    dp[0] = 1;
    
    // Step 2 : Tabulation
    for(int i=0; i<n; i++){

        for(int j=coins[i]; j<=target; j++){

            dp[j] += dp[j-coins[i]];
        }
    }

    return dp[target];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter coins : ";

    vector <int> coins(size);

    for(int i=0; i<size; i++){

        cin >> coins[i]; 
    }

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Coin Change 2
    int ways = coinsChange(coins, target);

    cout << "Total Ways : " << ways;


    cout << endl;
    return 0;
}