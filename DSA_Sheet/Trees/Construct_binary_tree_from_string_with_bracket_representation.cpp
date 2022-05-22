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

void printTree(Node* root){

    queue<Node*> q;
    q.push(root);

    cout << "Printing the tree : \n";
    while(!q.empty()){

        int size = q.size();

        while(size--){

            // Get the node & Print it
            Node* front = q.front();
            q.pop();

            cout << front->data << " ";

            // Push its child in the queue
            if(front->left != NULL){

                q.push(front->left);
            }

            if(front->right != NULL){

                q.push(front->right);
            }
        }

        cout << endl;
    }
}

// Method 1 : Taking Left and Right Subtree based on brackets
// Time Complexity : O(n^2)   Space Complexity : O(n) 
// [As we are iterating the sub-string many times : Time Complexity is O(n^2)] 
// int findClosingBracket(string input, int start){

//     int count = 1;
//     start = start + 1;

//     while(count != 0){

//         if(input[start] == '('){

//             count++;
//         }
//         else if(input[start] == ')'){

//             count--;
//         }

//         if(count == 0) return start;

//         start++;
//     }

//     return start;
// }

// Node* convertHelper(string input, int start, int end){

//     if(start > end) return NULL;

//     // Start should always be at some data initially
//     // Create Node from start data
//     Node* root = new Node(input[start]-'0');
//     int index = -1;

//     // Check if left/right tree exits
//     if(start + 1 <= end && input[start + 1] == '('){

//         index = findClosingBracket(input, start + 1);
//     }

//     // If left/right exits
//     if(index != -1){

//         // Left Child
//         root->left = convertHelper(input, start + 2, index - 1);
    
//         // Right Child
//         root->right = convertHelper(input, index + 2, end - 1);
//     }

//     return root;
// }

// Node* convertStringToTree(string s){

//     if(s.size() == 0) return NULL;

//     Node* root = convertHelper(s, 0, s.size());

//     return root;
// }

// Method 2 : Moving with brackets
// Time Complexity : O(n)   Space Complexity : O(n) 
Node* createTreeHelper(string &input, int &start){

    if(start >= input.size()) return NULL;

    Node* root = NULL;

    if(input[start] != '(' && input[start] != ')'){

        root = new Node(input[start]-'0');
        start = start + 1;
    }        

    // Left Child
    if(start < input.size() && input[start] == '('){

        start = start + 1;
        root->left = createTreeHelper(input, start);
    }
    
    if(start < input.size() && input[start] == ')'){

        start = start + 1;
        return root;
    }

    // Right Child
    if(start < input.size() && input[start] == '('){

        start = start + 1;
        root->right = createTreeHelper(input, start);
    }
    
    if(start < input.size() && input[start] == ')'){

        start = start + 1;
    }

    return root;
}

Node* convertStringToTree(string s){

    if(s.size() == 0) return NULL;    

    int start = 0;
    Node* root = createTreeHelper(s, start);

    return root;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // Create Binary Tree from String [With bracket representation]
    Node* root = convertStringToTree(input);

    printTree(root);

    

    cout << endl;
    return 0;
}