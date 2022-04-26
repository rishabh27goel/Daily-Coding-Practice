#include <iostream>
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

    cout << "Enter node data : ";
    int data;
    cin >> data;
    cout << endl;

    // Leaf Node [Terminate]
    if(data == -1) return NULL;

    // Creating Node
    root = new Node(data);

    cout << "Enter left value of " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter right value of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

void printTree(Node* root){

    queue<Node*> q;
    q.push(root);

    cout << "Printing the tree : ";
    while(!q.empty()){

        // Get the node & Print it
        Node* front = q.front();
        q.pop();

        cout << front->data << " ";

        // Push its child in the queue
        if(front->left != NULL){

            q.push(front->left);
        }

        if(front->right != NULL){

            q.push(front->right);
        }
    }
}

int main()
{
    Node* root = NULL;

    // Creating a Tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    root = createTree(root);

    // Printing the tree [Level Order]
    printTree(root);

    cout << endl;
    return 0;
}