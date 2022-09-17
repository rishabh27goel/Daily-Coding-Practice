#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3^n)  Space Complexity : O(n)
// int maximumCuts(int n, int x, int y, int z){

//     // Base Case
//     if(n < 0)  return INT_MIN;
//     if(n == 0)  return 0;

//     int maxCuts = INT_MIN;

//     int seg1 = maximumCuts(n-x, x, y, z);
//     int seg2 = maximumCuts(n-y, x, y, z);
//     int seg3 = maximumCuts(n-z, x, y, z);

//     if(seg1 != INT_MIN)
//         maxCuts = max(maxCuts, seg1+1);

//     if(seg2 != INT_MIN)
//         maxCuts = max(maxCuts, seg2+1);

//     if(seg3 != INT_MIN)
//         maxCuts = max(maxCuts, seg3+1);


//     return maxCuts;
// }

// int maximizeCutSegments(int n, int x, int y, int z){

//     int output = maximumCuts(n, x, y, z);

//     if(output < 0)
//         return 0;


//     return output;
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int maximumCuts(int n, int x, int y, int z, vector<int> &dp){

//     // Base Case
//     if(n < 0)  return INT_MIN;
//     if(n == 0)  return 0;

//     // Step 3 : Already Exists
//     if(dp[n] != -1)
//         return dp[n];

//     int maxCuts = INT_MIN;

//     int seg1 = maximumCuts(n-x, x, y, z, dp);
//     int seg2 = maximumCuts(n-y, x, y, z, dp);
//     int seg3 = maximumCuts(n-z, x, y, z, dp);

//     if(seg1 != INT_MIN)
//         maxCuts = max(maxCuts, seg1+1);

//     if(seg2 != INT_MIN)
//         maxCuts = max(maxCuts, seg2+1);

//     if(seg3 != INT_MIN)
//         maxCuts = max(maxCuts, seg3+1);

//     // Step 2 : Store in dp array
//     dp[n] = maxCuts;

//     return maxCuts;
// }

// int maximizeCutSegments(int n, int x, int y, int z){

//     // Step 1 : Create dp array
//     vector<int> dp(n+1, -1);

//     int output = maximumCuts(n, x, y, z, dp);

//     if(output < 0)
//         return 0;


//     return output;
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
int maximizeCutSegments(int n, int x, int y, int z){

    // Step 1 : Create dp array
    vector<int> dp(n+1, INT_MIN);

    // Base Case
    dp[0] = 0;

    // Step 2 : Tabulation
    for(int i=1; i<=n; i++){

        if(i >= x){

            dp[i] = max(dp[i-x] + 1, dp[i]);
        }

        if(i >= y){

            dp[i] = max(dp[i-y] + 1, dp[i]);
        }

        if(i >= z){

            dp[i] = max(dp[i-z] + 1, dp[i]);
        }
    }

    if(dp[n] < 0)
        return 0;

    return dp[n];
}

int main()
{
    cout << "Enter length : ";
    int len;
    cin >> len;

    cout << "Enter segments : ";
    int x, y, z;
    cin >> x >> y >> z;


    // Maximize Cut Segments
    int maxSeg = maximizeCutSegments(len, x, y, z);

    cout << "Maximum Segments : " << maxSeg;

    cout << endl;
    return 0;
}