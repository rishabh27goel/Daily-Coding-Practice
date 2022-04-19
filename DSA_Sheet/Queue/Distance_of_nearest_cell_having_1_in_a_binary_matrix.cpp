#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#include <math.h>

// Method 1 : Brute Force
// Time Complexity : O(m^2 * n^2)   Space Complexity : O(1)
// vector<vector<int> > distanceNearestCell(vector<vector<int> > matrix){

//     int m = matrix.size();
//     if(m == 0) return matrix;
//     int n = matrix[0].size();

//     vector<vector<int> > output(m, vector<int> (n, 0));

//     // Iterate & check each element
//     for(int i=0; i<m; i++){

//         for(int j=0; j<n; j++){

//             if(matrix[i][j] == 1){

//                 output[i][j] = 0;
//             }
//             else{

//                 // If matrix[i][j] is 0
//                 int getMin = INT_MAX;

//                 for(int x=0; x<m; x++){

//                     for(int y=0; y<n; y++){

//                         if(matrix[x][y] == 1){

//                             getMin = min(getMin, abs(x-i) + abs(y-j));
//                         }
//                     }
//                 }

//                 output[i][j] = getMin; 
//             }
//         }
//     }

//     return output;
// }

// Method 2 : Using Queue
// Time Complexity : O(m * n)   Space Complexity : O(m * n)
vector<vector<int> > distanceNearestCell(vector<vector<int> > matrix){

    int m = matrix.size();
    if(m == 0) return matrix;
    int n = matrix[0].size();

    vector<vector<int> > output(m, vector<int> (n, INT_MAX));
    queue<pair<int, int> > q;

    // Store i,j pairs where matrix[i][j] = 1 in queue
    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            if(matrix[i][j] == 1){

                output[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){

        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        int dirX[4] = { -1, 0, 1, 0 };
        int dirY[4] = { 0, 1, 0, -1 };

        for(int i=0; i<4; i++){

            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if((newX >= 0 && newX < m) && (newY >=0 && newY < n)){
                    
                if(output[x][y] + 1 < output[newX][newY]){
                    
                    output[newX][newY] = output[x][y] + 1;
                    q.push(make_pair(newX, newY));
                }
            }
        }
    }

    return output;
}

int main()
{
    int m, n;
    cout << "Enter number of Rows and Columns : ";
    cin >> m >> n;

    vector<vector<int> > matrix(m);
    int data;

    cout << "Enter matrix : ";
    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            cin >> data;
            matrix[i].push_back(data);
        }
    }

    vector<vector<int> > output = distanceNearestCell(matrix);
    
    cout << "Distance Array : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[0].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}