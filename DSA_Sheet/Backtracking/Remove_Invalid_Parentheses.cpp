#include <iostream>
#include <vector>
using namespace std;

// Method : Backtracking
// Time Complexity : O()  Space Complexity : O()
vector<string> output;

bool isValid(string &s){

    int pair = 0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == '('){

            pair++;
        }
        else if(s[i] == ')'){

            pair--;

            if(pair < 0)  return false;
        }

    }

    // If string is balanced
    return pair == 0;
}

void removeHelper(string input, int index, int left, int right){

    if(left == 0 && right == 0){

        // Pushing the valid string only
        if(isValid(input)){

            output.push_back(input);
        }

        return;
    }

    for(int i=index; i<input.size(); i++){

        if(i > index && input[i] == input[i-1])  continue;

        string tmp = input;

        if(right == 0 && left > 0 && input[i] == '('){

            tmp.erase(i, 1);
            removeHelper(tmp, i, left-1, right);
        }
        else if(right > 0 && input[i] == ')'){

            tmp.erase(i, 1);
            removeHelper(tmp, i, left, right-1);
        }
    }
}

vector<string> removeInvalidParentheses(string &input){

    if(input.size() == 0)  return output; 

    // Count '(' & ')' due to which string is invalid
    int left = 0;
    int right = 0;

    for(int i=0; i<input.size(); i++){

        if(input[i] == '('){

            left++;
        }
        else if(input[i] == ')'){

            if(left > 0){

                left--;
            }
            else{

                right++;
            }
        }

    }

    // Helper for removing invalid parentheses
    removeHelper(input, 0, left, right);

    return output;
}

int main()
{
    cout << "Enter Input : ";
    string input;
    cin >> input;

    // Remove Invalid Parentheses
    vector<string> output = removeInvalidParentheses(input);

    cout << "Valid Strings : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}