#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// Method : Dijkstra's Algorithm
// Time Complexity : O(E * log(V))  Space Complexity : O(V + E)
int minimumEdges(int n, vector< pair<int, int> > &edges, int src, int dst){

    // Create Adjacency List [Original : Weight 0 and Reverse : Weight 1]
    unordered_map <int, vector< pair<int, int> > >  adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(make_pair(edges[i].second, 0));
        adjList[edges[i].second].push_back(make_pair(edges[i].first, 1));
    }

    // Using Dijkstra's Algorithm
    vector <int> shortest(n, INT_MAX);

    set< pair<int, int> > st; // {Distance, Source}

    st.insert(make_pair(0, src));
    shortest[src] = 0;

    while(!st.empty()){

        pair <int, int> front = *(st.begin());
        st.erase(st.begin());

        int distance = front.first;
        int start = front.second;
        

        for(int i=0; i<adjList[start].size(); i++){

            int child = adjList[start][i].first;
            int weight = adjList[start][i].second;

            if(shortest[child] > distance + weight){

                // If we have duplicate of child in set
                set< pair<int, int> > :: iterator itr = st.find(make_pair(shortest[child], child));

                if(itr != st.end()){

                    st.erase(itr);
                }

                shortest[child] = distance + weight;
                st.insert(make_pair(distance + weight, child));
            }
        }
    }

    // Now get the minimum distance from source to destination
    if(shortest[dst] == INT_MAX)
        return -1;


    return shortest[dst];
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
    int src;
    cin >> src;

    cout << "Enter Destination : ";
    int dst;
    cin >> dst;

    // Minimum Edges to Reverse
    int mini = minimumEdges(n, edges, src, dst);

    cout << "Minimum Edges : " << mini;


    cout << endl;
    return 0;
}