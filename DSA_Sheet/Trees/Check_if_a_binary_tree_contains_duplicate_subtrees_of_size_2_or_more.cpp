#include <iostream>
#include <vector>
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

// Method : Using map for storing string of subtrees
// Time Complexity : O(n^2)  Space Complexity : O(n^2)
// Insert string in map [Space N * N] [Time N * N]
string fillSubtreeMap(Node* root, unordered_map<string, int> &mp, bool &duplicale){

    if(root == NULL) return "";

    string s = "(";
    s += fillSubtreeMap(root->left, mp, duplicale);

    string rootStr = to_string(root->data);
    s += rootStr;

    s += fillSubtreeMap(root->right, mp, duplicale);
    s += ")";

    // Check in the string map : Finding String in Map   [Time : O(n)]
    // Size 2 or more
    if(mp.find(s) != mp.end() && rootStr.size() + 2 < s.size()){

        duplicale = true;
    }

    mp[s]++;

    return s;
}

bool checkForDuplicateSubtree(Node* root){

    if(root == NULL) return false;

    unordered_map <string, int> mp;
    bool duplicate = false;

    string output = fillSubtreeMap(root, mp, duplicate);    

    return duplicate;
}

int main()
{
    Node* root = NULL;

    // Create Tree { 1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Check if duplicate subtrees exits
    bool check = checkForDuplicateSubtree(root);

    if(check){

        cout << "Duplicate exits !";
    }
    else{

        cout << "Duplicate does not exits !";
    }

    cout << endl;
    return 0;
}