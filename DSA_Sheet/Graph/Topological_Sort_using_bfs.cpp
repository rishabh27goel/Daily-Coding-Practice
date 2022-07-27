#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Method : Breadth First Search [Kahn's Algorithm -> Use of in-degree]
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
vector<int> topologicalSort(int n, vector< pair<int, int> > &edges){

    vector<int> output;

    // Create the adjacency list
    unordered_map<int, vector<int> > adjList;
    vector<int> indegree(n, 0);

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);

        // Update the in-degree
        indegree[edges[i].second]++;
    }

    // Put the nodes with indegree as 0 in the queue
    queue <int> q;

    for(int i=0; i<n; i++){

        if(indegree[i] == 0)
            q.push(i);
    }
    
    // Use queue to get the topological sort
    while(!q.empty()){

        int front = q.front();
        q.pop();

        output.push_back(front);

        // Remove front node and update the indegree
        for(int i=0; i<adjList[front].size(); i++){

            indegree[adjList[front][i]]--;

            if(indegree[adjList[front][i]] == 0)
                q.push(adjList[front][i]);
        }
    }

    return output;
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

    // Topological Sort
    vector<int> output = topologicalSort(n, edges);

    cout << "Topological Sort : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}