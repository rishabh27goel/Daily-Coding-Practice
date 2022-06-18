#include <iostream>
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

// Method 1 : Check valid bst for each node
// Time Complexity : O(n^2)  Space Complexity : O(n)
// bool validBst(Node* root, int &count, int minRange, int maxRange){

//     if(root == NULL) return true;

//     if(!(minRange < root->data && root->data < maxRange)) return false;

//     count++;

//     return validBst(root->left, count, minRange, root->data) && validBst(root->right, count, root->data, maxRange);
// }

// int largestBst(Node* root){

//     if(root == NULL) return 0;

//     int maxCount = INT_MIN;
//     int count = 0;

//     if(validBst(root, count, INT_MIN, INT_MAX)){

//         maxCount = max(count, maxCount);
//     }

//     int leftChild = largestBst(root->left);
//     int rightChild = largestBst(root->right);

//     maxCount = max(maxCount, max(leftChild, rightChild));

//     return maxCount;
// }   

// Method 2 : Bottom-Up Approach
// Time Complexity : O(n)  Space Complexity : O(n)
class Info {

    public:
        int size;
        int minValue;
        int maxValue;
        bool isBst;

    Info(int size, int minValue, int maxValue, bool isBst){

        this->size = size;
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->isBst = isBst;
    }
};

Info* largestBstHelper(Node* root, int &maxCount){

    if(root == NULL) return new Info(0, INT_MAX, INT_MIN, true);
    
    Info* lC = largestBstHelper(root->left, maxCount);
    Info* rC = largestBstHelper(root->right, maxCount);

    int total = 1 + lC->size + rC->size;
    int minValue = min(root->data,  min(lC->minValue, rC->minValue));
    int maxValue = max(root->data,  max(lC->maxValue, rC->maxValue));
    bool isBst = (root->data > lC->maxValue && root->data < rC->minValue && lC->isBst && rC->isBst);

    if(isBst)
        maxCount = max(total, maxCount);

    return new Info(total, minValue, maxValue, isBst);
}

int largestBst(Node* root){

    if(root == NULL) return 0;

    int maxCount = INT_MIN;

    Info* rootInfo = largestBstHelper(root, maxCount);

    return maxCount;
}

int main()
{
    Node* root = NULL;

    // Create BST { 8 11 10 9 -1 -1 4 -1 -1 -1 1 1 -1 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Largest Bst in Binary Tree
    int size = largestBst(root);

    cout << "Size of Largest Bst is : " << size;

    cout << endl;
    return 0;
}