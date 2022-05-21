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

// Method 1 : Recursive Method 
// Time Complexity : O(n)   Space Complexity : O(n)
// bool checkMirrors(Node* root1, Node* root2){

//     if(root1 == NULL && root2 == NULL) 
//         return true;

//     else if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
//         return false; 

//     else{

//         if(root1->data == root2->data){

//             return checkMirrors(root1->left, root2->right) && checkMirrors(root1->right, root2->left);
//         }
//         else{

//             return false;
//         }
//     }
// }

// Method 2 : Iterative Method 
// Time Complexity : O(n)   Space Complexity : O(n)
bool checkMirrors(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL) 
        return true;

    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)) 
        return false;

    // Store the nodes in the queue
    queue< pair<Node*, Node*> > q;
    q.push(make_pair(root1, root2));

    while(!q.empty()){

        pair<Node*, Node*> pr = q.front();
        q.pop();

        Node* front1 = pr.first;
        Node* front2 = pr.second;

        if(front1->data != front2->data)
            return false;

        // Left Childs
        if(front1->left != NULL && front2->right != NULL){

            q.push(make_pair(front1->left, front2->right));
        }
        else if(front1->left != NULL && front2->right != NULL){

            return false;
        }

        // Right Childs
        if(front1->right != NULL && front2->left != NULL){

            q.push(make_pair(front1->right, front2->left));
        }
        else if(front1->right != NULL || front2->left != NULL){

            return false;
        }
    }

    return true;
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter Tree 1 data : ";
    root1 = createTree(root1);

    cout << "Enter Tree 2 data : ";
    root2 = createTree(root2);

    // Check for Mirror Trees
    bool check = checkMirrors(root1, root2);

    if(check){

        cout << "Trees are Mirrors !";
    }
    else{

        cout << "Trees are not Mirrors !";
    }

    cout << endl;
    return 0;
}