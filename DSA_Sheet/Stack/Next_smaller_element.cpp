#include <iostream>
#include <stack>
using namespace std;

// Method 1 : Checking rest window
// Time Complexity : O(n^2)  Space Complexity : O(1)
// void nextSmallerElement(int* input, int n){

//     if(n == 0) return;

//     for(int i=0; i<n; i++){

//         int val = -1;

//         for(int j=i+1; j<n; j++){

//             if(input[i] > input[j]){

//                 val = input[j];
//                 break;
//             }
//         }

//         cout << val << " ";
//     }
// }

// Method 2 : Using Stack and Iterating from right
// Time Complexity : O(n)  Space Complexity : O(n)
void nextSmallerElement(int* input, int n){

    if(n == 0) return;

    int output[n];
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){

        while(st.top() >= input[i]){

            st.pop();
        }

        output[i] = st.top();  
        st.push(input[i]);
    }

    for(int i=0; i<n; i++){

        cout << output[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter size of the array : "; 
    cin >> n;

    int arr[n];

    cout << "Enter elements of the array : ";
    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    cout << "Next Smaller Elements : ";
    nextSmallerElement(arr, n);

    cout << endl;
    return 0;
}