#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Method : Using topological order
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
void findTopologicalOrder(unordered_map <int, vector<int> > &adjList, vector<int> &inorder, vector<int> &time){

    // Using Queue for finding topological order
    queue <int> q;

    // Push the nodes with inorder 0
    for(int i=0; i<inorder.size(); i++){

        if(inorder[i] == 0){

            q.push(i);
            time[i] = 1;
        }
            
    }

    // Traverse the graph
    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int i=0; i<adjList[front].size(); i++){

            inorder[adjList[front][i]]--;

            if(inorder[adjList[front][i]] == 0){

                // Use bfs it will gives minimum time always
                time[adjList[front][i]] = time[front] + 1;

                q.push(adjList[front][i]);
            }
        }
    }
}

vector<int> minimumTimeTaken(int n, vector< pair<int, int> > &edges){

    vector<int> time(n);

    // Create Adjacency List
    unordered_map <int, vector<int> > adjList;
    vector<int> inorder(n, 0);

    for(int i=0; i<edges.size(); i++){

        // Directed Edges
        adjList[edges[i].first-1].push_back(edges[i].second-1);

        // Update Inorder
        inorder[edges[i].second-1]++;
    }

    // Using Topological Order along with updating time
    // [Source as node in-degree with 0]

    findTopologicalOrder(adjList, inorder, time);

    return time;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

// Input : 10 13
// 1 3
// 1 4
// 1 5
// 2 3
// 2 8
// 2 9
// 3 6
// 4 6
// 4 8
// 5 8
// 6 7
// 7 8
// 8 10

    vector< pair<int, int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));    
    }

    // Minimum Time Taken 
    vector<int> time = minimumTimeTaken(n, edges);

    cout << "Time Taken : ";
    for(int i=0; i<time.size(); i++){

        cout << time[i] << " ";
    }

    cout << endl;
    return 0;
}