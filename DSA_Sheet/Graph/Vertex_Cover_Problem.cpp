#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Taking each edge one by one
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
vector<int> vertexCover(int n, vector< pair<int, int> > &edges){

    vector<int> vertex;

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Now create the vertex cover
    vector <bool> visited(n, false); 
    
    for(int i=0; i<n; i++){

        if(visited[i] == false){

            for(int j=0; j<adjList[i].size(); j++){

                if(visited[adjList[i][j]] == false){

                    visited[adjList[i][j]] = true;
                    visited[i] = true;
 
                    break;
                }
            }
        }
    }

    // Vertex Cover
    for(int i=0; i<n; i++){

        if(visited[i] == true)
            vertex.push_back(i);
    }


    return vertex;
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

    // Vertex Cover Problem
    vector<int> vertex = vertexCover(n, edges);

    cout << "Vertex Cover : ";

    for(int i=0; i<vertex.size(); i++){

        cout << vertex[i] << " ";
    }


    cout << endl;
    return 0;
}