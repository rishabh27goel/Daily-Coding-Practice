#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2^n)  Space Complexity : O(n)  
// int maximumMoney(int n, vector<int> &nums, int ind){

//     // Base Case
//     if(ind >= n)  return 0;

//     // Include house or exclude it
//     int include = nums[ind] + maximumMoney(n, nums, ind+2);
//     int exclude = maximumMoney(n, nums, ind+1);


//     return max(include, exclude);
// }

// int houseRobber(int n, vector<int> &nums){

//     return maximumMoney(n, nums, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)  
// int maximumMoney(int n, vector<int> &nums, int ind, vector<int> &dp){

//     // Base Case
//     if(ind >= n)  return 0;

//     // Step 3 : Already Exists
//     if(dp[ind] != -1)
//         return dp[ind];

//     // Include house or exclude it
//     int include = nums[ind] + maximumMoney(n, nums, ind+2, dp);
//     int exclude = maximumMoney(n, nums, ind+1, dp);

//     // Step 2 : Store in dp array
//     dp[ind] = max(include, exclude);


//     return dp[ind];
// }

// int houseRobber(int n, vector<int> &nums){

//     // Step 1 : Creating dp array
//     vector<int> dp(n, -1);

//     return maximumMoney(n, nums, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)  
// int houseRobber(int n, vector<int> &nums){

//     if(n == 1)  return nums[0];
//     if(n == 2)  return max(nums[0], nums[1]);

//     // Step 1 : Creating dp array
//     vector<int> dp(n, -1);

//     // Base Case
//     dp[0] = max(nums[0], 0);
//     dp[1] = max(nums[1], dp[0]);

//     // Step 2 : Tabulation
//     for(int i=2; i<n; i++){

//         int include = nums[i] + dp[i-2];
//         int exclude = dp[i-1];

//         dp[i] = max(include, exclude);
//     }

//     return dp[n-1];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)  
int houseRobber(int n, vector<int> &nums){

    if(n == 1)  return nums[0];
    if(n == 2)  return max(nums[0], nums[1]);

    // Base Case
    int twoBack = max(nums[0], 0);
    int oneBack = max(nums[1], twoBack);


    for(int i=2; i<n; i++){

        int store = oneBack;

        int include = nums[i] + twoBack;
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

    vector <int> nums(size);

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }   

    // House Robber
    int money = houseRobber(size, nums);

    cout << "Maximum Money : " << money;


    cout << endl;
    return 0;
}