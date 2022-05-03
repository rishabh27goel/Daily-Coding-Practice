#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>
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

// Method 1 : Recursive Method [Using Map]
// Time Complexity : O(n * logn)   Space Complexity : O(n)
// void bottomViewHelper(Node* root, int vertical, int height, map<int, pair<int, int> > &mp){

//     if(root == NULL) return;

//     // If vertical index has occured first time
//     if(mp.find(vertical) == mp.end()){

//         mp[vertical] = make_pair(root->data, height);
//     }
//     else{

//         // If it exits in the map
//         pair<int, int> get = mp[vertical];

//         // Check the height of the new root with same vertical index
//         if(height >= get.second){

//             // Update the new node data
//             get.first = root->data;
//             get.second = height;
//             mp[vertical] = get;
//         }
//     }

//     bottomViewHelper(root->left, vertical - 1, height + 1, mp);
//     bottomViewHelper(root->right, vertical + 1, height + 1, mp);
// }

// void bottomViewBinaryTree(Node* root, vector<int> &bottomView){

//     if(root == NULL) return;

//     // For storing vertical & tree node data
//     map<int, pair<int, int> > mp;

//     bottomViewHelper(root, 0, 1, mp);

//     // Get the Bottom View from map
//     map<int, pair<int, int> > :: iterator itr;

//     for(itr = mp.begin(); itr != mp.end(); itr++){

//         bottomView.push_back(itr->second.first);
//     }
// }

// Method 2 : Iterative Method [Using Queue with Ordered Map]
// Time Complexity : O(n * logn)   Space Complexity : O(n)
// void bottomViewBinaryTree(Node* root, vector<int> &bottomView){

//     if(root == NULL) return;

//     // For tree node data
//     map<int, int> mp;

//     // Storing the tree nodes & vertical height
//     queue< pair<Node*, int> > q;
//     q.push(make_pair(root, 0));

//     while(!q.empty()){

//         pair<Node*, int> frontPair = q.front();
//         q.pop();

//         // Getting node and vertical index
//         Node* front = frontPair.first;
//         int index = frontPair.second;

//         // Storing index in map
//         // It takes O(log(n)) to insert in Ordered-Map
//         mp[index] = front->data;

//         // Left Child
//         if(front->left != NULL){

//             q.push(make_pair(front->left, index - 1));
//         }

//         // Right Child
//         if(front->right != NULL){

//             q.push(make_pair(front->right, index + 1));
//         }
//     }

//     // Get the Bottom View from map
//     map<int, int> :: iterator itr;

//     for(itr = mp.begin(); itr != mp.end(); itr++){

//         bottomView.push_back(itr->second);
//     }
// }

// Method 3 : Iterative Method [Using Queue with Unordered Map]
// Time Complexity : O(n)   Space Complexity : O(n)
void bottomViewBinaryTree(Node* root, vector<int> &bottomView){

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
        mp[index] = front->data;

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
    bottomView.resize(mp.size());

    for(itr = mp.begin(); itr != mp.end(); itr++){

        bottomView[itr->first + min] = itr->second;
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Bottom View Of Binary Tree
    vector<int> bottomView;

    bottomViewBinaryTree(root, bottomView);

    cout << "Bottom View : ";
    for(int i=0; i<bottomView.size(); i++){

        cout << bottomView[i] << " ";
    }

    cout << endl;
    return 0;
}