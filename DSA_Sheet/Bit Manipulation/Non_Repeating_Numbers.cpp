#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Method 1 : Using Map
// Time Complexity : O(n)  Space Complexity : O(n)
// vector<int> getNonRepeatingNumber(int *arr, int n){

//     vector<int> pair;
//     if(n < 4) return pair;
//     map <int, int> store;
   
//     for(int i=0; i<n; i++){

//         if(store.find(arr[i]) != store.end()){

//             store[arr[i]] = -1;
//         }
//         else{

//             store[arr[i]] = 1;
//         }
//     }

//     map<int, int>::iterator itr;
//     // Iterate Map and get the pair
//     for(itr = store.begin(); itr != store.end(); itr++){

//         if(itr->second == 1){

//             pair.push_back(itr->first);
//         }
//     }

//     sort(pair.begin(), pair.end());

//     return pair;
// }

// Method 2 : Sorting Of Array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// vector<int> getNonRepeatingNumber(int *arr, int n){

//     vector<int> pair;
//     if(n < 4) return pair;

//     sort(arr, arr+n);
    
//     for(int i=0; i<n-1; i++){

//         if(arr[i] == arr[i+1]){

//             i++;
//         }
//         else{

//             pair.push_back(arr[i]);
//         }
//     }

//     if(pair.size() == 1){

//         pair.push_back(arr[n-1]);
//     }

//     sort(pair.begin(), pair.end());

//     return pair;
// }

// Method 3 : Using Xor
// Time Complexity : O(n)  Space Complexity : O(1)
vector<int> getNonRepeatingNumber(int *arr, int n){

    vector<int> pair;
    if(n < 4) return pair;

    int a = 0;
    int b = 0;
    long all_xor = 0;

    // Find the xor of all elements
    // This will give XOR -> A ^ B, rest all zero
    for(int i=0; i<n; i++){

        all_xor ^= arr[i];
    }

    // Get the rightmost set bit
    all_xor = all_xor & ~(all_xor - 1);

    for(int i=0; i<n; i++){

        if(all_xor & arr[i]){

            a ^= arr[i];
        }
        else{

            b ^= arr[i];
        }
    }

    pair.push_back(a);
    pair.push_back(b);

    sort(pair.begin(), pair.end());

    return pair;
}

int main()
{
    int n;
    cout <<"Enter size of the array : ";
    cin >> n;

    int arr[n];
    cout<<"Enter elements of the array : ";
    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Non Repeating Numbers
    vector<int> pair = getNonRepeatingNumber(arr, n);

    if(pair.size() != 0){

        cout <<"Non-Repeating Numbers : " <<pair[0]<<" "<<pair[1];  
    }

    cout <<endl;
    return 0;
}
