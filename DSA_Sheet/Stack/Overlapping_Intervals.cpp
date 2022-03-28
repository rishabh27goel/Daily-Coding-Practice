#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n^2)  Space Complexity : O(1)
static bool compare(vector<int> a, vector<int> b){

    if(a[0] < b[0]){

        return true;
    }
    else if(a[0] == b[0] && a[1] < b[1]){

        return true;
    }
    else{

        return false;
    }
}

// vector<vector<int> > overlappingIntervals(vector<vector<int> > intervals){

//     if(intervals.size() <= 1) return intervals;
//     sort(intervals.begin(), intervals.end(), compare);

//     // Iterate and Add Merged Intervals
//     vector<vector<int> > output;
//     int i = 0;

//     while(i < intervals.size()){

//         int index = i + 1;
//         int endMax = intervals[i][1];
//         vector<int> pair;

//         while(index < intervals.size()){

//             if(intervals[index][0] <= intervals[i][1]){

//                 if(endMax < intervals[index][1]){

//                     endMax = intervals[index][1];
//                 }

//                 intervals[i][1] = endMax;
//                 intervals.erase(intervals.begin() + index);
//             }
//             else{

//                 break;
//             }
//         }

//         pair.push_back(intervals[i][0]);
//         pair.push_back(intervals[i][1]);
//         output.push_back(pair);
//         i++;
//     }

//     return output;
// }

// Method 2 : Using Stack for tracking
// Time Complexity : O(n * log(n))  Space Complexity : O(n) [For Stack]
vector<vector<int> > overlappingIntervals(vector<vector<int> > intervals){

    if(intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end(), compare);

    // Adding Intervals to Stack
    vector<vector<int> > output;
    stack<int> st;

    // Add first pair to stack
    st.push(intervals[0][0]);
    st.push(intervals[0][1]);
    int i = 1;

    while(i < intervals.size()){
  
        if(intervals[i][0] <= st.top()){

            // Merge Possible
            if(intervals[i][1] > st.top()){

                st.pop();
                st.push(intervals[i][1]);
            }
        }
        else{

            // Merge Not Possible
            st.push(intervals[i][0]);
            st.push(intervals[i][1]);
        }

        i++;
    }

    // Stack Contains all the Merged Intervals
    while(!st.empty()){

        vector<int> pair;
        int endInterval = st.top();
        st.pop();

        int startInterval = st.top();
        st.pop();

        pair.push_back(startInterval);
        pair.push_back(endInterval);

        output.push_back(pair);
    }

    // Sort at the end
    sort(output.begin(), output.end(), compare);

    return output;
}

// Method 3 : Without Extra Space
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
vector<vector<int> > overlappingIntervals(vector<vector<int> > intervals){

}

int main()
{
    int n;
    cout << "Enter number of intervals : ";
    cin >> n;

    cout << "Enter intervals values : ";
    vector<vector <int> > intervals(n);
    int a, b;

    for(int i=0; i<n; i++){

        cin >> a >> b;
        intervals[i].push_back(a);
        intervals[i].push_back(b);
    }

    cout << "Merged Intervals : \n";
    vector<vector<int> > output = overlappingIntervals(intervals);

    for(int i=0; i<output.size(); i++){

        cout << output[i][0] << " " << output[i][1] << endl;
    }

    cout << endl;
    return 0;
}