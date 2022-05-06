#include <iostream>
#include <map>
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

// Method 1 : Using Map [Recursive Method]
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// void diagonalTraversalHelper(Node* root, int index, map<int, vector<int> > &mp){

//     if(root == NULL) return;

//     mp[index].push_back(root->data);

//     // Index + 1 for left child
//     diagonalTraversalHelper(root->left, index + 1, mp);

//     // Same index as parent for right child
//     diagonalTraversalHelper(root->right, index, mp);    
// }

// vector<vector<int> > diagonalTraversal(Node* root){

//     vector<vector<int> > diagonal;
//     if(root == NULL) return diagonal;

//     // Store the diagonals in the Map
//     map<int, vector<int> > mp;

//     diagonalTraversalHelper(root, 0, mp);

//     map<int, vector<int> > :: iterator itr;

//     for(itr = mp.begin(); itr != mp.end(); itr++){

//         diagonal.push_back(itr->second);
//     } 

//     return diagonal;
// }

// Method 2 : Using Queue [Iterative Method] 
// Time Complexity : O(n)  Space Complexity : O(n)
vector<vector<int> > diagonalTraversal(Node* root){

    vector<vector<int> > diagonal;
    if(root == NULL) return diagonal;

    // Storing nodes in queue
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int> single;

        while(size--){

            Node* front = q.front();
            q.pop();

            while(front != NULL){

                if(front->left != NULL){

                    q.push(front->left);
                }

                single.push_back(front->data);
                front = front->right;
            }
        }

        diagonal.push_back(single);
    }

    return diagonal;
}


// Method 3 : Only Single Line Printing 
// Time Complexity : O(n)  Space Complexity : O(n)
// void diagonalTraversal(Node* root){

//     if(root == NULL) return;

//     // Store the tree nodes
//     queue<Node*> q;
//     Node* curr = root;

//     while(!q.empty() || curr != NULL){

//         // Move to right nodes
//         while(curr != NULL){

//             q.push(curr);

//             curr = curr->right;
//         }

//         // Curr is NULL here
//         curr = q.front();
//         q.pop();

//         cout << curr->data;

//         curr = curr->left;
//     }
// }

int main()
{
    Node* root = NULL;

    // Creating a Tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Diagonal Traversal Of Binary Tree
    vector<vector<int> > diagonal;
    
    diagonal = diagonalTraversal(root);

    cout << "Diagonal Traversal : \n";
    for(int i=0; i<diagonal.size(); i++){

        for(int j=0; j<diagonal[i].size(); j++){

            cout << diagonal[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}