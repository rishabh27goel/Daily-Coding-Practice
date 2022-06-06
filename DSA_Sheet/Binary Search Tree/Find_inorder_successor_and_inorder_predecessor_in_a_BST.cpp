#include <iostream>
#include <utility>
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

// Method 1 : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(1) 
// void findInorderSuccessorPredecessor(Node* root, int target, pair<Node*, Node*> &pr){

//     if(root == NULL) return;


//     if(root->data == target){

//         // Inorder Successor
//         if(root->left != NULL){

//             Node* pred = root->left;

//             while(pred->right != NULL){

//                 pred = pred->right;
//             }

//             pr.first = pred;
//         }

//         // Inorder Predecessor
//         if(root->right != NULL){

//             Node* succ = root->right;

//             while(succ->left != NULL){

//                 succ = succ->left;
//             }

//             pr.second = succ;
//         }
//     }
//     else if(root->data > target){

//         pr.second = root;
//         findInorderSuccessorPredecessor(root->left, target, pr);
//     }
//     else{

//         pr.first = root;
//         findInorderSuccessorPredecessor(root->right, target, pr);
//     }
// }

// Method 2 : Iterative Method 
// Time Complexity : O(n)  Space Complexity : O(1) 
void findInorderSuccessorPredecessor(Node* root, int target, pair<Node*, Node*> &pr){

    if(root == NULL) return;

    // Reach the target node
    Node* curr = root;

    while(curr != NULL){

        if(curr->data == target){

            break;
        }
        else if(curr->data > target){

            pr.second = curr;
            curr = curr->left;
        }
        else{

            pr.first = curr;
            curr = curr->right;
        }
    }

    if(curr == NULL) return;

    // Change Inorder Successor
    if(curr->left != NULL){

        Node* pred = curr->left;

        while(pred->right != NULL){

            pred = pred->right;
        }

        pr.first = pred;
    }

    // Change Inorder Predecessor
    if(curr->right != NULL){

        Node* succ = curr->right;

        while(succ->left != NULL){

            succ = succ->left;
        }

        pr.second = succ;
    }
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

    int target;
    cout << "Enter target node : ";
    cin >> target;

    pair<Node*, Node*> inorder = make_pair((Node*) NULL, (Node*) NULL);
    findInorderSuccessorPredecessor(root, target, inorder);

    if(inorder.first != NULL){

        cout << "\nInorder Successor : " << inorder.first->data;
    }

    if(inorder.second != NULL){

        cout << "\nInorder Predecessor : " << inorder.second->data;
    }


    cout << endl;
    return 0;
}