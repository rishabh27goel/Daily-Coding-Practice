#include <iostream>
#include <stack>
using namespace std;

int evaluationOfPostfix(string input){

    stack<int> st;

    for(int i=0; i<input.size(); i++){

        // If char is number
        if(input[i] >= '0' && input[i] <= '9'){

            st.push(input[i]-'0');
        }
        else{

            int B = st.top();
            st.pop();

            int A = st.top();
            st.pop();

            if(input[i] == '+'){

                st.push(A + B);
            }
            else if(input[i] == '-'){

                st.push(A - B);
            }
            else if(input[i] == '*'){

                st.push(A * B);
            }
            else if(input[i] == '/'){

                st.push(A / B);
            }
        }

    }

    return st.top();
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    int value = evaluationOfPostfix(input);
    cout << "Value is : " << value;

    cout << endl;
    return 0;
}