#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(!n)   Space Complexity : O(|s|) [Length of String]
void getPermutationHelper(string input, int index, vector<string> &output){

    if(index == input.size()-1){

        output.push_back(input);
        return;
    }

    for(int i=index; i<input.size(); i++){

        if(i != index && input[i] == input[index])  continue;

        swap(input[i], input[index]);
        getPermutationHelper(input, index + 1, output);
    }
}

vector<string> permutations(string input){

    vector<string> output;
    if(input.size() == 0) return output;

    sort(input.begin(), input.end());
    getPermutationHelper(input, 0, output);

    return output;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // Permutations Of String
    vector<string> output = permutations(input);

    cout << "Permutations of String : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}