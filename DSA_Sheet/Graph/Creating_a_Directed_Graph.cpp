#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {

    public:
        int n;
        vector< vector<int> > adjMatrix;

    DirectedGraph(int n){

        this->n = n;
        adjMatrix.resize(n, vector<int> (n, 0));
    }

    void addEdge(int u, int v){

        adjMatrix[u][v] = 1; 
    }

    void printGraph(){

        cout << "\nPrinting Directed Graph : \n";

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                cout << adjMatrix[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;

    // Creating a graph
    DirectedGraph dg(n);

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        dg.addEdge(u, v);
    }

    dg.printGraph();


    cout << endl;
    return 0;
}