#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3^n)  Space Complexity : O(n)
// int findCost(int n, vector<int> &days, vector<int> &cost, int ind){

//     if(ind >= n)  
//         return 0;


//     // 1-Day Pass
//     int oneDay = cost[0] + findCost(n, days, cost, ind+1);
    
//     // 7-Day Pass [Reach the index if we take 7 day pass]
//     int i = ind;

//     while(i < n && days[i] < days[ind] + 7){

//         i++;
//     }

//     int sevenDay = cost[1] + findCost(n, days, cost, i);

//     // 30-Day Pass [Reach the index if we take 30 day pass]
//     while(i < n && days[i] < days[ind] + 30){

//         i++;
//     }
    
//     int thirtyDay = cost[2] + findCost(n, days, cost, i);


//     return min(oneDay, min(sevenDay, thirtyDay));
// }

// int minimumCost(vector<int> &days, vector<int> &cost){

//     int n = days.size();

//     return findCost(n, days, cost, 0);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n)  Space Complexity : O(n)
// int findCost(int n, vector<int> &days, vector<int> &cost, int ind, vector<int> &dp){

//     if(ind >= n)  
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[ind] != -1)
//         return dp[ind];

//     // 1-Day Pass
//     int oneDay = cost[0] + findCost(n, days, cost, ind+1, dp);
    
//     // 7-Day Pass [Reach the index if we take 7 day pass]
//     int i = ind;

//     while(i < n && days[i] < days[ind] + 7){

//         i++;
//     }

//     int sevenDay = cost[1] + findCost(n, days, cost, i, dp);

//     // 30-Day Pass [Reach the index if we take 30 day pass]
//     while(i < n && days[i] < days[ind] + 30){

//         i++;
//     }
    
//     int thirtyDay = cost[2] + findCost(n, days, cost, i, dp);

//     // Step 2 : Store in dp array
//     dp[ind] = min(oneDay, min(sevenDay, thirtyDay));

//     return dp[ind];
// }

// int minimumCost(vector<int> &days, vector<int> &cost){

//     int n = days.size();

//     // Step 1 : Create dp array
//     vector <int> dp(n, -1);

//     return findCost(n, days, cost, 0, dp);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n)  Space Complexity : O(n)
// int minimumCost(vector<int> &days, vector<int> &cost){

//     int n = days.size();

//     // Step 1 : Create dp array
//     vector <int> dp(n+1, INT_MAX);

//     // Base Case
//     dp[n] = 0;

//     // Step 2 : Tabulation
//     for(int ind = n-1; ind >= 0; ind--){

//         // 1-Day Pass
//         int oneDay = cost[0] + dp[ind+1];
    
//         // 7-Day Pass [Reach the index if we take 7 day pass]
//         int i = ind;

//         while(i < n && days[i] < days[ind] + 7){

//             i++;
//         }

//         int sevenDay = cost[1] + dp[i];

//         // 30-Day Pass [Reach the index if we take 30 day pass]
//         while(i < n && days[i] < days[ind] + 30){

//             i++;
//         }
        
//         int thirtyDay = cost[2] + dp[i];


//         dp[ind] = min(oneDay, min(sevenDay, thirtyDay));
//     }

//     return dp[0];
// }

// Method 4 : Space Optimisation
// Time Complexity : O(n)  Space Complexity : O(1)
int minimumCost(vector<int> &days, vector<int> &cost){

    int n = days.size();

    int output = 0;

    queue< pair<int, int> > weekly;
    queue< pair<int, int> > monthly;

    for(int i=0; i<days.size(); i++){

        while(!weekly.empty() && weekly.front().first + 7 <= days[i])
            weekly.pop();

        while(!monthly.empty() && monthly.front().first + 30 <= days[i])
            monthly.pop();


        weekly.push(make_pair(days[i], output + cost[1]));
        monthly.push(make_pair(days[i], output + cost[2]));

        output = min(output + cost[0], min(weekly.front().second, monthly.front().second));
    }

    return output;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> days(size);

    for(int i=0; i<size; i++){

        cin >> days[i];
    }

    cout << "Enter costs : ";
    vector <int> cost(3);

    for(int i=0; i<3; i++){

        cin >> cost[i];
    }

    // Minimum Cost for Tickets
    int minCost = minimumCost(days, cost);

    cout << "Minimum Cost : " << minCost;

    cout << endl;
    return 0;
}