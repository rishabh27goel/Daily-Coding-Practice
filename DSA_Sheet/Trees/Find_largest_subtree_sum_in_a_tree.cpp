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

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}


// Method : Simple Recursive Method
// Time Complexity : O(n)  Space Complexity : O(n)
int sumHelper(Node* root, int &maxSum){

    if(root == NULL) return 0;

    int leftChild = sumHelper(root->left, maxSum);
    int rightChild = sumHelper(root->right, maxSum);

    maxSum = max(maxSum, root->data + leftChild + rightChild);

    return root->data + leftChild + rightChild;
}

int largestSubtreeSum(Node* root){

    if(root == NULL) return 0;

    int maxSum = INT_MIN;
    int sum = sumHelper(root, maxSum);

    return maxSum;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Largest Subtree Sum
    int sum = largestSubtreeSum(root);

    cout << "Largest Sum is : " << sum;

    cout << endl;
    return 0;
}