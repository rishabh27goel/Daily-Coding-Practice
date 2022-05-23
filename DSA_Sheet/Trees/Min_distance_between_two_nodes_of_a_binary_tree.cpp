#include <iostream>
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

// Method 1 : Storing path in vectors
// Time Complexity : O(n)  Space Complexity : O(n)
// bool getPath(Node* root, int value, vector<int> &path){

//     // Empty Node
//     if(root == NULL) return false;

//     // When value is found
//     if(root->data == value){

//         path.push_back(root->data);
//         return true;
//     }

//     path.push_back(root->data);

//     bool leftChild = getPath(root->left, value, path);
//     bool rightChild = getPath(root->right, value, path);

//     // If root->data is not in the path
//     if(leftChild == false && rightChild == false){

//         path.pop_back();
//     }

//     return (leftChild || rightChild);
// }

// int minDistanceBetweenNodes(Node* root, int n1, int n2){

//     if(root == NULL) return -1;

//     // Storing path for nodes n1 & n2
//     vector<int> n1Path;
//     vector<int> n2Path;

//     bool first = getPath(root, n1, n1Path);
//     bool second = getPath(root, n2, n2Path);

//     // If n1 & n2 is not found
//     if(first == false || second == false) return -1;

//     int index = 0;

//     while(index < n1Path.size() && index < n2Path.size()){

//         if(n1Path[index] != n2Path[index])
//             break;

//         index++;
//     }

//     return (n1Path.size()-index) + (n2Path.size()-index);
// }

// Method 2 : Finding LCA & Get Distance
// Time Complexity : O(n)  Space Complexity : O(n)
Node* getLCA(Node* root, int n1, int n2){

    // Empty Node
    if(root == NULL) return NULL;

    // If value matches with root
    if(root->data == n1 || root->data == n2) return root;

    Node* leftChild = getLCA(root->left, n1, n2);
    Node* rightChild = getLCA(root->right, n1, n2);

    if(leftChild != NULL && rightChild != NULL){

        return root;
    }
    else if(leftChild != NULL && rightChild == NULL){

        return leftChild;
    }
    else if(leftChild == NULL && rightChild != NULL){

        return rightChild;
    }

    return NULL;
}

int levelDistance(Node* root, int value){

    if(root == NULL) return 0;

    if(root->data == value) return 1;

    int leftChild = levelDistance(root->left, value);
    int rightChild = levelDistance(root->right, value);

    if(leftChild != 0 && rightChild == 0){

        return 1 + leftChild;
    }
    else if(leftChild == 0 && rightChild != 0){

        return 1 + rightChild;
    }

    return 0;
}

int minDistanceBetweenNodes(Node* root, int n1, int n2){

    if(root == NULL) return -1;

    // Get the LCA
    Node* lcaNode = getLCA(root, n1, n2);

    if(lcaNode == NULL) return -1;

    // Find the distance : lca -> n1 & lca->n2
    if(lcaNode->data == n1){

        return levelDistance(lcaNode, n2) - 1;
    }
    else if(lcaNode->data == n2){

        return levelDistance(lcaNode, n1) - 1;
    }

    int dist1 = levelDistance(lcaNode, n1);
    int dist2 = levelDistance(lcaNode, n2);

    return dist1 + dist2 - 2;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    int n1;
    cout << "Enter Value 1 : ";
    cin >> n1;

    int n2;
    cout << "Enter Value 2 : ";
    cin >> n2;

    // Min Distance Between Two Nodes
    int distance = minDistanceBetweenNodes(root, n1, n2);

    cout << "Distance between nodes : " << distance;

    cout << endl;
    return 0;
}