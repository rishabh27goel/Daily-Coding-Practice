#include <iostream>
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

Node* createBST(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }
    
    // Iterating Left & Right Child
    if(root->data > value){

        root->left = createBST(root->left, value);
    }
    else{

        root->right = createBST(root->right, value);
    }

    return root;
}

int main()
{
    Node* root = NULL;

    int data = 0;
    cout << "Enter nodes data : ";
    
    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createBST(root, data);
    }

    cout << "Inorder Of Tree : ";
    printTree(root);


    cout << endl;
    return 0;
}