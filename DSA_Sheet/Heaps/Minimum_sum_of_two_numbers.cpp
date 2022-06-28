#include <iostream>
#include <queue>
#include <queue>
using namespace std;

// Method 1 : Using Sort Function
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// string minimumSum(vector<int> &arr){

//     if(arr.size() == 0) return "";

//     // Sort the array 
//     sort(arr.begin(), arr.end());

//     int index = 0;

//     while(index < arr.size() && arr[index] == 0){

//         index++;
//     }

//     // Create number strings
//     string n1 = "";
//     string n2 = "";

//     while(index < arr.size()){

//         n1 += ('0' + arr[index]);
//         index++;

//         if(index == arr.size()) break;

//         n2 += ('0' + arr[index]);
//         index++;
//     }

//     string output;
//     int carry = 0;
//     int i = n1.size()-1;
//     int j = n2.size()-1;

//     while(i >= 0 || j >= 0){

//         int a = 0;
//         int b = 0;

//         if(i >= 0){

//             a = (n1[i]-'0');
//             i--;
//         }

//         if(j >= 0){

//             b = (n2[j]-'0');
//             j--;
//         }

//         char ch = (((a + b + carry) % 10) + '0');

//         output = ch + output;
//         carry = (a + b + carry) / 10;
//     }

//     if(carry != 0){

//         char ch = (carry + '0');
//         output = ch + output; 
//     }

//     return output;
// }

// Method 2 : Using Heap
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
string minimumSum(vector<int> &arr){

    if(arr.size() == 0) return "";

    // Push all element in priority queue
    priority_queue<int> pq;

    for(int i=0; i<arr.size(); i++){

        if(arr[i] != 0)
            pq.push(arr[i]);
    }

    string output;
    int carry = 0;

    while(!pq.empty()){

        int a = 0;
        int b = 0;

        if(!pq.empty()){

            a = pq.top();
            pq.pop();
        }

        if(!pq.empty()){

            b = pq.top();
            pq.pop();
        }

        char ch = (((a + b + carry) % 10) + '0');

        output = ch + output;
        carry = (a + b + carry) / 10;
    }

    if(carry != 0){

        char ch = (carry + '0');
        output = ch + output; 
    }

    return output;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter data : ";
    int data;
    vector <int> arr;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Minimum Sum of Two Numbers
    minimumSum(arr);

    cout << endl;
    return 0;
}