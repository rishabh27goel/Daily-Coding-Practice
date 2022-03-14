#include <iostream>
using namespace std;

class Stack {

    public:
        int *arr;
        int size;
        int top1;
        int top2;

    Stack(int size){

        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data){

        if(top2 - top1 > 1){

            top1++;
            arr[top1] = data;
        }
        else{

            cout << "Stack 1 Overflow !!" << endl;
        }   
    }

    void push2(int data){

        if(top2 - top1 > 1){

            top2--;
            arr[top2] = data;
        }
        else{

            cout << "Stack 2 Overflow !!" << endl;
        }
    }

    void pop1(){

        if(top1 >= 0){

            top1--;
        }
        else{

            cout << "Stack 1 Underflow !!" << endl;
        }
    }

    void pop2(){

        if(top2 < size){

            top2++;
        }
        else{

            cout << "Stack 2 Underflow !!" << endl;
        }
    }

    int peek1(){

        if(top1 != 0){

            return arr[top1];
        }
        else{

            return -1;
        }
    }

    int peek2(){

        if(top2 != size){

            return arr[top2];
        }
        else{

            return -1;
        }
    }

    bool isEmpty1(){

        if(top1 == -1){

            return true;
        }
        else{

            return false;
        }
    }

    bool isEmpty2(){

        if(top2 == size){

            return true;
        }
        else{

            return false;
        }
    }
};

int main()
{
    // Creating an Object
    Stack s(5);

    // Pushing in first stack
    s.push1(5);
    s.push1(15);
    s.push1(25);

    // Pushing in second stack
    s.push2(10);
    s.push2(20);  

    // Top Values 
    cout << "Stack 1 top : " << s.peek1() << endl;  
    cout << "Stack 2 top : " << s.peek2() << endl;

    // Stack Empty
    if(s.isEmpty1()){

        cout << "Stack 1 is Empty !!" << endl;
    }
    else{

        cout << "Stack 1 is not Empty !!" << endl;;
    }

    if(s.isEmpty2()){

        cout << "Stack 2 is Empty !!" << endl;
    }
    else{

        cout << "Stack 2 is not Empty !!" << endl;
    }

    // Overflow Check
    s.push1(2);
    s.push2(3);

    // Underflow Check
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop2();
    s.pop2();
    s.pop2();

    cout << endl;
    return 0;
}