#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
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
void topViewBinaryTree(Node* root, vector<int> &topView){

    if(root == NULL) return;

    // For taking only single node in each level 
    map<int, int> mp;

    // Queue for storing (nodes, vertical index) pair
    queue <pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> frontPair = q.front();
        q.pop();

        Node* front = frontPair.first;
        int index = frontPair.second;

        // Check if Vertical Index exits
        if(mp.find(index) == mp.end()){

            mp[index] = front->data;
        }

        // Store Right Child
        if(front->left != NULL){

            q.push(make_pair(front->left, index - 1));
        }

        // Store Left Child
        if(front->right != NULL){

            q.push(make_pair(front->right, index + 1));
        }
    }

    // Get the Top View from Map
    map<int, int> :: iterator itr;

    for(itr = mp.begin(); itr != mp.end(); itr++){

        topView.push_back(itr->second);        
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