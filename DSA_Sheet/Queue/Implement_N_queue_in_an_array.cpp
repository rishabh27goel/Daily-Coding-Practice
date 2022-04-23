#include <iostream>
using namespace std;

// Method 1 : Dividing N Queue in Array [Equal Parts] 
// class NQueue {

//     public:
//         int nQ;
//         int nA;

//         int *arr;
//         int *front;
//         int *rear;

//     NQueue(int nQ, int nA){

//         this->nQ = nQ;
//         this->nA = nA;

//         arr = new int[nA];
//         front = new int[nQ];
//         rear = new int[nQ];

//         // Set initial values of front and rear
//         for(int i=0; i<nQ; i++){

//             front[i] = (i * (nA/nQ)) - 1;
//             rear[i] = (i * (nA/nQ)) - 1;
//         }
//     }

//     void push(int n, int data){

//         if(rear[n-1] >= ((n * (nA/nQ)) - 1)){

//             cout << "Queue is Full !" << endl;
//         }
//         else{

//             if(front[n-1] == (((n-1) * (nA/nQ)) - 1)){

//                 front[n-1]++;
//                 rear[n-1]++;
//             }
//             else{

//                 rear[n-1]++;
//             }

//             arr[rear[n-1]] = data;
//         }
//     }

//     void pop(int n){

//         if(front[n-1] == (((n-1) * (nA/nQ)) - 1)){

//             cout << "Queue is Empty !" << endl;
//         }
//         else{
            
//             int data = arr[front[n-1]];

//             if(front[n-1] == rear[n-1]){

//                 front[n-1] = ((n-1) * (nA/nQ)) - 1;
//                 rear[n-1] = ((n-1) * (nA/nQ)) - 1;;
//             }
//             else{

//                 front[n-1]++;
//             }

//             cout << "Deleted : " << data << endl;
//         }
//     }

//     void frontElement(int n){

//         if(front[n-1] == (((n-1) * (nA/nQ)) - 1)){

//             cout << "Queue is Empty !" << endl;
//         }
//         else{

//             cout << "Front Element is : " << arr[front[n-1]] << endl;
//         }
//     }
// };

// // Method 2 : No memory wastage [Optimised]
class NQueue {

    public:
        int nQ;
        int nA;
        int freeSpot;

        int *arr;
        int *next;
        int *front;
        int *rear;

    NQueue(int nQ, int nA){

        this->nQ = nQ;
        this->nA = nA;
        this->freeSpot = 0;

        arr = new int[nA];
        next = new int[nA];
        front = new int[nQ];
        rear = new int[nQ];

        // Set initial values of front and rear
        for(int i=0; i<nQ; i++){

            front[i] = -1;
            rear[i] = -1;
        }

        for(int i=0; i<nA; i++){

            next[i] = i + 1;
        }

        // Update last freespot
        next[nA-1] = -1;
    }

    void push(int n, int data){

        if(freeSpot == -1){

            cout << "Queue is Full !" << endl;
            return;
        }

        // Get the next freespot 
        int index = freeSpot;

        // Update the freeSpot
        freeSpot = next[index];

        // Check how many element Nth Queue has
        if(front[n-1] == -1){

            front[n-1] = index;
        } 
        else{

            // Connect prev and next element in Nth Queue
            next[rear[n-1]] = index;
        }

        // End of Nth Queue
        next[index] = -1;

        // Update rear
        rear[n-1] = index;

        // Store data in Nth array
        arr[index] = data;
    }

    void pop(int n){

        if(front[n-1] == -1){

            cout << "Queue is Empty !" << endl;
            return;
        }

        // Get front element of the Nth Queue
        int index = front[n-1];

        // Set the new front with the help of next array
        front[n-1] = next[index];
    
        // As next[index] is a freespot now
        // We have a link fromt index to current freespot
        next[index] = freeSpot;

        // Update freespot
        freeSpot = index;

        cout << "Deleted : " << arr[index] << endl;
    }

    void frontElement(int n){

        if(front[n-1] == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Front Element is : " << arr[front[n-1]] << endl;
        }
    }
};

int main()
{
    NQueue nq(3, 9);

    nq.push(1, 10);
    nq.push(2, 20);
    nq.push(1, 30);

    nq.push(2, 40);
    nq.push(3, 50);
    nq.push(1, 60);

    // Queue Full
    nq.push(3, 70);

    nq.pop(1);
    nq.pop(2);

    nq.frontElement(1);
    nq.frontElement(2);
    nq.frontElement(3);
    
    nq.pop(1);
    nq.frontElement(1);

    cout << endl;
    return 0;
}