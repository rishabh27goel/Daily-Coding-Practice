#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(n ^ target)  Space Complexity : O(target)
// int findWays(vector<int> &nums, int target){

//     // Base Case
//     if(target < 0)  return 0;
//     if(target == 0)  return 1;

//     int count = 0;

//     for(int i=0; i<nums.size(); i++){

//         count += findWays(nums, target-nums[i]);
//     }

//     return count;
// }

// int combinationSum(vector<int> &nums, int target){

//     return findWays(nums, target);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(target)  Space Complexity : O(target)
// int findWays(vector<int> &nums, int target, vector <int> &dp){

//     // Base Case
//     if(target < 0)  return 0;
//     if(target == 0)  return 1;

//     // Step 3 : Already Exists
//     if(dp[target] != -1)
//         return dp[target];

//     int count = 0;

//     for(int i=0; i<nums.size(); i++){

//         count += findWays(nums, target-nums[i], dp);
//     }

//     // Step 2 : Store in dp array
//     dp[target] = count;

//     return dp[target];
// }

// int combinationSum(vector<int> &nums, int target){

//     // Step 1 : Create dp array
//     vector <int> dp(target + 1, -1);

//     return findWays(nums, target, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(target)  Space Complexity : O(target)
int combinationSum(vector<int> &nums, int target){

    // Step 1 : Create dp array
    vector <int> dp(target + 1, 0);

    // Base Case
    dp[0] = 1;

    // Step 2 : Tabulation
    for(int i=1; i<=target; i++){

        for(int j=0; j<nums.size(); j++){

            if(i - nums[j] >= 0)
                dp[i] += dp[i - nums[j]];
        }
    }

    return dp[target];
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


    cout << "Enter target : ";
    int target;
    cin >> target;

    // Combination Sum 4
    int ways = combinationSum(nums, target);

    cout << "Possible Ways : " << ways;

    cout << endl;
    return 0;
}