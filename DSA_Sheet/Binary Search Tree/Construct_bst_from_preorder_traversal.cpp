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

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    cout << root->data << " ";

    printTree(root->right);
}

// Method 1 : Inserting a nodes [For all nodes]
// Time Complexity : O(n * h)  Space Complexity : O(h)
// Node* createTree(Node* root, int value){

//     if(root == NULL){

//         root = new Node(value);
//         return root;
//     }

//     if(root->data > value){

//         root->left = createTree(root->left, value);
//     }
//     else{

//         root->right = createTree(root->right, value);
//     }

//     return root;
// }

// Node* preorderToBST(vector<int> &preorder){

//     if(preorder.size() == 0) return NULL;

//     // Create BST from preorder vector
//     Node* root = NULL;

//     for(int i=0; i<preorder.size(); i++){

//         root = createTree(root, preorder[i]);
//     }

//     return root;
// }

// Method 2 : Creating tree from preorder & inorder
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// Node* createBSTHelper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index, unordered_map<int, int> &mp){

//     if(start > end) return NULL;

//     Node* root = new Node(preorder[index]);
    
//     int pos = mp[preorder[index]];
//     index++;

//     root->left = createBSTHelper(preorder, inorder, start, pos-1, index, mp);
//     root->right = createBSTHelper(preorder, inorder, pos+1, end, index, mp);

//     return root;
// }

// Node* createTree(vector<int> &preorder, vector<int> &inorder){

//     if(preorder.size() == 0) return NULL;

//     // Store index of Inorder
//     unordered_map<int, int> mp;

//     for(int i=0; i<inorder.size(); i++){

//         mp[inorder[i]] = i;
//     } 

//     // Now create the tree
//     int index = 0;
//     Node* root = createBSTHelper(preorder, inorder, 0, inorder.size()-1, index, mp);

//     return root;
// }

// Node* preorderToBST(vector<int> &preorder){

//     if(preorder.size() == 0) return NULL;

//     // Creating sorted vector
//     vector<int> inorder(preorder.begin(), preorder.end());

//     sort(inorder.begin(), inorder.end());


//     // Creating binary tree from preorder & inorder
//     Node* root = createTree(preorder, inorder);

//     return root;
// }

// Method 3 : Creating with keeping track of range [min , max]
// Time Complexity : O(n)  Space Complexity : O(n)
Node* createBSTHelper(vector<int> &preorder, int &index, int minValue, int maxValue){

    if(index >= preorder.size() || !(preorder[index] > minValue && preorder[index] < maxValue)) return NULL;

    Node* root = new Node(preorder[index]);
    index++;

    root->left = createBSTHelper(preorder, index, minValue, root->data);
    root->right = createBSTHelper(preorder, index, root->data, maxValue);

    return root;
}

Node* preorderToBST(vector<int> &preorder){

    if(preorder.size() == 0) return NULL;

    // Helper with range track
    int index = 0;
    Node* root = createBSTHelper(preorder, index, INT_MIN, INT_MAX);

    return root;
}


int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;


    cout << "Enter nodes data : ";
    vector<int> preorder;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        preorder.push_back(data);
    }

    // Construct BST from Preorder
    Node* root = preorderToBST(preorder);

    cout << "\nBinary Search Tree : ";
    printTree(root);

    cout << endl;
    return 0;
}   