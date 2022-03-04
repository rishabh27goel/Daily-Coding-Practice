#include <iostream>
using namespace std;

// Method 1 : Iterating from l to r
// void copySetBit(int &x, int &y, int &l, int &r){

//     if(l < 1 || r > 32) return;

//     for(int i=l-1; i<r; i++){

//         if(y & (1 << i)){

//             x |= (1 << i);
//         }
//     }
// }

// Method 2 : Without iterating
void copySetBit(int &x, int &y, int &l, int &r){

    if(l < 1 || r > 32) return;

    long maskNumber = (1LL << (r-l+1)) - 1;

    long mask = (maskNumber << (l-1)) & y;

    x = x | mask;
}

int main()
{
    int x, y, l, r;

    cout<< "Enter the 1st number : ";
    cin>>x;

    cout<< "Enter the 2nd number : ";
    cin>>y;

    cout<< "Enter left limit : ";
    cin>>l;

    cout<< "Enter right limit : ";
    cin>>r;

    copySetBit(x, y, l, r);

    cout<<"Modified X is : "<<x;;

    cout<<endl;
    return 0;
}