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

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method : Recursive Method [Two calls to left & right Child]
bool checkIsomorphicTree(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL) 
        return true;

    else if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) || (root1->data != root2->data))
        return false;

    // Identical Check
    bool leftChild1 = checkIsomorphicTree(root1->left, root2->left);
    bool rightChild1 = checkIsomorphicTree(root1->right, root2->left);
    
    // Mirror Check
    bool leftChild2 = checkIsomorphicTree(root1->left, root2->right);
    bool rightChild2 = checkIsomorphicTree(root1->right, root2->right);

    // If we find the match for leftchild 1
    if((leftChild1 && rightChild1) || (leftChild1 && rightChild2))
        return true;

    // If we find the match for leftchild 2
    if((leftChild2 && rightChild1) || (leftChild2 && rightChild2))
        return true;

    return false;
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL; 

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter Tree 1 data : ";
    root1 = createTree(root1);

    cout << "Enter Tree 2 data : ";
    root2 = createTree(root2);

    // Check for Isomorphic Tree
    bool check = checkIsomorphicTree(root1, root2);

    if(check){

        cout << "Trees are Isomorphic !";
    }
    else{

        cout << "Trees are not Isomorphic !";
    }

    cout << endl;
    return 0;
}