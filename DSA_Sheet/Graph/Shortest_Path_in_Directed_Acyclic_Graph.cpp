#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Method : Using topological order
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
void findTopologicalOrder(unordered_map <int, vector< pair<int, int> > > &adjList, vector<int> &inorder, vector<int> &topo){

    queue <int> q;

    // Push nodes with in-degree 0
    for(int i=0; i<inorder.size(); i++){

        if(inorder[i] == 0)
            q.push(i);
    }

    // Get the topological order
    while(!q.empty()){

        int front = q.front();
        q.pop();

        // Topological Vector
        topo.push_back(front);

        for(int i=0; i<adjList[front].size(); i++){

            inorder[adjList[front][i].first]--;

            if(inorder[adjList[front][i].first] == 0)
                q.push(adjList[front][i].first);

        }
    }
}

vector<int> shortestPath(vector< vector<int> > &edges, int s, int n){

    vector <int> output(n, INT_MAX);

    // Create Adjacency List [With Weights]
    unordered_map <int, vector< pair<int, int> > > adjList;
    vector<int> inorder(n, 0);

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        inorder[edges[i][1]]++;
    }

    // We need to find the topological order first
    vector<int> topo;

    findTopologicalOrder(adjList, inorder, topo);


    // Find the shortest path now

    output[s] = 0;  // Starting Point

    for(int index = 0; index < n; index++){

        if(output[index] != INT_MAX){

            for(int j=0; j<adjList[index].size(); j++){

                pair<int, int> child = adjList[index][j];

                // Update distance for shortest path
                output[child.first] = min(output[child.first], output[index] + child.second);
            }
        }
    }


    return output;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

// Input : 6 9
// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2

    vector < vector<int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        vector<int> ed;

        int u, v, w;
        cin >> u >> v >> w;

        ed.push_back(u);
        ed.push_back(v);
        ed.push_back(w);

        edges.push_back(ed);
    }

    cout << "Enter Source : ";
    int source;
    cin >> source;

    // Shortest Path in DAG
    vector<int> shortest = shortestPath(edges, source, n);

    cout << "Shortest Paths are : ";
    
    for(int i=0; i<shortest.size(); i++){

        if(shortest[i] == INT_MAX)
            cout << "INF ";
        else
            cout << shortest[i] << " ";
    }

    cout << endl;
    return 0;
}