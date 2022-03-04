#include <iostream>
using namespace std;

// Method 1 : Time Complexity : O(n * log(n))
// int setBits(int n){

//     if(n == 0) return 0;

//     return (n % 2) + setBits(n >> 1);
// }

// int countTotalSetBits(int n){

//     int result = 0;

//     for(int i=1; i<=n; i++){

//         result += setBits(i);
//     }

//     return result;
// }

// Method 2 : Time Complexity : O((bits to represent n) * n)
// int countTotalSetBits(int n){

//     int result = 0;
//     int twoPower = 1;

//     while(twoPower <= n){

//         for(int i=1; i<=n; i++){

//             if(i & twoPower){

//                 result++;
//             }
//         }

//         twoPower = (twoPower << 1);
//     }

//     return result;
// }

// Method 3 : Time Complexity : O(log(n))
int leftMostBitHelper(int n){

    int index = 0;

    while((1 << index) <= n){

        index++;
    }

    return index;
}

int countTotalSetBits(int n)
{
    if(n == 0) return 0;

    int leftMostBit = leftMostBitHelper(n);

    if(n == ((1 << leftMostBit) - 1)){

        return (leftMostBit * (1 << (leftMostBit-1)));
    }

    n = n - (1 << (leftMostBit - 1)) + 1;

    return n + countTotalSetBits(n - 1) + (((leftMostBit-1) * (1 << (leftMostBit-2)))) ;
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>> n;

    for(int i=0; i<=n; i++){

        int result = countTotalSetBits(i);
        cout <<"Total Set Bits : " <<result <<endl;
    }

    cout<<endl;
    return 0;
}