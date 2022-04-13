#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * k)    Space Complexity : O(1)  
// vector<int> sumOfMaxAndMin(vector<int> input, int k){

//     if(k <= 1) return input;

//     vector<int> output;

//     for(int i=0; i<input.size()-k+1; i++){

//         int min = input[i];
//         int max = input[i];

//         for(int j=i+1; j<i+k; j++){

//             // Update Max
//             if(max < input[j]){

//                 max = input[j];
//             }

//             // Update Min 
//             if(min > input[j]){

//                 min = input[j];
//             }
//         }

//         output.push_back(min + max);
//     }

//     return output;
// }

// Method 2 : Using Deque
// Time Complexity : O(n)    Space Complexity : O(k)  
vector<int> sumOfMaxAndMin(vector<int> input, int k){

    if(k <= 1) return input;

    vector<int> output;

    // Deque for Maximum & Minimum track
    deque<int> max;
    deque<int> min;

    // Iterate first window of k
    for(int i=0; i<k; i++){

        // Max track & remove smaller element present
        while(!max.empty() && input[i] >= input[max.back()]){

            max.pop_back();
        }

        // Min track & remove larger element present
        while(!min.empty() && input[i] <= input[min.back()]){

            min.pop_back();
        }

        max.push_back(i);
        min.push_back(i);
    }

    output.push_back(input[max.front()] + input[min.front()]);

    for(int i=k; i<input.size(); i++){

        // Removal of indexes
        while(!max.empty() && max.front() <= i - k){

            max.pop_front();
        }

        while(!min.empty() && min.front() <= i - k){

            min.pop_front();
        }

        // Add new indexes
        while(!max.empty() && input[i] >= input[max.back()]){

            max.pop_back();
        }

        while(!min.empty() && input[i] <= input[min.back()]){

            min.pop_back();
        }

        max.push_back(i);
        min.push_back(i);

        output.push_back(input[max.front()] + input[min.front()]);
    }

    return output;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    vector<int> arr;
    int data;
    cout<< "Enter elements of array : ";
    
    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    vector<int> sum = sumOfMaxAndMin(arr, k);

    cout << "Sum Array is : ";
    int totalSum = 0;
    for(int i=0; i<sum.size(); i++){

        totalSum += sum[i];
        cout << sum[i] << " ";
    }

    cout << "\nTotal Sum is : " << totalSum;

    cout << endl;
    return 0;
}