#include <iostream>
using namespace std;

// Method 1 : Time Complexity : O(n)
// int squareOfNumber(int n){

//     if(n == 0) return 0;

//     int sum = 0;

//     for(int i = 0; i<n; i++){

//         sum += n;
//     }

//     return sum;
// }

// Method 2 : Time Complexity : O(Log(n))
// int squareOfNumber(int n){

//     if(n == 0) return 0;

//     if(n < 0)
//         n = -n;

//     if(n & 1)
//         return ((squareOfNumber((n >> 1)) << 2) + ((n >> 1) << 2) + 1);
//     else
//         return (squareOfNumber((n >> 1)) << 2);
// }

// Method 3 : Time Complexity : O(Log(n))
// Converting [N * N] to [N * (power of 2 using bit manipulation)]
int squareOfNumber(int n){

    int result = 0;

    int store = n;
    int index = 0;

    while(store != 0){

        if(n & (1 << index)){

            result += (n << index);
            store -= (1 << index);
        }

        index++;
    }

    return result;
}


int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>> n;

    int result = squareOfNumber(n);

    cout <<"Square of the number is : " <<result;


    cout<<endl;
    return 0;
}