#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Dijkstra's Algorithm [Priority Queue]
// Time Complexity : O(E * log(V))  Space Complexity : O(V + E)
// class Info {

//     public:
//         int dist;
//         int node;
//         int stop;

//     Info(int dist, int node, int stop){

//         this->dist = dist;
//         this->node = node;
//         this->stop = stop;
//     }
// };

// class CompareInfo {

//     public:
//         bool operator()(Info* a, Info* b){

//             return a->dist < b->dist;
//         }
// };

// int cheapestFlights(int n, vector< vector<int> > &edges, int src, int dst, int k){

//     vector <int> shortest(n, INT_MAX);

//     // Create Adjacency List
//     vector< vector< pair<int, int> > > adjList(n);

//     for(int i=0; i<edges.size(); i++){

//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];

//         adjList[u].push_back(make_pair(v, w));
//     }

//     // Dijkstra Algorithm
//     priority_queue <Info*, vector<Info*>, CompareInfo> pq;

//     // Initialize Queue
//     pq.push(new Info(0, src, 0));
//     shortest[src] = 0;

//     while(!pq.empty()){

//         Info* top = pq.top();
//         pq.pop();

//         int distance = top->dist;
//         int start = top->node;
//         int stop = top->stop;

//         // If stop reaches k
//         if(stop > k)  continue;

//         for(int i=0; i<adjList[start].size(); i++){

//             int child = adjList[start][i].first;
//             int weight = adjList[start][i].second;

//             // Update Shortest Path
//             if(shortest[child] > distance + weight){

//                 shortest[child] = distance + weight;
//                 pq.push(new Info(distance + weight, child, stop + 1));
//             }
//         }
//     }

//     // If src to dst does not exits
//     if(shortest[dst] == INT_MAX)
//         return -1;


//     return shortest[dst];
// }


// Method 2 : Breadth First Search and Using Queue
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
int cheapestFlights(int n, vector< vector<int> > &edges, int src, int dst, int k){

    vector<int> shortest(n, INT_MAX);

    // Create Adjacency List
    vector< vector< pair<int, int> > > adjList(n);
 
    for(int i=0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back(make_pair(v, w));
    }

    // Find shortest distance till k stops 
    queue< pair<int, int> > q;

    q.push(make_pair(0, src));
    shortest[src] = 0;


    while(!q.empty() && k >= 0){

        int size = q.size();

        while(size--){

            pair<int, int> front = q.front();
            q.pop();

            int distance = front.first;
            int start = front.second;


            for(int i=0; i<adjList[start].size(); i++){

                int child = adjList[start][i].first;
                int weight = adjList[start][i].second;

                if(shortest[child] > distance + weight){

                    shortest[child] = distance + weight;
                    q.push(make_pair(distance + weight, child));
                }
            }
        }

        k--;
    }

    // If src to dst does not exits
    if(shortest[dst] == INT_MAX)
        return -1;


    return shortest[dst];
}


int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< vector<int> > edges;

    // Input : 
// 4
// [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
// 0
// 3
// 1

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v, w;
        cin >> u >> v >> w;

        vector <int> ed;

        ed.push_back(u);
        ed.push_back(v);
        ed.push_back(w);

        edges.push_back(ed);
    }

    cout << "Enter Source : ";
    int src;
    cin >> src;

    cout << "Enter Destination : ";
    int dst;
    cin >> dst;

    cout << "Enter Stops : ";
    int k;
    cin >> k;

    // Cheapest Flights within K Stops
    int cheap = cheapestFlights(n, edges, src, dst, k);

    cout << "Cheapest Flight : " << cheap;

    cout << endl;
    return 0;
}