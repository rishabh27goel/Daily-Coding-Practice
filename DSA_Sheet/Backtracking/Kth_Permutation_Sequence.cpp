#include <iostream>
#include <vector>
using namespace std;

// Method : 
// Time Complexity : O(n^2)  Space Complexity : O(n)
string kthPermutationSequence(int n, int k){

    if(n == 0)  return "";

    string output = "";

    vector<int> number;
    int fact = 1;

    for(int i=1; i<=n; i++){

        fact *= i;
        number.push_back(i);
    }

    // Update values
    k = k - 1;
    fact = fact / n;

    int num = n-1;
    int index;

    while(num != 0){

        index = k / fact; 

        // Get the index'th number
        output += (char) (number[index] + '0');

        // Remove the index'th from number vector
        number.erase(number.begin() + index);

        k = k % fact;
        fact = fact / num--;
    }

    // Last number from number vector
    output += (char) (number[0] + '0');

    return output;
}

int main()
{
    cout << "Enter value of n : ";
    int n;
    cin >> n;

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // K-th Permutation Sequence
    string output = kthPermutationSequence(n, k);

    cout << "Kth Permutation Sequence : " << output;


    cout << endl;
    return 0;
}