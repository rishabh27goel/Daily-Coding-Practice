#include <iostream>
#include <vector>
using namespace std;

// Method : Bellman Ford Algorithm
// Time Complexity : O(n * m)  Space Complexity : O()
void findShortestDistance(int n, vector< vector<int> > &edges, int src){

    vector <int> dist(n, INT_MAX);

    // Start from Source
    dist[src] = 0;

    // Step 1 : Iterate over edges and update minimum distance n-1 times
    for(int i=1; i<=n-1; i++){

        for(int j=0; j<edges.size(); j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){

                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2 : Check for Negative Weight Cycle
    for(int j=0; j<edges.size(); j++){

        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != INT_MAX && dist[v] > dist[u] + w){

            cout << "\nNegative Cycle Exists !!";
            return;
        }
    }

    cout << "\nShortest Distance : ";

    for(int i=0; i<n; i++){

        cout << dist[i] << " ";
    }
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    // Input : 
// 0 1 1
// 1 2 -1
// 2 3 3
// 3 0 2
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

    cout << "Enter Source : ";
    int src;
    cin >> src;


    // Bellman Ford
    findShortestDistance(n, edges, src);

    cout << endl;
    return 0;
}