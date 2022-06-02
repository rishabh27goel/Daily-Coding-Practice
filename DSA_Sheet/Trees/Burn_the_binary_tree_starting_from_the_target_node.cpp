#include <iostream>
#include <queue>
#include <unordered_map>
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

// Method : Step based approach [Using Map & Queue]
// Time Complexity : O(n)  Space Complexity : O(n)
void fillParentMap(Node* root, Node* parent, unordered_map<Node*, Node*> &mp){

    if(root == NULL) return;

    mp[root] = parent;

    fillParentMap(root->left, root, mp);
    fillParentMap(root->right, root, mp);
}

Node* findTargetNode(Node* root, int target){

    if(root == NULL) 
        return NULL;

    if(root->data == target) 
        return root;

    Node* leftChild = findTargetNode(root->left, target);
    Node* rightChild = findTargetNode(root->right, target);

    if(leftChild != NULL && rightChild == NULL){

        return leftChild;
    }
    else if(leftChild == NULL && rightChild != NULL){

        return rightChild;
    }

    return NULL;
}

int burnBinaryTree(Node* root, int target){

    if(root == NULL) return 0;

    // 1. Get the parent of each node
    unordered_map<Node*, Node*> mp;

    fillParentMap(root, (Node*)NULL, mp);


    // 2. Find the target node
    Node* targetNode = findTargetNode(root, target);

    if(targetNode == NULL) return 0;


    // 3. Find time using queue
    unordered_map <Node*, bool> visited;
    int timeTaken = 0;

    queue <Node*> q;
    q.push(targetNode);

    while(!q.empty()){

        bool isBurning = false;
        int size = q.size();

        while(size--){

            Node* front = q.front();
            q.pop();

            visited[front] = true;

            // Add Left, Right, Parent of front node
            if(front->left != NULL && !visited[front->left]){

                q.push(front->left);
                isBurning = true;
            }

            if(front->right != NULL && !visited[front->right]){

                q.push(front->right);
                isBurning = true;
            }

            if(mp[front] != NULL && !visited[mp[front]]){

                q.push(mp[front]);
                isBurning = true;
            }
        }

        if(isBurning)
            timeTaken++;
    }

    return timeTaken;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    int target;
    cout << "Enter target data : ";
    cin >> target;

    // Burn Binary Tree 
    int burningTime = burnBinaryTree(root, target);

    cout << "Time in burning the tree : " << burningTime;

    cout << endl;
    return 0;
}