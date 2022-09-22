#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2^n)  Space Complexity : O(n)
// Approach 1 : 
// int findCost(vector<int> &cost, int n){

//     if(n == 0)  return cost[0];
//     if(n == 1)  return cost[1];
 
//     int currCost = cost[n] + min(findCost(cost, n-1), findCost(cost, n-2));

//     return currCost;
// }

// int minimumCost(vector<int> &cost){

//     int n = cost.size();

//     return min(findCost(cost, n-1), findCost(cost, n-2));    
// }

// Approach 2 : 
// int findCost(vector<int> &cost, int n, int s){

//     if(s >= n)  
//         return 0;
 
//     int currCost = cost[s] + min(findCost(cost, n, s+1), findCost(cost, n, s+2));

//     return currCost;
// }

// int minimumCost(vector<int> &cost){

//     int n = cost.size();

//     return min(findCost(cost, n, 0), findCost(cost, n, 1));    
// }

// Method 2 : Dynamic Programming & Memoization
// Time Complexity : O(n)  Space Complexity : O(n)
// Approach 1 : 
// int findCost(vector<int> &cost, int n, vector<int> &dp){

//     if(n == 0)  return cost[0];
//     if(n == 1)  return cost[1];
 
//     // Step 3 : Already Exits
//     if(dp[n] != -1)
//         return dp[n];

//     // Step 2 : Store in dp array
//     dp[n] = cost[n] + min(findCost(cost, n-1, dp), findCost(cost, n-2, dp));

//     return dp[n];
// }

// int minimumCost(vector<int> &cost){

//     int n = cost.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     return min(findCost(cost, n-1, dp), findCost(cost, n-2, dp));    
// }

// Approach 2 : 
// int findCost(vector<int> &cost, int n, int s, vector<int> &dp){

//     if(s >= n)  
//         return 0;
 
//     // Step 3 : Already Exits
//     if(dp[s] != -1)
//         return dp[s];

//     // Step 2 : Store in dp array
//     dp[s] = cost[s] + min(findCost(cost, n, s+1, dp), findCost(cost, n, s+2, dp));

//     return dp[s];
// }

// int minimumCost(vector<int> &cost){

//     int n = cost.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     return min(findCost(cost, n, 0, dp), findCost(cost, n, 1, dp));    
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int minimumCost(vector<int> &cost){

//     int n = cost.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     // Base Case
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     // Step 2 : Tabulation
//     for(int i=2; i<n; i++){

//         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//     }

//     return min(dp[n-1], dp[n-2]);    
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int minimumCost(vector<int> &cost){

    int n = cost.size();

    for(int i=2; i<n; i++){

        cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
    }

    return min(cost[n-1], cost[n-2]);    
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> cost(size);

    // Input : 1 100 1 1 1 100 1 1 100 1
    for(int i=0; i<size; i++){

        cin >> cost[i];
    }

    // Minimum Cost Climbing Stairs
    int minCost = minimumCost(cost);

    cout << "Minimum Cost : " << minCost;


    cout << endl;
    return 0;
}