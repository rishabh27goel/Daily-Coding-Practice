#include <iostream>
#include <vector>
using namespace std;

void copyMatrixHelper(int row, int col, vector< vector<int> > &matrix, vector< vector<int> > &copyMat){
        
    int n = matrix.size();
    int x = 0;
    int y = 0;
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            
            if(i != row && j != col){
                
                copyMat[x][y++] = matrix[i][j];
                
                // Next Row
                if(y == n-1){
                    
                    y = 0;
                    x += 1;
                }
            }
        }
    }
}


int determinantOfMatrix(vector<vector<int> > &matrix, int n)
{
    if(n == 1)
        return matrix[0][0];
    
    int output = 0;
    int sign = 1;
    
    vector< vector<int> > copyMat(n, vector<int> (n));
    
    for(int i=0; i<n; i++){
        
        copyMatrixHelper(i, 0, matrix, copyMat);
        output += (sign * matrix[i][0] * determinantOfMatrix(copyMat, n-1));
        
        sign *= -1;
    }
    
    
    return output;
}

int findSpanningTrees(int n, vector< pair<int, int> > &edges){

    // Step 1 : Create Adjacency Matrix
    vector< vector<int> > adjMatrix(n, vector<int> (n, 0));

    for(int i=0; i<edges.size(); i++){

        adjMatrix[edges[i].first-1][edges[i].second-1] = 1;
        adjMatrix[edges[i].second-1][edges[i].first-1] = 1;
    }

    // Step 2 : Update the matrix with node degrees at (i,i) and (rest 1 -> -1)
    for(int i=0; i<n; i++){

        int degree = 0;

        for(int j=0; j<n; j++){

            if(adjMatrix[i][j] == 1){

                adjMatrix[i][j] = -1;
                degree++;
            }
        }

        adjMatrix[i][i] = degree;
    }

    // Step 3 : Find the co-factor of the matrix
    vector< vector<int> > copyMatrix(n, vector<int> (n));
    copyMatrixHelper(0, 0, adjMatrix, copyMatrix);

    int cofactor = determinantOfMatrix(copyMatrix, n-1);

    return cofactor;
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

    // Total Spanning Trees
    int total = findSpanningTrees(n, edges);

    cout << "Total Spanning Trees : " << total;


    cout << endl;
    return 0;
}