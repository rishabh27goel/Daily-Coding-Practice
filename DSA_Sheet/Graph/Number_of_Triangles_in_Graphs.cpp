#include <iostream>
#include <vector>
using namespace std;

// Method : Nested Loops [Counting Triplets]
// Time Complexity : O(V^3)  Space Complexity : O(V^2)
int numberOfTriangles(int n, vector< pair<int, int> > &edges){

    int triangle = 0;

    // Create Adjacency Matrix
    vector< vector<int> > adjMatrix(n, vector<int> (n, 0));

    for(int i=0; i<edges.size(); i++){

        // Directed Graph
        adjMatrix[edges[i].first][edges[i].second] = 1;

        // Undirected Graph
        adjMatrix[edges[i].second][edges[i].first] = 1;
    }

    cout << endl;

    // 3 Nested Loops [Check for all Triplets]
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            for(int k=0; k<n; k++){

                if(i != j && j != k && k != i){

                    if(adjMatrix[i][j] && adjMatrix[j][k] && adjMatrix[k][i]){

                        triangle++;
                    }
                }
            }
        }
    }

    // Directed Graph
    // return triangle / 3;

    // Undirected Graph
    return triangle / 6;
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

    // Number of Triangles
    int triangle = numberOfTriangles(n, edges);

    cout << "Total Triangles : " << triangle;

    cout << endl;
    return 0;
}