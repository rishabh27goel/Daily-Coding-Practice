#include <iostream>
#include <stack>
using namespace std;

// Method : Using Stack
bool redundantBrackets(string input){

    if(input.size() == 0) return false;

    // Valid Brackets is ( a * b ) -> Operator between brackets
    stack<char> st;

    for(int i=0; i<input.size(); i++){

        char ch = input[i];

        // If '(' or Operators push in stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){

            st.push(ch);
        }
        else{

            // Lowercase or ')' left
            if(ch == ')'){

                bool containsOperator = false;

                // Reach to '(' in stack
                while(st.top() != '('){

                    char top = st.top();

                    if(top == '+' || top == '-' || top == '*' || top == '/'){

                        containsOperator = true;
                        st.pop();
                    }
                }   

                if(containsOperator == false) return true;     

                // Now remove the topmost '(' bracket
                st.pop();
            }
        }
    }

    return false;
}

int main()
{
    string input;
    cout << "Enter Input String : ";
    cin >> input;

    bool check = redundantBrackets(input);

    if(check){

        cout << "Contains Reductant Brackets !!";
    }
    else{

        cout << "No Reductant Brackets !!";
    }

    cout << endl;
    return 0;
}