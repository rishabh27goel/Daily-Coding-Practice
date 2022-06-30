#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Sort Function
// Time Complexity : O((k * n) * log(k * n))  Space Complexity : O(1)
// vector<int> mergeKSortedArray(vector< vector<int> > &input){

//     vector<int> output;
//     if(input.size() == 0) return output;

//     // Push all elements to output
//     for(int i=0; i<input.size(); i++){

//         for(int j=0; j<input[i].size(); j++){

//             output.push_back(input[i][j]);
//         }
//     }

//     // Sort the output
//     sort(output.begin(), output.end());

//     return output;
// }

// Method 2 : Using Min Heap
// Time Complexity : O((k * n) * log(k))  Space Complexity : O(k)
class Store {

    public:
        int value;
        int row;
        int col;
        
    Store(int value, int row, int col){

        this->value = value;
        this->row = row;
        this->col = col;
    }
};

class InfoStore {

    public:
        bool operator()(Store* s1, Store* s2){

            return s1->value > s2->value;
        }
};

vector<int> mergeKSortedArray(vector< vector<int> > &input){

    vector<int> output;
    if(input.size() == 0) return output;

    // Create Min Heap
    priority_queue <Store*, vector<Store*>, InfoStore> pq;

    // Push first element of all arrays in Min Heap
    for(int i=0; i<input.size(); i++){

        if(input[i].size()){

            pq.push(new Store(input[i][0], i, 0));
        }
    }

    // Rest elements
    while(!pq.empty()){

        Store* top = pq.top();
        pq.pop();

        output.push_back(top->value);

        // Push Element
        int i = top->row;
        int j = top->col;

        if(j + 1 < input[i].size()){

            pq.push(new Store(input[i][j+1], i, j+1));
        }
    }

    return output;
}

int main()
{
    vector< vector<int> > input;
    cout << "Enter size : ";
    int size;
    cin >> size;

    for(int i=0; i<size; i++){

        cout << "Enter data : ";
        vector<int> sub;
        int data = 0;

        while(data != -1){

            cin >> data;
            if(data == -1) break;

            sub.push_back(data);
        }
        
        input.push_back(sub);
    }

    // Merge K Sorted Array
    vector<int> output = mergeKSortedArray(input);

    cout << "Merged Array : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}