#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// Method : Using Set
// Time Complexity : O(E * log(V))  Space Complexity : O(V + E)
vector<int> dijkstraAlgo(int n, vector< vector<int> > &edges, int src){

    // Initialize Paths
    vector<int> shortest(n, INT_MAX);

    // Create Adjacency List
    unordered_map<int, vector<pair<int, int> > >  adjList;

    for(int i=0; i<edges.size(); i++){

        adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjList[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    // Start from Source [Add Pair of [Distance, Node]]
    set< pair<int, int> >  st;

    st.insert(make_pair(0, src));
    shortest[src] = 0;

    while(!st.empty()){

        // As the set will give us the minimum distance at the start
        pair<int, int> top = *(st.begin());
        st.erase(st.begin());

        int distance = top.first;
        int start = top.second;

        for(int i=0; i<adjList[start].size(); i++){

            int child = adjList[start][i].first;
            int weight = adjList[start][i].second;

            if(shortest[child] > distance + weight){

                // Before adding new child with updated distance
                // Remove previous distance of same node if exits

                set <pair<int, int> > :: iterator itr = st.find(make_pair(shortest[child], child));

                // It means child exits in the set
                if(itr != st.end()){

                    st.erase(itr);
                }


                st.insert(make_pair(distance + weight, child));
                shortest[child] = distance + weight;
            }
        }
    }

    return shortest;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    vector< vector<int> > edges;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v, w;
        cin >> u >> v >> w;

        vector<int> edg;

        edg.push_back(u);
        edg.push_back(v);
        edg.push_back(w);

        edges.push_back(edg);
    }

    cout << "Enter Source : ";
    int src;
    cin >> src;

    // Dijkstra Algorithm
    vector<int> shortest = dijkstraAlgo(n, edges, src);

    cout << "Shortest Path : ";
    for(int i=0; i<shortest.size(); i++){

        cout << shortest[i] << " ";
    }


    cout << endl;
    return 0;
}