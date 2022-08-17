#include <iostream>
#include <vector>
using namespace std;

// Method : Floyd Warshall Algorithm
// [Shortest Distance between every pair of vertices]
// Time Complexity : O(V^3)  Space Complexity : O(1)
void floydWarshall(int n, vector< vector<int> > &edges){

    vector< vector<int> > adjMatrix(n, vector<int> (n, INT_MAX));

    // Step 1 : Create Adjacency Matrix with (i, i) -> 0
    for(int i=0; i<edges.size(); i++){

        adjMatrix[edges[i][0]][edges[i][1]] = edges[i][2]; 
    }

    for(int i=0; i<n; i++){

        adjMatrix[i][i] = 0;
    }

    // Step 2 : From each vertex & update the shortest path
    for(int k=0; k<n; k++){

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(k != i && k != j && i != j){

                    if(adjMatrix[i][k] != INT_MAX && adjMatrix[k][j] != INT_MAX && adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]){

                        adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    }
                }
            }
        }
    }

    // Shortest Distance
    cout << "Shortest Distance : \n";

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(adjMatrix[i][j] == INT_MAX){

                cout << "INF" << " ";
            }
            else{

                cout << adjMatrix[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< vector<int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v, w;
        cin >> u >> v >> w;

        vector<int> ed;

        ed.push_back(u);
        ed.push_back(v);
        ed.push_back(w);

        edges.push_back(ed);
    }

    // Floyd Warshall Algorithm
    floydWarshall(n, edges);

    cout << endl;
    return 0;
}