#include <iostream>
#include <math.h>
using namespace std;

// Method 1 : Time Complexity : O(a)
// int findQuotient(int a,int b){

//     bool flag = ((a < 0) ^ (b < 0)) ? true : false;
//     int quotient = 0;

//     a = abs(a);
//     b = abs(b);

//     while(a >= b){

//         a = a - b;
//         quotient++;
//     }

//     if(flag) return -quotient;

//     return quotient;
// }

// Method 2 : Time Complexity : O(log(a))
int findQuotient(long long a, long long b){

    if(b == 0) return -1;

    bool flag = ((a < 0) ^ (b < 0)) ? true : false;

    a = abs(a);
    b = abs(b);

    long long store = a;
    long long quotient = 0;

    long numBits = (int)log2(a) + 1;

    for(int i = numBits; i >= 0; i--){

        if(store >= (b << i)){

            store -= (b << i);
            quotient |= (1LL << i);
        }
    }

    if(flag) return -quotient;
    
    return quotient; 
}

int main()
{
    int a, b;
    cout<<"Enter the divident : ";
    cin>>a;

    cout<<"Enter the divisor: ";
    cin>>b;

    int quotient = findQuotient(a, b);
    
    cout<<"Quotient is : "<<quotient;

    cout << endl;
    return 0;
}