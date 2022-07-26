#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// Method : Depth First Search
// Time Complexity : O(V + E)  Space Complexity : O(V + E)  
void dfs(unordered_map <int, vector<int> > &adjList, vector<bool> &visited, stack<int> &st, int start){

    visited[start] = true;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            dfs(adjList, visited, st, adjList[start][i]);
        }
    }

    st.push(start);
}

vector<int> topologicalSort(int n, vector< pair<int, int> > &edges){

    vector<int> output;

    // Create the adjacency list
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
    }

    // Using DFS to find topological sort
    vector<bool> visited(n, false);
    stack<int> st;

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            dfs(adjList, visited, st, i);
        }
    }


    // Push all the elements from stack to vector
    while(!st.empty()){

        output.push_back(st.top());
        st.pop();
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