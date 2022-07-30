#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Check for cycle 
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
bool dfs(unordered_map<int, vector<int> > &adjList, vector<bool> &visited, vector<bool> &dfsExist, int start){
        
    visited[start] = true;
    dfsExist[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            if(dfs(adjList, visited, dfsExist, adjList[start][i])){

                return true;
            }
        }
        else{

            if(dfsExist[adjList[start][i]] == true){

                return true;
            }
        }
    }

    dfsExist[start] = false;

    return false;
}

bool finishAllTasks(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List [Directed Edge]
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
    }

    // Check for cycle
    vector<bool> visited(n, false);
    vector<bool> dfsExits(n, false);

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            // If cycle exits
            if(dfs(adjList, visited, dfsExits, i)){

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

    vector< pair<int, int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    // Finish All Tasks
    bool finish = finishAllTasks(n, edges);

    if(finish){

        cout << "Possible to complete !!";
    }
    else{

        cout << "Not Possible !!";
    }
    
    cout << endl;
    return 0;
}