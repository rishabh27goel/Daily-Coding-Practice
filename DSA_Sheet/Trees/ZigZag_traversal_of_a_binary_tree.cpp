#include <iostream>
#include <queue>
#include <vector>
#include <deque>
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

// Method 1 : Using Queue
// Time Complexity : O(n)   Space Complexity : O(n)
// void zigzagOrderTraversal(Node* root, vector<int> &zigzag){

//     if(root == NULL) return;

//     // Storing tree nodes in level order
//     bool level = true;
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){

//         int size = q.size();
//         vector<int> levelOrder;

//         while(size--){

//             Node* front = q.front();
//             q.pop();

//             levelOrder.push_back(front->data);

//             // Left Child
//             if(front->left != NULL){

//                 q.push(front->left);
//             }

//             // Right Child
//             if(front->right != NULL){

//                 q.push(front->right);
//             }
//         }

//         if(level == false){

//             // Reverse the levelOrder vector

//             int i = 0;
//             int j = levelOrder.size()-1;

//             while(i < j){

//                 swap(levelOrder[i], levelOrder[j]);
//                 i++;
//                 j--;
//             }
//         }

//         // // Store Level Order in Zigzag Vector
//         for(int i=0; i<levelOrder.size(); i++){

//             zigzag.push_back(levelOrder[i]);
//         }

//         level = !level;
//     }
// }

// Method 2 : Using Deque
// Time Complexity : O(n)   Space Complexity : O(n)
void zigzagOrderTraversal(Node* root, vector<int> &zigzag){

    if(root == NULL) return;

    // Using Deque for storing tree nodes
    int level = true;
    deque<Node*> dq;
    dq.push_back(root);

    while(!dq.empty()){

        int size = dq.size();

        while(size--){
            
            // Forward Level 
            if(level){

                Node* front = dq.front();
                dq.pop_front();

                zigzag.push_back(front->data);
                
                if(front->left != NULL){

                    dq.push_back(front->left);
                }

                if(front->right != NULL){

                    dq.push_back(front->right);
                }
            }
            // Backward Level
            else{

                Node* back = dq.back();
                dq.pop_back();

                zigzag.push_back(back->data);

                if(back->right != NULL){

                    dq.push_front(back->right);
                }

                if(back->left != NULL){

                    dq.push_front(back->left);
                }
            }
        }

        level = !level;
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);
    
    // ZigZag Order Traversal
    vector<int> zigzag;

    zigzagOrderTraversal(root, zigzag);

    cout << "Zigzag Order : ";
    for(int i=0; i<zigzag.size(); i++){

        cout << zigzag[i] << " ";
    }

    cout << endl;
    return 0;
}