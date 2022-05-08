#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
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

// Method 1 : Using Level Order & Map
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// void verticalTraversal(Node* root, vector<vector<int> > &vertical){

//     if(root == NULL) return;

//     // Store tree nodes & vertical index
//     map<int, vector<int> > mp;
//     queue<pair<Node*, int> > q;
//     q.push(make_pair(root, 0));

//     while(!q.empty()){

//         pair<Node*, int> frontPair = q.front();
//         q.pop();

//         Node* front = frontPair.first;
//         int vertical = frontPair.second;

//         mp[vertical].push_back(front->data);   // O(log(n)) insertion time

//         if(front->left != NULL){

//             q.push(make_pair(front->left, vertical - 1));
//         }
 
//         if(front->right != NULL){

//             q.push(make_pair(front->right, vertical + 1));
//         }
//     }

//     // Get the vertical order from map
//     map<int, vector<int> > :: iterator itr;

//     for(itr = mp.begin(); itr != mp.end(); itr++){

//         vertical.push_back(itr->second);
//     }
// }

// Method 2 : Using Level Order & Unordered Map
// Time Complexity : O(n)  Space Complexity : O(n)
void verticalTraversal(Node* root, vector<vector<int> > &vertical){

    if(root == NULL) return;

    // Store tree nodes & vertical index
    unordered_map<int, vector<int> > mp;
    int minVertical = 0;

    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> frontPair = q.front();
        q.pop();

        Node* front = frontPair.first;
        int vertical = frontPair.second;

        minVertical = min(vertical, minVertical);
        mp[vertical].push_back(front->data);   // O(1) insertion time

        if(front->left != NULL){

            q.push(make_pair(front->left, vertical - 1));
        }
 
        if(front->right != NULL){

            q.push(make_pair(front->right, vertical + 1));
        }
    }

    // Get the vertical order from map
    for(int i = minVertical; i < minVertical + (int)mp.size(); i++){

        vertical.push_back(mp[i]);
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Vertical Traversal Of Binary Tree
    vector<vector<int> > vertical;

    verticalTraversal(root, vertical);

    cout << "Vertical Traversal : \n";
    for(int i=0; i<vertical.size(); i++){

        for(int j=0; j<vertical[i].size(); j++){

            cout << vertical[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}