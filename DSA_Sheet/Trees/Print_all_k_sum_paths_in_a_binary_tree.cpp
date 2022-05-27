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


// Method 1 : Iterating Every Node
// Time Complexity : O(n * n)  Space Complexity : O(n * h)
// void printPathHelper(Node* root, int sum, vector<int> &path, int k, vector<vector<int> > &output){

//     if(root == NULL) return;

//     path.push_back(root->data);

//     if(sum + root->data == k){

//         output.push_back(path);
//     }

//     printPathHelper(root->left, sum + root->data, path, k, output);
//     printPathHelper(root->right, sum + root->data, path, k, output);

//     path.pop_back();
// }

// void printAllKSumPaths(Node* root, int k, vector<vector<int> > &output){

//     if(root == NULL) return;

//     vector<int> path;
//     printPathHelper(root, 0, path, k, output);

//     printAllKSumPaths(root->left, k, output);
//     printAllKSumPaths(root->right, k, output);
// }


// Method 2 : Single Iteration [Extra Space]
// Time Complexity : O(n * h * h)  Space Complexity : O(n)
void printPath(int index, vector<int> &path, vector<vector<int> > &output){

    vector<int> vt;

    for(int i=index; i<path.size(); i++){

        vt.push_back(path[i]);
    }

    output.push_back(vt);
}

void printPathHelper(Node* root, vector<int> &path, int k, vector<vector<int> > &output){

    if(root == NULL) return;

    path.push_back(root->data);

    printPathHelper(root->left, path, k, output);
    printPathHelper(root->right, path, k, output);

    // Find sum in reverse
    int sum = 0;

    for(int i=path.size()-1; i>=0; i--){

        sum += path[i];

        if(sum == k){

            printPath(i, path, output);
        }
    }  

    path.pop_back();
}

void printAllKSumPaths(Node* root, int k, vector<vector<int> > &output){

    if(root == NULL) return;

    vector<int> path;
    printPathHelper(root, path, k, output);

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k;
    cout << "Enter value of K : ";
    cin >> k;

    // Print All K Sum Paths
    vector< vector<int> > output;
    printAllKSumPaths(root, k, output);

    cout << "Printing K Sum Paths : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}