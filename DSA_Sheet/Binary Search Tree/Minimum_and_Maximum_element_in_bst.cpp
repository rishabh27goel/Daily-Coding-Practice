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

Node* createBST(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createBST(root->left, value);
    }
    else{

        root->right = createBST(root->right, value);
    }

    return root;
}

// Method 1 : Checking whole tree
// Time Complexity : O(n)  Space Complexity : O(n)
// void helperMinMax(Node* root, pair<int, int> &minmax){

//     if(root == NULL) return;

//     // Min Element
//     if(root->data < minmax.first){

//         minmax.first = root->data;
//     }

//     // Max Element
//     if(root->data > minmax.second){

//         minmax.second = root->data;
//     }

//     helperMinMax(root->left, minmax);
//     helperMinMax(root->right, minmax);
// }

// pair<int, int> findMinMaxElement(Node* root){

//     pair<int, int> minmax = make_pair(INT_MAX, INT_MIN);
//     if(root == NULL) return minmax;

//     helperMinMax(root, minmax);

//     return minmax;
// }

// Method 2 : Left & Right path in the tree
// Time Complexity : O(h)  Space Complexity : O(h)
pair<int, int> findMinMaxElement(Node* root){

    pair<int, int> minmax = make_pair(INT_MAX, INT_MIN);
    if(root == NULL) return minmax;

    // Minimum Element
    Node* minNode = root;

    while(minNode->left != NULL){

        minNode = minNode->left;
    }

    // Maximum Element
    Node* maxNode = root;

    while(maxNode->right != NULL){

        maxNode = maxNode->right;
    }

    return make_pair(minNode->data, maxNode->data);
}

int main()
{
    Node* root = NULL;

    // Create Tree { 50 30 15 40 75 60 85 80 -1 }
    int data = 0;
    cout << "Enter nodes data : ";
    
    while(data != -1){

        cin >> data;

        if(data == -1) break;
        root = createBST(root, data);
    }

    // Minimum & Maximum Element
    pair<int, int> minmax = findMinMaxElement(root);

    cout << "Min Element : " << minmax.first << endl;
    cout << "Max Element : " << minmax.second << endl;

    cout << endl;
    return 0;
}