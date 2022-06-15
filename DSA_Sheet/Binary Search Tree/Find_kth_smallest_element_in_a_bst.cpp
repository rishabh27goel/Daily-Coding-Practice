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

// Method 1 : Store the inorder 
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderHelper(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     inorderHelper(root->left, inorder);

//     inorder.push_back(root->data);

//     inorderHelper(root->right, inorder);
// }

// int kthSmallestElement(Node* root, int k){

//     if(root == NULL) return -1;

//     // Store the nodes
//     vector<int> inorder;

//     inorderHelper(root, inorder);

//     // Kth Smallest
//     if(k > inorder.size()) return -1;

//     int index = 0;
//     while(index < inorder.size()){

//         index++;
//         if(index == k)
//             break;
//     }

//     return inorder[index-1];
// }

// Method 2 : Using recursion method
// Time Complexity : O(n)  Space Complexity : O(n)
// void kthSmallestHelper(Node* root, int &k, int &output){

//     if(root == NULL) return;

//     kthSmallestHelper(root->left, k, output);

//     k--;
//     if(k == 0) output = root->data;
    
//     kthSmallestHelper(root->right, k, output);
// }

// int kthSmallestElement(Node* root, int k){

//     if(root == NULL) return -1;

//     int output = -1;

//     kthSmallestHelper(root, k, output);

//     return output;
// }

// Method 3 : Morris Traversal
// Time Complexity : O(n)  Space Complexity : O(1)
int kthSmallestElement(Node* root, int k){

    if(root == NULL) return -1;

    int output = -1;
    int count = 0;

    Node* itr = root;
    
    while(itr != NULL){

        if(itr->left == NULL){

            count++;

            if(count == k) 
                output = itr->data;

            itr = itr->right;
        }
        else{

            Node* pred = itr->left;

            while(pred->right != NULL && pred->right != itr){

                pred = pred->right;
            }

            if(pred->right == NULL){

                pred->right = itr;
                itr = itr->left;
            }
            else{

                count++;

                if(count == k) 
                    output = itr->data;

                pred->right = NULL;
                itr = itr->right;
            }
        }
    }

    return output;
}

int main()
{
    Node* root = NULL;

    // Create BST { 5 3 7 2 4 6 8 -1 } { 50 30 15 40 75 60 85 80 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    // Kth Smallest Element
    int element = kthSmallestElement(root, k);

    cout << "Kth Smallest Element : " << element;

    cout << endl;
    return 0;
}