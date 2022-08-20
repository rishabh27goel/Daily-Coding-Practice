#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Check bipartite graph on complement
// Time Complexity : O(V^2)  Space Complexity : O(V^2)
bool dfsBipartite(vector< vector<int> > &adjMat, vector<int> &visited, int start){

    int n = visited.size();

    // Check Neighbour Nodes
    for(int i=0; i<n; i++){

        // For Complement Nodes
        if(start != i && adjMat[start][i] == 1){

            // Color neighbour nodes
            if(visited[i] == -1){

                visited[i] = visited[start] ^ 1;

                if(dfsBipartite(adjMat, visited, i) == false){

                    return false;
                }
            }
            else{

                // If we have same color on neighbour
                if(visited[start] == visited[i])
                    return false;
            }
        }
    }

    return true;
}

bool twoClique(int n, vector< pair<int, int> > &edges){

    // Create Adjacency Matrix
    vector< vector<int> > adjMat(n, vector<int> (n, 1));

    for(int i=0; i<edges.size(); i++){

        adjMat[edges[i].first][edges[i].second] = 0;
        adjMat[edges[i].second][edges[i].first] = 0;
    }

    // Check for Bipartite Graph on Complement
    vector <int> visited(n, -1);
    
    for(int i=0; i<n; i++){

        if(visited[i] == -1){

            visited[i] = 0;

            if(dfsBipartite(adjMat, visited, i) == false){

                return false;
            }
        }
    }

    return true;
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

    // Two Clique Problem
    bool possible = twoClique(n, edges);

    if(possible){

        cout << "Two Clique Possible !!";
    }
    else{

        cout << "Two Clique not Possible !!";
    }


    cout << endl;
    return 0;
}