#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force 
int maximumSizeRectangle(vector<vector<int> > input){

    int n = input.size();
    int m = input[0].size();

    if(n == 0 || m == 0) return 0;

    int maxArea = 0;

    // Iterating Input Matrix
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            // Length and Breadth all possible values starting from i, j
            if(input[i][j] == 0) continue;

            for(int l=i; l<n; l++){

                for(int b=j; b<m; b++){

                    bool containOnes = true; 
                    int count = 0;

                    // Counting Ones (Comparing Start to End)
                    for(int x=i; x<=l; x++){

                        for(int y=j; y<=b; y++){

                            if(input[x][y] == 0){

                                containOnes = false;
                                break;
                            }

                            count++;
                        }

                        if(containOnes == false) break;
                    }  

                    if(containOnes == true){

                        if(maxArea < count){

                            maxArea = count;
                        }
                    }
                }
            }
        }
    }

    return maxArea;
}

int main()
{
    int n, m;
    cout << "Enter row size : ";
    cin >> n;

    cout << "Enter column size : ";
    cin >> m;

    cout << "Enter matrix values : ";
    vector<vector<int> > input(n, vector<int> (m));
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> input[i][j];
        }
    }

    int maxArea = maximumSizeRectangle(input);
    cout << "Maximum Area is : " << maxArea;

    cout << endl;
    return 0;
}