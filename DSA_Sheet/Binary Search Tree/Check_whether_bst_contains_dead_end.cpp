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

// Method 1 : Storing Inorder 
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderHelper(Node* root, vector <Node*> &inorder){

//     if(root == NULL) return;

//     inorderHelper(root->left, inorder);

//     inorder.push_back(root);

//     inorderHelper(root->right, inorder);
// }

// bool checkDeadEnd(Node* root){

//     if(root == NULL) return false;

//     // Store the inorder nodes
//     vector <Node*> inorder;

//     inorderHelper(root, inorder);


//     // Check for Dead End
//     int minValue = 0;

//     for(int i=0; i<inorder.size()-1; i++){

//         // If node is leaf node
//         if(inorder[i]->left == NULL && inorder[i]->right == NULL){

//             if((inorder[i]->data == minValue + 1) && (inorder[i]->data == inorder[i+1]->data - 1))
//                 return true;
//         }

//         minValue = inorder[i]->data;
//     }

//     return false;
// }

// Method 2 : Min & Max value track 
// Time Complexity : O(n)  Space Complexity : O(n)
bool checkDeadEndHelper(Node* root, int minValue, int maxValue){

    if(root == NULL) 
        return false;

    if((root->data == minValue + 1) && (root->data == maxValue - 1))
        return true;


    return checkDeadEndHelper(root->left, minValue, root->data) || checkDeadEndHelper(root->right, root->data, maxValue);
}

bool checkDeadEnd(Node* root){

    if(root == NULL) return false;

    return checkDeadEndHelper(root, 0, INT_MAX);
}

int main()
{
    Node* root = NULL;

    // Create BST { 8 5 9 2 7 1 -1 }   { 8 7 10 2 13 -1 }
    cout << "Enter nodes data : "; 
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    // Check for Dead End
    bool check = checkDeadEnd(root);

    if(check){

        cout << "Dead End Present !";
    }
    else{

        cout << "No Dead End Exists !";
    }


    cout << endl;
    return 0;
}