#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// Method 1 : Using Extra String Space
// Time Complexity : O(n)  Space Complexity : O(n)
// string reverseString(string input){

//     if(input.size() <= 1) return input;

//     string output = "";

//     for(int i=input.size()-1; i>=0; i--){

//         output += input[i];
//     }

//     return output;
// }

// Method 2 : Using Stack
// Time Complexity : O(n)  Space Complexity : O(n)
// string reverseString(string input){

//     if(input.size() <= 1) return input;

//     stack<char> store;

//     for(int i=0; i<input.size(); i++){

//         // Store in stack
//         store.push(input[i]);
//     }

//     int j = 0;
//     while(j < input.size() && !store.empty()){

//         input[j] = store.top();
//         store.pop(); 
//         j++;
//     }

//     return input;
// }

// Method 3 : Simple Two Pointer
// Time Complexity : O(n)  Space Complexity : O(1)
string reverseString(string input){

    if(input.size() <= 1) return input;

    int start = 0;
    int end = input.size()-1;

    while(start < end){

        swap(input[start], input[end]);
        start++;
        end--;
    }

    return input;
}

int main()
{
    string input;
    cout << "Enter Input String : ";
    cin >> input;

    // Reverse a string 
    string output = reverseString(input);

    cout << "Reversed String is : " << output << endl;

    cout << endl;
    return 0;
}