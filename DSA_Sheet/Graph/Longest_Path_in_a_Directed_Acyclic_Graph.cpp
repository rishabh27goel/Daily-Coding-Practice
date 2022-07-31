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

vector<int> longestPath(vector< vector<int> > &edges, int s, int n){

    vector <int> output(n, -1);

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

    output[s] = 0;

    for(int i=0; i<n; i++){

        // Reach the source & update weight
        if(output[topo[i]] != -1){

            int ind = topo[i];

            for(int j=0; j<adjList[ind].size(); j++){

                pair<int, int> pr = adjList[ind][j];

                output[pr.first] = max(output[pr.first], output[ind] + pr.second);
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

// Input : 6 10
// 0 1 5
// 0 2 3
// 1 3 6
// 1 2 2
// 2 4 4
// 2 5 2
// 2 3 7
// 3 5 1
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

    // Longest Path in DAG
    vector<int> longest = longestPath(edges, source, n);

    cout << "Longest Paths are : ";
    
    for(int i=0; i<longest.size(); i++){

        cout << longest[i] << " ";
    }

    cout << endl;
    return 0;
}