#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(2 ^ (n * k))  Space Complexity : O(n)
bool partitionOfKSetsHelper(vector<int> &arr, vector<int> &visited, int index, int target, int sum, int k){

    if(sum > target || index > arr.size())  return false;

    // Solution Exits
    if(k == 0)  return true;

    if(sum == target){
        
        // A subset is found
        return partitionOfKSetsHelper(arr, visited, 0, target, 0, k - 1);
    }

    for(int i=index; i<arr.size(); i++){

        if(visited[i] != -1)  continue;

        visited[i] = k;

        if(partitionOfKSetsHelper(arr, visited, i + 1, target, sum + arr[i], k)){

            return true;
        }

        // Backtracking
        visited[i] = -1;
    }

    return false;
}

pair< vector<int>, bool > partitionOfKSets(vector<int> &arr, int k){

    // Take the sum and find each subset with its sum / k
    int sum = 0;

    for(int i=0; i<arr.size(); i++){

        sum += arr[i];
    }

    // Now check if partition exits
    vector<int> visited(arr.size(), -1);

    if(sum % k != 0)  return make_pair(visited, false);

    bool exits = partitionOfKSetsHelper(arr, visited, 0, sum / k, 0, k);

    return make_pair(visited, exits);
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    // Input : 4 3 2 3 5 2 1
    cout << "Enter array : ";
    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Partition of a set into k subsets
    pair< vector<int>, bool > output = partitionOfKSets(arr, k);

    if(output.second){

        cout << "Partition Exits !\n" ;
    
        int n = k;

        cout << "Subsets are : \n";
        for(int j=k; j>0; j--){

            for(int i=0; i<arr.size(); i++){

                if(output.first[i] == j){

                    cout << arr[i] << " ";
                }
            }

            cout << endl;
        }
    }
    else{

        cout << "Partition Doesn't Exits !" ;
    }
    

    cout << endl;
    return 0;
}