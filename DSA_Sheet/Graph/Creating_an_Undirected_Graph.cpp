#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class UndirectedGraph {

    public:
        unordered_map <int, vector<int> > adjList;


    void addEdge(int u, int v){

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph(){

        unordered_map <int, vector<int> > :: iterator itr;

        cout << "Printing Undirected Graph : \n";

        for(itr = adjList.begin(); itr != adjList.end(); itr++){

            cout << itr->first << " -> ";
            
            for(int i=0; i<itr->second.size(); i++){

                cout << itr->second[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    // Creating a Graph
    UndirectedGraph ug;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        ug.addEdge(u, v);
    }

    // Adjacency List
    ug.printGraph();


    cout << endl;
    return 0;
}