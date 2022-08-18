#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Backtracking
// Time Complexity : O(!V)  Space Complexity : O(V + E)
// For n vertices -> worst case (connection to all nodes)
void dfs(unordered_map <int, vector< pair<int, int> > > &adjList, vector<bool> &visited, int k, int start, bool &exists){

    if(k <= 0){

        exists = true;
        return;
    }

    for(int i=0; i<adjList[start].size(); i++){

        pair<int, int> child = adjList[start][i];

        if(visited[child.first] == false){

            visited[child.first] = true;

            // Neighbour Call
            dfs(adjList, visited, k-child.second, child.first, exists);

            if(exists == true)  return;


            // Backtracking
            visited[child.first] = false;
        }
    }
}

bool pathOfKLength(int n, vector< vector<int> > &edges, int k){

    // Create Adjacency List
    unordered_map <int, vector< pair<int, int> > > adjList;

    for(int i=0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    // Start from 0 to check all paths
    vector <bool> visited(n, false);    
    bool exists = false;

    visited[0] = true;

    dfs(adjList, visited, k, 0, exists);


    return exists;
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

        vector<int> ed;

        ed.push_back(u);
        ed.push_back(v);
        ed.push_back(w);

        edges.push_back(ed);
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Path of more than K Lengths
    bool exists = pathOfKLength(n, edges, k);

    if(exists){

        cout << "Path Exists !!";
    }
    else{

        cout << "Path doesn't Exists !!";
    }
    

    cout << endl;
    return 0;
}