#include <iostream>
#include <stack>
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

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(n)
// void postorderTraversal(Node* root, vector<int> &postorder){

//     if(root == NULL) return;

//     // Left Node : Right Node : Root Node
//     postorderTraversal(root->left, postorder);
//     postorderTraversal(root->right, postorder);

//     postorder.push_back(root->data);
// }

// Method 2 : Iterative Method [Using Two Stacks]
// Time Complexity : O(n)  Space Complexity : O(n)
// void postorderTraversal(Node* root, vector<int> &postorder){

//     if(root == NULL) return;

//     // Storing the tree nodes
//     stack<Node*> helper;
//     helper.push(root);

//     stack<Node*> st;

//     while(!helper.empty()){

//         Node* top = helper.top();
//         helper.pop();

//         // Store popped items to main stack
//         st.push(top);

//         // Iterate left then right nodes of top
//         if(top->left != NULL){

//             helper.push(top->left);
//         }

//         if(top->right != NULL){

//             helper.push(top->right);
//         }
//     }

//     // After the end of loop we have inorder in the main stack
//     while(!st.empty()){

//         postorder.push_back(st.top()->data);
//         st.pop();
//     }
// }

// Method 3 : Iterative Method [Using Single Stacks]
// Time Complexity : O(n)  Space Complexity : O(n)
// void postorderTraversal(Node* root, vector<int> &postorder){

//     if(root == NULL) return;

//     // Storing the tree nodes
//     stack<Node*> st;
//     Node* itr = root;

//     while(!st.empty() || itr != NULL){

//         while(itr != NULL){

//             // Store the right child and then current node
//             if(itr->right != NULL){

//                 st.push(itr->right);
//             }

//             // Push current node
//             st.push(itr);

//             itr = itr->left;
//         }

//         // Get the top element
//         itr = st.top();
//         st.pop();

//         if(!st.empty() && itr->right == st.top()){

//             st.pop();
//             st.push(itr);
//             itr = itr->right;
//         }
//         else{

//             postorder.push_back(itr->data);
//             itr = NULL; 
//         }
//     }
// }

// Method 4 : Using Morris Traversal 
// Time Complexity : O(n)  Space Complexity : O(1)
void postorderTraversal(Node* root, vector<int> &postorder){

    if(root == NULL) return;

    Node* current = root;
    Node* pred;

    while(current != NULL){

        // Till no right present
        if(current->right == NULL){

            postorder.push_back(current->data);

            // Go to left [edge we created]
            current = current->left;
        }
        else{
            
            // Get the postorder predecessor of current
            pred = current->right;

            while(pred->left != NULL && pred->left != current){

                pred = pred->left;
            }   

            // Create connection with current to iterate later
            if(pred->left == NULL){

                postorder.push_back(current->data);
                pred->left = current;
                current = current->right;
            }
            else{

                // Restore original tree
                pred->left = NULL;
                current = current->left;
            }
        }
    }

    // At the end reverse postorder vector
    int i=0;
    int j=postorder.size()-1;

    while(i < j){

        swap(postorder[i], postorder[j]);
        i++;
        j--;
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : "; 
    root = createTree(root);

    // Postorder Traversal
    vector<int> postorder;

    postorderTraversal(root, postorder);

    cout << "Postorder Traversal : ";
    for(int i=0; i<postorder.size(); i++){

        cout << postorder[i] << " ";
    }

    cout << endl;
    return 0;
}