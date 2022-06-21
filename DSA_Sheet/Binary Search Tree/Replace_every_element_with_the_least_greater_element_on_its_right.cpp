#include <iostream>
#include <vector>
#include <utility>
#include <stack>
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

// Method 1 : Nested Loops [Brute Force]
// Time Complexity : O(n^2)  Space Complexity : O(1)
// vector<int> leastGreaterElement(vector<int> arr){

//     if(arr.size() == 0) return arr;

//     for(int i=0; i<arr.size(); i++){

//         int value = -1;

//         for(int j=i+1; j<arr.size(); j++){

//             if(arr[j] > arr[i]){

//                 if(value == -1){

//                     value = arr[j];
//                 }
//                 else{

//                     if((arr[j] - arr[i]) < (value - arr[i]))
//                         value = arr[j];
//                 }
//             }
//         }

//         arr[i] = value;
//     }


//     return arr;
// }

// Method 2 : Create Binary Search Tree
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// Time depends on structure of the tree [O(n^2) [Increasing or Decreasing Order]]
// Node* createTree(Node* root, int value, Node* &succ, bool &exits){

//     if(root == NULL){

//         // Data does not exits
//         if(!exits){

//             root = new Node(value);
//         }

//         return root;
//     }

//     if(root->data == value)
//         exits = true;

//     if(root->data > value){

//         succ = root;
//         root->left = createTree(root->left, value, succ, exits);
//     }
//     else{

//         root->right = createTree(root->right, value, succ, exits);
//     }

//     return root;
// }

// vector<int> leastGreaterElement(vector<int> arr){

//     if(arr.size() == 0) return arr;

//     // Create BST
//     Node* root = NULL;

//     for(int i=arr.size()-1; i>=0; i--){

//         Node* succ = NULL;
//         bool exits = false;

//         root = createTree(root, arr[i], succ, exits);

//         if(succ == NULL){

//             arr[i] = -1;
//         }
//         else{

//             arr[i] = succ->data;
//         }
//     }

//     return arr;
// }

// Method 3 : Next Greater Element [After Sorting]
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
static bool compare(const pair<int, int> p1, const pair<int, int> p2){


    return ((p1.first < p2.first) || (p1.first == p2.first && p1.second > p2.second));
}

vector<int> leastGreaterElement(vector<int> arr){

    if(arr.size() == 0) return arr;

    // Store pairs with indexes
    vector< pair<int, int> > pairs;

    for(int i=0; i<arr.size(); i++){

        pairs.push_back(make_pair(arr[i], i));
    }

    // Sort the vector of pairs
    sort(pairs.begin(), pairs.end(), compare);

    // Next Greater Element
    stack< pair<int, int> > st;

    for(int i=pairs.size()-1; i>=0; i--){

        // Delete elements
        while(!st.empty() && pairs[i].second > st.top().second){

            st.pop();
        }   

        // Insert elements
        if(st.empty()){

            arr[pairs[i].second] = -1;
        }
        else{

            arr[pairs[i].second] = st.top().first;
        }

        st.push(pairs[i]);
    }

    return arr;
}

int main()
{   
    int n;
    cout << "Enter number of elements : ";    
    cin >> n;

    // Input { 2 6 9 1 3 2 }
    cout << "Enter array values : ";
    vector<int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }


    // Least Greater Element
    vector<int> output = leastGreaterElement(arr);

    cout << "Output Array : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}