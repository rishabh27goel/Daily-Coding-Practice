#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Method 1 : Using M-Coloring [Breadth First Search]
// If we can color graph with 2 colors it is Bipartite Graph
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
// bool bipartiteGraph(int n, vector< pair<int, int> > &edges){

//     // Creating Adjacency List
//     unordered_map <int, vector<int> > adjList;

//     for(int i=0; i<edges.size(); i++){

//         adjList[edges[i].first].push_back(edges[i].second);
//         adjList[edges[i].second].push_back(edges[i].first);
//     }

//     // Coloring with 2 colors
//     vector<int> color(n, -1);

//     for(int i=0; i<n; i++){

//         // If color not filled
//         if(color[i] == -1){

//             // Traverse using queue
//             queue<int> q;

//             q.push(i);
//             color[i] = 0;

//             while(!q.empty()){

//                 int front = q.front();
//                 q.pop();

//                 for(int j=0; j<adjList[front].size(); j++){

//                     // If not visited
//                     if(color[adjList[front][j]] == -1){

//                         q.push(adjList[front][j]);
//                         color[adjList[front][j]] = color[front] ^ 1;
//                     }
//                     else{

//                         // If visited
//                         if(color[front] == color[adjList[front][j]])
//                             return false;
//                     }
//                 }
//             }
//         }
//     }

//     return true;
// }

// Method 2 : Using M-Coloring [Depth First Search]
// If we can color graph with 2 colors it is Bipartite Graph
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
bool dfs(unordered_map <int, vector<int> > &adjList, vector<int> &color, int start){

    for(int i=0; i<adjList[start].size(); i++){

        if(color[adjList[start][i]] == -1){

            // Color Adjacent Nodes
            color[adjList[start][i]] = color[start] ^ 1;

            // If we get same color with neighbour on this path
            if(dfs(adjList, color, adjList[start][i]) == false){

                return false;
            } 
        }
        else{

            // If Adjacent has same color
            if(color[start] == color[adjList[start][i]]){

                return false;
            }
        }
    }

    return true;
}

bool bipartiteGraph(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);        
    }

    // Coloring using 2 colors
    vector<int> color(n, -1);

    for(int i=0; i<n; i++){

        if(color[i] == -1){

            // Fill the starting node
            color[i] = 0;

            if(dfs(adjList, color, i) == false){

                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< pair<int, int> >  edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;


    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Check for Bipartite Graph
    bool check = bipartiteGraph(n, edges);

    if(check){

        cout << "Graph is Bipartite !!";
    }
    else{

        cout << "Graph is not Bipartite !!";
    }

    cout << endl;
    return 0;
}