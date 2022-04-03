#include <iostream>
#include <stack>
using namespace std;

// class Node {

//     public:
//         int data;
//         Node* next;

//     Node(int data){

//         this->data = data;
//         this->next = NULL;
//     }
// };

// class SpecialStack {

//     public:
//         int size;
//         int min;
//         Node* top;

//     SpecialStack(){

//         min = INT_MAX;
//         size = 0;
//         top = NULL;
//     }

//     void push(int data){

//         Node* newNode = new Node(data);

//         if(top == NULL){

//             top = newNode;
//             min = data;
//         }
//         else{

//             int val;

//             if(min > data){

//                 val = 2*data - min;
//                 min = data;
//                 newNode->data = val;
//             }

//             newNode->next = top;
//             top = newNode;
//         }
//     }

//     int pop(){

//         if(top == NULL){

//             cout << "Stack Underflow !!" << endl;
//             return -1;
//         }
//         else{

//             Node* store = top;
//             int val = top->data;
//             top = top->next;
//             delete store;

//             if(val < min){

//                 min = 2*min - val;
//                 return min;
//             }
//             else{

//                 return val;
//             }
//         }
//     }

//     int topValue(){

//         if(top == NULL){

//             return -1;
//         }
//         else{

//             int val = top->data;

//             if(val < min){

//                 return min;
//             }
//             else{

//                 return val;
//             }
//         }
//     }

//     void isEmpty(){

//         if(top == NULL){

//             cout << "Stack is Empty !" << endl;
//         }
            
//         else{

//             cout << "Stack is not Empty !" << endl;
//         }
//     }

//     int getMin(){

//         if(top == NULL){

//             return -1;
//         }
//         else{

//             return min;
//         }
//     }
// };

class SpecialStack {

    public:
        stack<int> st;
        int min; 

    SpecialStack(){

        min = INT_MAX;
    }

    void push(int data){

        if(st.empty()){

            min = data;
            st.push(data);
        }
        else{

            if(data < min){

                int val = 2*data - min;

                min = data;
                st.push(val);
            }
            else{

                st.push(data);
            }
        }
    }

    int pop(){

        if(st.empty()){

            return -1;
        }      
        else{

            int curr = st.top();
            st.pop();

            if(curr < min){

                min = 2*min - curr;
                return min;
            }
            else{

                return curr;
            }
        }
    }

    int topValue(){

        if(st.empty()){

            return -1;
        }
        else{

            if(st.top() < min){

                return min;
            }
            else{

                return st.top();
            }
        }
    }

    void isEmpty(){

        if(st.empty()){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Stack is not Empty !" << endl;
        }        
    }

    int getMin(){

        if(st.empty()){

            return -1;
        }
        else{

            return min;
        }
    }
};

int main()
{
    SpecialStack s;

    s.push(270);
    s.push(202);
    s.push(-320);

    cout << "Min Element : " << s.getMin() << endl;
    s.isEmpty();

    s.push(-752);
    cout << "Top Element : " << s.topValue() << endl;

    s.push(31);
    cout << "Deleted Element : " << s.pop() << endl;

    s.push(-87);

    cout << "Top Element : " << s.topValue() << endl;
    cout << "Deleted Element : " << s.pop() << endl;

    s.push(-939);
    cout << "Min Element : " << s.getMin() << endl;
    cout << "Deleted Element : " << s.pop() << endl;
    cout << "Min Element : " << s.getMin() << endl;

    return 0;
}