#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method :
// Time Complexity : O()  Space Complexity : O()
bool isSafe(unordered_map<int, vector<int> > &adjList, vector<int> &visited, int start, int color){

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == color){

            return false;
        }
    }

    return true;
}

bool colorDfs(unordered_map<int, vector<int> > &adjList, vector<int> &visited, int start, int color){

    int n = visited.size();

    // If all nodes are filled with colorsß
    if(start == n) 
        return true;

    
    for(int c=1; c<=color; c++){

        if(isSafe(adjList, visited, start, c)){

            visited[start] = c;

            // Color next node
            if(colorDfs(adjList, visited, start+1, color)){

                return true;
            }

            // Backtracking
            visited[start] = -1;
        }
    }


    return false;
}

bool colorGraph(int n, vector< pair<int, int> > &edges, int c){

    // Create Adjacency List
    unordered_map<int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // Start from 0 and iterate every node 
    vector<int> visited(n, -1);

    // If we can color all nodes from 0
    if(colorDfs(adjList, visited, 0, c) == false){

        return false;
    }

    return true;
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

    cout << "Enter number of colors : ";
    int c;
    cin >> c;

    // Graph Coloring Problem
    bool possible = colorGraph(n, edges, c);

    if(possible){

        cout << "Graph Coloring is Possible !!";
    }
    else{

        cout << "Graph Coloring is not Possible !!";
    }

    cout << endl;
    return 0;
}