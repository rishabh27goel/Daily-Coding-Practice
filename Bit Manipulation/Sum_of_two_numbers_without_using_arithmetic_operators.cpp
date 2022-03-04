#include<iostream>
using namespace std;

int sum(int a , int b){
    
    if(b == 0) return a;
    
    while(b != 0){
        
        unsigned carry = a & b;
        
        a = a ^ b;
        b = carry << 1;
    }
    
    return a;
}

int main()
{
    int a, b;
    cout <<"Enter the first number: ";
    cin >> a;
    cout <<"Enter the second number: ";
    cin >> b;

    int result = sum(a, b);
    cout <<"Sum of numbers is : " <<result;

    cout<<endl;
    return 0;
}