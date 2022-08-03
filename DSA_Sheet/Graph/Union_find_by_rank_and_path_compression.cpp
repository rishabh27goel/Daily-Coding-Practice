#include <iostream>
#include <vector>
using namespace std;

// Method : Union by Rank and Path Compression
vector<int> nodeParent;
vector<int> nodeRank;

int findParent(int node){

    // Base Case
    if(nodeParent[node] == node){

        return node;
    }

    // Path Compression
    nodeParent[node] = findParent(nodeParent[node]);

    return nodeParent[node];
}

void findUnion(int n, vector< pair<int, int> > &edges){

    // Initialize Rank and Parent
    for(int i=0; i<n; i++){

        nodeParent.push_back(i);
        nodeRank.push_back(0);       
    }

    for(int i=0; i<edges.size(); i++){

        // Getting Parents
        int u = findParent(edges[i].first);
        int v = findParent(edges[i].second);

        // Union by Rank
        if(nodeRank[u] < nodeRank[v]){

            nodeParent[u] = v;
        }
        else if(nodeRank[u] > nodeRank[v]){

            nodeParent[v] = u;
        }
        else{

            nodeParent[v] = u;
            nodeRank[u]++;
        }
    }

    cout << "\nRank of nodes : ";
    for(int i=0; i<n; i++){

        cout << nodeRank[i] << " ";
    }

    cout << "\nParent of nodes : ";
    for(int i=0; i<n; i++){

        cout << nodeParent[i] << " ";
    }
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

    // Finding Union
    findUnion(n, edges);

    cout << endl;
    return 0;
}