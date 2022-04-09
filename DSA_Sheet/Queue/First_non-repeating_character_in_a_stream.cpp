#include <iostream>
#include <queue>
using namespace std;

// Method 1 : Using Queue
// Time Complexity : O(n)   Space Complexity : O(n + 26(const))
// string firstNonRepeating(string input){

//     if(input.size() <= 1) return input;

//     string output = "";
//     int count[26] = {0};
//     queue<char> q;

//     for(int i=0; i<input.size(); i++){

//         // Updating Count
//         count[input[i]-'a']++;
//         q.push(input[i]);

//         while(!q.empty() && count[q.front()-'a'] > 1){

//             q.pop();
//         }

//         if(q.empty()){

//             output += '#';
//         }
//         else{

//             output += q.front();
//         }
//     }

//     return output;
// }

// Method 2 : Linear and Without Extra Space (Only Constant)
// Time Complexity : O(n * 26)   Space Complexity : O(26) [Constant]
string firstNonRepeating(string input){

    if(input.size() <= 1) return input;

    string output = "";
    int count[26] = {0};

    for(int i=0; i<input.size(); i++){

        if(count[input[i]-'a'] == 0){

            count[input[i]-'a'] = i+1;
        }
        else{

            count[input[i]-'a'] = -1;
        }

        int min = INT_MAX;

        for(int i=0; i<26; i++){

            if(count[i] > 0 && count[i] < min){

                min = count[i];
            }
        }

        if(min == INT_MAX){

            output += '#';
        }
        else{

            output += input[min-1];
        }
    }

    return output;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    string output = firstNonRepeating(input);
    cout << "Output String is : " << output;

    cout << endl;
    return 0;
}