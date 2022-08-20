#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Using Discovered Time and Lowest Time Vector
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
void dfsPoint(unordered_map <int, vector<int> > &adjList, vector <int> &disc, vector <int> &low, vector <bool> &visited, int &timer, int start, int parent, vector <bool> &point){

    int child = 0;

    visited[start] = true;
    disc[start] = low[start] = timer++;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited[adjList[start][i]] == false){

            child++;

            // Check Neighbour Nodes
            dfsPoint(adjList, disc, low, visited, timer, adjList[start][i], start, point);
        
            // Update lowest time 
            low[start] = min(low[start], low[adjList[start][i]]);

            // Check for articulation point
            if(low[adjList[start][i]] >= disc[start] && parent != -1){

                point[start] = true;
            }
        }
        else{
                
            // Back Edge
            low[start] = min(low[start], disc[adjList[start][i]]);
        }
    }

    // Extra Case [For Articulation Point]
    if(parent == -1 && child > 1){

        point[start] = true;
    }
}

vector<int> articulationPoint(int n, vector< pair<int, int> > &edges){

    vector<int> artiPoints;

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // Start finding articulation point
    vector <bool> point(n, false);
    vector <bool> visited(n, false);

    vector <int> disc(n, -1);
    vector <int> low(n, -1);

    int timer = 0;

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            dfsPoint(adjList, disc, low, visited, timer, i, -1, point);
        }
    }

    // Get the articulation points
    for(int i=0; i<n; i++){

        if(point[i] == true){

            artiPoints.push_back(i);
        }
    }


    return artiPoints;
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

    // Articulation Point of Graph
    vector<int> point = articulationPoint(n, edges);

    cout << "Articulation Point : ";
    
    for(int i=0; i<point.size(); i++){

        cout << point[i] << " ";
    }

    cout << endl;
    return 0;
}