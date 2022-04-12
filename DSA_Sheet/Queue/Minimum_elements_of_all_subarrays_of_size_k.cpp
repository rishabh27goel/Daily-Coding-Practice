#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * k)    Space Complexity : O(1) 
// vector<int> minimumElementInSubArray(vector<int> input, int k){

//     if(k <= 1) return input;

//     vector<int> output;

//     for(int i=0; i<input.size()-k+1; i++){

//         int min = input[i];

//         for(int j=i+1; j<i+k; j++){

//             if(input[j] < min){

//                 min = input[j];
//             }
//         }

//         output.push_back(min);
//     }

//     return output;
// }

// Method 2 : Using Deque
// Time Complexity : O(n)    Space Complexity : O(k)  
vector<int> minimumElementInSubArray(vector<int> input, int k){

    if(k <= 1) return input;

    vector<int> output;
    deque<int> dq;

    // Check for first k
    for(int i=0; i<k; i++){

        // Remove all larger elements present than input[i]
        while(!dq.empty() && input[i] <= input[dq.back()]){

            dq.pop_back();
        }

        // Add new indexes
        dq.push_back(i);
    }

    output.push_back(input[dq.front()]);

    // Check windows after k 
    for(int i=k; i<input.size(); i++){

        // Remove indexes than does not lie in the window
        while(!dq.empty() && dq.front() <= i - k){

            dq.pop_front();
        }

        // Remove all larger elements present than input[i]
        while(!dq.empty() && input[i] <= input[dq.back()]){

            dq.pop_back();
        }

        dq.push_back(i);
        output.push_back(input[dq.front()]);
    }

    return output;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    cout << "Enter array values : ";
    vector<int> input(n);

    for(int i=0; i<n; i++){

        cin >> input[i];
    }

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    vector<int> output = minimumElementInSubArray(input, k);

    cout << "Minimum Array is : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}