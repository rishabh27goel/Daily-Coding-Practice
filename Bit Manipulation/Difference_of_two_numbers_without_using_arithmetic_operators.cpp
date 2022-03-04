#include<iostream>
using namespace std;

int difference(int a , int b){
    
    if(b == 0) return a;
    
    while(b != 0){
        
        int diff = (~a) & b;
        
        a = a ^ b;
        b = diff << 1;
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

    int result = difference(a, b);
    cout <<"Difference of numbers is : " <<result;

    cout<<endl;
    return 0;
}