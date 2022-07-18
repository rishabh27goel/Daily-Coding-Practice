#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(4 ^ (m * n))  Space Complexity : O(m * n)
bool isSafe(vector< vector<int> > &matrix, int i, int j){

    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        return false;

    return true;
}

void longestRouteHelper(vector< vector<int> > &matrix, vector< vector<bool> > &visited, pair<int, int> &src, pair<int, int> &dst, int count, int &longest){

    if(src.first == dst.first && src.second == dst.second){

        longest = max(longest, count);
        return;
    }

    visited[src.first][src.second] = true;

    // Position Vector
    int xPos[4] = {0, 1, 0, -1};
    int yPos[4] = {1, 0, -1, 0};

    for(int i=0; i<4; i++){

        int a = src.first + xPos[i];
        int b = src.second + yPos[i];

        if(isSafe(matrix, a, b) && visited[a][b] == false && matrix[a][b] == 1){

            pair<int, int> pr = make_pair(a, b);

            longestRouteHelper(matrix, visited, pr, dst, count + 1, longest);
        }
    }

    // Backtracking
    visited[src.first][src.second] = false;
}

int longestRoute(vector< vector<int> > &matrix, int sx, int sy, int dx, int dy){

    int n = matrix.size();
    int m = matrix[0].size();

    if(n == 0 || m == 0)  return 0;

    // Longest Possible Route
    int longest = 0;
    pair<int, int> source = make_pair(sx, sy);
    pair<int, int> destination = make_pair(dx, dy);

    vector< vector<bool> > visited(n, vector<bool> (m, false));

    longestRouteHelper(matrix, visited, source, destination, 0, longest);

    return longest;
}

int main()
{
    cout << "Enter m and n : ";
    int m, n;
    cin >> n >> m;

// Input : 
// 1 1 1 1 1 1 1 1 1 1
// 1 1 0 1 1 0 1 1 0 1
// 1 1 1 1 1 1 1 1 1 1
    cout << "Enter matrix : \n";
    vector< vector<int> > matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> matrix[i][j];
        }
    }

    cout << "Enter Source Index : ";
    int sx, sy;
    cin >> sx >> sy;

    cout << "Enter Destination Index : ";
    int dx, dy;
    cin >> dx >> dy;

    // Longest Possible Route 
    int longest = longestRoute(matrix, sx, sy, dx, dy);

    cout << "Longest Route : " << longest;

    cout << endl;
    return 0;
}