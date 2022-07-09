#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(x^2 * 2^n)  Space Complexity : O(x * 2^n)
// X is average of summation target/arri for every number in the array.
void combinationHelper(vector<int> &arr, int target, int index, vector<int> &sub, vector< vector<int> > &output){

    if(target < 0)  return;

    if(target == 0){

        output.push_back(sub);
        return;
    }

    int i = index;

    while(i < arr.size()){

        // To avoid repeated values
        if(i > 0 && arr[i] == arr[i-1]){
            
            i++;
            continue;
        }

        sub.push_back(arr[i]);
        combinationHelper(arr, target - arr[i], i, sub, output);
        i++;
        sub.pop_back();
    }
}

vector< vector<int> > combinationalSum(vector<int> &arr, int target){

    vector< vector<int> > output;
    if(arr.size() == 0) return output;

    // For sorted order in output
    sort(arr.begin(), arr.end());

    vector<int> sub;
    combinationHelper(arr, target, 0, sub, output);

    return output;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector<int> arr;
    int data;

    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Combinational Sum
    vector< vector<int> > output = combinationalSum(arr, target);

    cout << "Combinational Sum : " << endl;
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}