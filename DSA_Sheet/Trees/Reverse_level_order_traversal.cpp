#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <deque>
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

    // Leaf Node
    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Recursive Method [Using Map]
// Time Complexity : O(n)  Space Complexity : O(n) + O(n) [Recursive Call Stack]
// void reverseLevelOrderTraversalHelper(int level, Node* root, map<int, vector<int> > &mp){

//     if(root == NULL) return;

//     mp[level].push_back(root->data);

//     reverseLevelOrderTraversalHelper(level+1, root->left, mp);
//     reverseLevelOrderTraversalHelper(level+1, root->right, mp);
// }

// void reverseLevelOrderTraversal(Node* root){ 

//     if(root == NULL) return;

//     int level = 1;
//     map<int, vector<int> > mp;
    
//     reverseLevelOrderTraversalHelper(level, root, mp);

//     cout << "Reverse Level Order Traversal : \n";
//     map<int, vector<int> > :: iterator itr = --mp.end();

//     for(; itr != mp.begin(); --itr){

//         for(int i=0; i<itr->second.size(); i++){

//             cout << itr->second[i] << " ";
//         }

//         cout << endl;
//     }

//     for(int i=0; i<itr->second.size(); i++){

//         cout << itr->second[i] << " ";
//     }
// }


// Method 2 : Using Queue & Stack [Iterative Method]
// Time Complexity : O(n)  Space Complexity : O(n)
void reverseLevelOrderTraversal(Node* root){ 

    if(root == NULL) return;

    // For iterating in the level order
    queue<Node*> q;
    q.push(root);

    // For reversing level order
    stack<Node*> st;

    while(!q.empty()){

        int level = q.size();

        while(level--){

            Node* front = q.front();
            q.pop();

            if(front->right != NULL){

                q.push(front->right);
            }

            if(front->left != NULL){

                q.push(front->left);
            }

            st.push(front);
        }

        // Add a separator in the stack after each level
        st.push(NULL);
    }

    cout << "Reverse Level Order Traversal : ";
    while(!st.empty()){

        Node* top = st.top();
        st.pop();

        // If it is a separator
        if(top == NULL){

            cout << endl;
        }
        else{

            cout << top->data << " ";
        }
    }
}


int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter the data : ";
    root = createTree(root);

    // Reverse Level Order Traversal
    reverseLevelOrderTraversal(root);

    cout << endl;
    return 0;
}