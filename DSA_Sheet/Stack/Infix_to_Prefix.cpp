#include <iostream>
#include <stack>
using namespace std;

void reverseString(string &str){

    int i = 0;
    int j = str.size()-1;

    while(i < j){

        swap(str[i], str[j]);
        i++;
        j--;
    }
}

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

string infixToPrefix(string infix){

    string prefix = "";
    stack<char> st;

    for(int i=0; i<infix.size(); i++){

        char ch = infix[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){

            prefix += ch;
        }
        else if(ch == '('){

            st.push(ch);
        }
        else if(ch == ')'){

            while(st.top() != '('){

                prefix += st.top();
                st.pop();
            }

            st.pop();
        }
        else{

            if(ch == '^'){

                while(!st.empty() && prec(st.top()) >= prec(ch)){

                    prefix += st.top();
                    st.pop();
                }
            }
            else{

                while(!st.empty() && prec(st.top()) > prec(ch)){

                    prefix += st.top();
                    st.pop();
                }
            }

            st.push(ch);
        }
    }

    // Empty the stack now
    while(!st.empty()){

        prefix += st.top();
        st.pop();
    }

    return prefix;
}

int main()
{
    string infix;
    cout << "Enter Infix String : ";
    cin >> infix;

    // Reverse Brackets
    for(int i=0; i<infix.size(); i++){

        if(infix[i] == '('){

            infix[i] = ')';
        }
        else if(infix[i] == ')'){

            infix[i] = '(';
        }
    }

    reverseString(infix);

    string prefix = infixToPrefix(infix);
    reverseString(prefix);

    cout << "Prefix String : " << prefix;

    cout << endl;
    return 0;
}