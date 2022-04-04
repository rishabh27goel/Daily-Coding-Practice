#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n^3)  Space Complexity : O(n)
// int longestValidParentheses(string s){

//     if(s.size() <= 1) return 0;

//     int maxCount = 0;
//     string sub = ""; 

//     for(int x=0; x<s.size(); x++){

//         sub = s[x];

//         for(int i=x+1; i<s.size(); i++){

//             sub += s[i];

//             if(sub.size() % 2 == 0){

//                 // Check for valid parentheses
//                 bool valid = true;
//                 stack<char> st;

//                 for(int j=0; j<sub.size(); j++){

//                     if(sub[j] == '('){

//                         st.push(sub[j]);
//                     }
//                     else{

//                         if(st.empty()){

//                             valid = false;
//                             break;
//                         }

//                         st.pop();
//                     }
//                 }

//                 if(st.empty() && valid){

//                     maxCount = max(maxCount, (int) sub.size());
//                 }
//             }
//         }
//     }

//     return maxCount;
// }

// Method 2 : Storing Index in Stack
// Time Complexity : O(n)  Space Complexity : O(1)
// int longestValidParentheses(string s){

//     if(s.size() <= 1) return 0;

//     stack<int> st;
//     st.push(-1);
//     int maxCount = 0;

//     for(int i=0; i<s.size(); i++){

//         if(s[i] == '('){

//             st.push(i);
//         }
//         else{

//             if(!st.empty())  st.pop();

//             if(!st.empty())
//                 maxCount = max(maxCount, i - st.top());
//             else
//                 st.push(i);
//         }
//     }

//     return maxCount;
// }

// Method 3 : Using Both Brackets Count
// Time Complexity : O(n)  Space Complexity : O(1)
int longestValidParentheses(string s){

    if(s.size() <= 1) return 0;

    int maxCount = 0;
    
    int left = 0;
    int right = 0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == '(') left++;

        if(s[i] == ')') right++;

        if(left == right){

            maxCount = max(maxCount, left + right);
        }
        else if(right > left){

            left = 0;
            right = 0;
        }
    }

    // To track from right
    left = 0;
    right = 0;

    for(int i=s.size()-1; i>=0; i--){

        if(s[i] == '(') left++;

        if(s[i] == ')') right++;

        if(left == right){

            maxCount = max(maxCount, left + right);
        }
        else if(right < left){

            left = 0;
            right = 0;
        }
    }

    return maxCount;
}

int main()
{
    string input;
    cout << "Enter Input string : ";
    cin >> input;

    int len = longestValidParentheses(input);
    cout << "Longest Valid Parentheses : " << len;


    cout << endl;
    return 0;
}