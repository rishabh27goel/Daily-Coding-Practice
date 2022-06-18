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

Node* createTree(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createTree(root->left, value);
    }
    else{

        root->right = createTree(root->right, value);
    }

    return root;
}

// Method 1 : Separate min and max functions
// Time Complexity : O(n^2)  Space Complexity : O(h)
// void findMin(Node* root, int &value){

//     if(root == NULL) return;

//     if(root->data < value){

//         value = root->data;
//     }

//     findMin(root->left, value);
//     findMin(root->right, value);
// }

// void findMax(Node* root, int &value){

//     if(root == NULL) return;

//     if(root->data > value){

//         value = root->data;
//     }

//     findMax(root->left, value);
//     findMax(root->right, value);
// }

// bool checkBST(Node* root){

//     if(root == NULL) return true;

//     int leftMax = INT_MIN;
//     int rightMin = INT_MAX;

//     findMin(root->right, rightMin);
//     findMax(root->left, leftMax);

//     if(!(root->data > leftMax && root->data < rightMin)){

//         return false;
//     }

//     return checkBST(root->left) && checkBST(root->right);
// }

// Method 2 : Track min and max for each node
// Time Complexity : O(n)  Space Complexity : O(n)
// bool checkBSTHelper(Node* root, int minValue, int maxValue){

//     if(root == NULL) 
//         return true;

//     if(!(root->data > minValue && root->data < maxValue)) 
//         return false;


//     return checkBSTHelper(root->left, minValue, root->data) && checkBSTHelper(root->right, root->data, maxValue);
// }

// bool checkBST(Node* root){

//     return checkBSTHelper(root, INT_MIN, INT_MAX);
// }

// Method 3 : Inorder should be sorted 
// Time Complexity : O(n)  Space Complexity : O(n)
void checkBSTHelper(Node* root, Node* &prev, bool &check){

    if(root == NULL) return;

    checkBSTHelper(root->left, prev, check);

    if(prev != NULL && prev->data > root->data){

        check = false;
    }

    prev = root;

    checkBSTHelper(root->right, prev, check);
}

bool checkBST(Node* root){

    if(root == NULL) return true;

    bool check = true;
    Node* prev = NULL;

    checkBSTHelper(root, prev, check);

    return check;
}

int main()
{
    Node* root = NULL;

    // Create BST { 50 30 15 40 75 60 85 80 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    // Bst check for binary tree
    bool check = checkBST(root);

    if(check){

        cout << "Binary Tree is BST";
    }
    else{

        cout << "Binary Tree is not BST";
    }


    cout << endl;
    return 0;
}