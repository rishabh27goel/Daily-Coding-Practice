#include <iostream>
#include <unordered_map>
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

void printInorder(Node* root){

    if(root == NULL) return;

    printInorder(root->left);

    cout << root->data << " ";

    printInorder(root->right);
}

// Method : Using map for storing string of subtrees
// Time Complexity : O(n^2)  Space Complexity : O(n^2)
// Insert string in map [Space N * N] [Time N * N]
string fillSubtreeMap(Node* root, unordered_map<string, int> &mp, vector<Node*> &output){

    if(root == NULL) return "";

    string s = "(";
    s += fillSubtreeMap(root->left, mp, output);
    
    s += to_string(root->data);

    s += fillSubtreeMap(root->right, mp, output);
    s += ")";

    if(mp[s] == 1){

        output.push_back(root);
    }

    mp[s]++;

    return s;
}

vector<Node*> findDuplicateSubtree(Node* root){

    vector<Node*> output;
    if(root == NULL) output;

    unordered_map <string, int> mp;

    string str = fillSubtreeMap(root, mp, output);

    return output;
}

int main()
{
    Node* root = NULL;

    // Create Tree { 1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Find all duplicate subtrees
    vector<Node*> output = findDuplicateSubtree(root);

    cout << "Printing Subtree : \n";
    for(int i=0; i<output.size(); i++){

        printInorder(output[i]);
        cout << endl;
    }

    cout << endl;
    return 0;
}