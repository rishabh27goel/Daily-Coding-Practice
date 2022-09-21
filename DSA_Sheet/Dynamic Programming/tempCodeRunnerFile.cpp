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