#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Using Euler Tour
vector<int> tour;
unordered_map<int, int> level;
unordered_map<int, int> startIndex;
unordered_map<int, int> endIndex;

void eulerTour(unordered_map<int, vector<int> > &adjList, int start, int lvl){

    tour.push_back(start);
    level[start] = lvl;

    for(int i=0; i<adjList[start].size(); i++){

        if(level.find(adjList[start][i]) == level.end()){

            eulerTour(adjList, adjList[start][i], lvl + 1);
        }
    }

    tour.push_back(start);
}

void fillMax(vector<int> &prefixMax, vector<int> &suffixMax){

    prefixMax = vector<int> (tour.size());
    suffixMax = vector<int> (tour.size());

    int mx = INT_MIN;
        
    for(int i=0; i<tour.size(); i++){
        
        mx = max(mx, level[tour[i]]);
        
        prefixMax[i] = mx;
    }

    mx = INT_MIN;

    for(int i=tour.size()-1; i>=0; i--){
            
        mx = max(mx, level[tour[i]]);
        
        suffixMax[i] = mx;
    }
}

vector<int> roadBlockage(int n, vector< pair<int, int> > &edges, vector< pair<int, int> > &query){

    vector<int> distance;

    // Create Adjacency List
    unordered_map<int, vector<int> > adjList;
 
    for(int i=0; i<edges.size(); i++){

        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    // Get Euler Tour
    eulerTour(adjList, 0, 0);

    // Find Prefix Max
    vector<int> prefixMax;
    vector<int> suffixMax;

    fillMax(prefixMax, suffixMax);

    // Fill start and end mapping for Queries
    for(int i=0; i<tour.size(); i++){

        if(startIndex.find(tour[i]) == startIndex.end()){

            startIndex[tour[i]] = i;
        }

        endIndex[tour[i]] = i;
    }

    // Now find distance for queries
    for(int i=0; i<query.size(); i++){

        int x = query[i].first;
        int y = query[i].second;

        int cost;

        if(level[x] < level[y]){

            cost = max(prefixMax[startIndex[y] - 1], suffixMax[endIndex[y] + 1]);
        }
        else{

            cost = max(prefixMax[startIndex[x] - 1], suffixMax[endIndex[x] + 1]);
        }

        distance.push_back(cost);
    }

    return distance;
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

    vector< pair<int, int> > query;

    cout << "Enter number of queries : ";
    int q;
    cin >> q;

    for(int i=0; i<q; i++){

        int a, b;
        cin >> a >> b;

        query.push_back(make_pair(a, b));
    }

    // Road Blockage
    vector<int> output = roadBlockage(n, edges, query);

    cout << "Max Distance : ";
    
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }


    cout << endl;
    return 0;
}