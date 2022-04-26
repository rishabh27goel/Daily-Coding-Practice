#include <iostream>
#include <queue>
#include <map>
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


// Method 1 : Iterative Method (Using Separator)
// Time Complexity : O(n)  Space Complexity : O(n) 
// void levelOrderTraversal(Node* root){

//     if(root == NULL) return;

//     // Queue for storing nodes
//     queue<Node*> q;
//     q.push(root);

//     // Add Separator
//     q.push(NULL);

//     cout << "Level Order Traversal : \n";
//     while(!q.empty()){

//         Node* front = q.front();
//         q.pop();
        
//         // Separator is reached
//         if(front == NULL){

//             cout << endl;

//             // Is tree fully traversed or not [Add Separator]
//             // A level is over
//             if(!q.empty()){

//                 q.push(NULL);
//             }
//         }
//         else{

//             cout << front->data << " ";

//             // Left Child
//             if(front->left != NULL){

//                 q.push(front->left);
//             }

//             // Right Child
//             if(front->right != NULL){

//                 q.push(front->right);
//             }
//         }
//     }
// }


// Method 2 : Iterative Method
// Time Complexity : O(n)  Space Complexity : O(n) 
// void levelOrderTraversal(Node* root){

//     if(root == NULL) return;

//     // Queue for storing nodes
//     queue<Node*> q;
//     q.push(root);

//     cout << "Level Order Traversal : \n";
//     while(!q.empty()){

//         int lvl = q.size();

//         while(lvl--){

//             Node* front = q.front();
//             q.pop();

//             cout << front->data << " ";

//             // Left Child
//             if(front->left != NULL){

//                 q.push(front->left);
//             }

//             // Right Child
//             if(front->right != NULL){

//                 q.push(front->right);
//             }
//         }

//         cout << endl;
//     }
// }


// Method 3 : Recursive Method
// Time Complexity : O(n)  Space Complexity : O(n) + O(n) [recursive]
void levelOrderHelper(int level, Node* root, map<int, vector<int> > &mp){

    if(root == NULL) return;

    // Store by level in map
    mp[level].push_back(root->data);

    // Recursive Call to left and right
    levelOrderHelper(level+1, root->left, mp);
    levelOrderHelper(level+1, root->right, mp);
}

void levelOrderTraversal(Node* root){

    if(root == NULL) return;
    
    int level = 1;
    map<int, vector<int> > mp;

    levelOrderHelper(1, root, mp);

    cout << "Level Order Traversal : \n";
    map<int, vector<int> > :: iterator itr;
    for(itr=mp.begin(); itr != mp.end(); itr++){

        for(int i=0; i<itr->second.size(); i++){

            cout << itr->second[i] << " ";
        }  

        cout << endl;     
    }
}


int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Printing Level Order Traversal
    levelOrderTraversal(root);

    cout << endl;
    return 0;
}