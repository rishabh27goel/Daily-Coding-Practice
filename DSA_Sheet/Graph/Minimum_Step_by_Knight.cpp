#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Method : Breadth First Search
// Time Complexity : O(n^2)  Space Complexity : O(n^2)
bool isSafe(int n, int x, int y){

    if(x < 0 || y < 0 || x >= n || y >= n)
        return false;

    return true;
}

int minimumSteps(int n, pair<int, int> &start, pair<int, int> &target){

    if(n == 0) return 0;

    vector< vector<bool> > visited(n, vector<bool> (n, false));
    int step = 0;

    // Pushing start position 
    queue< pair<int, int> > q;

    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){

        int size = q.size();

        while(size--){

            pair<int, int> current = q.front();
            q.pop();

            if(current.first == target.first && current.second == target.second)
                return step;

            int xPos[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    	    int yPos[8] = {1, 2, 2, 1, -1, -2, -2, -1};

            for(int i=0; i<8; i++){

                int x = xPos[i] + current.first;
                int y = yPos[i] + current.second;

                // If next position is safe and not visited yet
                if(isSafe(n, x, y) && visited[x][y] == false){

                    q.push(make_pair(x, y));
                    visited[x][y] = true;
                }
            }
        }

        // Increament the step
        step += 1;
    }

    return -1;
}

int main()
{
    cout << "Enter value of n : ";
    int n;
    cin >> n;

    int a, b;
    pair<int, int> start;
    pair<int, int> target;

    cout << "Enter Starting Position : ";
    cin >> a >> b;
    start = make_pair(a, b);
    
    cout << "Enter Target Position : ";
    cin >> a >> b;
    target = make_pair(a, b);

    // Minimum Steps by Knight
    int step = minimumSteps(n, start, target);

    cout << "Minimum Steps : " << step;

    cout << endl;
    return 0;
}