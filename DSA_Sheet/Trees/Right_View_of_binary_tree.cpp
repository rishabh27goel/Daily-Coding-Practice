#include <iostream>
#include <map>
#include <queue>
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

// Method 1 : Recursive Method [Using Map] 
// Time Complexity : O(n * logn)   Space Complexity : O(n)
// void rightViewHelper(Node* root, int level, map<int, int> &mp){

//     if(root == NULL) return;

//     if(mp.find(level) == mp.end()){

//         mp[level] = root->data;
//     }

//     rightViewHelper(root->right, level + 1, mp);
//     rightViewHelper(root->left, level + 1, mp);
// }

// void rightViewBinaryTree(Node* root, vector<int> &rightView){

//     if(root == NULL) return;

//     // For getting the one element from each level
//     int level = 1;
//     map<int, int> mp;

//     rightViewHelper(root, level, mp);

//     // Get the Right View from the map
//     map<int, int> :: iterator itr;

//     for(itr=mp.begin(); itr != mp.end(); itr++){

//         rightView.push_back(itr->second);
//     }
// }

// Method 2 : Recursive Method [Only Recursive Stack Space] 
// Time Complexity : O(n)  Space Complexity : O(n)
// void rightViewHelper(Node* root, int &maxLevel, int level, vector<int> &rightView){

//     if(root == NULL) return;

//     if(maxLevel == level){

//         rightView.push_back(root->data);
//         maxLevel += 1;
//     }

//     rightViewHelper(root->right, maxLevel, level + 1, rightView);
//     rightViewHelper(root->left, maxLevel, level + 1, rightView);
// }

// void rightViewBinaryTree(Node* root, vector<int> &rightView){

//     if(root == NULL) return;

//     int maxLevel = 1;
//     int level = 1;

//     rightViewHelper(root, maxLevel, level, rightView);
// }

// Method 3 : Iterative Method [Using Queue] 
// Time Complexity : O(n)  Space Complexity : O(n)
// void rightViewBinaryTree(Node* root, vector<int> &rightView){

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

//             if(count == lvl - 1){

//                 rightView.push_back(front->data);
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
void rightViewBinaryTree(Node* root, vector<int> &rightView){

    if(root == NULL) return;

    // For storing root nodes
    queue<Node*> q;
    q.push(root);

    // Add a separator
    q.push(NULL);

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        // We have front as element before separator
        if(!q.empty() && q.front() == NULL){

            rightView.push_back(front->data);
        }

        if(front == NULL){

            // Check for queue [If something is present]
            if(!q.empty()){

                // Add new Separator
                q.push(NULL);
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

    // Right View Of Binary Tree
    vector<int> rightView;

    rightViewBinaryTree(root, rightView);

    cout << "Right View : ";
    for(int i=0; i<rightView.size(); i++){

        cout << rightView[i] << " ";
    }

    cout << endl;
    return 0;
}