#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Iterative Method [Using Map]
// Time Complexity : O(n * logn)   Space Complexity : O(n)
// void topViewBinaryTree(Node* root, vector<int> &topView){

//     if(root == NULL) return;

//     // For taking only single node in each level 
//     map<int, int> mp;

//     // Queue for storing (nodes, vertical index) pair
//     queue <pair<Node*, int> > q;
//     q.push(make_pair(root, 0));

//     while(!q.empty()){

//         pair<Node*, int> frontPair = q.front();
//         q.pop();

//         Node* front = frontPair.first;
//         int index = frontPair.second;

//         // Check if Vertical Index exits
//         if(mp.find(index) == mp.end()){

//             mp[index] = front->data;
//         }

//         // Store Right Child
//         if(front->left != NULL){

//             q.push(make_pair(front->left, index - 1));
//         }

//         // Store Left Child
//         if(front->right != NULL){

//             q.push(make_pair(front->right, index + 1));
//         }
//     }

//     // Get the Top View from Map
//     map<int, int> :: iterator itr;

//     for(itr = mp.begin(); itr != mp.end(); itr++){

//         topView.push_back(itr->second);        
//     }
// }

// Method 2 : Iterative Method [Without Using Map]
// Time Complexity : O(n)   Space Complexity : O(n)
// void topViewBinaryTree(Node* root, vector<int> &topView){

//     if(root == NULL) return;

//     // Queue for storing (nodes, vertical index) pair
//     queue <pair<Node*, int> > q;
//     q.push(make_pair(root, 0));

//     // Keep track of all the vertical indexes
//     int left = 0;
//     int right = 0;

//     // We need to store nodes data 
//     stack<int> leftNodes;    // To reverse the order
//     vector<int> rightNodes;   // To maintain the same order

//     while(!q.empty()){

//         // Get the front pair
//         pair<Node*, int> frontPair = q.front();
//         q.pop();

//         Node* front = frontPair.first;
//         int index = frontPair.second;

//         // If index is equal to left or right we will ignore 
//         // [As we only need one node vertically]

//         if(index < left){

//             // Store in Stack

//             leftNodes.push(front->data);
//             left = index;
//         }

//         if(index > right){

//             // Store in Vector

//             rightNodes.push_back(front->data);
//             right = index;
//         }

//         // Store Right Child
//         if(front->left != NULL){

//             q.push(make_pair(front->left, index - 1));
//         }

//         // Store Left Child
//         if(front->right != NULL){

//             q.push(make_pair(front->right, index + 1));
//         }
//     }

//     // Now the Top View from stack and vector [From left and right resp.]
//     // Left Half
//     while(!leftNodes.empty()){

//         topView.push_back(leftNodes.top());
//         leftNodes.pop();
//     }

//     // Root data
//     topView.push_back(root->data);

//     // Right Half
//     for(int i=0; i<rightNodes.size(); i++){

//         topView.push_back(rightNodes[i]);
//     }
// }

// Method 3 : Iterative Method [Using Queue with Unordered Map]
// Time Complexity : O(n)   Space Complexity : O(n)
void topViewBinaryTree(Node* root, vector<int> &topView){

    if(root == NULL) return;

    // For tree node data
    unordered_map<int, int> mp;

    // Storing the tree nodes & vertical height
    queue< pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    int min = 0;

    while(!q.empty()){

        pair<Node*, int> frontPair = q.front();
        q.pop();

        Node* front = frontPair.first;
        int index = frontPair.second;

        if(min > index){

            min = index;
        }

        // It takes O(1) to insert in Unordered-Map
        if(mp.find(index) == mp.end()){

            mp[index] = front->data;
        }

        // Left Child
        if(front->left != NULL){

            q.push(make_pair(front->left, index - 1));
        }

        // Right Child
        if(front->right != NULL){

            q.push(make_pair(front->right, index + 1));
        }
    }

    // Get the min vertical index
    unordered_map<int, int> :: iterator itr;
    min = abs(min);
    topView.resize(mp.size());

    for(itr = mp.begin(); itr != mp.end(); itr++){

        topView[itr->first + min] = itr->second;
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Top View Of Binary Tree
    vector<int> topView;

    topViewBinaryTree(root, topView);

    cout << "Top View : ";
    for(int i=0; i<topView.size(); i++){

        cout << topView[i] << " ";
    }

    cout << endl;
    return 0;
}