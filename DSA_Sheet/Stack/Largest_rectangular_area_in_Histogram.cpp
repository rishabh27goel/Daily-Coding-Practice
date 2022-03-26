#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method 1 : Simple Iteration to left and right (Brute Force)
// Time Complexity : O(n^2)  Space Complexity : O(1)
// int largestRectangularArea(int *arr, int n){

//     if(n == 1) return arr[0];

//     int maxArea = INT_MIN;
//     int area;

//     // Iterate Histogram
//     for(int i=0; i<n; i++){

//         int count = 1;

//         // Left Check
//         for(int j=i-1; j>=0; j--){

//             if(arr[j] < arr[i]){

//                 break;
//             }
//             else{

//                 count++;
//             }
//         }

//         // Right Check
//         for(int j=i+1; j<n; j++){

//             if(arr[j] < arr[i]){

//                 break;
//             }
//             else{

//                 count++;
//             }
//         }

//         area = (arr[i] * count);

//         if(area > maxArea){

//             maxArea = area;
//         }
//     }

//     return maxArea;
// }

// Method 2 : 
// Time Complexity : O(n)  Space Complexity : O(n)
void getNextSmaller(int *arr, int n, vector<int> &nextSmaller){

    stack<int> st;

    for(int i=n-1; i>=0; i--){

        while(!st.empty() && arr[st.top()] >= arr[i]){

            st.pop();
        }

        if(st.empty()){

            st.push(i);
        }
        else{

            nextSmaller[i] = st.top();
            st.push(i);
        }
    }
}

void getPrevSmaller(int *arr, int n, vector<int> &prevSmaller){

    stack<int> st;

    for(int i=0; i<n; i++){

        while(!st.empty() && arr[st.top()] >= arr[i]){

            st.pop();
        }

        if(st.empty()){

            st.push(i);
        }
        else{

            prevSmaller[i] = st.top();
            st.push(i);
        }
    }
}

int largestRectangularArea(int *arr, int n){

    if(n == 1) return arr[0];

    int maxArea = INT_MIN;
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);

    // Next Smaller Element
    getNextSmaller(arr, n, nextSmaller);

    // Prev Smaller Element
    getPrevSmaller(arr, n, prevSmaller);

    // Finding Largest Area
    int area;

    for(int i=0; i<n; i++){

        if(prevSmaller[i] != -1){

            area = (arr[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        else{

            area = (arr[i] * (nextSmaller[i] + prevSmaller[i] + 1));
        }

        if(area > maxArea){

            maxArea = area;
        }
    }

    return maxArea;
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

    int maxValue = largestRectangularArea(arr, n);
    cout << "Max Area is : " << maxValue;

    cout << endl;
    return 0;
}