#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Method : Backtracking 
// Time Complexity : O(2^n)  Space Complexity : O(n)
pair< vector<int>, vector<int> > output;

void partitionHelper(vector<int> &arr, int s1, int s2, int index, bool &check, vector<int> &left, vector<int> &right){

    if(index >= arr.size() && s1 != s2)  return;
    
    if(index == arr.size() && s1 == s2){

        output = make_pair(left, right);
        check = true;
        return;
    }

    // Include arr[index] in left
    left.push_back(arr[index]); 
    partitionHelper(arr, s1+arr[index], s2, index+1, check, left, right);
    left.pop_back();

    // Include arr[index] in right
    right.push_back(arr[index]); 
    partitionHelper(arr, s1, s2+arr[index], index+1, check, left, right);
    right.pop_back();
}

bool partitionSubsetSum(vector<int> &arr){

    if(arr.size() == 1 && arr[0] == 0){ 

        output = make_pair(arr, arr); 
        return true;
    }

    if(arr.size() <= 1)  return false;

    // Now generate partitions
    bool check = false;

    int s1 = arr[0];
    int s2 = 0;

    vector<int> left;
    vector<int> right;

    left.push_back(arr[0]);

    partitionHelper(arr, s1, s2, 1, check, left, right);

    return check;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <int> arr;
    cout << "Enter array : ";
    int data;
    
    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Partition Equal Subset Sum
    if(partitionSubsetSum(arr)){

        cout << "Left Subset : ";
        for(int i=0; i<output.first.size(); i++){

            cout << output.first[i] << " ";
        }

        cout << "\nRight Subset : ";
        for(int i=0; i<output.second.size(); i++){

            cout << output.second[i] << " ";
        }
    }

    cout << endl;
    return 0;
}