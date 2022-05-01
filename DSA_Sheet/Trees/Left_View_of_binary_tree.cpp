#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

// Method 1 : Recursive Method [Using Map] 
// Time Complexity : O(n)  Space Complexity : O(n)
// void leftViewHelper(Node* root, int level, map<int, int> &mp){

//     if(root == NULL) return;

//     // Check if level is present in the map
//     if(mp.find(level) == mp.end()){

//         mp[level] = root->data;
//     }

//     leftViewHelper(root->left, level + 1, mp);
//     leftViewHelper(root->right, level + 1, mp);
// }

// void leftViewBinaryTree(Node* root, vector<int> &leftView){

//     if(root == NULL) return;

//     // For getting the one element from each level
//     int level = 1;
//     map<int , int> mp;

//     leftViewHelper(root, level, mp);

//     // Get the Left View from the map
//     map<int, int> :: iterator itr;

//     for(itr=mp.begin(); itr != mp.end(); itr++){

//         leftView.push_back(itr->second);
//     }
// }

// Method 2 : Recursive Method [Only Recursive Stack Space] 
// Time Complexity : O(n)  Space Complexity : O(n)
// void leftViewHelper(Node* root, int level, int &maxLevel, vector<int> &leftView){

//     if(root == NULL) return;

//     if(maxLevel == level){

//         leftView.push_back(root->data);
//         maxLevel += 1;
//     }

//     leftViewHelper(root->left, level + 1, maxLevel, leftView);
//     leftViewHelper(root->right, level + 1, maxLevel, leftView);
// }

// void leftViewBinaryTree(Node* root, vector<int> &leftView){

//     if(root == NULL) return;

//     int level = 1;
//     int maxLevel = 1;

//     leftViewHelper(root, level, maxLevel, leftView);
// }

// Method 3 : Iterative Method [Using Queue] 
// Time Complexity : O(n)  Space Complexity : O(n)
// void leftViewBinaryTree(Node* root, vector<int> &leftView){

//     if(root == NULL) return;

//     // For storing root nodes
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){

//         int count = 0;
//         int lvl = q.size();

//         while(count < lvl){

//             Node* front = q.front();
//             q.pop();

//             if(count == 0){

//                 leftView.push_back(front->data);
//             }

//             if(front->left != NULL){

//                 q.push(front->left);
//             }

//             if(front->right != NULL){

//                 q.push(front->right);
//             }

//             count++;
//         }
//     }
// }

// Method 4 : Iterative Method [Using Queue with separator] 
// Time Complexity : O(n)  Space Complexity : O(n)
void leftViewBinaryTree(Node* root, vector<int> &leftView){

    if(root == NULL) return;

    // For storing root nodes
    queue<Node*> q;
    q.push(root);

    // Add a separator
    q.push(NULL);

    leftView.push_back(root->data);

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        // We have a separator
        if(front == NULL){

            if(!q.empty()){

                // Add new Separator
                q.push(NULL);
                leftView.push_back(q.front()->data);
            }
        }
        else{

            if(front->left != NULL){

                q.push(front->left);
            }

            if(front->right != NULL){

                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Left View Of Binary Tree
    vector<int> leftView;

    leftViewBinaryTree(root, leftView);

    cout << "Left View : ";
    for(int i=0; i<leftView.size(); i++){

        cout << leftView[i] << " ";
    }

    cout << endl;
    return 0;
}