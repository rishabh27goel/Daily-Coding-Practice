#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(k^n)  Space Complexity : O(n)
// int frontJumpHelper(int n, vector<int> &energy, int k){

//     // Base Case [If we are at first step]
//     if(n < 0)  return -1;
//     if(n == 0)  return 0;

//     // Look k step back
//     int minEnergy = INT_MAX;

//     for(int i=1; i<=k; i++){

//         int e = frontJumpHelper(n-i, energy, k);
    
//         if(e != -1)
//             minEnergy = min(abs(energy[n] - energy[n-i]) + e, minEnergy);
//     }


//     return minEnergy;
// }

// int frogJumpKDistances(int n, vector<int> &energy, int k){


//     return frontJumpHelper(n-1, energy, k);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n * k)  Space Complexity : O(n)
// int frontJumpHelper(int n, vector<int> &energy, int k, vector<int> &dp){

//     // Base Case [If we are at first step]
//     if(n < 0)  return -1;
//     if(n == 0)  return 0;

//     // Step 3 : Already Exits
//     if(dp[n] != -1)
//         return dp[n];


//     // Look k step back
//     int minEnergy = INT_MAX;

//     for(int i=1; i<=k; i++){

//         int e = frontJumpHelper(n-i, energy, k, dp);
    
//         if(e != -1)
//             minEnergy = min(abs(energy[n] - energy[n-i]) + e, minEnergy);
//     }

//     // Step 2 : Store in dp array
//     dp[n] = minEnergy;

//     return dp[n];
// }

// int frogJumpKDistances(int n, vector<int> &energy, int k){

//     // Step 1 : Create dp array
//     vector<int> dp(n, -1);

//     return frontJumpHelper(n-1, energy, k, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n * k)  Space Complexity : O(n)
int frogJumpKDistances(int n, vector<int> &energy, int k){

    // Step 1 : Create dp array
    vector <int> dp(n, -1);

    // Base Case
    dp[0] = 0;

    // Step 2 : Tabulation
    for(int i=1; i<n; i++){

        int minEnergy = INT_MAX;

        for(int j=1; j<=k; j++){

            if(i - j < 0)  break;

            int e = dp[i - j];

            minEnergy = min(abs(energy[i] - energy[i-j]) + e, minEnergy);
        }

        dp[i] = minEnergy;
    }

    return dp[n-1];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> energy(size);

    for(int i=0; i<size; i++){

        cin >> energy[i]; 
    }

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Frog Jump K Distances
    int minEnergy = frogJumpKDistances(size, energy, k);

    cout << "Minimum Energy : " << minEnergy;

    cout << endl;
    return 0;
}