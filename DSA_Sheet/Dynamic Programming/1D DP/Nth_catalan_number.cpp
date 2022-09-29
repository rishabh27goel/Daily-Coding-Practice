#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(3 ^ n)  Space Complexity : O(n)
// int findNumber(int n){

//     // Base Case
//     if(n == 0 || n == 1)
//         return 1;
    

//     // Find the product for previous catalan's
//     int sum = 0;

//     for(int i=0; i<n; i++){

//         sum += (findNumber(i) * findNumber(n-i-1));
//     }

//     return sum;
// }

// int nthCatalanNumber(int n){

//     return findNumber(n);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(n ^ 2)  Space Complexity : O(n)
// int findNumber(int n, vector<int> &catalan){

//     // Base Case
//     if(n == 0 || n == 1)
//         return 1;

    
//     // Step 3 : Already Exists 
//     if(catalan[n] != 0)
//         return catalan[n];
    

//     // Find the product for previous catalan's
//     for(int i=0; i<n; i++){

//         // Step 2 : Store in dp array
//         catalan[n] += (findNumber(i, catalan) * findNumber(n-i-1, catalan));
//     }

//     return catalan[n];
// }

// int nthCatalanNumber(int n){

//     // Step 1 : Create dp array
//     vector <int> catalan(n+1, 0);

//     return findNumber(n, catalan);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(n ^ 2)  Space Complexity : O(n)
int nthCatalanNumber(int n){

    // Step 1 : Create dp array
    vector<int> catalan(n + 1, 0);

    // Base Case
    catalan[0] = 1;
    catalan[1] = 1;

    // Step 2 : Tabulation
    for(int i=2; i<=n; i++){

        for(int j=0; j<i; j++){

            catalan[i] += (catalan[j] * catalan[i-j-1]);
        }
    }

    return catalan[n];
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Nth Catalan Number
    int value = nthCatalanNumber(n);

    cout << "Nth Catalan Numbecr : " << value;


    cout << endl;
    return 0;
}