#include <iostream>
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

// Method : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(n)
void helperBloodline(Node* root, int length, int pathSum, pair<int, int> &pr){

    // Empty Node
    if(root == NULL) return;

    // Leaf Node
    if(root->left == NULL && root->right == NULL){

        // Check when length is higher
        if(length >= pr.first){

            pr.first = length;
            pr.second = max(pathSum + root->data, pr.second);
        }

        return;
    }

    helperBloodline(root->left, length + 1, pathSum + root->data, pr);
    helperBloodline(root->right, length + 1, pathSum + root->data, pr);    
}

int sumLongestBloodline(Node* root){

    if(root == NULL) return 0;

    pair<int, int> pr = make_pair(0, 0);

    helperBloodline(root, 1, 0, pr);

    return pr.second;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Sum Of Longest Bloodline 
    int sum = sumLongestBloodline(root);

    cout << "Sum of Longest Bloodline : " << sum;

    cout << endl;
    return 0;
}