#include <iostream>
#include <vector>
using namespace std;

// Method : Simple Heapify the input
// Time Complexity : O(n)  Space Complexity : O(1)
void heapify(vector<int> &arr, int size, int parent){

    while(parent < size){

        int newParent = parent;

        int left = 2*parent + 1;
        int right = 2*parent + 2;

        if(left < size && arr[left] > arr[newParent])
            newParent = left;

        if(right < size && arr[right] > arr[newParent])
            newParent = right;

        if(parent == newParent) break;

        swap(arr[parent], arr[newParent]);
        parent = newParent;
    }
}

vector<int> convertToMaxHeap(vector<int> &arr){

    int n = arr.size();

    if(n == 0) return arr;

    int startIndex = n-(n/2)-1;

    for(int i=startIndex; i>=0; i--){

        heapify(arr, n, i);
    }

    return arr;
}

int main()
{   
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr;
    int data;

    // Input { 3 5 9 6 8 20 10 12 18 9 }
    cout << "Enter array : ";
    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Convert Min Heap to Max Heap
    vector<int> output = convertToMaxHeap(arr);

    cout << "Max Heap : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}