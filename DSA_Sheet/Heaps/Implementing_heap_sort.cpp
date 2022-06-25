#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr){

    cout << "\nPrinting Heap : ";
    for(int i=0; i<arr.size(); i++){

        cout << arr[i] << " ";
    }
}

void heapify(vector<int> &arr, int size, int parent){

    if(size == 0) return;

    while(parent < size){

        int newParent = parent;

        int leftIndex = 2*parent + 1;
        int rightIndex = 2*parent + 2;

        if(leftIndex < size && arr[newParent] < arr[leftIndex]){

            newParent = leftIndex;
        }

        if(rightIndex < size && arr[newParent] < arr[rightIndex]){

            newParent = rightIndex;
        }

        if(parent == newParent) break;

        swap(arr[parent], arr[newParent]);
        parent = newParent;
    }
}

void buildMaxHeap(vector<int> &arr){

    if(arr.size() == 0) return;

    int startIndex = (arr.size() / 2) - 1;

    for(int i=startIndex; i>=0; i--){

        heapify(arr, arr.size(), i);
    }
}

void heapSort(vector<int> &arr){

    if(arr.size() == 0) return;

    // Heap Sort Using Heapify
    int size = arr.size();

    while(size > 0){

        swap(arr[0], arr[size-1]);
        size = size - 1;
        heapify(arr, size, 0);
    }
}

int main()
{
    cout << "Enter number of elements : ";
    int n;
    cin >> n;

    // Insert Elements { 1 3 5 4 6 13 10 9 8 15 17 -1 }
    vector<int> arr;
    cout << "Enter data : ";
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Build the Max Heap [Time : O(n)   Space : O(1)]
    buildMaxHeap(arr);

    // Heap Sort Function [Time : O(n * log(n))   Space : O(1)]
    heapSort(arr);

    printArray(arr);

    cout << endl;
    return 0;
}