#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * n * log(n))  Space Complexity : O(n) [Extra Elements]
// int minimumCostOfRopes(vector<int> &arr){

//     if(arr.size() == 1) return 0;

//     // Sort the vector
//     sort(arr.begin(), arr.end());

//     int sum = 0;
//     int index = 0;

//     while(arr.size() - index != 1){

//         int a = arr[index];
//         index++;

//         int b = arr[index];
//         index++;

//         sum += (a + b);

//         arr.push_back(a + b);
//         sort(arr.begin(), arr.end());
//     }

//     return sum;
// }

// Method 2 : Using Max Heaps
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
int minimumCostOfRopes(vector<int> &arr){

    if(arr.size() == 1) return 0;

    // Push all data into Priority Queue
    priority_queue <int, vector<int>, greater<int> > pq;

    for(int i=0; i<arr.size(); i++){

        pq.push(arr[i]);
    }

    int sum = 0;

    while(pq.size() != 1){

        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        sum += (a + b);
        pq.push(a + b);
    }

    return sum;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter data : ";
    vector <int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Minimum Cost Of Ropes
    int cost = minimumCostOfRopes(arr);

    cout << "Minimum Cost : " << cost;

    cout << endl;
    return 0;
}