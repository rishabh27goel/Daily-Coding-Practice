#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(4 ^ (n * n)) or O(3 ^ (n * n))   Space Complexity : O(n * n)
// [O(3 ^ (n * n))] As at max a point (i, j) will have 3 position to travel
bool isSafe(vector< vector<int> > &maze, vector< vector<int> > &visited, int i, int j){

    if(i < 0 || j < 0 || i >= maze.size() || j >= maze.size())
        return false;

    // If new position is not visited and not 0
    if(maze[i][j] == 0 || visited[i][j] == 1)
        return false;

    return true;
}

void ratInMazeHelper(vector< vector<int> > &maze, vector< vector<int> > &visited, int i, int j, string path, vector<string> &output){

    int n = maze.size();

    if(i == n-1 && j == n-1){

        output.push_back(path);
        return;
    }

    // Down Case
    if(isSafe(maze, visited, i+1, j)){

        visited[i][j] = 1;
        ratInMazeHelper(maze, visited, i+1, j, path + 'D', output);

        visited[i][j] = 0; 
    }

    // Left Case
    if(isSafe(maze, visited, i, j-1)){

        visited[i][j] = 1;
        ratInMazeHelper(maze, visited, i, j-1, path + 'L', output);

        visited[i][j] = 0; 
    }

    // Right Case
    if(isSafe(maze, visited, i, j+1)){

        visited[i][j] = 1;
        ratInMazeHelper(maze, visited, i, j+1, path + 'R', output);

        visited[i][j] = 0; 
    }

    // Up Case
    if(isSafe(maze, visited, i-1, j)){

        visited[i][j] = 1;
        ratInMazeHelper(maze, visited, i-1, j, path + 'U', output);

        visited[i][j] = 0; 
    }
}

vector<string> ratInMaze(vector< vector<int> > &maze){

    vector<string> output;
    if(maze.size() == 0) return output;

    int n = maze.size();

    // If path does not exits
    if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return output;

    // Visited Array to track the path
    vector< vector<int> > visited(n, vector<int> (n, 0));

    ratInMazeHelper(maze, visited, 0, 0, "", output);

    return output;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter maze : \n";
    vector< vector<int> > maze(size);
    int data = 0;

    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){

            cin >> data;
            maze[i].push_back(data);
        }
    }

    // Rat in a maze
    vector<string> output = ratInMaze(maze);

    cout << "Paths of maze : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }


    cout << endl;
    return 0;
}