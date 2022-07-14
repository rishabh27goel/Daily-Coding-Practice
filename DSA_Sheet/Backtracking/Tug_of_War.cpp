#include <iostream>
#include <vector>
using namespace std;

#include <math.h>

// Method : Backtracking
// Time Complexity : O(n * 2^n)  Space Complexity : O(n)
vector<int> output;

void tugOfWarHelper(vector<int> &arr, int index, int s1, int s2, vector<int> &left, vector<int> &right, int &diff, vector<int> &subset){

    if(index == arr.size()){

        if(left.size() == right.size() || abs((int) left.size() - (int) right.size()) == 1){

            if(diff > abs(s1 - s2)){

                diff = abs(s1 - s2);

                for(int i=0; i<left.size(); i++){

                    output[i] = left[i];
                }

                for(int i=0; i<right.size(); i++){

                    output[i + left.size()] = right[i];
                }
            }
        }

        return;
    }

    // Include in first set
    left.push_back(arr[index]);
    subset[index] = 1;
    tugOfWarHelper(arr, index + 1, s1 + arr[index], s2, left, right, diff, subset);
    subset[index] = 0;
    left.pop_back();

    // Include in second set
    right.push_back(arr[index]);
    subset[index] = 2;
    tugOfWarHelper(arr, index + 1, s1, s2 + arr[index], left, right, diff, subset);
    subset[index] = 0;
    right.pop_back();
}

void tugOfWar(vector<int> &arr){

    if(arr.size() == 0) return;

    // Creating two subsets 
    int diff = INT_MAX;

    vector<int> left;
    vector<int> right;
    vector<int> subset(arr.size(), 0);

    output.resize(arr.size(), 0);
    left.push_back(arr[0]);
    subset[0] = 1;

    tugOfWarHelper(arr, 1, arr[0], 0, left, right, diff, subset);

    cout << "Difference is : " << diff << endl;
    
    cout << "Subsets : ";
    if(output.size())
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    // Input { 3 4 5 -3 100 1 89 54 23 20 }
    cout << "Enter number of elements : ";

    vector <int> arr;
    int data;

    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Tug of War
    tugOfWar(arr);

    cout << endl;
    return 0;
}