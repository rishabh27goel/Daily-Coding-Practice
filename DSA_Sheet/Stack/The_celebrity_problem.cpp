#include <iostream>
#include <stack>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n^2)   Space Complexity : O(1)
// int findCelebrity(int *input, int n){

//     if(n == 0 || n == 1) return -1;

//     bool isCelebrity;

//     // Check for all persons rows and col
//     for(int i=0; i<n; i++){

//         isCelebrity = false;

//         // Row check for 0
//         for(int row=0; row<n; row++){

//             if(row != i){

//                 if(*((input + i*n) + row) == 0){

//                     isCelebrity = true;
//                 }
//                 else{

//                     isCelebrity = false;
//                     break;
//                 }
//             } 
//         }

//         if(isCelebrity == false) 
//             continue;

//         // Column check for 1
//         for(int col=0; col<n ; col++){

//             if(i != col){

//                 if(*((input + col*n) + i) == 1){

//                     isCelebrity = true;
//                 }
//                 else{

//                     isCelebrity = false;
//                     break;
//                 }
//             }
            
//         }

//         if(isCelebrity == true) return i;
//     }

//     return -1;
// }

// Method 2 : Using Stack Elimination
// Time Complexity : O(n)   Space Complexity : O(n)
// int findCelebrity(int *input, int n){

//     if(n == 0 || n == 1) return -1;

//     stack<int> st;

//     // Storing all people in stack
//     for(int i=0; i<n; i++){

//         st.push(i);
//     }

//     // Now iterate till stack does not have only one person left
//     while(st.size() != 1){

//         int A = st.top();
//         st.pop();

//         int B = st.top();
//         st.pop();


//         if(*((input + A*n) + B) == 1){
                
//             // A is not a celebrity
//             st.push(B);
//         }
//         else{
            
//             // A can be a celebrity
//             st.push(A);
//         }
//     }

//     // Now check whether person left in the 
//     // stack is a celebrity or not

//     bool isCelebrity = false;
//     int person = st.top();
    
//     // Check row & column
//     for(int i=0; i<n; i++){

//         if(i != person){

//             if(*((input + person*n) + i) == 0 && *((input + i*n) + person) == 1){

//                 isCelebrity = true;
//             }
//             else{

//                 return -1;
//             }
//         }
//     }

//     return person;
// }

// Method 3 : Without any stack elimination
// Time Complexity : O(n)   Space Complexity : O(n)
int findCelebrity(int *input, int n){

    if(n == 0 || n == 1) return -1;

    int start = 0;
    int last = n-1;

    // Eliminate person after each cycle
    while(start != last){

        if(*((input + start*n) + last) == 1){

            // Start is not the celebrity
            start++;
        }
        else{

            // Start can be a celebrity
            last--;
        }
    }

    int person = start;
    
    // Now check row and col for person
    for(int i=0; i<n; i++){

        if(person != i){

            if(*((input + person*n) + i) != 0 && *((input + i*n) + person) != 1){

                return -1;
            }
        }
    }

    return person;
}

int main()
{
    int n;
    cout << "Enter size of matrix : ";
    cin >> n;

    int input[n][n];

    cout << "Enter values of matrix : ";
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> input[i][j];
        }
    }

    int person = findCelebrity((int *)input, n);
    
    if(person == -1){

        cout << "No Celebrity Exits !! ";
    }
    else{

        cout << person << " is the celebrity !! ";
    }

    cout << endl;
    return 0;
}