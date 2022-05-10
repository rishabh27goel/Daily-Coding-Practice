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

// Method 1 : Using Sum Helper 
// Time Complexity : O(n^2)  Space Complexity : O(n)
// int sumHelper(Node* root){

//     if(root == NULL) return 0;

//     // Special Case for leaf nodes
//     if(root->left == NULL && root->right == NULL) return root->data;

//     return root->data + sumHelper(root->left) + sumHelper(root->right);
// }

// bool checkSumTree(Node* root){

//     // Empty tree is a sum tree
//     if(root == NULL) return true;
    
//     // Sum tree logic does not apply for leaf nodes [But it is also true]
//     if(root->left == NULL && root->right == NULL) return true;

//     int lS = sumHelper(root->left);
//     int rS = sumHelper(root->right);


//     if(checkSumTree(root->left) == false || checkSumTree(root->right) == false || root->data != (lS + rS))
//         return false;
    
//     return true;
// }

// Method 2 : Single Function for checking & getting sum
// Time Complexity : O(n)  Space Complexity : O(n)
int sumHelper(Node* root, bool &checkSum){

    // Empty Tree
    if(root == NULL) return 0;

    // Leaf Nodes
    if(root->left == NULL && root->right == NULL) return root->data;

    int lS = sumHelper(root->left, checkSum);
    int rS = sumHelper(root->right, checkSum);

    if(root->data != (lS + rS)){

        checkSum = false;
    }

    return root->data + lS + rS;
}

bool checkSumTree(Node* root){

    if(root == NULL) return true;

    bool checkSum = true;

    int sum = sumHelper(root, checkSum);

    return checkSum;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Check For Sum Tree
    bool check = checkSumTree(root);

    if(check){

        cout << "Binary Tree is also a Sum Tree !!";
    }
    else{

        cout << "Binary Tree is not a Sum Tree !!";
    }

    cout << endl;
    return 0;
}