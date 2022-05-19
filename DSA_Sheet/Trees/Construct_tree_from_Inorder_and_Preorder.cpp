#include <iostream>
#include <vector>
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

void postorderTraversal(Node* root){

    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);

    cout << root->data << " ";
}

// Method 1 : Recursive Brute Force
// Time Complexity : O(n^2)  Space Complexity : O(n)
// int findIndex(vector<int> &inorder, int val, int start, int end){

//     for(int i=start; i<=end; i++){

//         if(inorder[i] == val){

//             return i;
//         }
//     }

//     return start;
// }

// Node* createTreeHelper(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end){

//     if(start > end) return NULL;

//     Node* root = new Node(preorder[index]);

//     int find = findIndex(inorder, preorder[index], start, end);
//     index = index + 1;

//     // Left Call [Based on Inorder Index]
//     root->left = createTreeHelper(inorder, preorder, index, start, find-1);

//     // Right Call [Based on Inorder Index]
//     root->right = createTreeHelper(inorder, preorder, index, find+1, end);

//     return root;
// }

// Node* treeFromInorderPreorder(vector<int> &inorder, vector<int> &preorder){

//     if(inorder.size() == 0) return NULL;

//     int index = 0;
//     Node* root = createTreeHelper(inorder, preorder, index, 0, inorder.size()-1);

//     return root;
// }

// Method 2 : Recursive Optimized [Using Map]
// Time Complexity : O(n)  Space Complexity : O(n)
Node* createTreeHelper(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end, unordered_map<int, int> &helperMap){

    if(start > end) return NULL;

    Node* root = new Node(preorder[index]);

    // Get index from map
    int find = helperMap[preorder[index]];
    index = index + 1;

    // Left Call [Based on Inorder Index]
    root->left = createTreeHelper(inorder, preorder, index, start, find-1, helperMap);

    // Right Call [Based on Inorder Index]
    root->right = createTreeHelper(inorder, preorder, index, find+1, end, helperMap);

    return root;
}

Node* treeFromInorderPreorder(vector<int> &inorder, vector<int> &preorder){

    if(inorder.size() == 0) return NULL;

    // Helper Map 
    unordered_map<int, int> helperMap;

    for(int i=0; i<inorder.size(); i++){

        helperMap[inorder[i]] = i;
    }

    // Created Tree
    int index = 0;
    Node* root = createTreeHelper(inorder, preorder, index, 0, inorder.size()-1, helperMap);

    return root;
}

int main()
{
    cout << "Enter size of tree : ";
    int n;
    cin >> n;

    // Size of Inorder Vector & Preorder Vector should be same
    int data;
    cout << "Enter Inorder : ";
    vector<int> inorder;
    for(int i=0; i<n; i++){

        cin >> data;
        inorder.push_back(data);
    }

    cout << "Enter Preorder : ";
    vector<int> preorder;
    for(int i=0; i<n; i++){

        cin >> data;
        preorder.push_back(data);
    }

    // Create tree from inorder & preorder
    Node* root = treeFromInorderPreorder(inorder, preorder);

    cout << "Postorder Traversal : ";
    postorderTraversal(root);

    cout << endl;
    return 0;
}