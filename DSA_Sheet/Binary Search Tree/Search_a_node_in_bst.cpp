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

Node* createBST(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createBST(root->left, value);
    }
    else{

        root->right = createBST(root->right, value);
    }

    return root;
}

// Method 1 : Recursive Method
// Time Complexity : O(h)  Space Complexity : O(h)
// bool findValueInBST(Node* root, int target){

//     if(root == NULL) return false;

//     if(root->data == target){

//         return true;
//     }
//     else if(root->data > target){

//         return findValueInBST(root->left, target);
//     }
//     else{

//         return findValueInBST(root->right, target);
//     }

//     return false;
// }


// Method 2 : Iterative Method
// Time Complexity : O(h)  Space Complexity : O(h)
bool findValueInBST(Node* root, int target){

    if(root == NULL) return false;

    // Start from root to reach target
    Node* curr = root;

    while(curr != NULL){

        if(curr->data == target){

            return true;
        }
        else if(curr->data > target){

            curr = curr->left;
        }
        else{

            curr = curr->right;
        }
    }

    return false;
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
    
        root = createBST(root, data);
    }

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Search a node in BST
    bool found = findValueInBST(root, target);

    if(found){

        cout << "Target found !";
    }
    else{

        cout << "Target not found !";
    }

    cout << endl;
    return 0;
}