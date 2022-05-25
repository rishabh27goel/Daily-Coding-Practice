#include <iostream>
#include <queue>
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

// Method : Sorting the vector of levels
// Time Complexity : O(min(m, n))  Space Complexity : O(min(m, n))
bool levelsAreAnagrams(Node* root1, Node* root2){

    // If both are empty
    if(root1 == NULL && root2 == NULL) return true;

    // If any of them is empty
    if(root1 == NULL || root2 == NULL) return false;

    // For storing the nodes of both trees
    queue <Node*> q1;
    q1.push(root1);
    
    queue <Node*> q2;
    q2.push(root2);

    while(!q1.empty() && !q2.empty()){

        vector<int> level1;
        vector<int> level2;

        int size1 = q1.size();
        int size2 = q2.size();

        if(size1 != size2) return false;

        while(size1--){

            Node* front1 = q1.front();
            q1.pop();

            Node* front2 = q2.front();
            q2.pop();

            level1.push_back(front1->data);
            level2.push_back(front2->data);


            // For Queue 1
            if(front1->left != NULL){

                q1.push(front1->left);
            }

            if(front1->right != NULL){

                q1.push(front1->right);
            }
        
            // For Queue 2
            if(front2->left != NULL){

                q2.push(front2->left);
            }

            if(front2->right != NULL){

                q2.push(front2->right);
            }
        }

        // Sort to check for Anagrams
        sort(level1.begin(), level1.end());
        sort(level2.begin(), level2.end());

        for(int i=0; i<level1.size(); i++){

            if(level1[i] != level2[i]) return false;
        }
    }

    return true;
}   

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter Tree 1 data : ";
    root1 = createTree(root1);

    cout << "Enter Tree 2 data : ";
    root2 = createTree(root2);

    // Levels of Binary Trees are Anagrams
    bool check = levelsAreAnagrams(root1, root2);

    if(check){

        cout << "Levels are Anagrams !";
    }
    else{

        cout << "Levels are not Anagrams !";
    }

    cout << endl;
    return 0;
}