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

// Method 1 : Using Height Helper
// Time Complexity : O(n^2)  Space Complexity : O(n)
// int heightHelper(Node* root){

//     if(root == NULL) return 0;

//     int lH = heightHelper(root->left);
//     int rH = heightHelper(root->right);

//     return max(lH, rH) + 1;
// }

// bool checkBalanceTree(Node* root){

//     if(root == NULL) return true;

//     int lH = heightHelper(root->left);
//     int rH = heightHelper(root->right);

//     if(checkBalanceTree(root->left) == false || checkBalanceTree(root->right) == false|| abs(lH - rH) > 1){

//         return false;
//     }
//     else{

//         return true;
//     }
// }

// Method 2 : Single Function for checking & height
// Time Complexity : O(n)  Space Complexity : O(n)
int heightHelper(Node* root, bool &balance){

    if(root == NULL) return 0;

    int lH = heightHelper(root->left, balance);
    int rH = heightHelper(root->right, balance);

    if(abs(lH - rH) > 1){

        balance = false;
    }

    return max(lH, rH) + 1;
}

bool checkBalanceTree(Node* root){

    if(root == NULL) return true;

    bool balance = true;

    int height = heightHelper(root, balance);

    return balance;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter root data : ";
    root = createTree(root);

    // Check For Height Balanced Tree
    bool check = checkBalanceTree(root);

    if(check){

        cout << "Tree is Height Balanced !!";
    }
    else{

        cout << "Tree is not Height Balanced !!";
    }

    cout << endl;
    return 0;
}