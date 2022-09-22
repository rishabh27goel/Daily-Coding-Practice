#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursive Method
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int amountHelper(int n, vector<int> &nums, int start, int end){

//     if(start >= end)  return 0;

//     // Include or Exclude House
//     int include = nums[start] + amountHelper(n, nums, start+2, end);
//     int exclude = amountHelper(n, nums, start+1, end);


//     return max(include, exclude);
// }

// int houseRobber(int n, vector<int> &nums){

//     // If we include first house
//     int include = nums[0] + amountHelper(n, nums, 2, n-1);

//     // If we exclude second house 
//     int exclude = amountHelper(n, nums, 1, n);

//     return max(include, exclude);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int amountHelper(int n, vector<int> &nums, int start, int end, vector<int> &dp){

//     if(start >= end)  return 0;

//     // Step 3 : Already Exists
//     if(dp[start] != -1)
//         return dp[start];


//     // Include or Exclude House
//     int include = nums[start] + amountHelper(n, nums, start+2, end, dp);
//     int exclude = amountHelper(n, nums, start+1, end, dp);

//     // Step 2 : Store in dp arrays
//     dp[start] = max(include, exclude);

//     return dp[start];
// }

// int houseRobber(int n, vector<int> &nums){

//     // Step 1 : Create dp arrays
//     vector<int> first(n, -1);
//     vector<int> second(n, -1);

//     // If we include first house
//     int include = nums[0] + amountHelper(n, nums, 2, n-1, first);

//     // If we exclude second house 
//     int exclude = amountHelper(n, nums, 1, n, second);


//     return max(include, exclude);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int houseRobber(int n, vector<int> &nums){

//     // Step 1 : Create dp arrays
//     vector<int> firstDp(n, -1);
//     vector<int> secondDp(n, -1);

//     // Base Case
//     // First Included
//     firstDp[0] = max(nums[0], 0);
//     firstDp[1] = max(0, firstDp[0]);

//     // First Excluded
//     secondDp[0] = 0;
//     secondDp[1] = max(nums[1], 0);

//     // Step 2 : Tabulation
//     // Include Case
//     for(int i=2; i<n-1; i++){

//         int include = nums[i] + firstDp[i-2];
//         int exclude = firstDp[i-1];

//         firstDp[i] = max(include, exclude);
//     }

//     // Exclude Case
//     for(int i=2; i<n; i++){

//         int include = nums[i] + secondDp[i-2];
//         int exclude = secondDp[i-1];

//         secondDp[i] = max(include, exclude);
//     }

//     return max(firstDp[n-2], secondDp[n-1]);
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int houseRobber(int n, vector<int> &nums){

    // Base Case
    // First Included
    int twoBack = max(nums[0], 0);
    int oneBack = max(0, twoBack);


    for(int i=2; i<n-1; i++){

        int store = oneBack;

        int include = nums[i] + twoBack;
        int exclude = oneBack;

        oneBack = max(include, exclude);
        twoBack = store;
    }

    int maxInclude = oneBack;

    // Exclude Case
    twoBack = 0;
    oneBack = max(nums[1], 0);


    for(int i=2; i<n; i++){

        int store = oneBack;

        int include = nums[i] + twoBack;
        int exclude = oneBack;

        oneBack = max(include, exclude);
        twoBack = store;
    }

    return max(maxInclude, oneBack);
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> nums(size); 

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // House Robber [Circular Robbery]
    int money = houseRobber(size, nums);

    cout << "Maximum Money : " << money;

    cout << endl;
    return 0;
}