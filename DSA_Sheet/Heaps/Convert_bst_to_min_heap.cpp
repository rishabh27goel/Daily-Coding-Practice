#include <iostream>
#include <vector>
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

Node* createTree(Node* root, int data){

    if(root == NULL){

        root = new Node(data);
        return root;
    }

    if(root->data > data){

        root->left = createTree(root->left, data);
    }
    else{

        root->right = createTree(root->right, data);
    }

    return root;
}

// Method : Storing inorder
// Time Complexity : O(n)  Space Complexity : O(n)
void inorderTraversal(Node* root, vector <int> &inorder){

    if(root == NULL) return;

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

void replaceData(Node* root, int &index, vector <int> &inorder){

    if(root == NULL || index >= inorder.size()) return;

    root->data = inorder[index];
    index++;

    replaceData(root->left, index, inorder);
    replaceData(root->right, index, inorder);
}

Node* convertToMinHeap(Node* root){

    if(root == NULL) return root;

    // Storing the inorder
    vector <int> inorder;
    inorderTraversal(root, inorder);

    // Replacing the nodes data with preorder
    int index = 0;
    replaceData(root, index, inorder);

    return root;
}

int main()
{
    Node* root = NULL;

    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    // Convert BST to Min Heap
    Node* newNode = convertToMinHeap(root);

    cout << "Modified Tree : ";
    printTree(newNode);

    cout << endl;
    return 0;
}