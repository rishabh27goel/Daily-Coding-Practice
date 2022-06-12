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

Node* createTree(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createTree(root->left, value);
    }
    else{

        root->right = createTree(root->right, value);
    }

    return root;
}

// Method 1 : Storing the inorder
// Time Complexity : O(n)  Space Complexity : O(n)
// void fillInorder(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     fillInorder(root->left, inorder);

//     inorder.push_back(root->data);

//     fillInorder(root->right, inorder);
// }

// int findMedian(Node* root){

//     if(root == NULL) return -1;

//     // Fill inorder vector
//     vector<int> inorder;
//     fillInorder(root, inorder);

//     if(inorder.size() & 1){

//         return inorder[inorder.size()/2];
//     }
//     else{

//         return (inorder[(inorder.size()-1)/2] + inorder[inorder.size()/2]) / 2;
//     }
// }

// Method 2 : Double Iteration of the tree
// Time Complexity : O(n)  Space Complexity : O(1)
// int getCount(Node* root){

//     if(root == NULL) return 0;

//     int leftCount = getCount(root->left);
//     int rightCount = getCount(root->right);

//     return 1 + leftCount + rightCount;
// }

// void getMedianHelper(Node* root, int count, int &currCount, Node* &prev, int &median){

//     if(root == NULL) return;

//     getMedianHelper(root->left, count, currCount, prev, median);

//     currCount++;

//     // Odd nodes
//     if((count & 1) && currCount == (count + 1)/2){

//         median = root->data;
//     }
//     // Even nodes
//     else if(!(count & 1) && currCount == ((count/2) + 1)){

//         median = (prev->data + root->data)/2;
//     }

//     prev = root;

//     getMedianHelper(root->right, count, currCount, prev, median);
// }

// int findMedian(Node* root){

//     if(root == NULL) return -1;

//     // Get the count of nodes
//     int count = getCount(root);

//     // Get the median with helper
//     Node* prev = NULL;
//     int median = 0;
//     int currCount = 0;

//     getMedianHelper(root, count, currCount, prev, median);
    
//     return median;
// }

// Method 3 : Using Morris Traversal
// Time Complexity : O(n)  Space Complexity : O(1)
int getCount(Node* root){

    // Using Morris Traversal count the nodes 
    int count = 0;
    Node* itr = root;

    while(itr != NULL){

        if(itr->left == NULL){

            count++;
            itr = itr->right;
        }
        else{

            // Get the Inorder Predecessor
            Node* pred = itr->left;

            while(pred->right != NULL && pred->right != itr){

                pred = pred->right;
            }

            // If connection is not created
            if(pred->right == NULL){

                pred->right = itr;
                itr = itr->left;
            }
            else{

                // If connection exits [pred->right == itr]

                count++;
                pred->right = NULL;
                itr = itr->right;
            }
        }

    }

    return count;
}

int findMedian(Node* root){

    if(root == NULL) return -1;

    // First Iteration : Morris Traversal
    // Get the number of nodes
    int count = getCount(root);

    int currCount = 0;
    Node* itr = root;
    Node* prev;

    while(itr != NULL){

        if(itr->left == NULL){

            currCount++;

            // Odd count of total nodes
            if((count & 1) && currCount == (count + 1)/2){

                return itr->data;
            }
            // Even count of total nodes
            else if(!(count & 1) && currCount == ((count/2) + 1)){

                return (prev->data + itr->data)/2;
            }

            prev = itr;
            itr = itr->right;
        }
        else{

            // Get the Inorder Predecessor
            Node* pred = itr->left;

            while(pred->right != NULL && pred->right != itr){

                pred = pred->right;
            }

            // If connection is not created
            if(pred->right == NULL){

                pred->right = itr;
                itr = itr->left;
            }
            else{

                // If connection exits [pred->right == itr]

                currCount++;

                // Odd count of total nodes
                if((count & 1) && currCount == (count + 1)/2){

                    return itr->data;
                }
                // Even count of total nodes
                else if(!(count & 1) && currCount == ((count/2) + 1)){

                    return (prev->data + itr->data)/2;
                }


                pred->right = NULL;
                prev = itr;
                itr = itr->right;
            }
        }

    }

    return -1;
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

    // Find the median of BST
    int median = findMedian(root);

    cout << "Median of Bst is : " << median;

    cout << endl;
    return 0;
}