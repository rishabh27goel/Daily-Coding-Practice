#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

// Method 1 : Breadth First Search
// Time complexity : O(V + E)  Space Complexity : O(V + E)
// bool cycleHelper(unordered_map <int, vector<int> > &adjList, unordered_map <int, int> &visited, int start){

//     queue <int> q;
//     q.push(start);

//     visited[start] = -1;

//     while(!q.empty()){

//         int front = q.front();
//         q.pop();

//         // Add connceted node to the queue other than parent
//         for(int i=0; i<adjList[front].size(); i++){

//             if(visited.find(adjList[front][i]) == visited.end()){

//                 q.push(adjList[front][i]);
//                 visited[adjList[front][i]] = front;
//             }
//             else{

//                 // If already present node value is other than parent
//                 // It means loop exits
//                 if(visited[front] != adjList[front][i] && visited[adjList[front][i]] != front)
//                      return true;
//             }
//         }
//     }

//     return false;
// }

// bool detectCycle(int n, vector< pair<int, int> > &edges){

//     if(n == 0) return false;

//     // Create adjacency list
//     unordered_map <int, vector<int> > adjList;

//     for(int i=0; i<edges.size(); i++){

//         int x = edges[i].first;
//         int y = edges[i].second;

//         adjList[x].push_back(y);
//         adjList[y].push_back(x);
//     }

//     unordered_map <int, int> visited;

//     for(int i=1; i<=n; i++){

//         if(visited.find(i) == visited.end()){

//             if(cycleHelper(adjList, visited, i)){

//                 return true;
//             }
//         }
//     }

//     return false;
// }

// Method 2 : Depth First Search
// Time complexity : O(V + E)  Space Complexity : O(V + E)
bool cycleHelper(unordered_map <int, vector<int> > &adjList, unordered_map <int, int> &visited, int parent, int start){

    visited[start] = parent;

    for(int i=0; i<adjList[start].size(); i++){

        if(visited.find(adjList[start][i]) == visited.end()){

            // If cycle exits with this path
            if(cycleHelper(adjList, visited, start, adjList[start][i])){

                return true;
            }
        }
        else{
            
            if(parent != adjList[start][i] && visited[adjList[start][i]] != start){

                return true;
            }
        }
    }

    return false;
}

bool detectCycle(int n, vector< pair<int, int> > &edges){

    if(n == 0)  return false;

    // Create adjacency list
    unordered_map <int, vector<int> > adjList;

    for(int i=0; i<edges.size(); i++){

        int x = edges[i].first;
        int y = edges[i].second;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    unordered_map <int, int> visited;

    for(int i=1; i<=n; i++){

        if(visited.find(i) == visited.end()){

            if(cycleHelper(adjList, visited, -1, i)){

                return true;
            }
        }
    }

    return false;
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

    // Detect Cycle in Undirected Graph
    bool loop = detectCycle(n, edges);

    if(loop){

        cout << "Loop exits !!";
    }
    else{

        cout << "Loop doesn't exits !!";
    }

    cout << endl;
    return 0;
}