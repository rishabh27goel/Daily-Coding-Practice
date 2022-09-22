#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Using Recursion
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int jumpSolve(int n, vector<int> &energy){

//     // Base Case
//     if(n == 0)  return 0;
//     if(n == 1)  return abs(energy[1] - energy[0]);

//     // Find the energy for 1 step and 2 step back
//     int oneBack = abs(energy[n] - energy[n-1]) + jumpSolve(n-1, energy);
//     int twoBack = abs(energy[n] - energy[n-2]) + jumpSolve(n-2, energy);

//     return min(oneBack, twoBack);
// }

// int frogJump(vector<int> &energy){

//     int n = energy.size();

//     return jumpSolve(n-1, energy);
// }

// Method 2 : Using Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int jumpSolve(int n, vector<int> &energy, vector<int> &dp){

//     // Base Case
//     if(n == 0)  return 0;
//     if(n == 1)  return abs(energy[1] - energy[0]);

//     // Step 3 : Already Exits
//     if(dp[n] != -1)
//         return dp[n];

//     // Find the energy for 1 step and 2 step back
//     int oneBack = abs(energy[n] - energy[n-1]) + jumpSolve(n-1, energy, dp);
//     int twoBack = abs(energy[n] - energy[n-2]) + jumpSolve(n-2, energy, dp);

//     // Step 2 : Store in dp
//     dp[n] = min(oneBack, twoBack);

//     return dp[n];
// }

// int frogJump(vector<int> &energy){

//     int n = energy.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     return jumpSolve(n-1, energy, dp);
// }

// Method 3 : Using Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int frogJump(vector<int> &energy){

//     int n = energy.size();

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     // Base Case
//     dp[0] = 0;
//     dp[1] = abs(energy[1] - energy[0]);

//     // Step 2 : Tabulation
//     for(int i=2; i<n; i++){

//         int oneBack = abs(energy[i] - energy[i-1]) + dp[i-1]; 
//         int twoBack = abs(energy[i] - energy[i-2]) + dp[i-2];

//         dp[i] = min(oneBack, twoBack);
//     }

//     return dp[n-1];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int frogJump(vector<int> &energy){

    int n = energy.size();

    // Base Case
    int x = 0;
    int y = abs(energy[1] - energy[0]);

    for(int i=2; i<n; i++){

        int store = y;

        int oneBack = abs(energy[i] - energy[i-1]) + y; 
        int twoBack = abs(energy[i] - energy[i-2]) + x;

        x = store;
        y = min(oneBack, twoBack);
    }

    return y;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> energy(size);

    for(int i=0; i<size; i++){

        cin >> energy[i];
    }

    // Frog Jump
    int minEnergy = frogJump(energy);

    cout << "Minimum Energy : " << minEnergy;

    cout << endl;
    return 0;
}