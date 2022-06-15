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

// Method 1 : Storing nodes in inorder
// Time Complexity : O(n)  Space Complexity : O(n)
// void fillInorder(Node* root, vector <Node*> &inorder){

//     if(root == NULL) return;

//     fillInorder(root->left, inorder);

//     inorder.push_back(root);

//     fillInorder(root->right, inorder);
// }

// Node* flattenBST(Node* root){

//     if(root == NULL) return root;

//     // Store the nodes in inorder
//     vector <Node*> inorder;

//     fillInorder(root, inorder);

//     // Create the list 
//     Node* head = NULL;
//     Node* tail = NULL;

//     for(int i=0; i<inorder.size(); i++){

//         inorder[i]->left = NULL;

//         if(head == NULL){

//             head = inorder[i];
//         }
//         else{

//             tail->right = inorder[i];
//         }

//         tail = inorder[i];
//     }

//     return head;
// }

// Method 2 : Using Inorder Traversal [Without vector]
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderHelper(Node* root, Node* &head, Node* &tail){

//     if(root == NULL) return;

//     inorderHelper(root->left, head, tail);

//     root->left = NULL;

//     if(head == NULL){

//         head = root;
//     }
//     else{

//         tail->right = root;
//     }

//     tail = root;

//     inorderHelper(root->right, head, tail);
// }

// Node* flattenBST(Node* root){

//     if(root == NULL) return root;

//     // Create list using inorder
//     Node* head = NULL;
//     Node* tail = NULL;

//     inorderHelper(root, head, tail);

//     return head;
// }

// Method 3 : Morris Traversal
// Time Complexity : O(n)  Space Complexity : O(1)
Node* flattenBST(Node* root){

    if(root == NULL) return root;

    Node* head = NULL;
    Node* tail = NULL;
    Node* itr = root;

    while(itr != NULL){

        if(itr->left == NULL){

            if(head == NULL){

                head = itr;
            }
            else{

                tail->right = itr;
            }

            tail = itr;
            itr = itr->right;
        }
        else{

            // Get the Inorder Predecessor
            Node* pred = itr->left;

            while(pred->right != NULL && pred->right != itr){

                pred = pred->right;
            }

            if(pred->right == NULL){

                pred->right = itr;

                Node* leftStore = itr->left;
                itr->left = NULL;
                
                itr = leftStore;
            }
            else{

                if(head == NULL){

                    head = itr;
                }
                else{

                    tail->right = itr;
                }

                tail = itr;

                pred->right = NULL;
                itr = itr->right;
            }
        }
    }

    return head;
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

    // Flatten BST
    Node* curr = flattenBST(root);

    cout << "Linked List : ";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->right;
    }

    cout << endl;
    return 0;
}