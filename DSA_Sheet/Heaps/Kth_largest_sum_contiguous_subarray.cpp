#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Storing the sum & sorting it
// Time Complexity : O((n * n) * log(n * n))  Space Complexity : O(n^2)
// int kthLargestSum(vector<int> &arr, int k){

//     if(arr.size() == 0 || k == 0) return -1;

//     // Store sum array
//     vector <int> storeSum;
//     int i = 0;

//     while(i < arr.size()){

//         int j = i;
//         int sum = 0;

//         while(j < arr.size()){

//             sum += arr[j];
//             storeSum.push_back(sum);

//             j++;
//         }

//         i++;
//     }

//     // Sort the sum array
//     sort(storeSum.begin(), storeSum.end(), greater<int>());

//     return storeSum[k-1];
// }

// Method 2 : Using Min Heap
// Time Complexity : O(n * n * log(k))  Space Complexity : O(k)
int kthLargestSum(vector<int> &arr, int k){

    if(arr.size() == 0 || k == 0) return -1;

    // Using Priority Queue
    priority_queue <int, vector<int>, greater<int> > pq;

    int i = 0;

    while(i < arr.size()){

        int j = i;
        int sum = 0;

        while(j < arr.size()){

            sum += arr[j];

            if(pq.size() < k){

                pq.push(sum);
            }
            else{

                if(pq.top() < sum){

                    pq.pop();
                    pq.push(sum);
                }
            }

            j++;
        }

        i++;
    }   

    return pq.top();
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> arr;
    int data;

    // Input { 10 -10 20 -40 }   k = 6
    cout << "Enter array : ";
    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Kth Largest Sum Contiguous Subarray
    int largest = kthLargestSum(arr, k);

    cout << "Kth Largest : " << largest;

    cout << endl;
    return 0;
}