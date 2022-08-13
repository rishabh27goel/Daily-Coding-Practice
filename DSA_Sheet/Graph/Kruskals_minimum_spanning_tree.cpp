#include <iostream>
#include <vector>
using namespace std; 

// Method : Kruskal's Algorithm [Using Disjoint Set]
// Time Complexity : O(E * log(E))  Space Complexity : O(V)
vector <int> rankNode;
vector <int> parent;

// Path Compression
int findParent(int node){

    if(parent[node] == node){

        return node;
    }

    parent[node] = findParent(parent[node]);

    return parent[node];
}

// Union by Rank
void unionByRank(int px, int py){

    if(rankNode[px] < rankNode[py]){

        parent[px] = py;
    }
    else if(rankNode[px] > rankNode[py]){

        parent[py] = px;
    }
    else{

        parent[py] = px;
        rankNode[px]++;
    }
}

static bool compareEdge(const vector<int> &v1, const vector<int> &v2){

    return v1[2] < v2[2];
}

void minimumSpanningTree(int n, vector< vector<int> > &edges){

    vector <int> mst(n, INT_MAX);
    int total = 0;

    // Initialize Parent and Rank
    for(int i=0; i<n; i++){

        parent.push_back(i);
        rankNode.push_back(0);
    }

    // Sort the edges [Greedy Approach for MST]
    sort(edges.begin(), edges.end(), compareEdge);

    cout << "\nMinimum Spanning Tree : " << endl;

    // Find Minimum Spanning Tree
    for(int i=0; i<edges.size(); i++){

        int x = findParent(edges[i][0]);
        int y = findParent(edges[i][1]);

        int weight = edges[i][2];

        // Union Call
        if(x != y){

            mst[edges[i][1]] = weight;

            cout << edges[i][0] << " " << edges[i][1] << " " << weight << endl;

            total += weight;
            unionByRank(x, y);
        }
    }

    cout << "\nMinimum Cost : " << total << endl;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

// Input 
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 7 6 1
// 7 8 7
// 2 8 2
// 6 8 6
// 2 5 4
// 2 3 7
// 5 6 2
// 3 5 14
// 3 4 9
// 4 5 10

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

    // Kruskal's Algorithm
    minimumSpanningTree(n, edges);


    cout << endl;
    return 0;
}