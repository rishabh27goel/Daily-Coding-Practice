#include <iostream>
#include <vector>
using namespace std;

class Interval {

    public:
        int low;
        int high;

    Interval(int low, int high){

        this->low = low;
        this->high = high;
    }
};

class Node {

    public:
        Interval* interval;
        Node* left;
        Node* right;

    Node(Interval* interval){

        this->interval = interval;
        this->left = NULL;
        this->right = NULL;
    }
};

// Method 1 : Brute Force [Two Loops]
// Time Complexity : O(n^2)   Space Complexity : O(1)
// void findConflicts(vector <Interval*> intervals){

//     if(intervals.size() == 0) return;

//     // Iterate all intervals before a interval
//     int i = 0;

//     cout << "Conflicting Intervals : " << endl;
//     while(i < intervals.size()){

//         for(int j=0; j<i; j++){

//             if(intervals[j]->low <= intervals[i]->low && intervals[j]->high > intervals[i]->low){

//                 cout << "{ " << intervals[i]->low << ", " << intervals[i]->high << " } conflicts with { " << intervals[j]->low << ", " << intervals[j]->high << " }" << endl;
//                 break;
//             }
//         }

//         i++;
//     }
// }

// Method 2 : Binary Search Tree Approach
// Time Complexity : More than O(n * log(n))   Space Complexity : O(n)
// Space for creating bst & it can take more than n * logn as searching depends on tree structure
Node* insertInterval(Node* root, Interval* newInterval){

    if(root == NULL){

        root = new Node(newInterval);
        return root;
    }

    if(root->interval->low > newInterval->low){

        root->left = insertInterval(root->left, newInterval);
    }
    else{

        root->right = insertInterval(root->right, newInterval);
    }

    return root;
}

void searchInterval(Node* root, Interval* find){

    if(root == NULL) return;

    if(root->interval->low <= find->low && root->interval->high > find->low){

        Interval* intv = root->interval;
        cout << "{ " << find->low << ", " << find->high << " } conflicts with { " << intv->low << ", " << intv->high << " }" << endl;
                
        return;
    }

    if(root->interval->low > find->low){

        searchInterval(root->left, find);
    }
    else{

        searchInterval(root->right, find);
    }    
}

void findConflicts(vector <Interval*> intervals){

    if(intervals.size() == 0) return;

    cout << "Conflicting Intervals : " << endl;
    Node* root = NULL;
    root = insertInterval(root, intervals[0]);

    // First search and then insert intervals
    for(int i=1; i<intervals.size(); i++){

        // Time : O(log(n))
        searchInterval(root, intervals[i]);

        // Time : O(log(n))
        root = insertInterval(root, intervals[i]);
    }
}

int main()
{
    int n;
    cout << "Enter number of appointments : ";
    cin >> n;

    // Input { 1 5 3 7 2 6 10 15 5 6 4 100 }
    vector <Interval*> intervals;
    int a, b;
    cout << "Enter Intervals : ";
    
    for(int i=0; i<n; i++){

        cin >> a >> b;
        intervals.push_back(new Interval(a, b));
    }

    // Find all conflicts
    findConflicts(intervals);

    cout << endl;
    return 0;
}