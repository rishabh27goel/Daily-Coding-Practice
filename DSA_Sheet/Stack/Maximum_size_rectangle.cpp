#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1 : Brute Force 
// Time Complexity : O(n^6)  Space Complexity : O(1)
// int maximumSizeRectangle(vector<vector<int> > input){

//     int n = input.size();
//     int m = input[0].size();

//     if(n == 0 || m == 0) return 0;

//     int maxArea = 0;

//     // Iterating Input Matrix
//     for(int i=0; i<n; i++){

//         for(int j=0; j<m; j++){

//             // Length and Breadth all possible values starting from i, j
//             if(input[i][j] == 0) continue;

//             for(int l=i; l<n; l++){

//                 for(int b=j; b<m; b++){

//                     bool containOnes = true; 
//                     int count = 0;

//                     // Counting Ones (Comparing Start to End)
//                     for(int x=i; x<=l; x++){

//                         for(int y=j; y<=b; y++){

//                             if(input[x][y] == 0){

//                                 containOnes = false;
//                                 break;
//                             }

//                             count++;
//                         }

//                         if(containOnes == false) break;
//                     }  

//                     if(containOnes == true){

//                         if(maxArea < count){

//                             maxArea = count;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     return maxArea;
// }

// Method 2 : Treating as Histogram (Non-Optimised) 
// Time Complexity : O(n^3)  Space Complexity : O(1)
// int maximumSizeRectangle(vector<vector<int> > input){

//     int n = input.size();
//     int m = input[0].size();

//     if(n == 0 || m == 0) return 0;

//     int maxArea = 0;

//     for(int i=0; i<n; i++){

//         for(int j=0; j<m; j++){

//             if(input[i][j] == 0) continue;

//             // Starting from second row
//             if(i > 0){

//                 input[i][j] += input[i-1][j];
//             }
//         }

//         int value;

//         // Treating each Row as a Histogram
//         for(int x=0; x<m; x++){

//             int len = 1;

//             // Left Check
//             for(int y=x-1; y>=0; y--){

//                 if(input[i][y] < input[i][x]){

//                     break;
//                 }
//                 else{

//                     len++;
//                 }
//             }

//             // Right Check
//             for(int y=x+1; y<m; y++){

//                 if(input[i][y] < input[i][x]){

//                     break;
//                 }
//                 else{

//                     len++;
//                 }
//             }

//             value = (input[i][x] * len);

//             if(maxArea < value){

//                 maxArea = value;
//             }
//         }
//     }

//     return maxArea;
// }

// Method 3 : Treating as Histogram (Optimised) 
// Time Complexity : O(n^2)  Space Complexity : O(n)
void nextSmallerVector(vector<int> input, vector<int> &nextSmaller){

    stack<int> st;

    for(int i=input.size()-1; i>=0; i--){

        while(!st.empty() && input[st.top()] >= input[i]){

            st.pop();
        }

        if(st.empty()){

            st.push(i);
        }
        else if(input[st.top()] < input[i]){

            nextSmaller[i] = st.top();
            st.push(i);
        }
    }
}

void prevSmallerVector(vector<int> input, vector<int> &prevSmaller){

    stack<int> st;

    for(int i=0; i<input.size(); i++){

        while(!st.empty() && input[st.top()] >= input[i]){

            st.pop();
        }

        if(st.empty()){

            st.push(i);
        }
        else if(input[st.top()] < input[i]){

            prevSmaller[i] = st.top();
            st.push(i);
        }
    }
}

int largestAreaHistogram(vector<int> histo){

    int maxArea = 0;

    // Next Smaller 
    vector<int> nextSmaller(histo.size(), histo.size());
    nextSmallerVector(histo, nextSmaller);

    // Prev Smaller
    vector<int> prevSmaller(histo.size(), -1);
    prevSmallerVector(histo, prevSmaller);

    int area;

    for(int i=0; i<histo.size(); i++){

        if(prevSmaller[i] != -1){

            area = histo[i] * (nextSmaller[i] - prevSmaller[i] - 1);
        }
        else{

            area = histo[i] * (nextSmaller[i] + prevSmaller[i] + 1);
        }

        if(area > maxArea){

            maxArea = area;
        }
    }

    return maxArea;
}


int maximumSizeRectangle(vector<vector<int> > input){

    int maxArea = 0;

    for(int i=0; i<input.size(); i++){

        for(int j=0; j<input[0].size(); j++){

            if(input[i][j] == 0) continue;

            if(i > 0){

                input[i][j] += input[i-1][j];
            }
        }
    }

    for(int i=0; i<input.size(); i++){

        maxArea = max(maxArea, largestAreaHistogram(input[i]));
    }

    return maxArea;
}

int main()
{
    int n, m;
    cout << "Enter row size : ";
    cin >> n;

    cout << "Enter column size : ";
    cin >> m;

    cout << "Enter matrix values : ";
    vector<vector<int> > input(n, vector<int> (m));
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> input[i][j];
        }
    }

    int maxArea = maximumSizeRectangle(input);
    cout << "Maximum Area is : " << maxArea;

    cout << endl;
    return 0;
}