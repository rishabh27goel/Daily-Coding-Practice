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

void preorderTraversal(Node* root){

    if(root == NULL) return;

    cout << root->data << " ";

    preorderTraversal(root->left); 
    preorderTraversal(root->right);
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

// Node* createTreeHelper(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end){

//     if(start > end) return NULL;

//     Node* root = new Node(postorder[index]);

//     int find = findIndex(inorder, postorder[index], start, end);
//     index = index - 1;

//     // Right Call First
//     root->right = createTreeHelper(inorder, postorder, index, find+1, end);

//     // Left Call Second
//     root->left = createTreeHelper(inorder, postorder, index, start, find-1);

//     return root;
// }

// Node* treeFromInorderPostorder(vector<int> &inorder, vector<int> &postorder){

//     if(inorder.size() == 0) return NULL;

//     int index = postorder.size()-1;
//     Node* root = createTreeHelper(inorder, postorder, index, 0, inorder.size()-1);

//     return root;
// }

// Method 2 : Recursive Optimized [Using Map]
// Time Complexity : O(n)  Space Complexity : O(n)
Node* createTreeHelper(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, unordered_map<int, int> &helperMap){

    if(start > end) return NULL;

    Node* root = new Node(postorder[index]);

    int find = helperMap[postorder[index]];
    index = index - 1;

    // Right Call First
    root->right = createTreeHelper(inorder, postorder, index, find+1, end, helperMap);

    // Left Call Second
    root->left = createTreeHelper(inorder, postorder, index, start, find-1, helperMap);

    return root;
}

Node* treeFromInorderPostorder(vector<int> &inorder, vector<int> &postorder){

    if(inorder.size() == 0) return NULL;

    // Helper Map
    unordered_map<int, int> helperMap;
    
    for(int i=0; i<inorder.size(); i++){

        helperMap[inorder[i]] = i;
    }

    int index = postorder.size()-1;
    Node* root = createTreeHelper(inorder, postorder, index, 0, inorder.size()-1, helperMap);

    return root;
}

int main()
{
    cout << "Enter size of tree : ";
    int n;
    cin >> n;

    int data;
    cout << "Enter Inorder : ";
    vector<int> inorder;

    for(int i=0; i<n; i++){

        cin >> data;
        inorder.push_back(data);
    }

    cout << "Enter Postorder : ";
    vector<int> postorder;

    for(int i=0; i<n; i++){

        cin >> data;
        postorder.push_back(data);
    }

    // Create tree from inorder & postorder
    Node* root = treeFromInorderPostorder(inorder, postorder);

    cout << "Preorder Traversal : ";
    preorderTraversal(root);

    cout << endl;
    return 0;
}