#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2^n)  Space Complexity : O(n)
// int findMaxValue(int n, vector<int> &weights, vector<int> &values, int ind, int maxWeight){

//     // Base Case
//     if(ind == n-1){

//         // If we can include last element
//         if(weights[n-1] <= maxWeight)
//             return values[n-1];

//         // On excluding
//         return 0;
//     }


//     int include = 0;

//     // If we can include weight in left over maxWeight
//     if(weights[ind] <= maxWeight){

//         include = values[ind] + findMaxValue(n, weights, values, ind+1, maxWeight-weights[ind]);
//     }

//     // Exclude the current element
//     int exclude = findMaxValue(n, weights, values, ind+1, maxWeight);


//     return max(include, exclude);
// }

// int knapsackProblem(vector<int> &weights, vector<int> &values, int maxWeight){

//     int n = weights.size();

//     return findMaxValue(n, weights, values, 0, maxWeight);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
int findMaxValue(int n, vector<int> &weights, vector<int> &values, int ind, int maxWeight, vector< vector<int> > &dp){

    // Base Case
    if(ind == n-1){

        // If we can include last element
        if(weights[n-1] <= maxWeight)
            return values[n-1];

        // On excluding
        return 0;
    }

    // Step 3 : Already Exists
    if(dp[ind][maxWeight] != -1)
        return dp[ind][maxWeight];

    int include = 0;

    // If we can include weight in left over maxWeight
    if(weights[ind] <= maxWeight){

        include = values[ind] + findMaxValue(n, weights, values, ind+1, maxWeight-weights[ind], dp);
    }

    // Exclude the current element
    int exclude = findMaxValue(n, weights, values, ind+1, maxWeight, dp);


    // Step 2 : Store in dp array
    dp[ind][maxWeight] = max(include, exclude);


    return dp[ind][maxWeight];
}

int knapsackProblem(vector<int> &weights, vector<int> &values, int maxWeight){

    int n = weights.size();

    // Step 1 : Create dp array
    vector< vector<int> > dp(n, vector<int> (maxWeight + 1, -1));

    return findMaxValue(n, weights, values, 0, maxWeight, dp);
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> weights(size);
    vector<int> values(size);

    cout << "Enter weights : ";

    for(int i=0; i<size; i++){

        cin >> weights[i];
    }

    cout << "Enter values : ";

    for(int i=0; i<size; i++){

        cin >> values[i];
    }    

    cout << "Enter total weight : ";
    int maxWeight;
    cin >> maxWeight;

    // O-1 Knapsack Problem
    int maxValue = knapsackProblem(weights, values, maxWeight); 

    cout << "Maximum Value : " << maxValue;

    cout << endl;
    return 0;
}