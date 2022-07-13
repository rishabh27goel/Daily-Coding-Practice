#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O(n * 2^n)  Space Complexity : O(n^2)
bool isPalindrome(string &input){

    int i = 0;
    int j = input.size()-1;

    while(i < j){

        if(input[i] != input[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void partitionHelper(string &input, int index, string s, vector <string> &partition, vector< vector<string> > &output){

    if(index == input.size()){

        if(s.size() == 0){

            output.push_back(partition);
        }

        return;
    }

    string next = s + input[index];

    if(isPalindrome(next)){

        partition.push_back(next);
        partitionHelper(input, index + 1, "", partition, output);
        partition.pop_back();
    }

    partitionHelper(input, index + 1, next, partition, output);
}

vector< vector<string> > possiblePalindromicPartitions(string &input){

    vector< vector<string> > output;
    if(input.size() == 0) return output;

    vector <string> partition;
    partitionHelper(input, 0, "", partition, output);

    return output;
}

int main()
{   
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // Possible Palindromic Partitions
    vector< vector<string> > output = possiblePalindromicPartitions(input);

    cout << "Possible Palindromic Partitions : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}