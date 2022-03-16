#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool parenthesisChecker(string input){

    if(input.size() == 0) return true;
    if(input.size() == 1) return false;

    // Mapping Parenthesis
    stack<char> store;

    map<char, char> mapping;
    mapping['['] = ']';
    mapping['{'] = '}';
    mapping['('] = ')';

    for(char ch : input){

        if(ch == '[' || ch == '{' || ch == '('){
                
            store.push(ch);
        }
        else{

            if(store.empty()) return false;

            if(mapping[store.top()] == ch){

                store.pop();
            }
            else{

                return false;
            }
        }
    }

    return store.empty();
}

int main()
{
    string input;
    cout << "Enter Input String : ";
    cin >> input;

    // Parenthesis Checker
    if(parenthesisChecker(input)){

        cout << "Balanced !!";
    }
    else{

        cout << "Not Balanced !!";
    }

    cout << endl;
    return 0;
}