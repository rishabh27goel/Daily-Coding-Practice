#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method 1 : Brute Force [Nested Loops]
// Time Complexity : O(n^2)  Space Complexity : O(1)
// bool checkPreorder(vector<int> &preorder){

//     if(preorder.size() == 0) return true;

//     for(int i=0; i<preorder.size(); i++){

//         int j = i + 1;

//         while(j < preorder.size()){

//             if(preorder[j] > preorder[i])
//                 break;

//             j++;
//         }

//         while(j < preorder.size()){

//             if(preorder[j] < preorder[i])
//                 return false;

//             j++;
//         }
//     }

//     return true;
// }

// Method 2 : Using Stack [Iterative Method]
// Time Complexity : O(n)  Space Complexity : O(n)
// bool checkPreorder(vector<int> &preorder){

//     if(preorder.size() == 0) return true;

//     // Stack for storing values
//     stack<int> st;
//     int root = INT_MIN;

//     for(int i=0; i<preorder.size(); i++){

//         // After moving the root down we can not have a smaller value than root
//         if(root > preorder[i])
//             return false;


//         // Check if right values are greater
//         // If it is then move the root down 
//         while(!st.empty() && st.top() < preorder[i]){

//             root = st.top();
//             st.pop();
//         }

//         st.push(preorder[i]);
//     }

//     return true;
// }

// Method 3 : Using Min & Max track [Recursive Method]
// Time Complexity : O(n)  Space Complexity : O(h)
void checkPreorderHelper(vector<int> &preorder, int &index, int minValue, int maxValue){

    if(index >= preorder.size() || !(preorder[index] > minValue && preorder[index] < maxValue)) 
        return;


    int value = preorder[index];
    index++;

    checkPreorderHelper(preorder, index, minValue, value);
    checkPreorderHelper(preorder, index, value, maxValue);
}

bool checkPreorder(vector<int> &preorder){

    if(preorder.size() == 0) return true;

    int index = 0;
    checkPreorderHelper(preorder, index, INT_MIN, INT_MAX);

    return (index == preorder.size());
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    // Input { 40 30 35 20 80 100 }   { 40 30 35 34 80 100 }
    cout << "Enter data : ";
    vector<int> preorder;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        preorder.push_back(data);
    }

    // Check if Preorder is Valid
    bool check = checkPreorder(preorder);

    if(check){

        cout << "Preorder is Valid !";
    }
    else{

        cout << "Preorder is not Valid !";
    }

    cout << endl;
    return 0;
}