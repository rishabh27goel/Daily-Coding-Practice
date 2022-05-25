#include <iostream>
#include <queue>
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

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Tracking the parent [Recursive Method]
// Time Complexity : O(n)  Space Complexity : O(n)
// Node* helperSibling(Node* root, Node* parent, int value){

//     // Empty Node
//     if(root == NULL) return NULL;

//     // If root is value node
//     if(root->data == value){

//         if(parent == NULL){

//             return NULL;
//         }
//         else{

//             if(parent->left == root){

//                 if(parent->right != NULL){

//                     return parent->right;
//                 }
//             }
//             else{

//                 if(parent->left != NULL){

//                     return parent->left;
//                 }
//             }

//             return NULL;
//         }
//     }

//     Node* leftChild = helperSibling(root->left, root, value);
//     Node* rightChild = helperSibling(root->right, root, value);

//     if(leftChild != NULL) return leftChild;
//     if(rightChild != NULL) return rightChild;
    
//     return NULL;
// }

// Node* findSiblingOfNode(Node* root, int value){

//     if(root == NULL) return NULL;

//     return helperSibling(root, NULL, value);
// }

// Method 2 : Tracking the parent [Iterative Method]
// Time Complexity : O(n)  Space Complexity : O(n)
Node* findSiblingOfNode(Node* root, int value){

    if(root == NULL) return NULL;

    // Storing the nodes { node , parent }
    queue <pair<Node*, Node*> > q;  
    q.push(make_pair(root, (Node*) NULL));

    while(!q.empty()){

        int size = q.size();
        
        while(size--){

            pair<Node*, Node*> pr = q.front();
            q.pop();

            Node* front = pr.first;
            Node* parent = pr.second;

            if(front->data == value){

                if(parent != NULL){

                    if(parent->left == front && parent->right != NULL){

                        return parent->right;
                    }

                    if(parent->right == front && parent->left != NULL){

                        return parent->left;
                    }
                }

                return NULL;
            }

            // Left Child
            if(front->left != NULL){

                q.push(make_pair(front->left, front));
            }

            // Right Child
            if(front->right != NULL){

                q.push(make_pair(front->right, front));
            }
        }
    }

    return NULL;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);


    int value;
    cout << "Enter Input Node : ";
    cin >> value;


    // Find the Sibling of Node
    Node* sibling = findSiblingOfNode(root, value);

    if(sibling == NULL){

        cout << "Sibling does not exits !";
    }
    else{

        cout << "Sibling is : " << sibling->data;
    }

    cout << endl;
    return 0;
}