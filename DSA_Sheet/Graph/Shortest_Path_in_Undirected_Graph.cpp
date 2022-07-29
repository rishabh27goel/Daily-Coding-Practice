#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Method : Breadth First Search & Keeping parent track
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
vector<int> shortestPath(int n, vector< pair<int, int> > &edges, int s, int d){

    vector <int> path;

    // Creating Adjacency List
    unordered_map <int, vector<int> > adjList;
 
    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // BFS
    unordered_map <int, int> visited;
    queue <int> q;

    q.push(s);
    visited[s] = -1;

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int i=0; i<adjList[front].size(); i++){

            if(visited.find(adjList[front][i]) == visited.end()){

                q.push(adjList[front][i]);
                visited[adjList[front][i]] = front;
            }
        }
    }

    // Create the path using map
    int index = d;

    while(index != -1){

        path.push_back(index);
        index = visited[index];
    }

    reverse(path.begin(), path.end());

    return path;
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

    cout << "Enter Source : ";
    int s;
    cin >> s;

    cout << "Enter Destination : ";
    int d;
    cin >> d;

    // Shortest Path
    vector<int> path = shortestPath(n, edges, s, d);

    cout << "Shortest Path : ";
    for(int i=0; i<path.size(); i++){

        cout << path[i] << " ";
    }

    cout << endl;
    return 0;
}