#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Check every pair [Two Loop]
// Time Complexity : O(n^2)  Space Complexity : O(1)
// int maximumXor(vector<int> &arr){

//     int maxXor = 0;

//     for(int i=0; i<arr.size(); i++){

//         for(int j=i; j<arr.size(); j++){

//             maxXor = max (maxXor, arr[i] ^ arr[j]);
//         }
//     }

//     return maxXor;
// }

// Method 2 : Using Trie
// Time Complexity : O(32 * n)  Space Complexity : O(32 * n) 
int maxXor = 0;

class TrieNode {

    public:
        TrieNode* child[2];
        int number;

    TrieNode(){

        for(int i=0; i<2; i++){

            child[i] = NULL;
        }

        this->number = -1;
    }
};

void insertNumber(TrieNode* node, int index, int number){

    if(index == 0){

        node->number = number;
        return;
    }

    int data = (number & (1 << (index-1))) ? 1 : 0;
    TrieNode* newNode;

    if(node->child[data] == NULL){

        newNode = new TrieNode();
        node->child[data] = newNode;
    }
    else{

        newNode = node->child[data];
    }

    insertNumber(newNode, index-1, number);
}

void findXor(TrieNode* node, int index, int number){

    if(node == NULL)  return;

    if(node->number != -1){

        maxXor = max (maxXor, node->number ^ number);
        return;
    }

    // Check for opposite bits for maximum xor
    int org = (number & (1 << (index-1))) ? 1 : 0;
    int data = !org;

    if(node->child[data] == NULL){

        findXor(node->child[org], index-1, number);
    }
    else{

        findXor(node->child[data], index-1, number);
    }
}

int maximumXor(vector<int> &arr){

    // Create a trie
    TrieNode* root = new TrieNode();

    for(int i=0; i<arr.size(); i++){

        insertNumber(root, 31, arr[i]);
    }

    // Check for Maximum Xor
    for(int i=0; i<arr.size(); i++){

        findXor(root, 31, arr[i]);
    }


    return maxXor;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    // Input { 14 70 53 83 49 91 36 80 92 51 66 70 }
    cout << "Enter array : ";
    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    // Maximum Xor of two numbers
    int maxXor = maximumXor(arr);

    cout << "Maximum Xor : " << maxXor;

    cout << endl;
    return 0;
}