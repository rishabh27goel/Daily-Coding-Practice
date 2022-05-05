#include <iostream>
#include <vector>
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

Node* createTree(Node* root, int index, vector<int> &arr){

    // If index is out of range
    if(index >= arr.size()) return NULL;
    if(arr[index] == -1) return NULL;

    root = new Node(arr[index]);

    // Recursive Call to left & right child
    root->left = createTree(root->left, 2*index + 1, arr);
    root->right = createTree(root->right, 2*index + 2, arr);

    return root;
}

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    cout << root->data << " ";

    printTree(root->right);
}

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    cout << "Enter nodes data : ";
    vector<int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    Node* root = NULL;

    // Creating the tree
    root = createTree(root, 0, arr);

    cout << "\nPrinting the tree : ";
    printTree(root);

    cout << endl;
    return 0;
}