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

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    cout << root->data << " ";

    printTree(root->right);
}

// Method 1 : Using extra vector space
// Time Complexity : O(n1 + n2)   Space Complexity : O(n1 + n2)
// void fillInorder(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     fillInorder(root->left, inorder);

//     inorder.push_back(root->data);

//     fillInorder(root->right, inorder);
// }

// void mergeTwoVectors(vector<int> &first, vector<int> &second, vector<int> &output){

//     int i = 0;
//     int j = 0;

//     while(i < first.size() && j < second.size()){

//         if(first[i] < second[j]){

//             output.push_back(first[i]);
//             i++;
//         }
//         else{

//             output.push_back(second[j]);
//             j++;
//         }
//     }

//     while(i < first.size()){

//         output.push_back(first[i]);
//         i++;
//     }

//     while(j < second.size()){

//         output.push_back(second[j]);
//         j++;
//     }

// }

// Node* createBalancedBst(vector<int> &output, int start, int end){

//     if(start > end) return NULL;

//     int middle = (start + end)/2;

//     Node* root = new Node(output[middle]);

//     root->left = createBalancedBst(output, start, middle-1);
//     root->right = createBalancedBst(output, middle+1, end);

//     return root;
// }

// Node* mergeTwoBst(Node* root1, Node* root2){

//     if(root1 == NULL) return root2;
//     if(root2 == NULL) return root1;


//     // Step 1 : Store the inorder of trees
//     vector<int> inorder1;
//     vector<int> inorder2;

//     fillInorder(root1, inorder1);
//     fillInorder(root2, inorder2);


//     // Step 2 : Merge two sorted vectors
//     vector<int> output;

//     mergeTwoVectors(inorder1, inorder2, output);


//     // Step 3 : Create balanced bst
//     Node* newTree = createBalancedBst(output, 0, output.size()-1);


//     return newTree;
// }


// Method 2 : Without extra space
// Time Complexity : O(n1 + n2)   Space Complexity : O(log(n1 + n2))
Node* convertToList(Node* root){

    Node* head = NULL;
    Node* tail = NULL;

    Node* itr = root;

    while(itr != NULL){

        if(itr->left == NULL){

            if(head == NULL){

                head = itr;
            }
            else{

                tail->right = itr;
            }

            tail = itr;
            itr = itr->right;
        }
        else{

            Node* pred = itr->left;

            while(pred->right != NULL && pred->right != itr){

                pred = pred->right;
            }


            if(pred->right == NULL){

                pred->right = itr;

                Node* leftStore = itr->left;
                itr->left = NULL;
                
                itr = leftStore;
            }
            else{

                if(head == NULL){

                    head = itr;
                }
                else{

                    tail->right = itr;
                }

                tail = itr;
                pred->right = NULL;
                itr = itr->right;
            }

        }
    }

    return head;
}

Node* mergeTwoList(Node* first, Node* second){

    Node* head = NULL;
    Node* tail = NULL;

    while(first != NULL && second != NULL){

        if(first->data < second->data){

            if(head == NULL){

                head = first;
            }
            else{

                tail->right = first;
            }
            
            tail = first;
            first = first->right;
        }
        else{

            if(head == NULL){

                head = second;
            }
            else{

                tail->right = second;
            }
            
            tail = second;
            second = second->right;
        }
    }

    while(first != NULL){

        if(head == NULL){

            head = first;
        }
        else{

            tail->right = first;
        }
        
        tail = first;
        first = first->right;
    }

    while(second != NULL){

        if(head == NULL){

            head = second;
        }
        else{

            tail->right = second;
        }
        
        tail = second;
        second = second->right;
    }

    return head;
}

// Using below method : T(n) = 2T(n/2) + n/2  => nlogn
// Method 2 (Using Below):  Time Complexity : O((n1 + n2) * log(n1 + n2))   Space Complexity : O(log(n1 + n2))
// Node* convertListToBST(Node* head, Node* tail){

//     if(head == tail) return NULL;

//     if(head->right == tail){

//         head->left = NULL;
//         head->right = NULL;

//         return head;
//     }

//     Node* middle = head;
//     Node* fast = head;

//     while(fast != tail && fast->right != tail){

//         middle = middle->right;
//         fast = fast->right->right;
//     }

//     Node* root = middle;

//     root->left = convertListToBST(head, middle);
//     root->right = convertListToBST(middle->right, tail);

//     return root;
// }

// By Reference we pass head
Node* convertListToBST(Node* &head, int n){

    if(n <= 0 || head == NULL) return NULL;

    Node* leftChild = convertListToBST(head, n/2);

    Node* root = head;
    head = head->right;

    root->left = leftChild;

    root->right = convertListToBST(head, n-(n/2)-1);

    return root;
}

int getCount(Node* head){

    int count = 0;

    while(head != NULL){

        count++;
        head = head->right;
    }

    return count;
}

Node* mergeTwoBst(Node* root1, Node* root2){

    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;


    // Step 1 : Convert to sorted linked list [Morris Traversal]
    root1 = convertToList(root1);
    root2 = convertToList(root2);    


    // Step 2 : Merge Two Sorted Linked List
    Node* newList = mergeTwoList(root1, root2);


    // Step 3 : Convert Sorted List to BST
    int count = getCount(newList);
    Node* newTree = convertListToBST(newList, count);

    // Method 2 (Using Below):  
    // Time Complexity : O((n1 + n2) * log(n1 + n2))   Space Complexity : O(log(n1 + n2))
    // Node* newTree = convertListToBST(newList, NULL);

    return newTree;
}   

int main()
{
    // Creating Tree 1
    Node* root1 = NULL;

    // Create BST { 5 3 7 2 4 6 8 -1 }
    cout << "Enter tree 1 data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root1 = createTree(root1, data);
    }

    // Creating Tree 2
    Node* root2 = NULL;

    // Create BST { 7 3 9 1 4 -1 }
    cout << "Enter tree 2 data : ";
    data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root2 = createTree(root2, data);
    }

    // Merge Two Bst
    Node* root = mergeTwoBst(root1, root2);

    cout << "\nNew BST Tree : ";
    printTree(root);

    cout << endl;
    return 0;
}