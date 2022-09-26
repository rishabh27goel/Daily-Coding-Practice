#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ (n * n^2) or 2 ^ (n^3))  Space Complexity : O(n^2)
// int findScore(vector<int> &ver, int i, int j){

//     // Base Case
//     if(j - i == 1)
//         return 0;

//     // Check all triangle combinations
//     int minScore = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int score = findScore(ver, i, k) + (ver[i] * ver[k] * ver[j]) + findScore(ver, k, j);
    
//         minScore = min(score, minScore);
//     }

//     return minScore;
// }

// int minimumScore(vector<int> &ver){

//     int n = ver.size();

//     return findScore(ver, 0, n-1);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n^3)  Space Complexity : O(n^2)
// int findScore(vector<int> &ver, int i, int j, vector< vector<int> > &dp){

//     // Base Case
//     if(j - i == 1)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[i][j] != -1)
//         return dp[i][j];

//     // Check all triangle combinations
//     int minScore = INT_MAX;

//     for(int k=i+1; k<j; k++){

//         int score = findScore(ver, i, k, dp) + (ver[i] * ver[k] * ver[j]) + findScore(ver, k, j, dp);
    
//         minScore = min(score, minScore);
//     }

//     // Step 2 : Store in dp array
//     dp[i][j] = minScore;


//     return dp[i][j];
// }

// int minimumScore(vector<int> &ver){

//     int n = ver.size();

//     // Step 1 : Create dp array
//     vector< vector<int> > dp(n, vector<int> (n, -1));

//     return findScore(ver, 0, n-1, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n^3)  Space Complexity : O(n^2)
int minimumScore(vector<int> &ver){

    int n = ver.size();

    // Step 1 : Create dp array
    vector< vector<int> > dp(n, vector<int> (n, 0));


    // Step 2 : Tabulation
    for(int i=n-1; i>=0; i--){

        for(int j=i+2; j<n; j++){

            // Iterate in range i - j
            int minScore = INT_MAX;

            for(int k=i+1; k<j; k++){

                int score = dp[i][k] + (ver[i] * ver[k] * ver[j]) + dp[k][j];
            
                minScore = min(score, minScore);
            }

            dp[i][j] = minScore;
        }
    }

    return dp[0][n-1];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;


    cout << "Enter array : ";
    vector <int> arr(size); 

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    // Minimum Score Triangulation of Polygon
    int score = minimumScore(arr);

    cout << "Minimum Score : " << score;


    cout << endl;
    return 0;
}