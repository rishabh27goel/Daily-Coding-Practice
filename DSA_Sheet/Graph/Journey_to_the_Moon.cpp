#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Depth First Search [Count Components]
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
// void dfs(unordered_map <int, vector<int> > &adjList, vector<bool> &visited, int start, int &count){

//     visited[start] = true;
//     count++;

//     for(int i=0; i<adjList[start].size(); i++){

//         if(visited[adjList[start][i]] == false){

//             dfs(adjList, visited, adjList[start][i], count);
//         }
//     }
// }

// long long findWays(int n, vector< pair<int, int> > &edges){

//     long long ways;

//     // Create Adjacency List
//     unordered_map <int, vector<int> > adjList; 

//     for(int i=0; i<edges.size(); i++){

//         adjList[edges[i].first].push_back(edges[i].second);
//         adjList[edges[i].second].push_back(edges[i].first);
//     }

//     // Count the nodes in each component
//     vector <bool> visited(n, false);
//     vector<long> nodesCount(n, 0);

//     for(int i=0; i<n; i++){

//         if(visited[i] == false){

//             int count = 0;

//             dfs(adjList, visited, i, count);

//             nodesCount[i] = count;
//         }
//     }

//     long long singleSum = 0;
//     long long squareSum = 0;

//     for(int i=0; i<n; i++){

//         if(nodesCount[i] != 0){

//             singleSum += nodesCount[i];
//             squareSum += (nodesCount[i] * nodesCount[i]);
//         }
//     }

//     ways = ((singleSum * singleSum) - squareSum) / 2;

//     return ways;
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

long long findWays(int n, vector< pair<int, int> > &edges){

    long long ways;

    // Initialize Parent
    for(int i=0; i<n; i++){

        parent.push_back(i);
    }

    // Get Union of Edges
    for(int i=0; i<edges.size(); i++){

        int x = findParent(edges[i].first);
        int y = findParent(edges[i].second);
   
        if(x != y){

            parent[y] = x;
        }
    }

    // Get the count
    vector <int> nodesCount(n, 0);

    for(int i=0; i<n; i++){

        int parent = findParent(i);

        nodesCount[parent]++;
    }

    long long singleSum = 0;
    long long squareSum = 0;

    for(int i=0; i<n; i++){

        if(nodesCount[i] != 0){

            singleSum += nodesCount[i];
            squareSum += (nodesCount[i] * nodesCount[i]);
        }
    }

    ways = ((singleSum * singleSum) - squareSum) / 2;

    return ways;
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


    // Journey to Moon
    long long ways = findWays(n, edges);

    cout << "Number of Ways : " << ways;

    cout << endl;
    return 0;
}