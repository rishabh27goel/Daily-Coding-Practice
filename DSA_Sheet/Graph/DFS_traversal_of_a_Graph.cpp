#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Method : Depth First Search
// Time Complexity : O(|V| + |E|)  Space Complexity : O(|V| + |E|)
void dfsHelper(unordered_map <int, vector<int> > &adjList, unordered_map<int, bool> &visited, int start){

    visited[start] = true;

    cout << start << " ";

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            dfsHelper(adjList, visited, adjList[start][i]);
        }
    }
}

void dfsTraversal(int n, unordered_map <int, vector<int> > &adjList){

    cout << "Depth First Search : \n";

    // DFS visited track
    unordered_map<int, bool> visited;

    // For disconnected graph
    for(int i=1; i<n; i++){

        if(visited[i] == false){

            dfsHelper(adjList, visited, i);

            cout << endl;
        }
    }
}


int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    // Creating a graph
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;
    
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Depth First Search
    dfsTraversal(n, adjList);


    cout << endl;
    return 0;
}