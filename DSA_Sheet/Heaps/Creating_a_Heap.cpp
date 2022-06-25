#include <iostream>
using namespace std;

class Heap {

    public:
        int arr[100];
        int size;

    Heap(){

        this->size = 0;
    }

    // Insert an element at last [Move it to its correct position]
    void insert(int data){

        // Insert the data
        arr[size] = data;

        // Check for parent
        int index = size;
        int parent = ((index + 1)/2)-1;

        while(index > 0){

            if(arr[parent] > arr[index])  break;

            swap(arr[parent], arr[index]);
            index = parent;
            parent = ((index + 1)/2)-1;
        }

        size = size + 1;
    }

    // This will delete the root element -> arr[1]
    void deleteRoot(){

        // Remove root and add last element to root
        int index = size-1;
        arr[0] = arr[index];
        size = size - 1;

        // Convert to heap again
        int parent = 0;

        while(parent < size){

            // New Parent wll have index of largest element
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

    void printHeap(){

        cout << "\nPrinting Heap : ";
        for(int i=0; i<size; i++){

            cout << arr[i] << " ";
        }
    }
};

int main()
{
    // Create a Heap
    Heap hp;

    // Insert Elements { 1 3 5 4 6 13 10 9 8 15 17 -1 }
    cout << "Enter heap data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        hp.insert(data);
    }

    hp.printHeap();
    
    hp.deleteRoot();
    hp.printHeap();

    hp.deleteRoot();
    hp.printHeap();

    hp.deleteRoot();
    hp.printHeap();


    cout << endl;
    return 0;
}