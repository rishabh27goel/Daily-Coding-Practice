#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Backtracking
// Time Complexity : O(2^n)  Space Complexity : O(n^2)
unordered_map <string, bool> words; 

void wordBreakHelper(string &input, int index, string word, string sent, vector<string> &output){

    if(index > input.size())  return;

    // If we are at last index and last word also exits in map
    if(index == input.size() && words.find(word) != words.end()){

        if(sent.size() == 0){

            sent = word;
        }
        else{

            sent = sent + " " + word;
        }

        output.push_back(sent);

        return;
    }

    // Go to the depth of the string first and check work break
    wordBreakHelper(input, index + 1, word + input[index], sent, output);

    // Check in map 
    if(words.find(word) != words.end()){

        if(sent.size() == 0){

            sent = word;
        }
        else{

            sent = sent + " " + word;
        }

        wordBreakHelper(input, index, "", sent, output);
    }
}

vector<string> workBreakProblem(string &input, vector <string> &dict){

    vector <string> output;
    if(input.size() == 0 || dict.size() == 0) return output;

    // Store the dict in map
    for(int i=0; i<dict.size(); i++){

        words[dict[i]] = true;
    }

    wordBreakHelper(input, 0, "", "", output);

    return output;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    cout << "Enter number of words : ";
    int n;
    cin >> n;

    cout << "Enter words : ";
    vector <string> dict;

    for(int i=0; i<n; i++){

        string word;
        cin >> word;

        dict.push_back(word);
    }

    // Word Break Problem
    vector <string> output = workBreakProblem(input, dict);

    cout << "Word Breaks : \n";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << endl;
    }

    cout << endl;
    return 0;
}