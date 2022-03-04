#include <iostream>
#inclide <vector>
using namespace std;

class Solution{
    public:
    
    vector <string> solution;
    
    void findPathHelper(int row, int col, vector<vector<int>> maze, vector<vector<int>> track, int n, string path){
        
        if(row == n-1 && col == n-1){
            
            solution.push_back(path);
        }
        
        track[row][col] = 1;
        
        
        // Check Down  
        if(row+1 < n && maze[row+1][col] == 1 && track[row+1][col] == 0)
            findPathHelper(row+1, col,maze, track, n, path + 'D');
        
        // Check Up
        if(row-1 >= 0 && maze[row-1][col] == 1 && track[row-1][col] == 0)
            findPathHelper(row-1, col,maze, track, n, path + 'U');
        
        // Check Left
        if(col-1 >= 0 && maze[row][col-1] == 1 && track[row][col-1] == 0)
            findPathHelper(row, col-1,maze, track, n, path + 'L');
        
        // Check Right
        if(col+1 < n && maze[row][col+1] == 1 && track[row][col+1]  == 0)
            findPathHelper(row, col+1,maze, track, n, path + 'R');
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(n == 0 || m[0][0] == 0) return solution;
        
        vector<vector<int>> track(n, vector<int> (n, 0));
        
        string path = "";
        
        findPathHelper(0, 0, m, track, n, path);
        
        return solution;
    }
};