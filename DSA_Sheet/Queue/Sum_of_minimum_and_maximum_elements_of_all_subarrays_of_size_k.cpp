#include <iostream>
#include <vector>
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