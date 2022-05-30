#include <iostream>
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

// Declaration of Function
// int findMaxSumHelper(Node* root, unordered_map <Node*, int> &mp);
// int sumOfGrandChild(Node* root, unordered_map <Node*, int> &mp);
// int maximumSumOfNodes(Node* root);

// Method 1 : Seperate Functions for Grand Children & Children
// Time Complexity : O(n)  Space Complexity : O(n)
// int sumOfGrandChild(Node* root, unordered_map <Node*, int> &mp){

//     int sum = 0;

//     if(root->left != NULL){

//         sum += findMaxSumHelper(root->left->left, mp) + findMaxSumHelper(root->left->right, mp);
//     }

//     if(root->right != NULL){

//         sum += findMaxSumHelper(root->right->left, mp) + findMaxSumHelper(root->right->right, mp);
//     }

//     return sum;
// }

// int findMaxSumHelper(Node* root, unordered_map <Node*, int> &mp){

//     if(root == NULL) return 0;

//     if(mp.find(root) != mp.end()){

//         return mp[root];
//     }

//     int include = root->data + sumOfGrandChild(root, mp);

//     int exclude = findMaxSumHelper(root->left, mp) + findMaxSumHelper(root->right, mp);

//     mp[root] = max(include, exclude);

//     return mp[root];
// }

// int maximumSumOfNodes(Node* root){

//     if(root == NULL) return 0;

//     unordered_map <Node*, int> mp;

//     return findMaxSumHelper(root, mp);
// }

// Method 2 : pair of include & exclude
// Time Complexity : O(n)  Space Complexity : O(n)
pair<int, int> findMaxSumHelper(Node* root){

    if(root == NULL) 
        return make_pair(0, 0);


    pair<int, int> pairLeft = findMaxSumHelper(root->left);
    pair<int, int> pairRight = findMaxSumHelper(root->right);

    int maxLeft = max(pairLeft.first, pairLeft.second);
    int maxRight = max(pairRight.first, pairRight.second);


    return make_pair(root->data + pairLeft.second + pairRight.second, maxLeft + maxRight);
}

int maximumSumOfNodes(Node* root){

    if(root == NULL) return 0;

    pair<int, int> pr = findMaxSumHelper(root);

    return max(pr.first, pr.second);
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Maximum Sum Of Nodes
    int sum = maximumSumOfNodes(root);

    cout << "Maximum Sum is : " << sum;

    cout << endl;
    return 0;
}