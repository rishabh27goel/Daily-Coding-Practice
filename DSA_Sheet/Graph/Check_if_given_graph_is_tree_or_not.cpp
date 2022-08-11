#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Check for Connected and Cycle
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
// bool dfs(unordered_map <int, vector<int> > &adjList, unordered_map <int, int> &visited, int parent, int start, int &count){

//     visited[start] = parent;
//     count++;

//     for(int i=0; i<adjList[start].size(); i++){

//         // If neighbour is parent skip it
//         if(adjList[start][i] == parent)  continue;


//         if(visited.find(adjList[start][i]) == visited.end()){

//             // If this path consist a cycle
//             if(dfs(adjList, visited, start, adjList[start][i], count)){

//                 return true;
//             }
//         }
//         else{

//             // If cycle is present
//             if(visited[adjList[start][i]] != start){

//                 return true;
//             }
//         }
//     }

//     return false;
// }

// bool checkTree(int n, vector< pair<int, int> > &edges){

//     // Create Adjacency List
//     unordered_map <int, vector<int> > adjList;

//     for(int i=0; i<edges.size(); i++){

//         adjList[edges[i].first].push_back(edges[i].second);
//         adjList[edges[i].second].push_back(edges[i].first);
//     }

//     // Check for cycle in the graph [DFS]
//     unordered_map <int, int> visited;
//     int count = 0;

//     // If cycle exits
//     if(dfs(adjList, visited, -1, 0, count)){

//         return false;
//     }

//     if(count != n){

//         return false;
//     }


//     return true;
// }


// Method 2 : Check for Connected and n-1 Edges
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
void dfs(unordered_map <int, vector<int> > &adjList, vector <bool> &visited, int start){

    visited[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            dfs(adjList, visited, adjList[start][i]);
        }
    }
}

bool checkTree(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // Count Connected Components
    vector <bool> visited(n, false);
    int components = 0;

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            dfs(adjList, visited, i);
            components++;
        }
    }

    if(components == 1 && edges.size() == n-1)
        return true;

    return false;
}


int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    // Input : 
    // { 0 1
    //   0 2
    //   2 3    
    //   3 4 }
    vector< pair<int, int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Check if graph is a tree
    bool check = checkTree(n, edges);

    if(check){

        cout << "Graph is a Tree !";
    }
    else{

        cout << "Graph is not a Tree !";
    }
        


    cout << endl;
    return 0;
}