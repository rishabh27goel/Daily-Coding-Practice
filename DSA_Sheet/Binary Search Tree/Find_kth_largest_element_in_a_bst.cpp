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

// Method 1 : Store the nodes [Reverse Inorder]
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderHelper(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     inorderHelper(root->right, inorder);

//     inorder.push_back(root->data);

//     inorderHelper(root->left, inorder);
// }

// int kthLargestElement(Node* root, int k){

//     if(root == NULL || k == 0) return -1;

//     // Store the nodes
//     vector<int> inorder;

//     inorderHelper(root, inorder);

//     // Kth Largest
//     if(k > inorder.size()) return -1;
//     int index = 0;

//     while(index < inorder.size()){

//         index++;

//         if(index == k) break;
//     }

//     return inorder[index-1];
// }

// Method 2 : Recursive Method [Reverse Inorder]
// Time Complexity : O(n)  Space Complexity : O(n)
// void kthLargestHelper(Node* root, int &k, int &output){

//     if(root == NULL) return;

//     kthLargestHelper(root->right, k, output);

//     k--;
//     if(k == 0)  output = root->data;

//     kthLargestHelper(root->left, k, output);
// }

// int kthLargestElement(Node* root, int k){

//     if(root == NULL || k == 0) return -1;

//     int output = -1;

//     kthLargestHelper(root, k, output);

//     return output;
// }

// Method 3 : Morris Traversal [Reverse Inorder]
// Time Complexity : O(n)  Space Complexity : O(1)
int kthLargestElement(Node* root, int k){

    if(root == NULL) return -1;

    int output = -1; 
    int count = 0;

    Node* itr = root;

    while(itr != NULL){

        if(itr->right == NULL){

            count++;

            if(count == k)  
                output = itr->data;

            itr = itr->left;
        }
        else{

            Node* succ = itr->right;

            while(succ->left != NULL && succ->left != itr){

                succ = succ->left;
            }

            if(succ->left == NULL){

                succ->left = itr;
                itr = itr->right;
            }
            else{

                count++;

                if(count == k)  
                    output = itr->data;

                succ->left = NULL;
                itr = itr->left;
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

    // Kth Largest Element
    int element = kthLargestElement(root, k);

    cout << "Kth Largest Element : " << element;

    cout << endl;
    return 0;
}