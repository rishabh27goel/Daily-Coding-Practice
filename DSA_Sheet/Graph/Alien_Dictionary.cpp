#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// Method 1 : Using Depth First Search
// Time Complexity : O(N * |S| + K})  Space Complexity : O(N + K)
// N -> Number of Strings    |S| -> Max length of string   K-> Number of distinct characters 
// void topologicalDFS(unordered_map <char, vector<char> > &adjList, unordered_map <char, bool> &visited, string &output, char start){

//     visited[start] = true;

//     for(int i=0; i<adjList[start].size(); i++){

//         if(visited.find(adjList[start][i]) == visited.end()){

//             topologicalDFS(adjList, visited, output, adjList[start][i]);
//         }
//     }

//     output += start;
// }


// string findAlienDictionary(int n, vector <string> &dict){

//     // Create Adjacency List
//     unordered_map <char, vector<char> > adjList;

//     for(int k=0; k<n-1; k++){

//         int i = 0;
//         int j = 0;

//         while(i < dict[k].size() && j < dict[k+1].size()){

//             if(dict[k][i] != dict[k+1][j]){

//                 // Add Edge
//                 adjList[dict[k][i]].push_back(dict[k+1][j]);

//                 break;
//             }

//             i++;
//             j++;
//         }
//     }

//     // Find Topological Order
//     unordered_map<char, bool> visited;
//     string output = "";
    
//     unordered_map <char, vector<char> > :: iterator itr;

//     for(itr = adjList.begin(); itr != adjList.end(); itr++){

//         if(visited.find(itr->first) == visited.end()){

//             topologicalDFS(adjList, visited, output, itr->first);
//         }
//     }
    
//     // Reverse the order
//     reverse(output.begin(), output.end());

//     return output;
// }


// Method 2 : Using Breadth First Search
// Time Complexity : O(N * |S| + K})  Space Complexity : O(N + K)
// N -> Number of Strings    |S| -> Max length of string   K-> Number of distinct characters 
string findAlienDictionary(int n, vector <string> &dict){

    // Create Adjacency List
    unordered_map <char, vector<char> > adjList;
    unordered_map <char, int> inorder;
    
    int index = 0;

    for(int k=0; k<n-1; k++){

        int i = 0;
        int j = 0;

        while(i < dict[k].size() && j < dict[k+1].size()){

            inorder[dict[k][i]] = 0;
            inorder[dict[k+1][j]] = 0;

            if(dict[k][i] != dict[k+1][j]){

                // Add Edge
                adjList[dict[k][i]].push_back(dict[k+1][j]);

                break;
            }

            i++;
            j++;
        }
    }

    // Find the inorder of nodes
    unordered_map <char, int> :: iterator itr;

    for(itr = inorder.begin(); itr != inorder.end(); itr++){

        char ch = itr->first;

        for(int i=0; i<adjList[ch].size(); i++){

            inorder[adjList[ch][i]]++;
        }
    }

    // Find the topological order
    queue <char> q;

    for(itr = inorder.begin(); itr != inorder.end(); itr++){

        if(inorder[itr->first] == 0){

            q.push(itr->first);
        }
    }

    string output = "";

    while(!q.empty()){

        char front = q.front();
        q.pop();

        output += front;

        for(int i=0; i<adjList[front].size(); i++){

            inorder[adjList[front][i]]--;

            if(inorder[adjList[front][i]] == 0){

                q.push(adjList[front][i]);
            }
        }
    }

    return output;
}

int main()
{
    cout << "Enter number of strings : ";
    int n;
    cin >> n;

    // Input : { wrt wrf er ett rftt }
    cout << "Enter Strings : ";
    vector <string> dict;

    for(int i=0; i<n; i++){

        string str;
        cin >> str;

        dict.push_back(str);
    }

    // Alien Dictionary
    string order = findAlienDictionary(n, dict);

    if(order.size()){

        cout << "Order is : " << order;
    }
    else{

        cout << "No Order Exits !!";
    }
    

    cout << endl;
    return 0;
}