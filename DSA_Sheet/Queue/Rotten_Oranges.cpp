#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(m^2 * n^2)   Space Complexity : O(1)
// int rottenOranges(vector<vector<int> > matrix){

//     int m = matrix.size();
//     if(m == 0) return 0;
//     int n = matrix[0].size();

//     int minTime = 0;
//     int rottenStart = 2;

//     while(true){

//         bool rottenSome = false;

//         for(int i=0; i<m; i++){

//             for(int j=0; j<n; j++){

//                 if(matrix[i][j] == rottenStart){

//                     int x = i;
//                     int y = j;

//                     int dirX[4] = {1, -1, 0, 0};
//                     int dirY[4] = {0, 0, 1, -1};

//                     for(int k=0; k<4; k++){

//                         int adjX = x + dirX[k];
//                         int adjY = y + dirY[k];
                        
//                         // If adjX & adjY are valid
//                         if((adjX >= 0 && adjX < m) && (adjY >= 0 && adjY < n)){

//                             // Only for fresh oranges
//                             if(matrix[adjX][adjY] == 1){

//                                 matrix[adjX][adjY] = matrix[x][y] + 1;
//                                 rottenSome = true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         if(rottenSome == false){

//             break;
//         }

//         // Update rotten value for next Frame
//         rottenStart++;
//         minTime++;
//     }

//     // Check if still some oranges are fresh or not
//     for(int i=0; i<m; i++){

//         for(int j=0; j<n; j++){

//             if(matrix[i][j] == 1)
//                 return -1;
//         }
//     }

//     return minTime;
// }

// Method 2 : Using Queue
// Time Complexity : O(m * n)   Space Complexity : O(m * n)
bool checkDelimiter(pair<int, int> p){

    if(p.first == -1 && p.second == -1){

        return true;
    }
    else{

        return false;
    }
}

int rottenOranges(vector<vector<int> > matrix){

    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();

    queue<pair<int, int> > rotten;
    int minTime = 0;

    // Store pair(i, j) of rotten oranges
    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            // If Rotten Oranges then store in Queue
            if(matrix[i][j] == 2){

                rotten.push(make_pair(i, j));
            }
        }
    }

    // Add Delimiter
    rotten.push(make_pair(-1, -1));

    while(!rotten.empty()){

        bool rottenSome = false;

        // Check for frame [Reach till Delimiter]
        while(!checkDelimiter(rotten.front())){

            pair<int, int> p = rotten.front();
            rotten.pop();

            int x = p.first;
            int y = p.second;

            int dirX[4] = {1, -1, 0, 0};
            int dirY[4] = {0, 0, 1, -1};
        
            for(int i=0; i<4; i++){

                int adjX = x + dirX[i];
                int adjY = y + dirY[i];

                // If adjX & adjY are valid
                if((adjX >= 0 && adjX < m) && (adjY >= 0 && adjY < n)){

                    // Only for fresh oranges
                    if(matrix[adjX][adjY] == 1){

                        // Make it rotten
                        matrix[adjX][adjY] = 2;
                        rotten.push(make_pair(adjX, adjY));
                        rottenSome = true;
                    }
                }
            }
        }

        // If Frame Ends [We get the Delimiter] -> Remove it
        rotten.pop();

        if(!rotten.empty()){

            // Add a delimiter
            rotten.push(make_pair(-1, -1));
        }

        // Move to next frame
        if(rottenSome){

            minTime += 1;
        }
    }

    // Check if still some oranges are fresh or not
    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            if(matrix[i][j] == 1)
                return -1;
        }
    }

    return minTime;
}

int main()
{
    int m, n;
    cout << "Enter Rows and Columns of the matrix : ";
    cin >> m >> n;

    vector<vector<int> > matrix(m);
    int data;

    cout << "Enter Matrix : \n";
    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            cin >> data;
            matrix[i].push_back(data);
        }
    }

//  0 : Empty cell
//  1 : Cells have fresh oranges
//  2 : Cells have rotten oranges

    int time = rottenOranges(matrix);
    
    cout << "Min Time Required : " << time;

    cout << endl;
    return 0;
}