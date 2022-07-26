#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Depth First Search
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
bool cycleHelper(unordered_map <int, vector<int> > &adjList, unordered_map <int, int> &visited, unordered_map <int, int> &dfsExits, int start){

    visited[start] = true;
    dfsExits[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            // If we have cycle on this path
            if(cycleHelper(adjList, visited, dfsExits, adjList[start][i])){

                return true;
            }
        }
        else{

            // If node is in the visited map
            // And it is in the recursion stack
            if(dfsExits[adjList[start][i]] == true){

                // Loops Exits
                return true;
            }
        }
    }

    // Call remove from recursion stack
    dfsExits[start] = false;

    return false;
}

bool detectCycle(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
    }

    // Visited and Recursion Track of Start
    unordered_map <int, int> visited;
    unordered_map <int, int> dfsExits;

    for(int i=1; i<=n; i++){

        if(visited[i] == false){

            // If cycle exits with ith node
            if(cycleHelper(adjList, visited, dfsExits, i)){
                
                return true;
            }
        }
    }

    return false;
}


int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    vector< pair<int, int> > edges;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Detect Cycle in Directed Graph
    bool loop = detectCycle(n, edges);

    if(loop){

        cout << "Loop exits !!";
    }
    else{

        cout << "Loop doesn't exits !!";
    }

    cout << endl;
    return 0;
}