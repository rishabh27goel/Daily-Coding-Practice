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

Node* createTree(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createTree(root->left, value);
    }
    else{

        root->right = createTree(root->right, value);
    }

    return root;
}

// Method 1 : Count track using helper
// Time Complexity : O(n)   Space Complexity : O(n)
// void countBSTNodesHelper(Node* root, int l, int h, int &count){

//     if(root == NULL) return;

//     if(root->data >= l && root->data <= h)
//         count++;

//     countBSTNodesHelper(root->left, l, h, count);
//     countBSTNodesHelper(root->right, l, h, count);
// }

// int countBSTNodes(Node* root, int l, int h){

//     if(root == NULL) return 0;

//     int count = 0;
//     countBSTNodesHelper(root, l, h, count);

//     return count;
// }

// Method 2 : Optimised Approach
// Time Complexity : O(n)   Space Complexity : O(n)
int countBSTNodes(Node* root, int l, int h){

    if(root == NULL) return 0;

    // If root lies in [l, r] (both inclusive)
    if(root->data >= l && root->data <= h){

        return 1 + countBSTNodes(root->left, l, h) + countBSTNodes(root->right, l, h);
    }
    // If root lies on left side of range
    else if(root->data > h){

        return countBSTNodes(root->left, l, h);
    }
    // If root lies on right side of range
    else{

        return countBSTNodes(root->right, l, h);
    }
}

int main()
{
    Node* root = NULL;

    // Create BST { 50 30 15 40 75 60 85 80 -1 }
    cout << "Enter nodes data : "; 
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    int lower;
    cout << "Enter Lower Limit : ";
    cin >> lower;

    int upper;
    cout << "Enter Upper Limit : ";
    cin >> upper;

    // Count BST nodes 
    int count = countBSTNodes(root, lower, upper);

    cout << "Nodes Count is : " << count;

    cout << endl;
    return 0;
}