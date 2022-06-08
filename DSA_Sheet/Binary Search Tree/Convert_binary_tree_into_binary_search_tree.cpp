#include <iostream>
#include <vector>
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

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    cout << root->data << " ";

    printTree(root->right);
}

// Method 1 : Inorder storing & replacing 
// // Time Complexity : O(n)  Space Complexity : O(n)
// void fillInorder(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     fillInorder(root->left, inorder);

//     inorder.push_back(root->data);

//     fillInorder(root->right, inorder);
// }

// Node* replaceData(Node* root, vector<int> &inorder, int &index){

//     if(root == NULL) return root;

//     root->left = replaceData(root->left, inorder, index);

//     root->data = inorder[index];
//     index++;

//     root->right = replaceData(root->right, inorder, index);

//     return root;
// }

// Node* binaryTreeToBST(Node* root){

//     if(root == NULL) return root;

//     vector<int> inorder;

//     // Storing inorder
//     fillInorder(root, inorder);

//     // Sort the vector
//     sort(inorder.begin(), inorder.end());

//     // Replacing data in inorder way
//     int index = 0;
//     root = replaceData(root, inorder, index);

//     return root;
// }


// Method 2 : Minimum number of swaps approach
// Time Complexity : O(n)  Space Complexity : O(n)
void fillInorder(Node* root, vector<pair<Node*, int> > &inorder, int &index){

    if(root == NULL) return;

    fillInorder(root->left, inorder, index);
    
    inorder.push_back(make_pair(root, index));
    index++;

    fillInorder(root->right, inorder, index);
}

static bool comparePair(const pair<Node*, int> p1, const pair<Node*, int> p2){

    return p1.first->data < p2.first->data;
}

Node* binaryTreeToBST(Node* root){

    if(root == NULL) return root;

    // Store the inorder
    vector<pair<Node*, int> > inorder;
    int index = 0;

    fillInorder(root, inorder, index);

    // Sort the inorder pair
    sort(inorder.begin(), inorder.end(), comparePair);

    int i = 0;

    while(i < inorder.size()){

        if(i != inorder[i].second){

            swap(inorder[i].first->data, inorder[inorder[i].second].first->data);
            swap(inorder[i].first, inorder[inorder[i].second].first);
            swap(inorder[i].second, inorder[inorder[i].second].second);
        }

        if(i == inorder[i].second)
            i++;
    }

    return root;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);


    cout << "\nBinary Tree : ";
    printTree(root);

    // Binary Tree To BST
    root = binaryTreeToBST(root);

    cout << "\nBinary Search Tree : ";
    printTree(root);


    cout << endl;
    return 0;
}