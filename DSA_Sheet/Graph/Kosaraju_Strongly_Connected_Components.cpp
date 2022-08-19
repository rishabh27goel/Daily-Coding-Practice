#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// Method : Kosaraju's Algorithm
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
void dfsTopologicalOrder(unordered_map<int, vector<int> > &adjList, vector<bool> &visited, stack<int> &topo, int start){

    visited[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            dfsTopologicalOrder(adjList, visited, topo, adjList[start][i]);
        }
    }

    topo.push(start);
}

void dfsCountComponents(unordered_map<int, vector<int> > &transList, vector<bool> &track, int start){

    track[start] = true;

    for(int i=0; i<transList[start].size(); i++){

        if(track[transList[start][i]] == false){

            dfsCountComponents(transList, track, transList[start][i]);
        }
    }
}

int stronglyConnectedComponents(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List
    unordered_map<int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
    }


    // Find Topological Order
    vector <bool> visited(n, false);
    stack <int> topo;

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            dfsTopologicalOrder(adjList, visited, topo, i);
        }
    }

    // Create Transpose Graph
    unordered_map<int, vector<int> > transList;

    for(int i=0; i<edges.size(); i++){

        transList[edges[i].second].push_back(edges[i].first);
    }

    // Use DFS get the strongly connected components
    vector <bool> track(n, false);
    int components = 0;

    while(!topo.empty()){

        int top = topo.top();
        topo.pop();

        if(track[top] == false){

            components++;
            dfsCountComponents(transList, track, top);
        }
    }

    return components;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< pair<int, int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Strongly Connected Components
    int components = stronglyConnectedComponents(n, edges);

    cout << "Components : " << components;


    cout << endl;
    return 0;
}