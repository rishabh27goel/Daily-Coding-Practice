#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Depth First Search [Can also use Bfs]
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
// void dfs(unordered_map <int, vector<int> > &adjList, unordered_map <int, int> &visited, int start){

//     visited[start] = true;

//     for(int i=0; i<adjList[start].size(); i++){

//         if(visited[adjList[start][i]] == false){

//             dfs(adjList, visited, adjList[start][i]);
//         }
//     }
// }

// int numberOfOperation(int n, vector< pair<int, int> > &edges){

//     // Not possible to connect
//     if(edges.size() < n-1)  return -1;

//     // Create Adjacency List
//     unordered_map <int, vector<int> > adjList;

//     for(int i=0; i<edges.size(); i++){

//         adjList[edges[i].first].push_back(edges[i].second);
//         adjList[edges[i].second].push_back(edges[i].first);
//     }

//     // Count Number of Connected Components
//     unordered_map <int, int> visited;
//     int components = 0;

//     for(int i=0; i<n; i++){

//         if(visited[i] == false){

//             dfs(adjList, visited, i);
//             components++;
//         }
//     }

//     return components-1;
// }

// Method 2 : Union Find
// Time Complexity : O(V + E)  Space Complexity : O(V)
vector<int> parent;

int findParent(int node){

    if(parent[node] == node)
        return node;

    parent[node] = findParent(parent[node]);

    return parent[node];
}

int numberOfOperation(int n, vector< pair<int, int> > &edges){

    if(edges.size() < n-1)  return -1;

    // Initialize Parent
    for(int i=0; i<n; i++){

        parent.push_back(i);
    }

    // Union of edges
    for(int i=0; i<edges.size(); i++){

        int x = findParent(edges[i].first);
        int y = findParent(edges[i].second);

        if(x != y){

            parent[y] = x;
        }
    }

    // Find number of components
    int components = 0;
    
    for(int i=0; i<n; i++){

        if(parent[i] == i)
            components++;
    }

    return components-1;
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

    // Making Wired Connections
    int number = numberOfOperation(n, edges);

    if(number == -1){

        cout << "Not Possible to Connect !!";
    }
    else{

        cout << "Minimum Connections : " << number;
    }

    cout << endl;
    return 0;
}