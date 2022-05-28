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

// Method 1 : Check each node in main tree
// Time Complexity : O(m * n)  Space Complexity : O(n)
// bool identicalHelper(Node* root1, Node* root2){

//     if(root1 == NULL && root2 == NULL) 
//         return true;

//     else if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL) || root1->data != root2->data)
//         return false;

//     return identicalHelper(root1->left, root2->left) && identicalHelper(root1->right, root2->right);
// }

// bool checkSubtreeInTree(Node* root1, Node* root2){

//     if(root1 == NULL) return false;

//     bool rootBool = identicalHelper(root1, root2);

//     bool leftChild = checkSubtreeInTree(root1->left, root2);
//     bool rightChild = checkSubtreeInTree(root1->right, root2);

//     return (rootBool || leftChild || rightChild);
// }

// Method 2 : Checking substring in inorder & preorder/postorder
// Time Complexity : O(max(m, n))  Space Complexity : O(max(m, n))
void findInorder(Node* root, string &inorder){

    if(root == NULL){
            
        inorder += '$';
        return;
    }

    findInorder(root->left, inorder);

    inorder += to_string(root->data);

    findInorder(root->right, inorder);
}

void findPreorder(Node* root, string &preorder){

    if(root == NULL){
            
        preorder += '$';
        return;
    }

    preorder += to_string(root->data);

    findPreorder(root->left, preorder);

    findPreorder(root->right, preorder);
}

bool compareString(string &s1, string &s2){

    size_t pos = s1.find(s2);
  
    if(pos != string :: npos){

        return true;
    }

    return false;
}

bool checkSubtreeInTree(Node* root1, Node* root2){

    if(root1 == NULL) return false;

    // Main Tree
    string mainInorder = "";
    findInorder(root1, mainInorder);

    string mainPreorder = "";
    findPreorder(root1, mainPreorder);

    // Sub Tree
    string subInorder = "";
    findInorder(root2, subInorder);

    string subPreorder = "";
    findPreorder(root2, subPreorder);

    bool inorder = compareString(mainInorder, subInorder);    
    bool preorder = compareString(mainPreorder, subPreorder);

    return (inorder && preorder);
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter Tree 1 Data : ";
    root1 = createTree(root1);   

    cout << "Enter Tree 2 Data : ";
    root2 = createTree(root2); 

    // Check for Subtree in Another Tree
    bool check = checkSubtreeInTree(root1, root2);

    if(check){

        cout << "Tree2 is a Subtree of Tree 1 !";
    }
    else{

        cout << "Tree2 not a Subtree of Tree 1 !";
    }

    cout << endl;
    return 0;
}