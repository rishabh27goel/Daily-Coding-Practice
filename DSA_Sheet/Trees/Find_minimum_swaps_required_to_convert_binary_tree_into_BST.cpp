#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Count by placing to correct position
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
void inorderTreeArray(vector<int> &nodes, int index, vector<int> &inorder){

    if(index >= nodes.size()) return;

    // Left Child
    inorderTreeArray(nodes, 2*index + 1, inorder);

    // Root Node
    inorder.push_back(nodes[index]);

    // Right Child
    inorderTreeArray(nodes, 2*index + 2, inorder);
}

int swapsBinaryTreeToBST(vector<int> &nodes){

    if(nodes.size() <= 1) return 0; 

    // Get the inorder from nodes array
    vector<int> inorder;
    inorderTreeArray(nodes, 0, inorder);

    // Store sorted pair in another vector
    vector< pair<int, int> > sorted(inorder.size());

    for(int i=0; i<sorted.size(); i++){

        sorted[i].first = inorder[i];
        sorted[i].second = i;
    }

    sort(sorted.begin(), sorted.end());


    // Find the swaps
    int swaps = 0;
    int index = 0;

    while(index < sorted.size()){

        if(index == sorted[index].second){

            index++;
            continue;
        }
        else{

            // If index is not a match [Increment Swaps]
            // Place index to original destination
            swap(sorted[index].first, sorted[sorted[index].second].first );
            swap(sorted[index].second, sorted[sorted[index].second].second);
            
            swaps++;
        }

        if(index != sorted[index].second) continue;

        index++;
    }

    return swaps;
}

// Method 2 : Using Graph
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// To be done

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int data;
    vector<int> nodes;

    cout << "Enter nodes data : ";
    for(int i=0; i<n; i++){

        cin >> data;
        nodes.push_back(data);
    }

    // Find Minimum Number Of Swaps 
    int swaps = swapsBinaryTreeToBST(nodes);

    cout << "Minimum Swaps : " << swaps;


    cout << endl;
    return 0;
}