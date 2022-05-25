#include <iostream>
#include <vector>
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

// Method 1 : Storing Level in Vector [Iterative Method]
// Time Complexity : O(n)  Space Complexity : O(n)
// vector<int> printCousinsOfNode(Node* root, int value){

//     vector<int> output;
//     if(root == NULL) return output;

//     // Storing the nodes
//     queue< pair<Node*, Node*> > q;
//     q.push(make_pair(root, (Node*) NULL));

//     while(!q.empty()){

//         Node* matchParent = NULL;
//         vector< pair<Node*, Node*> > level;
//         int size = q.size();

//         while(size--){

//             pair<Node*, Node*> pr = q.front();
//             q.pop();

//             Node* front = pr.first;
//             Node* parent = pr.second;

//             // Store the Level in vector
//             level.push_back(pr);

//             // Check for Match
//             if(front->data == value)
//                 matchParent = parent;


//             // Left Child
//             if(front->left != NULL){

//                 q.push(make_pair(front->left, front));
//             }

//             // Right Child
//             if(front->right != NULL){

//                 q.push(make_pair(front->right, front));
//             }
//         }

//         if(matchParent != NULL){

//             for(int i=0; i<level.size(); i++){

//                 if(level[i].second != matchParent){

//                     output.push_back(level[i].first->data);
//                 }
//             }

//             return output;
//         }

//     }

//     return output;
// }


// Method 2 : Using Queue Only [Iterative Method]
// Time Complexity : O(n)  Space Complexity : O(n)
vector<int> printCousinsOfNode(Node* root, int value){

    vector<int> output;
    if(root == NULL) return output;

    // Storing the nodes [Only Parent]
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){

        bool matchFound = false;
        int size = q.size();

        while(size--){

            Node* front = q.front();
            q.pop();

            // Check from Parent [left & right of the node]
            if((front->left != NULL && front->left->data == value) || (front->right != NULL && front->right->data == value)){

                matchFound = true;
                continue;
            }

            // Left Child
            if(front->left != NULL){

                q.push(front->left);
            }

            // Right Child
            if(front->right != NULL){

                q.push(front->right);
            }
        }

        // If we find the match [Break at current state of Queue]
        if(matchFound)
            break;
    }

    // Check for Cousins
    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        output.push_back(front->data);
    }

    return output;
}


int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    int value;
    cout << "Enter Input Data : ";
    cin >> value;

    // Print Cousins Of Node
    vector<int> cousins = printCousinsOfNode(root, value);

    if(cousins.size() != 0){

        cout << "Cousins of the Node : ";
        for(int i=0; i<cousins.size(); i++){

            cout << cousins[i] << " ";
        }
    }
    else{

        cout << "No Cousins Exists !";
    }

    cout << endl;
    return 0;
}