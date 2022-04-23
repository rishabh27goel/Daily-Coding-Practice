#include <iostream>
using namespace std;

// Method 1 : Dividing N Stack in Array [Equal Parts] 
// class NStack {

//     public:
//         int nS;
//         int nA;
//         int *arr;
//         int *top;

//     NStack(int nS, int nA){

//         this->nS = nS;
//         this->nA = nA;
//         arr = new int[nA];
//         top = new int[nS];

//         for(int i=0; i<nS; i++){

//             top[i] = (i * (nA/nS)) - 1;
//         }
//     }

//     void push(int x, int m){

//         if(top[m-1] >= ((m * (nA/nS)) - 1)){

//             cout << "Stack is Full !" << endl;
//             return;
//         }

//         top[m-1]++;
//         arr[top[m-1]] = x;
//     }

//     void pop(int m){

//         if(top[m-1] == (((m-1) * (nA/nS))-1)){

//             cout << "Stack is Empty !" << endl;
//             return;
//         }

//         int index = top[m-1];
//         top[m-1]--;

//         cout << "Deleted : " << arr[index] << endl;
//     }

//     void topElement(int m){

//         if(top[m-1] == (((m-1) * (nA/nS))-1)){

//             cout << "Stack is Empty !" << endl;
//         }
//         else{

//             cout << "Top Element is : " << arr[top[m-1]];
//         }
//     }
// };

// Method 2 : No memory wastage [Optimised]
class NStack {

    public:
        int nS;
        int nA;
        int freeSpot;

        int *arr;
        int *top;
        int *next;

    NStack(int nS, int nA){

        this->nS = nS;
        this->nA = nA;

        // Set up array
        arr = new int[nA];
        top = new int[nS];
        next = new int[nA];

        // Initialize freeSpot
        this->freeSpot = 0;

        // Initialize next and top to initial values
        for(int i=0; i<nS; i++){

            top[i] = -1;
        }

        for(int i=0; i<nA; i++){

            next[i] = i + 1;
        }

        // Set last to -1;
        next[nA-1] = -1;
    }

    void push(int x, int m){

        if(freeSpot == -1){

            cout << "Array is Full !" << endl;
            return;
        }

        // Store Freespot
        int index = freeSpot;

        // Update Freespot
        freeSpot = next[index];

        // Add value in the array
        arr[index] = x;

        // Update the next array
        next[index] = top[m-1];

        // Update top array
        top[m-1] = index;
    }

    void pop(int m){

        if(top[m-1] == -1){

            cout << "Stack is Empty !" << endl;
            return;
        }

        // Implement Push Steps in Reverse Order
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        cout << "Deleted : " << arr[index] << endl;
    }

    void topElement(int m){

        if(top[m-1] == -1){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Top Element is : " << arr[top[m-1]];
        }
    }
};

int main()
{
    NStack nS(3, 6);

    nS.push(10, 1);
    nS.push(20, 1);
    nS.push(30, 2);
    nS.push(40, 3);
    nS.push(5, 2);

    nS.pop(1);
    nS.pop(1);

    nS.pop(1);

    nS.push(10, 3);
    nS.push(10, 3);
    nS.push(25, 1);

    nS.pop(1);


    cout << endl;
    return 0;
}