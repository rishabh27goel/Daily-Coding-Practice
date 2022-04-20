#include <iostream>
#include <stack>
using namespace std;

int prec(char ch){

    if(ch == '^'){

        return 3;
    }
    else if(ch == '/' || ch == '*'){

        return 2;
    }
    else if(ch == '+' || ch == '-'){

        return 1;
    }
    else{

        return -1;
    }
}

string infixToPostfix(string infix){

    stack<char> st;
    string postfix = "";

    for(int i=0; i<infix.size(); i++){

        char ch = infix[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){

            postfix += ch;
        }
        else if(ch == '('){

            st.push(ch);
        }
        else if(ch == ')'){

            while(st.top() != '('){

                postfix += st.top(); 
                st.pop();
            }

            st.pop();
        }
        else{

            while(!st.empty() && prec(ch) <= prec(st.top())){

                // ‘^’ operator is right associative and other operators 
                // like ‘+’,’-‘,’*’ and ‘/’ are left associative 
                // Check especially for a condition when both top of the 
                // operator stack and scanned operator are ‘^’
                if(ch == '^' && st.top() == '^'){

                    // In this condition the precedence of scanned operator is 
                    // higher due to it’s right associativity. So it will be pushed 
                    // in the operator stack
                    break;
                }
                else{

                    postfix += st.top();
                    st.pop();
                }
            }

            st.push(ch);
        }
    }

    // Empty the start now
    while(!st.empty()){

        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    cout << "Enter Infix Expression : ";
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix is : " << postfix;

    cout << endl;
    return 0;
}