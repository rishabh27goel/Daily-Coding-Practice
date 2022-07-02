#include <iostream>
#include <vector>
using namespace std;

// Method : Using Merge and Heapify
// Time Complexity : O(n + m)  Space Complexity : O(1) [Not considering output space]
void heapify(vector<int> &output, int size, int parent){

    while(parent < size){

        int newParent = parent;

        int left = 2*parent + 1;
        int right = 2*parent + 2;

        if(left < size && output[left] > output[newParent])
            newParent = left;

        if(right < size && output[right] > output[newParent])
            newParent = right;


        if(newParent == parent) break;

        swap(output[newParent], output[parent]);
        parent = newParent; 
    }
}

void buildMaxHeap(vector<int> &output){

    int n = output.size();
    if(n == 0) return;

    int startIndex = n-(n/2)-1;

    for(int i=startIndex; i>=0; i--){

        heapify(output, n, i);
    }
}

vector<int> mergeTwoHeaps(vector<int> &first, vector<int> &second){

    if(first.size() == 0) return second;
    if(second.size() == 0) return first;

    vector<int> output;

    // Push all the elements 
    for(int i=0; i<first.size(); i++){

        output.push_back(first[i]);
    }

    for(int i=0; i<second.size(); i++){

        output.push_back(second[i]);
    }

    // Build Max Heap Using Heapify
    buildMaxHeap(output);

    return output;
}

int main()
{
    cout << "Enter first size : ";
    int n;
    cin >> n;

    int data = 0;
    vector<int> first;
    cout << "Enter data : ";
    
    for(int i=0; i<n; i++){

        cin >> data;
        first.push_back(data);
    }

    cout << "Enter second size : ";
    int m;
    cin >> m;

    vector<int> second;
    cout << "Enter data : ";

    for(int i=0; i<m; i++){

        cin >> data;
        second.push_back(data);
    }

    // Merge Two Binary Max Heaps
    vector<int> merge = mergeTwoHeaps(first, second);

    cout << "Merged Heaps : ";
    for(int i=0; i<merge.size(); i++){

        cout << merge[i] << " ";
    }

    cout << endl;
    return 0;
}