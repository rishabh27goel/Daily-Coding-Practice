#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : 
// Time Complexity : O()  Space Complexity : O()
void minimumSpanningTree(int n, vector< vector<int> > &edges){

    // Create Adjacency List
    unordered_map<int, vector< pair<int, int> > > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjList[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    // Find Minimum Spanning Tree
    vector <int> parent(n, -1);
    vector <bool> mst(n, false);
    vector <int> key(n, INT_MAX);


    // Start from 0 
    key[0] = 0;

    for(int i=0; i<n; i++){

        // Find the minimum index in the key vector
        int index = 0;
        int miniValue = INT_MAX;

        for(int j=0; j<n; j++){

            if(mst[j] == false && key[j] < miniValue){

                index = j;
                miniValue = key[j];
            }
        }


        // Mark minimum node as visited
        mst[index] = true;

        for(int j=0; j<adjList[index].size(); j++){

            if(mst[adjList[index][j].first] == false && key[adjList[index][j].first] > adjList[index][j].second){

                key[adjList[index][j].first] = adjList[index][j].second;
                parent[adjList[index][j].first] = index;
            }
        }
    }


    // Printing Parent Vector

    cout << "\nParent Vector : ";
    for(int i=0; i<parent.size(); i++){

        cout << parent[i] << " ";
    }

    cout << "\nMinimum Key : ";
    for(int i=0; i<key.size(); i++){

        cout << key[i] << " ";
    }
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< vector<int> > edges; 

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v, w;
        cin >> u >> v >> w;

        vector<int> edg;

        edg.push_back(u);
        edg.push_back(v);
        edg.push_back(w);

        edges.push_back(edg);
    }

    // Using Prim's Algorithm
    minimumSpanningTree(n, edges);


    cout << endl;
    return 0;
}