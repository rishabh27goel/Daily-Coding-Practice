#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

// Method : Using Discovered Time and Lowest Time Vector
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
vector< pair<int, int> > bridges;

void bridgesHelper(unordered_map <int, vector<int> > &adjList, vector <int> &disc, vector <int> &low, vector <bool> &visited, int parent, int &timer, int start){

    // Update time of current node and mark it as visited
    visited[start] = true;
    
    disc[start] = timer;
    low[start] = timer;
    timer++;

    // Now move to neighbour nodes
    for(int i=0; i<adjList[start].size(); i++){

        // If neighbour is visited
        if(visited[adjList[start][i]] == false){

            bridgesHelper(adjList, disc, low, visited, start, timer, adjList[start][i]);

            // Update Low [after neighbour is visited]
            low[start] = min(low[start], low[adjList[start][i]]);

            // Check if we have a bridge between [start, adjList[start][i]]
            if(disc[start] < low[adjList[start][i]]){

                // Bridge Exits
                bridges.push_back(make_pair(start, adjList[start][i]));
            }
        }
        else{

            // If neighbour is parent
            if(adjList[start][i] == parent){

                continue;
            }
            else{

                // Back Edge [Update the low time]
                low[start] = min(low[start], disc[adjList[start][i]]);
            }
        }
    }
}

vector< pair<int, int> > findBridges(int n, vector< pair<int, int> > &edges){

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // Start finding the bridges
    vector <int> disc(n, -1);
    vector <int> low(n, -1);

    int parent = -1;
    int timer = 0;
    vector <bool> visited(n, false);

    for(int i=0; i<n; i++){

        if(visited[i] == false){

            bridgesHelper(adjList, disc, low, visited, parent, timer, i);
        }
    }


    return bridges;
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

    // Find Bridge in a Graph
    vector< pair<int, int> > bridge = findBridges(n, edges);

    cout << "Bridges Present : \n";
    
    for(int i=0; i<bridge.size(); i++){

        cout << bridge[i].first << " " << bridge[i].second << endl;
    }   


    cout << endl;
    return 0;
}