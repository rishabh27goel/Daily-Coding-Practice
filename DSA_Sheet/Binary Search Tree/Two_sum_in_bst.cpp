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

Node* createTree(Node* root, int data){

    if(root == NULL){

        root = new Node(data);
        return root;
    }

    if(root->data > data){

        root->left = createTree(root->left, data);
    }
    else{

        root->right = createTree(root->right, data);
    }

    return root;
}

// Method 1 : Brute Force
// Time Complexity : O(n^2)  Space Complexity : O(n)
// bool findMatch(Node* root, Node* current, int target){

//     if(root == NULL) return false;

//     if(root != current && target == (root->data + current->data))
//         return true;

//     return findMatch(root->left, current, target) || findMatch(root->right, current, target);
// }

// bool twoSumBstHelper(Node* current, Node* root, int target){

//     if(current == NULL) return false;

//     // Check match for current in the tree

//     return findMatch(root, current, target) || twoSumBstHelper(current->left, root, target) || twoSumBstHelper(current->right, root, target);
// }

// bool twoSumBst(Node* root, int target){

//     if(root == NULL) return false;

//     return twoSumBstHelper(root, root, target);
// }

// Method 2 : Using Map
// Time Complexity : O(n)  Space Complexity : O(n)
// bool twoSumBstHelper(Node* root, unordered_map<int, int> &mp, int target){

//     if(root == NULL) return false;

//     if(mp.find(target - root->data) != mp.end())
//         return true;
    
//     mp[root->data] = 1;

//     return twoSumBstHelper(root->left, mp, target) || twoSumBstHelper(root->right, mp, target);
// }

// bool twoSumBst(Node* root, int target){

//     if(root == NULL) return false;

//     // Using map to keep track of nodes
//     unordered_map<int, int> mp;

//     return twoSumBstHelper(root, mp, target);
// }

// Method 2 : Storing Inorder
// Time Complexity : O(n)  Space Complexity : O(n)
void fillInorder(Node* root, vector<int> &inorder){

    if(root == NULL) return;


    fillInorder(root->left, inorder);

    inorder.push_back(root->data);

    fillInorder(root->right, inorder);
}

bool twoSumBst(Node* root, int target){

    if(root == NULL) return false;

    // Store inorder
    vector<int> inorder;

    fillInorder(root, inorder);

    // Two Pointer
    int i = 0;
    int j = inorder.size()-1;

    while(i < j){

        if(inorder[i]+inorder[j] == target){

            return true;
        }
        else if(inorder[i]+inorder[j] > target){

            j--;
        }
        else{

            i++;
        }
    }

    return false;
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

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Two Sum BST
    bool check = twoSumBst(root, target);

    if(check){

        cout << "Sum exits !";
    }
    else{

        cout << "Sum doesn't exits !";
    }

    cout << endl;
    return 0;
}