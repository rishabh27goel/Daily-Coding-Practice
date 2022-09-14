#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursive Method 
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int sumHelper(int n, vector <int> &arr, int ind){

//     // Base Case
//     if(ind >= n)  return 0;

//     // We will take two path 
//     // 1. Where we include the element
//     // 2. Where we exclude the element

//     int include = arr[ind] + sumHelper(n, arr, ind + 2);
//     int exclude = sumHelper(n, arr, ind + 1);


//     return max(include, exclude);
// }

// int maximumSum(int n, vector<int> &arr){

//     return sumHelper(n, arr, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int sumHelper(int n, vector <int> &arr, int ind, vector<int> &dp){

//     // Base Case
//     if(ind >= n)  return 0;

//     // Step 3 : Already Exists
//     if(dp[ind] != -1)
//         return dp[ind];

//     // We will take two path 
//     // 1. Where we include the element
//     // 2. Where we exclude the element

//     int include = arr[ind] + sumHelper(n, arr, ind + 2, dp);
//     int exclude = sumHelper(n, arr, ind + 1, dp);

//     // Step 2 : Store in dp array
//     dp[ind] = max(include, exclude);

//     return dp[ind];
// }

// int maximumSum(int n, vector<int> &arr){

//     // Step 1 : Create dp array
//     vector <int> dp(n, -1);

//     return sumHelper(n, arr, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int maximumSum(int n, vector<int> &arr){

//     // Step 1 : Create dp array
//     vector <int> dp(n, -1);

//     // Base Case
//     dp[0] = max(arr[0], 0);
//     dp[1] = max(arr[1], dp[0]);

//     // Step 2 : Tabulation
//     for(int i=2; i<n; i++){

//         int include = arr[i] + dp[i-2];
//         int exclude = dp[i-1];

//         dp[i] = max(include, exclude);
//     }

//     return dp[n-1];
// }

// Method 4 : Space Optimisation 
// Time Complexity : O(n)  Space Complexity : O(1)
int maximumSum(int n, vector<int> &arr){

    // Base Case
    int twoBack = max(arr[0], 0);
    int oneBack = max(arr[1], twoBack);


    for(int i=2; i<n; i++){

        int store = oneBack;

        int include = arr[i] + twoBack;
        int exclude = oneBack;

        oneBack = max(include, exclude);
        twoBack = store;
    }

    return oneBack;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    // Maximum sum of non adjacent elements
    int sum = maximumSum(size, arr);

    cout << "Maximum Sum : " << sum;

    cout << endl;
    return 0;
}