#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(2 ^ (n * m))  Space Complexity : O(n)
bool isSafe(vector< vector<int> > &matrix, int i, int j){

    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        return false;

    return true;
}

void allPossiblePaths(vector< vector<int> > &matrix, int row, int col, vector <int> &path, vector< vector<int> > &output){

    if(row == matrix.size()-1 && col == matrix[0].size()-1){

        path.push_back(matrix[row][col]);

        output.push_back(path);
        path.pop_back();

        return;
    }

    path.push_back(matrix[row][col]);

    // Move Downward
    if(isSafe(matrix, row+1, col)){

        allPossiblePaths(matrix, row+1, col, path, output);
    }

    // Move Forward
    if(isSafe(matrix, row, col+1)){

        allPossiblePaths(matrix, row, col+1, path, output);
    }


    // Backtracking
    path.pop_back();
}

vector< vector<int> > allPossiblePaths(vector< vector<int> > &matrix){

    vector< vector<int> > output;
    if(matrix.size() == 0) return output;

    // Generate all possible paths
    vector <int> path;
    
    allPossiblePaths(matrix, 0, 0, path, output);


    return output;
}

int main()
{
    cout << "Enter n and m : ";
    int n, m;
    cin >> n >> m;

    cout << "Enter matrix : \n";
    vector< vector<int> > matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> matrix[i][j];
        }
    }

    // All Possible Paths
    vector< vector<int> > output = allPossiblePaths(matrix);

    cout << "Possible Paths : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[0].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << output.size();

    cout << endl;
    return 0;
}