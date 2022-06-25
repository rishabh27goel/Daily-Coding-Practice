#include <iostream>
#include <vector>
using namespace std;

void printHeap(vector<int> &arr){

    cout << "\nPrinting Heap : ";
    for(int i=0; i<arr.size(); i++){

        cout << arr[i] << " ";
    }
}

// Method : 
// Time Complexity : O(n)  Space Complexity : O(log(n)) [Due to recursion]
void heapify(vector<int> &arr, int parent){

    int newParent = parent;

    int leftIndex = 2*parent + 1;
    int rightIndex = 2*parent + 2;

    if(leftIndex < arr.size() && arr[newParent] < arr[leftIndex]){

        newParent = leftIndex;
    }

    if(rightIndex < arr.size() && arr[newParent] < arr[rightIndex]){

        newParent = rightIndex;
    }

    if(newParent != parent){

        swap(arr[newParent], arr[parent]);
        heapify(arr, newParent);
    }
}

void buildHeap(vector<int> &arr){

    if(arr.size() == 0) return;

    // Non-Leaf Nodes are only node we can heapity
    int startIndex = (arr.size() / 2) - 1;

    // In Reverse Order perform heapify
    for(int i=startIndex; i>=0; i--){

        heapify(arr, i);
    }
}

int main()
{
    cout << "Enter number of elements : ";
    int n;
    cin >> n;

    // Insert Elements { 1 3 5 4 6 13 10 9 8 15 17 -1 }
    cout << "Enter elements : ";
    vector<int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    buildHeap(arr);
    printHeap(arr);

    cout << endl;
    return 0;
}