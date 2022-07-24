#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


// Method :  Breadth First Search
// Time Complexity : O()  Space Complexity : O()
void bfsHelper(unordered_map <int, vector<int> > &adjList, unordered_map <int, bool> &visited, int start){

    // Pushing elements in queue
    queue<int> q;
    q.push(start);

    visited[start] = true;

    while(!q.empty()){

        int front = q.front();
        q.pop();

        cout << front << " ";

        // Pushing connected nodes to start
        for(int i=0; i<adjList[front].size(); i++){

            if(visited[adjList[front][i]] == false){

                q.push(adjList[front][i]);
                visited[adjList[front][i]] = true;
            }
        }
    }
}

void bfsTraversal(int n, unordered_map <int, vector<int> > &adjList){

    cout << "\nBreadth First Search : ";

    // BFS Traversal
    unordered_map <int, bool> visited;
    
    // For disconnected graph
    for(int i=1; i<=n; i++){

        if(visited[i] == false){

            bfsHelper(adjList, visited, i);
        }
    }
}


int main()
{
    cout << "Enter number of vertices : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;


    // Creating a graph
    unordered_map <int, vector<int> > adjList;

    cout << "Enter Edges : \n";
    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Breadth First Search
    unordered_map <int, bool> visited;

    bfsTraversal(n, adjList);


    cout << endl;
    return 0;
}