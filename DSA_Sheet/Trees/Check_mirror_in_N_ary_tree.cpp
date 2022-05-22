#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

// Method : Using Map
// Time Complexity : O(e)  Space Complexity : O(e)
bool checkNAryTreeMirror(int *tree1, int *tree2, int e){

    if(e == 0) return true;

    // For storing edges
    unordered_map <int , stack<int> > mp;

    // Store the tree1 edges
    for(int i=0; i<e; i++){

        int a = tree1[2*i];
        int b = tree1[2*i + 1];

        mp[a].push(b);
    }

    // Check in tree2 [If it is mirror or not]
    for(int i=0; i<e; i++){

        int a = tree2[2*i];
        int b = tree2[2*i + 1];

        if(mp[a].top() != b) return false;

        mp[a].pop();
    }

    return true;
}

int main()
{
    int e;
    cout << "Enter number of edges : ";
    cin >> e;

    int a, b;

    int tree1[2*e];
    cout << "Enter for Tree 1 : ";
    for(int i=0; i<e; i++){

        cin >> a >> b;
        tree1[2*i] = a;
        tree1[2*i + 1] = b;
    }

    int tree2[2*e];
    cout << "Enter for Tree 2 : ";
    for(int i=0; i<e; i++){

        cin >> a >> b;
        tree2[2*i] = a;
        tree2[2*i + 1] = b;
    }

    // Check Mirror for N-ary Tree
    bool check = checkNAryTreeMirror(tree1, tree2, e);

    if(check){

        cout << "Trees are Mirrors !";
    }
    else{

        cout << "Trees are not Mirrors !";
    }

    cout << endl;
    return 0;
}