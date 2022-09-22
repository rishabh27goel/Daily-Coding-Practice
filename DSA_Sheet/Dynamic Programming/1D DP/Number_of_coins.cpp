#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method 
// Time Complexity : O(n^sum)  Space Complexity : O(sum)
// int countCoins(int n, vector<int> &coins, int sum){

//     // Base Case
//     if(sum < 0)  return -1;
//     if(sum == 0)  return 0;

//     // Try all coins
//     int minCoins = INT_MAX;

//     for(int i=0; i<n; i++){

//         int c = countCoins(n, coins, sum-coins[i]);

//         if(c != -1){

//             minCoins = min(minCoins, c+1);
//         }
//     }

//     if(minCoins == INT_MAX)
//         return -1;

//     return minCoins;
// }

// int numberOfCoins(int n, vector<int> &coins, int sum){

//     return countCoins(n, coins, sum);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * sum)  Space Complexity : O(sum)
// int countCoins(int n, vector<int> &coins, int sum, vector<int> &dp){

//     // Base Case
//     if(sum < 0)  return -1;
//     if(sum == 0)  return 0;

//     // Step 3 : If already exists
//     if(dp[sum] != -1)
//         return dp[sum];

//     // Try all coins
//     int minCoins = INT_MAX;

//     for(int i=0; i<n; i++){

//         int c = countCoins(n, coins, sum-coins[i], dp);

//         if(c != -1){

//             minCoins = min(minCoins, c+1);
//         }
//     }

//     if(minCoins == INT_MAX)
//         return -1;

//     // Step 2 : Store dp array
//     dp[sum] = minCoins;

//     return dp[sum];
// }

// int numberOfCoins(int n, vector<int> &coins, int sum){

//     // Step 1 : Create dp array
//     vector<int> dp(sum + 1, -1);

//     return countCoins(n, coins, sum, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * sum)  Space Complexity : O(sum)
int numberOfCoins(int n, vector<int> &coins, int sum){

    // Step 1 : Create dp array
    vector<int> dp(sum + 1, INT_MAX);

    // Base Case
    dp[0] = 0;

    // Step 2 : Tabulation
    for(int i=0; i<=sum; i++){

        for(int j=0; j<n; j++){

            if(i >= coins[j]){

                int c = dp[i-coins[j]];
            
                if(c != INT_MAX){

                    dp[i] = min(dp[i], c + 1);
                }
            }
        }
    }

    if(dp[sum] == INT_MAX)
        return -1;

    return dp[sum];
}

int main()
{
    cout << "Enter number of coins : ";
    int n;
    cin >> n;
    
    vector<int> coins(n);

    for(int i=0; i<n; i++){

        cin >> coins[i];
    }

    cout << "Enter Sum : ";
    int sum;
    cin >> sum;

    // Number of coins
    int number = numberOfCoins(n, coins, sum);

    cout << "Number of coins : " << number;


    cout << endl;
    return 0;
}